void setRendering(bool rendering);
bool isRendering();
void cancelRendering();

namespace smallpaint_fixed {
struct Vec;
void imageOutput(Vec **pix, int spp);
void processImage(Vec **pix, int spp);
}
namespace smallpaint_painterly {
struct Vec;
void imageOutput(Vec **pix, int spp);
void processImage(Vec **pix, int spp);
}
namespace smallpaint_bvh {
struct Vec;
void imageOutput(Vec **pix, int spp);
void processImage(Vec **pix, int spp);
}
namespace smallpaint_pssmlt {
struct Vec;
void imageOutput(Vec **pix, int spp);
void processImage(Vec **pix, int spp);
}
namespace smallpaint_smallmedia {
struct Vec;
void imageOutput(Vec **pix, int spp);
void processImage(Vec **pix, int spp);
}
namespace smallpaint_ppm {
struct Vec;
void imageOutput(Vec **pix, int spp);
void processImage(Vec **pix, int spp);
}
namespace smallpaint_vrl {
struct Vec;
void imageOutput(Vec **pix, int spp, int vrls);
void processImage(Vec **pix, int spp, int vrls);
}
namespace smallpaint {
bool isRunning(int id);
void sendToRender(int size, int spp, float refr, std::string renderer);
}
