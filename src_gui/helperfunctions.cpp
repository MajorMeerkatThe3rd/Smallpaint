#include "helperfunctions.h"
#include "mainwindow.h"

MainWindow* mainWindow;

/**
 * Saves MainWindow instance.
 */
void setInstanceForHelperFunctions(MainWindow* w) {
	mainWindow = w;
}

/**
 * Creates the defaults.
 */
void HelperFunctions::setDefaults() {
    fixedDefaults = defaults(50, 1, 400, 250, 2500, 1.5, 1., 5.);
	painterlyDefaults = defaults(50, 1, 400, 250, 2500, 1.5, 1., 5.);
	bvhDefaults = defaults(50, 1, 400, 250, 2500, 1.5, 1., 5.);
	pssmltDefaults = defaults(10, 1, 400, 250, 2500, 1.5, 1., 5.);
	smallmediaDefaults = defaults(20, 1, 400, 250, 2500, 1.5, 1., 5.);
	ppmDefaults = defaults(1000, 1, 400, 250, 1500, 1.5, 1., 5.);
    vrlDefaults = defaults(1000, 1, 400, 250, 2500, 1.5, 1., 5.);
}

/**
 * Saves image to specified path.
 */
void HelperFunctions::saveImage() {
    if (mainWindow->lastImage == "") return;
    mainWindow->ui->renderedImage->clear();
    QString filename = QFileDialog::getSaveFileName(mainWindow, QObject::tr("Save Image"), QString::fromUtf8(mainWindow->lastImage.c_str()), QObject::tr("Image Files (*.ppm)"));
    if (filename == "") {
        mainWindow->ui->renderInfo->setText("Image not saved");
    } else {
		mainWindow->ui->renderInfo->setText("Image saved to: " + filename);
		mainWindow->image.save(filename, "PPM", -1);
    }
    mainWindow->resizeImage();
}

/**
 * Returns the renderer short name.
 */
QString HelperFunctions::getRenderer(QString renderer) {
	if (renderer == "Path Tracing (Fixed)") {
		return "fixed";
	}
	if (renderer == "Path Tracing (Painterly)") {
		return "painterly";
	}
	if (renderer == "Bounding Volume Hierarchy") {
		return "bvh";
	}
	if (renderer == "Primary Sample Space MLT") {
		return "pssmlt";
	}
	if (renderer == "Volumetric Path Tracing") {
		return "smallmedia";
	}
	if (renderer == "Progressive Photon Mapping") {
		return "ppm";
	}
    if (renderer == "Virtual Ray Lights") {
        return "vrl";
    }
	if (renderer == "Tests") {
		return "tests";
	}
	return "";
}

/**
 * Changes Menu items.
 */
