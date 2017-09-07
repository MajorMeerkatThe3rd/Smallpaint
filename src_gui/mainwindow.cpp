#include "mainwindow.h"
#include "main.h"

/**
 * Constructor that connects signals & slots.
 */
MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow) {
	ui->setupUi(this);
	connect(this, SIGNAL(smallpaint_fixedSignal(smallpaint_fixed::Vec**, int)),
			this, SLOT(smallpaint_fixedSlot(smallpaint_fixed::Vec**, int)));
	connect(this, SIGNAL(smallpaint_painterlySignal(smallpaint_painterly::Vec**, int)),
			this, SLOT(smallpaint_painterlySlot(smallpaint_painterly::Vec**, int)));
	connect(this, SIGNAL(smallpaint_bvhSignal(smallpaint_bvh::Vec**, int)),
			this, SLOT(smallpaint_bvhSlot(smallpaint_bvh::Vec**, int)));
	connect(this, SIGNAL(smallpaint_pssmltSignal(smallpaint_pssmlt::Vec**, int)),
			this, SLOT(smallpaint_pssmltSlot(smallpaint_pssmlt::Vec**, int)));
	connect(this, SIGNAL(smallpaint_smallmediaSignal(smallpaint_smallmedia::Vec**, int)),
			this, SLOT(smallpaint_smallmediaSlot(smallpaint_smallmedia::Vec**, int)));
	connect(this, SIGNAL(smallpaint_ppmSignal(smallpaint_ppm::Vec**, int)),
			this, SLOT(smallpaint_ppmSlot(smallpaint_ppm::Vec**, int)));
    connect(this, SIGNAL(smallpaint_vrlSignal(smallpaint_vrl::Vec**, int, int)),
            this, SLOT(smallpaint_vrlSlot(smallpaint_vrl::Vec**, int, int)));
	helper.setDefaults();
}

/**
 * Destructor.
 */
MainWindow::~MainWindow() {
	delete ui;
}

/**
 * Displays QMessageBox, closes all windows and cancels rendering for shutdown.
 */
void MainWindow::closeEvent(QCloseEvent *event) {
	QMessageBox::StandardButton resBtn = QMessageBox::question(this, "", tr("Are you sure you want to quit?\nUnsaved renderings will be discarded."), QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes);
	if (resBtn != QMessageBox::Yes) {
		event->ignore();
	} else {
		if (isRendering()) cancelRendering();
		ui->renderInfo->setText("Exit");
		QApplication::closeAllWindows();
		event->accept();
	}
}

/**
 * Centers rendered image in middle of its area.
 */
void MainWindow::resizeEvent(QResizeEvent *event) {
    if (lastImage == "" && image.isNull()) return;
	float width = event->size().width() - ui->menu->minimumWidth() - 30;
	float height = event->size().height() - ui->bottom->minimumHeight() - 30;
	float value = std::min(width, height);
	if (image.size().width() != 0) ui->renderedImage->setPixmap(QPixmap::fromImage(image.scaled(value, value)));
	ui->renderedImage->hide();
	ui->renderedImage->show();
	ui->renderedImage->resize(value, value);
	ui->renderedImage->move((int)((event->size().width() + (10 + ui->menu->minimumWidth()) - value) / 2),
		(int)((event->size().height() - (10 + ui->bottom->minimumHeight()) - value) / 2));
}

/**
 * Opens QFileDialog if right click on image.
 */
void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
	if (isRendering()) return;
	if (event->button() == Qt::RightButton) {
		if (event->pos().x() >= ui->renderedImage->pos().x() &&
			event->pos().x() <= (ui->renderedImage->pos().x() + ui->renderedImage->size().width()) &&
			event->pos().y() >= ui->renderedImage->pos().y() &&
			event->pos().y() <= (ui->renderedImage->pos().y() + ui->renderedImage->size().height())) {
			helper.saveImage();
		}
	}
}

/**
 * Enter key toggles render button.
 */
void MainWindow::keyPressEvent(QKeyEvent *event) {
	if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
		on_renderButton_clicked();
	}
}

/**
 * Handles change of ComboBox.
 */
void MainWindow::on_renderModesComboBox_currentTextChanged(const QString &arg1) {
	helper.changedComboBox(helper.getRenderer(arg1));
	resizeImage();
}

/**
 * Saves new image and displayes it.
 */
void MainWindow::drawImage(QImage img, std::string name, int currentSpp, int goalSpp) {
    image = img.copy();
    if (name == "logo"){
        ui->renderedImage->setPixmap(QPixmap::fromImage(image));
        resizeImage();
    } else {
        if (!testing) {
            lastImage = name;
            helper.updateInfo(currentSpp, goalSpp);
            ui->renderedImage->setPixmap(QPixmap::fromImage(image));
            resizeImage();
        } else {
            helper.updateInfo(currentSpp, goalSpp);
            testWindow->setSecondImage(image);
            if (currentSpp == goalSpp) testWindow->setFinished(image);
        }
    }
}

