// smallpaint by karoly zsolnai - zsolnai@cg.tuwien.ac.at
// virtual ray lights implementation by michael oppitz - e1227129@student.tuwien.ac.at
//
// This is an implementation of the "Virtual Ray Lights for Rendering Scenes with Participating Media"
// paper by Novák et al.
//
// This program is used as an educational learning tool on the Rendering
// course at TU Wien. Course webpage:
// http://cg.tuwien.ac.at/courses/Rendering/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>
#include <algorithm>
#include "../src_gui/main.h"

namespace smallpaint_vrl {
// Helpers for random number generation
std::mt19937_64 mersenneTwister;
std::uniform_real_distribution<double> uniform;

#define RND (2.0*uniform(mersenneTwister)-1.0)
#define RND2 (uniform(mersenneTwister))

#define PI 3.1415926536
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int width, height;
const double inf = 1e9;
const double eps = 1e-6;
using namespace std;

struct Vec {
    double x, y, z;
    Vec(double x0, double y0, double z0) { x = x0; y = y0; z = z0; }
    Vec(double x0) { x = x0; y = x0; z = x0; }
    Vec() { x = 0; y = 0; z = 0; }
    Vec operator+(const Vec &b) const { return Vec(x + b.x, y + b.y, z + b.z); }
    Vec operator-(const Vec &b) const { return Vec(x - b.x, y - b.y, z - b.z); }
    Vec operator*(double b) const { return Vec(x*b, y*b, z*b); }
    Vec operator*(const Vec &b) const { return Vec(x*b.x, y*b.y, z*b.z); }
    Vec operator/(double b) const { return Vec(x / b, y / b, z / b); }
    Vec operator/(const Vec &b) const { return Vec(x / b.x, y / b.y, z / b.z); }
    Vec& norm() { return *this = *this * (1 / std::sqrt(x*x + y*y + z*z)); }
    double length() { return std::sqrt(x*x + y*y + z*z); }
    double dot(const Vec &b) const { return x*b.x + y*b.y + z*b.z; }
    Vec operator%(const Vec &b) const { return Vec(y*b.z - z*b.y, z*b.x - x*b.z, x*b.y - y*b.x); }
    Vec exp() const { return Vec(std::exp(x), std::exp(y), std::exp(z)); }
    float dist(const Vec &b) const { return std::sqrt((x - b.x)*(x - b.x) + (y - b.y)*(y - b.y) + (z - b.z)*(z - b.z)); }
};

// given v1, set v2 and v3 so they form an orthonormal system
// (we assume v1 is already normalized)
void ons(const Vec& v1, Vec& v2, Vec& v3) {
    if (std::abs(v1.x) > std::abs(v1.y)) {
        // project to the y = 0 plane and construct a normalized orthogonal vector in this plane
        float invLen = 1.f / sqrtf(v1.x * v1.x + v1.z * v1.z);
        v2 = Vec(-v1.z * invLen, 0.0f, v1.x * invLen);
    } else {
        // project to the x = 0 plane and construct a normalized orthogonal vector in this plane
        float invLen = 1.0f / sqrtf(v1.y * v1.y + v1.z * v1.z);
        v2 = Vec(0.0f, v1.z * invLen, -v1.y * invLen);
    }
    v3 = v1 % v2;
}

// Rays have origin and direction.
// The direction vector should always be normalized.
struct Ray {
    Vec o, d;
    Ray(Vec o0 = 0, Vec d0 = 0) { o = o0, d = d0.norm(); }
};

// struct to store raypaths, photon power at the origin of the ray and the distances
struct RayPath {
private:
    Vec o, d, e, power;
    float dist, prevDist;

public:
    RayPath(Vec o0, Vec d0, Vec e0, Vec power0, float dist0, float prevDist0) :
        o(o0), d(d0), e(e0), power(power0), dist(dist0), prevDist(prevDist0) {}
    RayPath(){}
    void addToPaths(std::vector<RayPath*>& paths, Vec e0, float dist0) {
        e = e0; dist = dist0;
        paths.push_back(this);
    }
    Vec getOrigin() { return o; }
    Vec getDirection() { return d; }
    Vec getEnd() { return e; }
    Vec getPhotonPower() { return power; }
    void setPhotonPower(Vec p) { power = p; }
    float ownDistance() { return dist; }
    float prevDistance() { return prevDist; }
    float combinedDistance() { return dist + prevDist; }
};

// Objects have color, emission, type (diffuse, specular, refractive)
// All object should be intersectable and should be able to compute their surface normals.
class Obj {
public:
    Vec cl;
    double emission;
    int type;
    void setMat(Vec cl_ = 0, double emission_ = 0, int type_ = 0) { cl = cl_; emission = emission_; type = type_; }
    virtual double intersect(const Ray&) const = 0;
    virtual Vec normal(const Vec&) const = 0;
};

class Plane : public Obj {
public:
    Vec n;
    double d;
    Plane(double d_ = 0, Vec n_ = 0) {
        d = d_;
        n = n_;
    }
    double intersect(const Ray& ray) const {
        double d0 = n.dot(ray.d);
        if (d0 != 0) {
            double t = -1 * (((n.dot(ray.o)) + d) / d0);
            return (t > eps) ? t : 0;
        } else return 0;
    }
    Vec normal(const Vec& p0) const { return n; }
};

class Sphere : public Obj {
public:
    Vec c;
    double r;