void HelperFunctions::changedComboBox(QString renderer) {
	if (renderer == "fixed") {
		mainWindow->ui->renderModesSettings->setCurrentWidget(mainWindow->ui->fixed);
		if (mainWindow->ui->fixedSize->text() == "") mainWindow->ui->fixedSize->setText(QString::number(fixedDefaults.size));
		if (mainWindow->ui->fixedSamples->text() == "") mainWindow->ui->fixedSamples->setText(QString::number(fixedDefaults.spp));
		if (mainWindow->ui->fixedRefraction->text() == "") mainWindow->ui->fixedRefraction->setText(QString::number(fixedDefaults.refr));
	}
	if (renderer == "painterly") {
		mainWindow->ui->renderModesSettings->setCurrentWidget(mainWindow->ui->painterly);
		if (mainWindow->ui->painterlySize->text() == "") mainWindow->ui->painterlySize->setText(QString::number(painterlyDefaults.size));
		if (mainWindow->ui->painterlySamples->text() == "") mainWindow->ui->painterlySamples->setText(QString::number(painterlyDefaults.spp));
		if (mainWindow->ui->painterlyRefraction->text() == "") mainWindow->ui->painterlyRefraction->setText(QString::number(painterlyDefaults.refr));
	}
	if (renderer == "bvh") {
		mainWindow->ui->renderModesSettings->setCurrentWidget(mainWindow->ui->bvh);
		if (mainWindow->ui->bvhSize->text() == "") mainWindow->ui->bvhSize->setText(QString::number(bvhDefaults.size));
		if (mainWindow->ui->bvhSamples->text() == "") mainWindow->ui->bvhSamples->setText(QString::number(bvhDefaults.spp));
		if (mainWindow->ui->bvhRefraction->text() == "") mainWindow->ui->bvhRefraction->setText(QString::number(bvhDefaults.refr));
	}
	if (renderer == "pssmlt") {
		mainWindow->ui->renderModesSettings->setCurrentWidget(mainWindow->ui->pssmlt);
		if (mainWindow->ui->pssmltSize->text() == "") mainWindow->ui->pssmltSize->setText(QString::number(pssmltDefaults.size));
		if (mainWindow->ui->pssmltSamples->text() == "") mainWindow->ui->pssmltSamples->setText(QString::number(pssmltDefaults.spp));
		if (mainWindow->ui->pssmltRefraction->text() == "") mainWindow->ui->pssmltRefraction->setText(QString::number(pssmltDefaults.refr));
	}
	if (renderer == "smallmedia") {
		mainWindow->ui->renderModesSettings->setCurrentWidget(mainWindow->ui->smallmedia);
		if (mainWindow->ui->smallmediaSize->text() == "") mainWindow->ui->smallmediaSize->setText(QString::number(smallmediaDefaults.size));
		if (mainWindow->ui->smallmediaSamples->text() == "") mainWindow->ui->smallmediaSamples->setText(QString::number(smallmediaDefaults.spp));
		if (mainWindow->ui->smallmediaRefraction->text() == "") mainWindow->ui->smallmediaRefraction->setText(QString::number(smallmediaDefaults.refr));
	}
	if (renderer == "ppm") {
		mainWindow->ui->renderModesSettings->setCurrentWidget(mainWindow->ui->ppm);
		if (mainWindow->ui->ppmSize->text() == "") mainWindow->ui->ppmSize->setText(QString::number(ppmDefaults.size));
		if (mainWindow->ui->ppmSamples->text() == "") mainWindow->ui->ppmSamples->setText(QString::number(ppmDefaults.spp));
		if (mainWindow->ui->ppmRefraction->text() == "") mainWindow->ui->ppmRefraction->setText(QString::number(ppmDefaults.refr));
	}
    if (renderer == "vrl") {
        mainWindow->ui->renderModesSettings->setCurrentWidget(mainWindow->ui->vrl);
        if (mainWindow->ui->vrlSize->text() == "") mainWindow->ui->vrlSize->setText(QString::number(vrlDefaults.size));
        if (mainWindow->ui->vrlSamples->text() == "") mainWindow->ui->vrlSamples->setText(QString::number(vrlDefaults.spp));
        if (mainWindow->ui->vrlRefraction->text() == "") mainWindow->ui->vrlRefraction->setText(QString::number(vrlDefaults.refr));
    }
	if (renderer == "tests") {
		mainWindow->ui->renderModesSettings->setCurrentWidget(mainWindow->ui->tests);
	}
}

/**
 * QString to int with input control.
 */
int HelperFunctions::getTextAsInt(QString text) {
	int out;
	if (text == "") {
		return -1;
	} else {
		out = text.toInt();
		if (out == 0) {
			return -1;
		}
	}
	return out;
}

/**
 * QString to float with input control.
 */
float HelperFunctions::getTextAsFloat(QString text) {
	float out;
	if (text == "") {
		return -1;
	} else {
		out = text.replace(",", ".").toFloat();
		if (out == 0.0) {
			return -1;
		}
	}
	return out;
}

/**
 * Reads the input from the corresponding elements, assigns default values.
 */