/**
 * Starts or cancels rendering.
 */
void MainWindow::on_renderButton_clicked() {
	if (ui->renderButton->text() == "Render") {
		QString selectedRenderer = helper.getRenderer(ui->renderModesComboBox->currentText());
		if (selectedRenderer == "") return;
		if (selectedRenderer == "tests" || testing) {
			testRender(true);
			return;
		}
		int spp = 0;
		int size = 0;
		float refr = 0;

		helper.getInput(selectedRenderer, spp, size, refr);
		helper.initializeRenderInformation(selectedRenderer, spp, size, refr);

        drawImage(QImage("../test_images/logo_processing.png"), "logo", 0, spp);

		start = clock();
		smallpaint::sendToRender(size, spp, refr, "smallpaint_" + selectedRenderer.toStdString());
	} else {
		ui->renderButton->setText("Render");
		if (!isRendering()) {
			ui->renderInfo->setText("Render ended");
			if (testing) {
				on_renderButton_clicked();
				return;
			}
		} else {
			cancelRendering();
			setRendering(false);
			ui->renderInfo->setText("Render canceled");

			if (testing) {
				testing = false;
				testWindow->makeCloseable();
				tests.clear();
			}
		}
		ui->timeInfo->clear();
		ui->progressBar->setValue(0);
		helper.saveImage();
	}
}

/**
 * Resizes the image.
 */
void MainWindow::resizeImage() {
	QResizeEvent* resizeEvent = new QResizeEvent(this->window()->size(), this->window()->size());
	MainWindow::resizeEvent(resizeEvent);
	resizeEvent->~QResizeEvent();
}

/**
 * Handles test renderings.
 */
void MainWindow::testRender(bool renderButtonActivated) {
	if (renderButtonActivated) {
		QString testRenderer;
		int spp = 0;
		int size = 0;
		float refr = 0;

		if (!testing && tests.size() == 0) {
			if (ui->fixedTest->isChecked()) tests.push_back(0);
			if (ui->painterlyTest->isChecked()) tests.push_back(1);
			if (ui->bvhTest->isChecked()) tests.push_back(2);
			if (ui->pssmltTest->isChecked()) tests.push_back(3);
			if (ui->smallmediaTest->isChecked()) tests.push_back(4);
			if (ui->ppmTest->isChecked()) tests.push_back(5);
		} else if (testing && tests.size() == 0) {
			ui->renderButton->setText("Cancel");
			testing = false;
			tests.clear();
			on_renderButton_clicked();
			return;
		}

		spp = 10000;
		size = 400;
		refr = 1.5;
		testing = true;

		if (tests.at(0) == 0) {
			testRenderer = "smallpaint_fixed";
		} else if (tests.at(0) == 1) {
			testRenderer = "smallpaint_painterly";
		} else if (tests.at(0) == 2) {
			testRenderer = "smallpaint_bvh";
		} else if (tests.at(0) == 3) {
			testRenderer = "smallpaint_pssmlt";
		} else if (tests.at(0) == 4) {
			testRenderer = "smallpaint_smallmedia";
		} else if (tests.at(0) == 5) {
			testRenderer = "smallpaint_ppm";
            spp *= 100000;
		}
		tests.erase(tests.begin());

		helper.initializeRenderInformation(testRenderer, spp, size, refr);

		testWindow = new TestWindow;
		testWindow->setWindowTitle(testRenderer);
        testWindow->setFirstImage(QImage("../test_images/" + testRenderer + ".ppm"));
		testWindow->setWindowFlags(Qt::WindowTitleHint);
		testWindow->show();

		start = clock();
		smallpaint::sendToRender(size, spp, refr, testRenderer.toStdString());
	}
}

/**
 * Slots that forward to the processImage functions.
 */

void MainWindow::smallpaint_fixedSlot(smallpaint_fixed::Vec **pix, int spp) {
	smallpaint_fixed::processImage(pix, spp);
}

void MainWindow::smallpaint_painterlySlot(smallpaint_painterly::Vec **pix, int spp) {
	smallpaint_painterly::processImage(pix, spp);
}

void MainWindow::smallpaint_bvhSlot(smallpaint_bvh::Vec **pix, int spp) {
	smallpaint_bvh::processImage(pix, spp);
}

void MainWindow::smallpaint_pssmltSlot(smallpaint_pssmlt::Vec **pix, int spp) {
	smallpaint_pssmlt::processImage(pix, spp);
}

void MainWindow::smallpaint_smallmediaSlot(smallpaint_smallmedia::Vec **pix, int spp) {
	smallpaint_smallmedia::processImage(pix, spp);
}

void MainWindow::smallpaint_ppmSlot(smallpaint_ppm::Vec **pix, int spp) {
	smallpaint_ppm::processImage(pix, spp);
}

void MainWindow::smallpaint_vrlSlot(smallpaint_vrl::Vec **pix, int spp, int vrls) {
    smallpaint_vrl::processImage(pix, spp, vrls);
}