    Sphere(double r_ = 0, Vec c_ = 0) { c = c_; r = r_; }
    double intersect(const Ray& ray) const {
        double b = ((ray.o - c) * 2).dot(ray.d);
        double c_ = (ray.o - c).dot((ray.o - c)) - (r*r);
        double disc = b*b - 4 * c_;
        if (disc < 0) return 0;
        else disc = sqrt(disc);
        double sol1 = -b + disc;
        double sol2 = -b - disc;
        return (sol2 > eps) ? sol2 / 2 : ((sol1 > eps) ? sol1 / 2 : 0);
    }

    Vec normal(const Vec& p0) const {
        return (p0 - c).norm();
    }
};

class Intersection {
public:
    Intersection() { t = inf; object = nullptr; }
    Intersection(double t_, Obj* object_) { t = t_; object = object_; }
    operator bool() { return object != nullptr; }
    double t;
    Obj* object;
};

class Medium {
public:
    float g;
    Vec sigma_a, sigma_s, sigma_t, pos, size;

    Medium(Vec s_a, Vec s_s, float g0, Vec p, Vec s)
        : sigma_a(s_a), sigma_s(s_s), g(g0), pos(p), size(s) {
        sigma_t = sigma_a + sigma_s;
    }
};

class Pointlight {
public:
    Vec pos, intensity;
    Pointlight(Vec pos0, Vec intensity0)
        : pos(pos0), intensity(intensity0) {}

    Vec getRandomDir() {
        return Vec(RND, RND, RND).norm();
    }
    Vec getConeDir() {
        return Vec(RND2 / 4 - .125, -1, RND2 / 4 - .125).norm();
    }
};

class Scene {
    vector<Obj*> objects;

public:
    Medium* medium;
    Pointlight* pointlight;
    double refr_index;

    void add(Obj* object) {
        objects.push_back(object);
    }

    void add(Pointlight* p) {
        pointlight = p;
    }

    void add(Medium* m) {
        medium = m;
    }

    Intersection intersect(const Ray& ray) const {
        Intersection closestIntersection;
        // intersect all objects, one after the other
        for (auto iter = objects.begin(); iter != objects.end(); ++iter) {
            double t = (*iter)->intersect(ray);
            if (t > eps && t < closestIntersection.t) {
                closestIntersection.t = t;
                closestIntersection.object = *iter;
            }
        }
        return closestIntersection;
    }