void HelperFunctions::getInput(QString selectedRenderer, int &spp, int &size, float &refr) {
	if (selectedRenderer == "fixed") {

		spp = getTextAsInt(mainWindow->ui->fixedSamples->text());
		if (spp == -1) spp = fixedDefaults.spp;
		if (spp < fixedDefaults.minSpp) spp = fixedDefaults.minSpp;

		size = getTextAsInt(mainWindow->ui->fixedSize->text());
		if (size == -1) size = fixedDefaults.size;
		if (size < fixedDefaults.minSize) size = fixedDefaults.minSize;
		if (size > fixedDefaults.maxSize) size = fixedDefaults.maxSize;

		refr = getTextAsFloat(mainWindow->ui->fixedRefraction->text());
		if (refr == -1) refr = fixedDefaults.refr;
		if (refr < fixedDefaults.minRefr) refr = fixedDefaults.minRefr;
		if (refr > fixedDefaults.maxRefr) refr = fixedDefaults.maxRefr;

	}

	if (selectedRenderer == "painterly") {

		spp = getTextAsInt(mainWindow->ui->painterlySamples->text());
		if (spp == -1) spp = painterlyDefaults.spp;
		if (spp < painterlyDefaults.minSpp) spp = painterlyDefaults.minSpp;

		size = getTextAsInt(mainWindow->ui->painterlySize->text());
		if (size == -1) size = painterlyDefaults.size;
		if (size < painterlyDefaults.minSize) size = painterlyDefaults.minSize;
		if (size > painterlyDefaults.maxSize) size = painterlyDefaults.maxSize;

		refr = getTextAsFloat(mainWindow->ui->painterlyRefraction->text());
		if (refr == -1) refr = painterlyDefaults.refr;
		if (refr < painterlyDefaults.minRefr) refr = painterlyDefaults.minRefr;
		if (refr > painterlyDefaults.maxRefr) refr = painterlyDefaults.maxRefr;

	}

	if (selectedRenderer == "bvh") {

		spp = getTextAsInt(mainWindow->ui->bvhSamples->text());
		if (spp == -1) spp = bvhDefaults.spp;
		if (spp < bvhDefaults.minSpp) spp = bvhDefaults.minSpp;

		size = getTextAsInt(mainWindow->ui->bvhSize->text());
		if (size == -1) size = bvhDefaults.size;
		if (size < bvhDefaults.minSize) size = bvhDefaults.minSize;
		if (size > bvhDefaults.maxSize) size = bvhDefaults.maxSize;

		refr = getTextAsFloat(mainWindow->ui->bvhRefraction->text());
		if (refr == -1) refr = bvhDefaults.refr;
		if (refr < bvhDefaults.minRefr) refr = bvhDefaults.minRefr;
		if (refr > bvhDefaults.maxRefr) refr = bvhDefaults.maxRefr;

	}

	if (selectedRenderer == "pssmlt") {

		spp = getTextAsInt(mainWindow->ui->pssmltSamples->text());
		if (spp == -1) spp = pssmltDefaults.spp;
		if (spp < pssmltDefaults.minSpp) spp = pssmltDefaults.minSpp;

		size = getTextAsInt(mainWindow->ui->pssmltSize->text());
		if (size == -1) size = pssmltDefaults.size;
		if (size < pssmltDefaults.minSize) size = pssmltDefaults.minSize;
		if (size > pssmltDefaults.maxSize) size = pssmltDefaults.maxSize;

		refr = getTextAsFloat(mainWindow->ui->pssmltRefraction->text());
		if (refr == -1) refr = pssmltDefaults.refr;
		if (refr < pssmltDefaults.minRefr) refr = pssmltDefaults.minRefr;
		if (refr > pssmltDefaults.maxRefr) refr = pssmltDefaults.maxRefr;

	}

	if (selectedRenderer == "smallmedia") {

		spp = getTextAsInt(mainWindow->ui->smallmediaSamples->text());
		if (spp == -1) spp = smallmediaDefaults.spp;
		if (spp < smallmediaDefaults.minSpp) spp = smallmediaDefaults.minSpp;

		size = getTextAsInt(mainWindow->ui->smallmediaSize->text());
		if (size == -1) size = smallmediaDefaults.size;
		if (size < smallmediaDefaults.minSize) size = smallmediaDefaults.minSize;
		if (size > smallmediaDefaults.maxSize) size = smallmediaDefaults.maxSize;

		refr = getTextAsFloat(mainWindow->ui->smallmediaRefraction->text());
		if (refr == -1) refr = smallmediaDefaults.refr;
		if (refr < smallmediaDefaults.minRefr) refr = smallmediaDefaults.minRefr;
		if (refr > smallmediaDefaults.maxRefr) refr = smallmediaDefaults.maxRefr;

	}

	if (selectedRenderer == "ppm") {

		spp = getTextAsInt(mainWindow->ui->ppmSamples->text());
		if (spp == -1) spp = ppmDefaults.spp;
		if (spp < ppmDefaults.minSpp) spp = ppmDefaults.minSpp;
		spp *= 1000;

		size = getTextAsInt(mainWindow->ui->ppmSize->text());
		if (size == -1) size = ppmDefaults.size;
		if (size < ppmDefaults.minSize) size = ppmDefaults.minSize;
		if (size > ppmDefaults.maxSize) size = ppmDefaults.maxSize;

		refr = getTextAsFloat(mainWindow->ui->ppmRefraction->text());
		if (refr == -1) refr = ppmDefaults.refr;
		if (refr < ppmDefaults.minRefr) refr = ppmDefaults.minRefr;
		if (refr > ppmDefaults.maxRefr) refr = ppmDefaults.maxRefr;

	}

    if (selectedRenderer == "vrl") {

        spp = getTextAsInt(mainWindow->ui->vrlSamples->text());
        if (spp == -1) spp = vrlDefaults.spp;
        if (spp < vrlDefaults.minSpp) spp = vrlDefaults.minSpp;

        size = getTextAsInt(mainWindow->ui->vrlSize->text());
        if (size == -1) size = vrlDefaults.size;
        if (size < vrlDefaults.minSize) size = vrlDefaults.minSize;
        if (size > vrlDefaults.maxSize) size = vrlDefaults.maxSize;

        refr = getTextAsFloat(mainWindow->ui->vrlRefraction->text());
        if (refr == -1) refr = vrlDefaults.refr;
        if (refr < vrlDefaults.minRefr) refr = vrlDefaults.minRefr;
        if (refr > vrlDefaults.maxRefr) refr = vrlDefaults.maxRefr;

    }
}

