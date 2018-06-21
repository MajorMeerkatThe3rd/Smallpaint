#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <QString>
#include <QImage>

class HelperFunctions {

public:
	void saveImage();
	QString getRenderer(QString renderer);
	void changedComboBox(QString renderer);
	int getTextAsInt(QString text);
	float getTextAsFloat(QString text);
	void getInput(QString selectedRenderer, int &spp, int &size, float &refr);
	void initializeRenderInformation(QString selectedRenderer, int spp, int size, float refr);
	QString processTime(int time);
	void updateInfo(int currentSpp, int goalSpp);
	void setDefaults();

private:
	struct defaults {
		int spp, minSpp, size, minSize, maxSize;
		float refr, minRefr, maxRefr;
		defaults() {};
		defaults(int spp, int minSpp, int size, int minSize, int maxSize, float refr, float minRefr, float maxRefr) : 
		spp(spp), minSpp(minSpp), size(size), minSize(minSize), maxSize(maxSize), refr(refr), minRefr(minRefr), maxRefr(maxRefr) {};
	};
    defaults fixedDefaults, painterlyDefaults, bvhDefaults, pssmltDefaults, smallmediaDefaults, ppmDefaults;
};

#endif // HELPERFUNCTIONS_H