    void clear() {
        for (int i = 0; i < objects.size(); i++) {
            delete objects.at(i);
        }
    }
};

// Input is the pixel offset, output is the appropriate coordinate
// on the image plane
Vec camcr(const double x, const double y) {
    double w = width;
    double h = height;
    float fovx = PI / 4;
    float fovy = (h / w) * fovx;
    return Vec(((2 * x - w) / w) * tan(fovx),
               -((2 * y - h) / h) * tan(fovy),
               -1.0);
}

// Uniform sampling on a hemisphere to produce outgoing ray directions.
// courtesy of http://www.rorydriscoll.com/2009/01/07/better-sampling/
Vec hemisphere(double u1, double u2) {
    const double r = sqrt(1.0 - u1*u1);
    const double phi = 2 * PI * u2;
    return Vec(cos(phi)*r, sin(phi)*r, u1);
}

// returns a random point on the surface
Ray sphere(Obj* light, double u1, double u2) {
    Sphere* s = dynamic_cast<Sphere*>(light);
    double theta = 2 * PI * u1;
    double phi = acos(1 - 2 * u2);
    double x = sin(phi) * cos(theta);
    double y = sin(phi) * sin(theta);
    double z = cos(phi);
    Vec d = Vec(x, y, z);
    return Ray(s->c + d * s->r, d);
}

//include closestPointOnLine & shortestPointsOnLineSegments functions (just to make this file smaller)
#include "smallpaint_vrl_distanceFunctions.h"

// isotropic sampling strategy from the virtual ray lights paper
Vec getIsotropicLightRaySample(RayPath rayPath, Vec v_h_pos, float v_h_distance, float h, float theta, float &A_0, float &A_1, float &t) {
    A_0 = asinh(-v_h_distance / h * sin(theta));
    A_1 = asinh((rayPath.ownDistance() - v_h_distance) / h * sin(theta));
    float xi = RND2;
    t = h * sinh((1 - xi)*A_0 + xi*A_1) / sin(theta);
    return  v_h_pos + rayPath.getDirection()*t;
}

// equi-angular distance sampling strategy from Kulla et al. (Importance sampling of area lights in participating media, 2011)
Vec getEquiAngularSample(RayPath line, Vec closest, float u_h_distance, float D, float &theta_o, float &theta_e, float &t) {
    theta_o = -atan(u_h_distance / D);
    theta_e = atan((line.ownDistance() - u_h_distance) / D);
    float xi = RND2;
    t = D*tan((1 - xi)*theta_o + xi*theta_e);
    return closest + line.getDirection()*t;
}

// calclualte the radiance from the medium
Vec radianceFromMedium(const Scene& scene, std::vector<RayPath*> paths, RayPath cameraPath) {
    Vec combined_contrib;
    for (auto iter = paths.begin(); iter != paths.end(); ++iter) {
        RayPath* rayPath = *iter;

        /*
        * ISOTROPIC SAMPLING
        */
        // find the points with the shortest distance between the two ray segments
        float h_1, dist_light_h, dist_cam_h;
        Vec v_h_pos, u_h_pos;
        shortestPointsOnLineSegments(*rayPath, cameraPath, h_1, v_h_pos, dist_light_h, u_h_pos, dist_cam_h);
        float theta = acos((rayPath->getDirection()).dot(cameraPath.getDirection()));

        // get the sample for the light ray
        float A_0, A_1, dist_closest_v;
        Vec v = getIsotropicLightRaySample(*rayPath, v_h_pos, dist_light_h, h_1, theta, A_0, A_1, dist_closest_v);
        float dist_light_v = dist_closest_v + dist_light_h;

        // find the closest point on the camera ray to the light ray sample
        float h_2, dist_o_closest;
        Vec closest;
        closestPointOnLine(v, cameraPath, closest, dist_o_closest);
        h_2 = v.dist(closest);

        // get the sample for the camera ray
        float B_0, B_1, dist_closest_u;
        Vec u = getEquiAngularSample(cameraPath, closest, dist_o_closest, h_2, B_0, B_1, dist_closest_u);
        float dist_camera_u = dist_closest_u + dist_o_closest;
        /*
        * ISOTROPIC SAMPLING
        */

        // calculate distance and direction between samples
        Vec dir = (u - v).norm();
        float dist_w = u.dist(v);

        // calculating visibility
        Intersection intersection = scene.intersect(Ray(v, dir));
        if (intersection) {
            if (intersection.t < dist_w - eps) {
                continue;
            }
        }
        // phase functions with the angle as input (Henyey-Greenstein phase function)
        /*float cos_theta_u = cameraPath.getDirection().norm().dot(dir.norm());
        float cos_theta_v = rayPath->getDirection().norm().dot(dir.norm());
        float g = scene.medium->g;
        float g_squ = g*g;
        Vec fs_u = (1 / (4 * PI)) * ((1 - g_squ) / pow(1 + g_squ - 2 * g * cos_theta_u, 1.5));
        Vec fs_v = (1 / (4 * PI)) * ((1 - g_squ) / pow(1 + g_squ - 2 * g * cos_theta_v, 1.5));*/
        float fs_iso = 1 / (4 * PI);
        // transmittance functions
        Vec tr_u = (scene.medium->sigma_t * dist_camera_u*-1).exp();
        //float traveledDist = rayPath->prevDistance() + dist_light_v;
        Vec tr_v = (scene.medium->sigma_t * dist_light_v*-1).exp();
        Vec tr_w = (scene.medium->sigma_t * dist_w*-1).exp();

        // putting the integrand of the formula together
        Vec integrand = rayPath->getPhotonPower() * (scene.medium->sigma_s*scene.medium->sigma_s*tr_u*tr_v*tr_w*fs_iso*fs_iso / (dist_w*dist_w));

        /*
        * ISOTROPIC SAMPLING
        */
        // constructing the pdf for the camera ray sample and the light ray sample and multiplying them
        float pdf_camera = h_2 / ((B_1 - B_0)*(h_2*h_2 + dist_closest_u*dist_closest_u));
        float pdf_vrl_numerator = PI / sqrt(h_1*h_1 + dist_closest_v*dist_closest_v * sin(theta)*sin(theta));
        float pdf_vrl_denominator = PI*((A_1 - A_0) / (sin(theta)));
        float pdf_light = pdf_vrl_numerator / pdf_vrl_denominator;
        float pdf = pdf_camera * pdf_light;
        /*
        * ISOTROPIC SAMPLING
        */

        combined_contrib = combined_contrib + (integrand / pdf);
    }
    return combined_contrib;
}

// calculate the surface radiance
Vec surfaceRadiance(const Scene& scene, std::vector<RayPath*> paths, RayPath cameraPath, Vec clr, Vec N) {
    Vec combined_contrib;

    for (auto iter = paths.begin(); iter != paths.end(); ++iter) {
        RayPath* rayPath = *iter;

        /*
        * ISOTROPIC SAMPLING
        */
        // find the closest point on the light ray to the camera ray.e
        float h, dist_o_closest;
        Vec closest;
        closestPointOnLine(cameraPath.getEnd(), *rayPath, closest, dist_o_closest);
        h = cameraPath.getEnd().dist(closest);

        // get the sample for the light ray
        float B_0, B_1, dist_closest_v;
        Vec v = getEquiAngularSample(*rayPath, closest, dist_o_closest, h, B_0, B_1, dist_closest_v);
        float dist_light_v = dist_closest_v + dist_o_closest;
        /*
        * ISOTROPIC SAMPLING
        */

        // calculate distance and direction between samples
        float dist = v.dist(cameraPath.getEnd());
        Vec dir = (cameraPath.getEnd() - v).norm();

        // calculating visibility
        Intersection intersection = scene.intersect(Ray(v, dir));
        if (intersection) {
            if (intersection.t < dist - eps) {
                continue;
            }
        }
        // phase functions with the angle as input (Henyey-Greenstein phase function)
        float fs = 1 / (4 * PI);
        // cosine-weight the BRDF
        clr = clr * abs(N.dot(dir*-1));
        // transmittance functions
        Vec tr_w = (scene.medium->sigma_t * dist*-1).exp();
        Vec tr_v = (scene.medium->sigma_t * dist_light_v*-1).exp();

        // putting the integrand of the formula together
        Vec vrl = rayPath->getPhotonPower() * ((clr*scene.medium->sigma_s*fs*tr_w*tr_v) / (dist*dist));

        /*
        * ISOTROPIC SAMPLING
        */
        // constructing the pdf for the sample
        float pdf = h / ((B_1 - B_0)*(h*h + dist_closest_v*dist_closest_v));
        /*
        * ISOTROPIC SAMPLING
        */

        combined_contrib = combined_contrib + vrl / pdf;
    }
    return combined_contrib;
}

void trace(Ray &ray, const Scene& scene, std::vector<RayPath*>& paths, RayPath* rayPath, bool vrlPass, int depth, Vec prev_tr_s, double prev_rrFactor, Vec& clr) {
    // Russian roulette: starting at depth 5, each recursive step will stop with a probability of 0.1
    double rrFactor = 1.0;
    if (depth >= 3) {
        const double rrStopProbability = 0.1;
        if (RND2 <= rrStopProbability) {
            if (vrlPass) {
                Intersection intersection = scene.intersect(ray);
                if (!intersection) {
                    rayPath->addToPaths(paths, rayPath->getOrigin() + rayPath->getDirection() * inf, inf);
                    return;
                }
                rayPath->addToPaths(paths, rayPath->getOrigin() + rayPath->getDirection() * intersection.t, intersection.t);
                return;
            }
            return;
        }
        rrFactor = 1.0 / (1.0 - rrStopProbability);
        rrFactor = rrFactor * prev_rrFactor;
    }

    Intersection intersection = scene.intersect(ray);
    if (!intersection) {
        if (vrlPass) {
            rayPath->addToPaths(paths, rayPath->getOrigin() + rayPath->getDirection() * inf, inf);
        } else {
            clr = clr + radianceFromMedium(scene, paths, RayPath(ray.o, ray.d, ray.o + ray.d * inf, Vec(), inf, 0)) * rrFactor;
        }
        return;
    }

    float distance = RND2 * inf;
    float pdf = 1.0/inf;

    if (distance > eps && distance < intersection.t) {
        Vec hp = ray.o + ray.d * distance;
        ray.o = hp;
        ray.d = Vec(RND).norm();

        Vec tr_s;
        if (vrlPass) {
            rayPath->addToPaths(paths, hp, distance);
            // multiply by transmittance and russian roulette factor
            tr_s = (scene.medium->sigma_t * rayPath->combinedDistance()*-1).exp();
            Vec power = rayPath->getPhotonPower() * tr_s * rrFactor / Vec(pdf);
            // create new light ray
            rayPath = new RayPath(ray.o, ray.d, Vec(), power, 0, rayPath->combinedDistance());
        } else {
            // calculating transmittance
            tr_s = (scene.medium->sigma_t * intersection.t*-1).exp() / Vec(pdf);
        }
        trace(ray, scene, paths, rayPath, vrlPass, depth + 1, tr_s * prev_tr_s, rrFactor, clr);
    } else {

        // Travel the ray to the hit point where the closest object lies and compute the surface normal there.
        Vec hp = ray.o + ray.d * intersection.t;
        Vec N = intersection.object->normal(hp);
        Vec surfaceClr = intersection.object->cl;
        int type = intersection.object->type;

        // calculate VRL contribution
        if (!vrlPass) {
            clr = clr + radianceFromMedium(scene, paths, RayPath(ray.o, ray.d, hp, Vec(), intersection.t, 0))  * rrFactor;
        }

        // Add the emission, the L_e(x,w) part of the rendering equation, but scale it with the Russian Roulette
        // probability weight.
        // const double emission = intersection.object->emission;
        // clr = clr + Vec(emission, emission, emission) * rrFactor;

        // Diffuse BRDF
        if (type == 1) {
            if (vrlPass) {
                // create new ray direction
                ray.o = hp;
                Vec rotX, rotY;
                ons(N, rotX, rotY);
                Vec sampledDir = hemisphere(RND2, RND2);
                Vec rotatedDir;
                rotatedDir.x = Vec(rotX.x, rotY.x, N.x).dot(sampledDir);
                rotatedDir.y = Vec(rotX.y, rotY.y, N.y).dot(sampledDir);
                rotatedDir.z = Vec(rotX.z, rotY.z, N.z).dot(sampledDir);
                ray.d = rotatedDir;	// already normalized

                rayPath->addToPaths(paths, hp, intersection.t);
                // calculate the diffuse reflection probability
                float diff_reflect_prob = max(surfaceClr.x, max(surfaceClr.y, surfaceClr.z));
                // calculate the new photon power
                Vec power;
                power.x = rayPath->getPhotonPower().x * (surfaceClr.x / diff_reflect_prob);
                power.y = rayPath->getPhotonPower().y * (surfaceClr.y / diff_reflect_prob);
                power.z = rayPath->getPhotonPower().z * (surfaceClr.z / diff_reflect_prob);
                // multiply by transmittance and russian roulette factor
                Vec tr_s = (scene.medium->sigma_t * rayPath->combinedDistance()*-1).exp();
                power = power * tr_s * rrFactor;
                // trace new light ray
                rayPath = new RayPath(ray.o, ray.d, Vec(), power, 0, rayPath->combinedDistance());
                trace(ray, scene, paths, rayPath, vrlPass, depth + 1, Vec(), rrFactor, clr);

            } else {
                // calculate surface radiance and multiply by transmittance and russion roulette factor
                RayPath r = RayPath(ray.o, ray.d, hp, Vec(), intersection.t, 0);
                Vec tr_s = (scene.medium->sigma_t * r.combinedDistance()*-1).exp();
                clr = clr + surfaceRadiance(scene, paths, r, surfaceClr, N) * tr_s * prev_tr_s * rrFactor;
            }
        }


        // Specular BRDF - this is a singularity in the rendering equation that follows
        // delta distribution, therefore we handle this case explicitly - one incoming
        // direction -> one outgoing direction, that is, the perfect reflection direction.
        if (type == 2) {
            ray.o = hp;
            ray.d = (ray.d - N*(ray.d.dot(N) * 2)).norm();
            Vec tr_s;
            if (vrlPass) {
                rayPath->addToPaths(paths, hp, intersection.t);
                // multiply by transmittance and russian roulette factor
                tr_s = (scene.medium->sigma_t * rayPath->combinedDistance()*-1).exp();
                Vec power = rayPath->getPhotonPower() * tr_s * rrFactor;
                // create new light ray
                rayPath = new RayPath(ray.o, ray.d, Vec(), power, 0, rayPath->combinedDistance());
            } else {
                // calculating transmittance
                tr_s = (scene.medium->sigma_t * intersection.t*-1).exp();
            }
           trace(ray, scene, paths, rayPath, vrlPass, depth + 1, tr_s * prev_tr_s, rrFactor, clr);
        }


        // Glass/refractive BRDF - we use the vector version of Snell's law and Fresnel's law
        // to compute the outgoing reflection and refraction directions and probability weights.
        if (type == 3) {
            ray.o = hp;
            double n = scene.refr_index;
            double R0 = (1.0 - n) / (1.0 + n);
            R0 = R0*R0;
            if (N.dot(ray.d) > 0) { // we're inside the medium
                N = N*-1;
                n = 1 / n;
            }
            n = 1 / n;
            double cost1 = (N.dot(ray.d))*-1; // cosine of theta_1
            double cost2 = 1.0 - n*n*(1.0 - cost1*cost1); // cosine of theta_2
            double Rprob = R0 + (1.0 - R0) * pow(1.0 - cost1, 5.0); // Schlick-approximation
            if (cost2 > 0 && RND2 > Rprob) { // refraction direction
                ray.d = ((ray.d*n) + (N*(n*cost1 - sqrt(cost2)))).norm();
            } else { // reflection direction
                ray.d = (ray.d + N*(cost1 * 2)).norm();
            }
            Vec tr_s;
            if (vrlPass) {
                rayPath->addToPaths(paths, hp, intersection.t);
                // multiply by transmittance and russian roulette factor
                tr_s = (scene.medium->sigma_t * rayPath->combinedDistance()*-1).exp();
                Vec power = rayPath->getPhotonPower() * tr_s * rrFactor;
                // create new light ray
                rayPath = new RayPath(ray.o, ray.d, Vec(), power, 0, rayPath->combinedDistance());
            } else {
                // calculating transmittance
                tr_s = (scene.medium->sigma_t * intersection.t*-1).exp();
            }
            trace(ray, scene, paths, rayPath, vrlPass, depth + 1, tr_s * prev_tr_s, rrFactor, clr);
        }
    }
}

void clear(Scene& scene, Vec **pix) {
    scene.clear();
    for (int i = 0; i < width; i++) {
        delete[] pix[i];
    }
    delete[] pix;
}

void render(int id, int size, int samples, double refr_index, double sigma_a, double sigma_s, double g) {
    Scene scene;
    auto add = [&scene](Obj* s, Vec cl, double emission, int type) {
        s->setMat(cl, emission, type);
        scene.add(s);
    };

    /*// Radius, position, color, emission, type (1=diff, 2=spec, 3=refr) for spheres
    add(new Sphere(1.05, Vec(-0.75, -1.45, -4.4)), Vec(.5, .5, .5), 0, 2); // Middle sphere
    add(new Sphere(0.5, Vec(2.0, -2.05, -3.7)), Vec(.5, .5, .5), 0, 3); // Right sphere
    add(new Sphere(0.6, Vec(-1.75, -1.95, -3.1)), Vec(0, 0, 1), 0, 1); // Left sphere
    // Position, normal, color, emission, type for planes
    add(new Plane(2.5, Vec(0, 1, 0)), Vec(.5, .5, .5), 0, 1); // Bottom plane
    //add(new Plane(5.5, Vec(0, 0, 1)), Vec(.5, .5, .5), 0, 1); // Back plane
    add(new Plane(2.75, Vec(1, 0, 0)), Vec(1, 0, 0), 0, 1); // Left plane
    add(new Plane(2.75, Vec(-1, 0, 0)), Vec(0, 1, 0), 0, 1); // Right plane
    add(new Plane(3.0, Vec(0, -1, 0)), Vec(.5, .5, .5), 0, 1); // Ceiling plane
    add(new Plane(0.5, Vec(0, 0, -1)), Vec(.5, .5, .5), 0, 1); // Front plane*/

    //Pointlight* pointlight = new Pointlight(Vec(0, 1.9, -3), Vec(100000));
    Pointlight* pointlight = new Pointlight(Vec(0, 0, -3), Vec(100));
    scene.add(pointlight);

    Medium* medium = new Medium(Vec(0.25), Vec(0.1), .5, Vec(-15), Vec(15));
    scene.add(medium);

    scene.refr_index = refr_index;
    const int vrlSamples = samples;
	width = size;
	height = size;

	Vec **pix = new Vec*[width];
	for (int i = 0; i < width; i++) {
		pix[i] = new Vec[height];
	}

	bool running = true;
    int vrls = 0;
    int count = 0;

    while (vrls < vrlSamples) {
        // trace the path from a photon through the scene
        std::vector<RayPath*> paths;
        //RayPath* rayPath = new RayPath(scene.pointlight->pos, scene.pointlight->getConeDir(), Vec(), scene.pointlight->intensity, 0, 0);
        RayPath* rayPath = new RayPath(scene.pointlight->pos, scene.pointlight->getRandomDir(), Vec(), scene.pointlight->intensity, 0, 0);
        Vec temp;
        Ray lRay = Ray(rayPath->getOrigin(), rayPath->getDirection());
        trace(lRay, scene, paths, rayPath, true, 0, 1.0, 1.0, temp);

        // remove paths if there were too many calculated
        vrls = vrls + paths.size();
        if (vrls > vrlSamples) {
            int diff = vrls - vrlSamples;
            paths.resize(diff);
            vrls = vrls - diff;
        }
//#pragma omp parallel for schedule(dynamic)
        for (int col = 0; col < width; col++) {
            for (int row = 0; row < height; row++) {
                if(running){
                    if(col ==200 && row == 200){
                        Vec temp = Vec();
                    }
                    Vec color;
                    Ray ray;
                    ray.o = (Vec(0, 0, 0)); // rays start out from here
                    Vec cam = camcr(col, row); // construct image plane coordinates
                    cam.x = cam.x + RND / 700; // anti-aliasing for free
                    cam.y = cam.y + RND / 700;
                    ray.d = (cam - ray.o).norm(); // point from the origin to the camera plane
                    trace(ray, scene, paths, NULL, false, 0, 1.0, 1.0, color);
                    pix[col][row] = pix[col][row] + color; // write the contributions
                    if (!smallpaint::isRunning(id)) running = false;
                }
            }
        }

        for (int i = 0; i < paths.size(); i++) {
            delete paths.at(i);
        }

        if (!running) {
            clear(scene, pix);
            return;
        }
        imageOutput(pix, count, vrls);
        count++;
    }
}
}