/**
 * Intitializes the render information and sets some start up values.
 */
void HelperFunctions::initializeRenderInformation(QString selectedRenderer, int spp, int size, float refr) {
	QString sppString;
	mainWindow->ui->renderButton->setText("Cancel");
	mainWindow->width = size;
	mainWindow->height = size;
	mainWindow->ui->renderedImage->clear();
	mainWindow->lastImage = "";
    mainWindow->ui->progressBar->setMinimum(0);
    mainWindow->ui->progressBar->setMaximum(spp);
    sppString = QString::number(spp);
	mainWindow->ui->timeInfo->setText("Processing...");
	if (selectedRenderer != "ppm") {
		mainWindow->ui->renderInfo->setText("Rendering with smallpaint_" + selectedRenderer + ": " + QString::number(size) + "x"
											+ QString::number(size) + " pixel, " + sppString + " samples, " + QString::number(refr) + " refraction index");
	} else {
		mainWindow->ui->renderInfo->setText("Rendering with smallpaint_" + selectedRenderer + ": " + QString::number(size) + "x"
											+ QString::number(size) + " pixel, " + sppString + " photons, " + QString::number(refr) + " refraction index");
	}
}

/**
 * Adds leading zeros and processes time to DD:HH:MM:SS format.
 */
QString HelperFunctions::processTime(int secondsToProcess) {
	struct Padding {
		static QString process(int time) {
			if (time == 0) return "00";
			QString timeString = QString::number(time);
			if (time < 10) return "0" + timeString;
			return timeString;
		}
	};
	int days, hours, minutes, seconds;
	days = secondsToProcess / 60 / 60 / 24;
	hours = (secondsToProcess / 60 / 60) % 24;
	minutes = (secondsToProcess / 60) % 60;
	seconds = secondsToProcess % 60;
	return Padding::process(days) + ":" + Padding::process(hours) + ":" + Padding::process(minutes) + ":" + Padding::process(seconds);
}

/**
 * Updates the render information after every new image.
 */
void HelperFunctions::updateInfo(int currentSpp, int goalSpp) {
    mainWindow->ui->progressBar->setValue(currentSpp);

    QString out = "Samples:\t" + QString::number(currentSpp) + " / " + QString::number(goalSpp) + "\n";
    int secondsElapsed = (clock() - mainWindow->start) / CLOCKS_PER_SEC;
    int secondsExpected = (goalSpp)*(secondsElapsed / (float)currentSpp);
    int secondsRemaining = secondsExpected - secondsElapsed;

    out += "Time elapsed:\t" + processTime(secondsElapsed) + "\n";
    out += "Time remaining:\t" + processTime(secondsRemaining) + "\n";
    out += "Expected Time:\t" + processTime(secondsExpected);
    mainWindow->ui->timeInfo->setText(out);
}
