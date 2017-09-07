// find the shortest point on a line to a point p
void closestPointOnLine(Vec p, RayPath line, Vec& closest, float &distance) {
	Vec op = p - line.getOrigin();
	Vec lineDir = line.getEnd() - line.getOrigin();

	float l = lineDir.length();
	distance = op.dot(lineDir) / (l*l);

	if (distance < 0) {
		closest = line.getOrigin();
		distance = 0;
	} else if (distance > 1) {
		closest = line.getEnd();
		distance = l;
	} else {
		closest = line.getOrigin() + lineDir * distance;
		distance = l*distance;
	}
}

// shortest Distance between two line segments adapted from
// implementation from user Nick on Matlab (http://de.mathworks.com/matlabcentral/fileexchange/32487-shortest-distance-between-two-line-segments)
// adapts the algorithm found on dan sunday's website (http://softsurfer.com/Archive/algorithm_0106/algorithm_0106.htm#dist3D_Segment_to_Segment)
void shortestPointsOnLineSegments(RayPath line1, RayPath line2, float &h, Vec &closest1, float &distance1, Vec &closest2, float &distance2) {
	Vec lineDir1 = line1.getEnd() - line1.getOrigin();
	Vec lineDir2 = line2.getEnd() - line2.getOrigin();
	Vec w = line1.getOrigin() - line2.getOrigin();

	float a, b, c, d, e, D, sD, tD, sN, tN, sc, tc;
	a = lineDir1.dot(lineDir1); 
	b = lineDir1.dot(lineDir2); 
	c = lineDir2.dot(lineDir2);
	d = lineDir1.dot(w); 
	e = lineDir2.dot(w);
	D = a*c - b*b; 
	sD = D; 
	tD = D;

	if (D < eps) {
		sN = 0.0; 
		sD = 1.0; 
		tN = e; 
		tD = c;
	} else {
		sN = (b*e - c*d); 
		tN = (a*e - b*d);
		if (sN < 0.0) {
			sN = 0.0; 
			tN = e; 
			tD = c;
		} else if (sN > sD) {
			sN = sD; 
			tN = e + b; 
			tD = c;
		}
	}

	if (tN < 0.0) {
		tN = 0.0;
		if (-d < 0.0) {
			sN = 0.0;
		} else if (-d > a) {
			sN = sD;
		} else {
			sN = -d; 
			sD = a;
		}
	} else if (tN > tD) {
		tN = tD;
		if ((-d + b) < 0.0) {
			sN = 0;
		} else if ((-d + b) > a) {
			sN = sD;
		} else {
			sN = (-d + b); 
			sD = a;
		}
	}

	if (abs(sN) < eps) {
		sc = 0.0;
	} else {
		sc = sN / sD;
	}
	if (abs(tN) < eps) {
		tc = 0.0;
	} else {
		tc = tN / tD;
	}

	Vec lineClosest = w + (lineDir1*sc) - (lineDir2*tc);

	closest1 = line1.getOrigin() + lineDir1*sc;
	distance1 = sc * lineDir1.length();
	closest2 = line2.getOrigin() + lineDir2*tc;
	distance2 = tc * lineDir2.length();

	h = lineClosest.length();
}