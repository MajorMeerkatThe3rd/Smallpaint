/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *top;
    QWidget *menu;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *modes;
    QComboBox *renderModesComboBox;
    QStackedWidget *renderModesSettings;
    QWidget *fixed;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *fixedSizeLabel;
    QLineEdit *fixedSize;
    QLabel *label;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QLabel *fixedSamplesLabel;
    QLineEdit *fixedSamples;
    QLabel *label_2;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *fixedRefractionLabel;
    QLineEdit *fixedRefraction;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QWidget *painterly;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *painterlySizeLabel;
    QLineEdit *painterlySize;
    QLabel *label_4;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *painterlySamplesLabel;
    QLineEdit *painterlySamples;
    QLabel *label_5;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *painterlyRefractionLabel;
    QLineEdit *painterlyRefraction;
    QLabel *label_6;
    QSpacerItem *verticalSpacer_2;
    QWidget *bvh;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_10;
    QLabel *bvhSizeLabel;
    QLineEdit *bvhSize;
    QLabel *label_7;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *bvhSamplesLabel;
    QLineEdit *bvhSamples;
    QLabel *label_8;
    QFrame *line_6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *bvhRefractionLabel;
    QLineEdit *bvhRefraction;
    QLabel *label_9;
    QSpacerItem *verticalSpacer_3;
    QWidget *pssmlt;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_11;
    QLabel *pssmltSizeLabel;
    QLineEdit *pssmltSize;
    QLabel *label_10;
    QFrame *line_7;
    QHBoxLayout *horizontalLayout_12;
    QLabel *pssmltSamplesLabel;
    QLineEdit *pssmltSamples;
    QLabel *label_11;
    QFrame *line_8;
    QHBoxLayout *horizontalLayout_13;
    QLabel *pssmltRefractionLabel;
    QLineEdit *pssmltRefraction;
    QLabel *label_12;
    QSpacerItem *verticalSpacer_4;
    QWidget *smallmedia;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_14;
    QLabel *smallmediaSizeLabel;
    QLineEdit *smallmediaSize;
    QLabel *label_13;
    QFrame *line_9;
    QHBoxLayout *horizontalLayout_15;
    QLabel *smallmediaSamplesLabel;
    QLineEdit *smallmediaSamples;
    QLabel *label_14;
    QFrame *line_10;
    QHBoxLayout *horizontalLayout_16;
    QLabel *smallmediaRefractionLabel;
    QLineEdit *smallmediaRefraction;
    QLabel *label_15;
    QSpacerItem *verticalSpacer_5;
    QWidget *ppm;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_17;
    QLabel *ppmSizeLabel;
    QLineEdit *ppmSize;
    QLabel *label_16;
    QFrame *line_11;
    QHBoxLayout *horizontalLayout_18;
    QLabel *ppmSamplesLabel;
    QLineEdit *ppmSamples;
    QLabel *label_17;
    QFrame *line_12;
    QHBoxLayout *horizontalLayout_19;
    QLabel *ppmRefractionLabel;
    QLineEdit *ppmRefraction;
    QLabel *label_18;
    QSpacerItem *verticalSpacer_6;
    QWidget *tests;
    QFormLayout *formLayout_5;
    QRadioButton *fixedTest;
    QRadioButton *painterlyTest;
    QRadioButton *bvhTest;
    QRadioButton *pssmltTest;
    QRadioButton *smallmediaTest;
    QRadioButton *ppmTest;
    QVBoxLayout *output;
    QTextBrowser *timeInfo;
    QProgressBar *progressBar;
    QLabel *renderedImage;
    QWidget *bottom;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *renderInfo;
    QPushButton *renderButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(800, 600));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        top = new QHBoxLayout();
        top->setSpacing(6);
        top->setObjectName(QStringLiteral("top"));
        menu = new QWidget(centralWidget);
        menu->setObjectName(QStringLiteral("menu"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(menu->sizePolicy().hasHeightForWidth());
        menu->setSizePolicy(sizePolicy1);
        menu->setMinimumSize(QSize(250, 0));
        menu->setMaximumSize(QSize(250, 16777215));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(200, 200, 200, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        menu->setPalette(palette);
        menu->setLayoutDirection(Qt::LeftToRight);
        menu->setAutoFillBackground(true);
        verticalLayout_2 = new QVBoxLayout(menu);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        modes = new QVBoxLayout();
        modes->setSpacing(6);
        modes->setObjectName(QStringLiteral("modes"));
        renderModesComboBox = new QComboBox(menu);
        renderModesComboBox->setObjectName(QStringLiteral("renderModesComboBox"));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        renderModesComboBox->setFont(font);
        renderModesComboBox->setMaxVisibleItems(10);

        modes->addWidget(renderModesComboBox);

        renderModesSettings = new QStackedWidget(menu);
        renderModesSettings->setObjectName(QStringLiteral("renderModesSettings"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush2(QColor(240, 240, 240, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        renderModesSettings->setPalette(palette1);
        renderModesSettings->setAutoFillBackground(true);
        renderModesSettings->setFrameShape(QFrame::Panel);
        renderModesSettings->setFrameShadow(QFrame::Sunken);
        fixed = new QWidget();
        fixed->setObjectName(QStringLiteral("fixed"));
        verticalLayout_3 = new QVBoxLayout(fixed);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        fixedSizeLabel = new QLabel(fixed);
        fixedSizeLabel->setObjectName(QStringLiteral("fixedSizeLabel"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        fixedSizeLabel->setFont(font1);
        fixedSizeLabel->setToolTipDuration(-1);

        horizontalLayout_2->addWidget(fixedSizeLabel);

        fixedSize = new QLineEdit(fixed);
        fixedSize->setObjectName(QStringLiteral("fixedSize"));
        fixedSize->setMaximumSize(QSize(100, 20));

        horizontalLayout_2->addWidget(fixedSize);


        verticalLayout_3->addLayout(horizontalLayout_2);

        label = new QLabel(fixed);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        line = new QFrame(fixed);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        fixedSamplesLabel = new QLabel(fixed);
        fixedSamplesLabel->setObjectName(QStringLiteral("fixedSamplesLabel"));
        fixedSamplesLabel->setFont(font1);

        horizontalLayout_3->addWidget(fixedSamplesLabel);

        fixedSamples = new QLineEdit(fixed);
        fixedSamples->setObjectName(QStringLiteral("fixedSamples"));
        fixedSamples->setMaximumSize(QSize(100, 20));

        horizontalLayout_3->addWidget(fixedSamples);


        verticalLayout_3->addLayout(horizontalLayout_3);

        label_2 = new QLabel(fixed);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        line_2 = new QFrame(fixed);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        fixedRefractionLabel = new QLabel(fixed);
        fixedRefractionLabel->setObjectName(QStringLiteral("fixedRefractionLabel"));
        fixedRefractionLabel->setFont(font1);

        horizontalLayout_4->addWidget(fixedRefractionLabel);

        fixedRefraction = new QLineEdit(fixed);
        fixedRefraction->setObjectName(QStringLiteral("fixedRefraction"));
        fixedRefraction->setMaximumSize(QSize(100, 20));

        horizontalLayout_4->addWidget(fixedRefraction);


        verticalLayout_3->addLayout(horizontalLayout_4);

        label_3 = new QLabel(fixed);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        renderModesSettings->addWidget(fixed);
        painterly = new QWidget();
        painterly->setObjectName(QStringLiteral("painterly"));
        verticalLayout_4 = new QVBoxLayout(painterly);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        painterlySizeLabel = new QLabel(painterly);
        painterlySizeLabel->setObjectName(QStringLiteral("painterlySizeLabel"));
        painterlySizeLabel->setFont(font1);

        horizontalLayout_7->addWidget(painterlySizeLabel);

        painterlySize = new QLineEdit(painterly);
        painterlySize->setObjectName(QStringLiteral("painterlySize"));
        painterlySize->setMaximumSize(QSize(100, 20));

        horizontalLayout_7->addWidget(painterlySize);


        verticalLayout_4->addLayout(horizontalLayout_7);

        label_4 = new QLabel(painterly);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_4->addWidget(label_4);

        line_3 = new QFrame(painterly);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        painterlySamplesLabel = new QLabel(painterly);
        painterlySamplesLabel->setObjectName(QStringLiteral("painterlySamplesLabel"));
        painterlySamplesLabel->setFont(font1);

        horizontalLayout_5->addWidget(painterlySamplesLabel);

        painterlySamples = new QLineEdit(painterly);
        painterlySamples->setObjectName(QStringLiteral("painterlySamples"));
        painterlySamples->setMaximumSize(QSize(100, 20));

        horizontalLayout_5->addWidget(painterlySamples);


        verticalLayout_4->addLayout(horizontalLayout_5);

        label_5 = new QLabel(painterly);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_4->addWidget(label_5);

        line_4 = new QFrame(painterly);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        painterlyRefractionLabel = new QLabel(painterly);
        painterlyRefractionLabel->setObjectName(QStringLiteral("painterlyRefractionLabel"));
        painterlyRefractionLabel->setFont(font1);

        horizontalLayout_6->addWidget(painterlyRefractionLabel);

        painterlyRefraction = new QLineEdit(painterly);
        painterlyRefraction->setObjectName(QStringLiteral("painterlyRefraction"));
        painterlyRefraction->setMaximumSize(QSize(100, 20));

        horizontalLayout_6->addWidget(painterlyRefraction);


        verticalLayout_4->addLayout(horizontalLayout_6);

        label_6 = new QLabel(painterly);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_4->addWidget(label_6);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        renderModesSettings->addWidget(painterly);
        bvh = new QWidget();
        bvh->setObjectName(QStringLiteral("bvh"));
        verticalLayout_5 = new QVBoxLayout(bvh);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        bvhSizeLabel = new QLabel(bvh);
        bvhSizeLabel->setObjectName(QStringLiteral("bvhSizeLabel"));
        bvhSizeLabel->setFont(font1);

        horizontalLayout_10->addWidget(bvhSizeLabel);

        bvhSize = new QLineEdit(bvh);
        bvhSize->setObjectName(QStringLiteral("bvhSize"));
        bvhSize->setMaximumSize(QSize(100, 20));

        horizontalLayout_10->addWidget(bvhSize);


        verticalLayout_5->addLayout(horizontalLayout_10);

        label_7 = new QLabel(bvh);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_5->addWidget(label_7);

        line_5 = new QFrame(bvh);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_5);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        bvhSamplesLabel = new QLabel(bvh);
        bvhSamplesLabel->setObjectName(QStringLiteral("bvhSamplesLabel"));
        bvhSamplesLabel->setFont(font1);

        horizontalLayout_9->addWidget(bvhSamplesLabel);

        bvhSamples = new QLineEdit(bvh);
        bvhSamples->setObjectName(QStringLiteral("bvhSamples"));
        bvhSamples->setMaximumSize(QSize(100, 20));

        horizontalLayout_9->addWidget(bvhSamples);


        verticalLayout_5->addLayout(horizontalLayout_9);

        label_8 = new QLabel(bvh);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_5->addWidget(label_8);

        line_6 = new QFrame(bvh);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        bvhRefractionLabel = new QLabel(bvh);
        bvhRefractionLabel->setObjectName(QStringLiteral("bvhRefractionLabel"));
        bvhRefractionLabel->setFont(font1);

        horizontalLayout_8->addWidget(bvhRefractionLabel);

        bvhRefraction = new QLineEdit(bvh);
        bvhRefraction->setObjectName(QStringLiteral("bvhRefraction"));
        bvhRefraction->setMaximumSize(QSize(100, 20));

        horizontalLayout_8->addWidget(bvhRefraction);


        verticalLayout_5->addLayout(horizontalLayout_8);

        label_9 = new QLabel(bvh);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_5->addWidget(label_9);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        renderModesSettings->addWidget(bvh);
        pssmlt = new QWidget();
        pssmlt->setObjectName(QStringLiteral("pssmlt"));
        verticalLayout_6 = new QVBoxLayout(pssmlt);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        pssmltSizeLabel = new QLabel(pssmlt);
        pssmltSizeLabel->setObjectName(QStringLiteral("pssmltSizeLabel"));
        pssmltSizeLabel->setFont(font1);

        horizontalLayout_11->addWidget(pssmltSizeLabel);

        pssmltSize = new QLineEdit(pssmlt);
        pssmltSize->setObjectName(QStringLiteral("pssmltSize"));
        pssmltSize->setMaximumSize(QSize(100, 20));

        horizontalLayout_11->addWidget(pssmltSize);


        verticalLayout_6->addLayout(horizontalLayout_11);

        label_10 = new QLabel(pssmlt);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_6->addWidget(label_10);

        line_7 = new QFrame(pssmlt);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_7);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        pssmltSamplesLabel = new QLabel(pssmlt);
        pssmltSamplesLabel->setObjectName(QStringLiteral("pssmltSamplesLabel"));
        pssmltSamplesLabel->setFont(font1);

        horizontalLayout_12->addWidget(pssmltSamplesLabel);

        pssmltSamples = new QLineEdit(pssmlt);
        pssmltSamples->setObjectName(QStringLiteral("pssmltSamples"));
        pssmltSamples->setMaximumSize(QSize(100, 20));

        horizontalLayout_12->addWidget(pssmltSamples);


        verticalLayout_6->addLayout(horizontalLayout_12);

        label_11 = new QLabel(pssmlt);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_6->addWidget(label_11);

        line_8 = new QFrame(pssmlt);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_8);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        pssmltRefractionLabel = new QLabel(pssmlt);
        pssmltRefractionLabel->setObjectName(QStringLiteral("pssmltRefractionLabel"));
        pssmltRefractionLabel->setFont(font1);

        horizontalLayout_13->addWidget(pssmltRefractionLabel);

        pssmltRefraction = new QLineEdit(pssmlt);
        pssmltRefraction->setObjectName(QStringLiteral("pssmltRefraction"));
        pssmltRefraction->setMaximumSize(QSize(100, 20));

        horizontalLayout_13->addWidget(pssmltRefraction);


        verticalLayout_6->addLayout(horizontalLayout_13);

        label_12 = new QLabel(pssmlt);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_6->addWidget(label_12);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_4);

        renderModesSettings->addWidget(pssmlt);
        smallmedia = new QWidget();
        smallmedia->setObjectName(QStringLiteral("smallmedia"));
        verticalLayout_7 = new QVBoxLayout(smallmedia);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        smallmediaSizeLabel = new QLabel(smallmedia);
        smallmediaSizeLabel->setObjectName(QStringLiteral("smallmediaSizeLabel"));
        smallmediaSizeLabel->setFont(font1);

        horizontalLayout_14->addWidget(smallmediaSizeLabel);

        smallmediaSize = new QLineEdit(smallmedia);
        smallmediaSize->setObjectName(QStringLiteral("smallmediaSize"));
        smallmediaSize->setMaximumSize(QSize(100, 20));

        horizontalLayout_14->addWidget(smallmediaSize);


        verticalLayout_7->addLayout(horizontalLayout_14);

        label_13 = new QLabel(smallmedia);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_7->addWidget(label_13);

        line_9 = new QFrame(smallmedia);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_9);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        smallmediaSamplesLabel = new QLabel(smallmedia);
        smallmediaSamplesLabel->setObjectName(QStringLiteral("smallmediaSamplesLabel"));
        smallmediaSamplesLabel->setFont(font1);

        horizontalLayout_15->addWidget(smallmediaSamplesLabel);

        smallmediaSamples = new QLineEdit(smallmedia);
        smallmediaSamples->setObjectName(QStringLiteral("smallmediaSamples"));
        smallmediaSamples->setMaximumSize(QSize(100, 20));

        horizontalLayout_15->addWidget(smallmediaSamples);


        verticalLayout_7->addLayout(horizontalLayout_15);

        label_14 = new QLabel(smallmedia);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_7->addWidget(label_14);

        line_10 = new QFrame(smallmedia);
        line_10->setObjectName(QStringLiteral("line_10"));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_10);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        smallmediaRefractionLabel = new QLabel(smallmedia);
        smallmediaRefractionLabel->setObjectName(QStringLiteral("smallmediaRefractionLabel"));
        smallmediaRefractionLabel->setFont(font1);

        horizontalLayout_16->addWidget(smallmediaRefractionLabel);

        smallmediaRefraction = new QLineEdit(smallmedia);
        smallmediaRefraction->setObjectName(QStringLiteral("smallmediaRefraction"));
        smallmediaRefraction->setMaximumSize(QSize(100, 20));

        horizontalLayout_16->addWidget(smallmediaRefraction);


        verticalLayout_7->addLayout(horizontalLayout_16);

        label_15 = new QLabel(smallmedia);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout_7->addWidget(label_15);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_5);

        renderModesSettings->addWidget(smallmedia);
        ppm = new QWidget();
        ppm->setObjectName(QStringLiteral("ppm"));
        verticalLayout_8 = new QVBoxLayout(ppm);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        ppmSizeLabel = new QLabel(ppm);
        ppmSizeLabel->setObjectName(QStringLiteral("ppmSizeLabel"));
        ppmSizeLabel->setFont(font1);

        horizontalLayout_17->addWidget(ppmSizeLabel);

        ppmSize = new QLineEdit(ppm);
        ppmSize->setObjectName(QStringLiteral("ppmSize"));
        ppmSize->setMaximumSize(QSize(100, 20));

        horizontalLayout_17->addWidget(ppmSize);


        verticalLayout_8->addLayout(horizontalLayout_17);

        label_16 = new QLabel(ppm);
        label_16->setObjectName(QStringLiteral("label_16"));

        verticalLayout_8->addWidget(label_16);

        line_11 = new QFrame(ppm);
        line_11->setObjectName(QStringLiteral("line_11"));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_11);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        ppmSamplesLabel = new QLabel(ppm);
        ppmSamplesLabel->setObjectName(QStringLiteral("ppmSamplesLabel"));
        ppmSamplesLabel->setFont(font1);

        horizontalLayout_18->addWidget(ppmSamplesLabel);

        ppmSamples = new QLineEdit(ppm);
        ppmSamples->setObjectName(QStringLiteral("ppmSamples"));
        ppmSamples->setMaximumSize(QSize(100, 20));

        horizontalLayout_18->addWidget(ppmSamples);


        verticalLayout_8->addLayout(horizontalLayout_18);

        label_17 = new QLabel(ppm);
        label_17->setObjectName(QStringLiteral("label_17"));

        verticalLayout_8->addWidget(label_17);

        line_12 = new QFrame(ppm);
        line_12->setObjectName(QStringLiteral("line_12"));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_12);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        ppmRefractionLabel = new QLabel(ppm);
        ppmRefractionLabel->setObjectName(QStringLiteral("ppmRefractionLabel"));
        ppmRefractionLabel->setFont(font1);

        horizontalLayout_19->addWidget(ppmRefractionLabel);

        ppmRefraction = new QLineEdit(ppm);
        ppmRefraction->setObjectName(QStringLiteral("ppmRefraction"));
        ppmRefraction->setMaximumSize(QSize(100, 20));

        horizontalLayout_19->addWidget(ppmRefraction);


        verticalLayout_8->addLayout(horizontalLayout_19);

        label_18 = new QLabel(ppm);
        label_18->setObjectName(QStringLiteral("label_18"));

        verticalLayout_8->addWidget(label_18);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_6);

        renderModesSettings->addWidget(ppm);
        tests = new QWidget();
        tests->setObjectName(QStringLiteral("tests"));
        formLayout_5 = new QFormLayout(tests);
        formLayout_5->setSpacing(6);
        formLayout_5->setContentsMargins(11, 11, 11, 11);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        fixedTest = new QRadioButton(tests);
        fixedTest->setObjectName(QStringLiteral("fixedTest"));
        fixedTest->setChecked(true);

        formLayout_5->setWidget(0, QFormLayout::LabelRole, fixedTest);

        painterlyTest = new QRadioButton(tests);
        painterlyTest->setObjectName(QStringLiteral("painterlyTest"));
        painterlyTest->setChecked(false);

        formLayout_5->setWidget(1, QFormLayout::LabelRole, painterlyTest);

        bvhTest = new QRadioButton(tests);
        bvhTest->setObjectName(QStringLiteral("bvhTest"));
        bvhTest->setChecked(false);

        formLayout_5->setWidget(2, QFormLayout::LabelRole, bvhTest);

        pssmltTest = new QRadioButton(tests);
        pssmltTest->setObjectName(QStringLiteral("pssmltTest"));
        pssmltTest->setChecked(false);

        formLayout_5->setWidget(3, QFormLayout::LabelRole, pssmltTest);

        smallmediaTest = new QRadioButton(tests);
        smallmediaTest->setObjectName(QStringLiteral("smallmediaTest"));
        smallmediaTest->setChecked(false);

        formLayout_5->setWidget(4, QFormLayout::LabelRole, smallmediaTest);

        ppmTest = new QRadioButton(tests);
        ppmTest->setObjectName(QStringLiteral("ppmTest"));
        ppmTest->setChecked(false);

        formLayout_5->setWidget(5, QFormLayout::LabelRole, ppmTest);

        renderModesSettings->addWidget(tests);

        modes->addWidget(renderModesSettings);


        verticalLayout_2->addLayout(modes);

        output = new QVBoxLayout();
        output->setSpacing(6);
        output->setObjectName(QStringLiteral("output"));
        timeInfo = new QTextBrowser(menu);
        timeInfo->setObjectName(QStringLiteral("timeInfo"));
        sizePolicy.setHeightForWidth(timeInfo->sizePolicy().hasHeightForWidth());
        timeInfo->setSizePolicy(sizePolicy);
        timeInfo->setMinimumSize(QSize(0, 0));
        timeInfo->setMaximumSize(QSize(16777215, 100));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        timeInfo->setPalette(palette2);
        timeInfo->setAutoFillBackground(true);
        timeInfo->setFrameShape(QFrame::Panel);
        timeInfo->setFrameShadow(QFrame::Sunken);
        timeInfo->setLineWidth(1);

        output->addWidget(timeInfo);

        progressBar = new QProgressBar(menu);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy2);
        progressBar->setMinimumSize(QSize(150, 28));
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        progressBar->setTextVisible(false);
        progressBar->setInvertedAppearance(false);

        output->addWidget(progressBar);


        verticalLayout_2->addLayout(output);


        top->addWidget(menu, 0, Qt::AlignLeft);

        renderedImage = new QLabel(centralWidget);
        renderedImage->setObjectName(QStringLiteral("renderedImage"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(renderedImage->sizePolicy().hasHeightForWidth());
        renderedImage->setSizePolicy(sizePolicy3);
        renderedImage->setMinimumSize(QSize(520, 520));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        renderedImage->setPalette(palette3);
        renderedImage->setAutoFillBackground(false);
        renderedImage->setFrameShape(QFrame::NoFrame);

        top->addWidget(renderedImage);


        verticalLayout->addLayout(top);

        bottom = new QWidget(centralWidget);
        bottom->setObjectName(QStringLiteral("bottom"));
        sizePolicy2.setHeightForWidth(bottom->sizePolicy().hasHeightForWidth());
        bottom->setSizePolicy(sizePolicy2);
        bottom->setMinimumSize(QSize(0, 50));
        bottom->setMaximumSize(QSize(16777215, 50));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Base, brush);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        bottom->setPalette(palette4);
        bottom->setAutoFillBackground(true);
        horizontalLayout = new QHBoxLayout(bottom);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        renderInfo = new QTextBrowser(bottom);
        renderInfo->setObjectName(QStringLiteral("renderInfo"));
        sizePolicy2.setHeightForWidth(renderInfo->sizePolicy().hasHeightForWidth());
        renderInfo->setSizePolicy(sizePolicy2);
        renderInfo->setMaximumSize(QSize(16777215, 26));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        renderInfo->setPalette(palette5);
        renderInfo->setAutoFillBackground(true);
        renderInfo->setFrameShape(QFrame::Panel);
        renderInfo->setFrameShadow(QFrame::Sunken);
        renderInfo->setLineWidth(1);
        renderInfo->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        renderInfo->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        horizontalLayout->addWidget(renderInfo, 0, Qt::AlignVCenter);

        renderButton = new QPushButton(bottom);
        renderButton->setObjectName(QStringLiteral("renderButton"));
        sizePolicy3.setHeightForWidth(renderButton->sizePolicy().hasHeightForWidth());
        renderButton->setSizePolicy(sizePolicy3);
        renderButton->setMinimumSize(QSize(120, 30));
        renderButton->setAutoDefault(false);

        horizontalLayout->addWidget(renderButton);

        horizontalLayout->setStretch(0, 50);
        horizontalLayout->setStretch(1, 50);

        verticalLayout->addWidget(bottom);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        renderModesComboBox->setCurrentIndex(0);
        renderModesSettings->setCurrentIndex(0);
        renderButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Smallpaint", 0));
        renderModesComboBox->clear();
        renderModesComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Path Tracing (Fixed)", 0)
         << QApplication::translate("MainWindow", "Path Tracing (Painterly)", 0)
         << QApplication::translate("MainWindow", "Bounding Volume Hierarchy", 0)
         << QApplication::translate("MainWindow", "Primary Sample Space MLT", 0)
         << QApplication::translate("MainWindow", "Volumetric Path Tracing", 0)
         << QApplication::translate("MainWindow", "Progressive Photon Mapping", 0)
         << QApplication::translate("MainWindow", "Tests", 0)
        );
#ifndef QT_NO_TOOLTIP
        fixedSizeLabel->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        fixedSizeLabel->setText(QApplication::translate("MainWindow", "Width / Height", 0));
#ifndef QT_NO_TOOLTIP
        fixedSize->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        fixedSize->setText(QApplication::translate("MainWindow", "400", 0));
        label->setText(QApplication::translate("MainWindow", "The width and height of the image.\n"
"Entering 400 creates a 400x400 image.", 0));
        fixedSamplesLabel->setText(QApplication::translate("MainWindow", "Samples", 0));
#ifndef QT_NO_TOOLTIP
        fixedSamples->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        fixedSamples->setText(QApplication::translate("MainWindow", "50", 0));
        label_2->setText(QApplication::translate("MainWindow", "The number of samples per pixel that \n"
"are used to render the image.", 0));
        fixedRefractionLabel->setText(QApplication::translate("MainWindow", "Refraction index", 0));
#ifndef QT_NO_TOOLTIP
        fixedRefraction->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        fixedRefraction->setText(QApplication::translate("MainWindow", "1.5", 0));
        label_3->setText(QApplication::translate("MainWindow", "The refraction index for refractive\n"
"spheres. (Water 1.3; Diamond 2.4)", 0));
        painterlySizeLabel->setText(QApplication::translate("MainWindow", "Width / Height", 0));
#ifndef QT_NO_TOOLTIP
        painterlySize->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("MainWindow", "The width and height of the image.\n"
"Entering 400 creates a 400x400 image.", 0));
        painterlySamplesLabel->setText(QApplication::translate("MainWindow", "Samples", 0));
#ifndef QT_NO_TOOLTIP
        painterlySamples->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("MainWindow", "The number of samples per pixel that \n"
"are used to render the image.", 0));
        painterlyRefractionLabel->setText(QApplication::translate("MainWindow", "Refraction index", 0));
#ifndef QT_NO_TOOLTIP
        painterlyRefraction->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("MainWindow", "The refraction index for refractive\n"
"spheres. (Water 1.3; Diamond 2.4)", 0));
        bvhSizeLabel->setText(QApplication::translate("MainWindow", "Width / Height", 0));
#ifndef QT_NO_TOOLTIP
        bvhSize->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_7->setText(QApplication::translate("MainWindow", "The width and height of the image.\n"
"Entering 400 creates a 400x400 image.", 0));
        bvhSamplesLabel->setText(QApplication::translate("MainWindow", "Samples", 0));
#ifndef QT_NO_TOOLTIP
        bvhSamples->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_8->setText(QApplication::translate("MainWindow", "The number of samples per pixel that \n"
"are used to render the image.", 0));
        bvhRefractionLabel->setText(QApplication::translate("MainWindow", "Refraction index", 0));
#ifndef QT_NO_TOOLTIP
        bvhRefraction->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_9->setText(QApplication::translate("MainWindow", "The refraction index for refractive\n"
"spheres. (Water 1.3; Diamond 2.4)", 0));
        pssmltSizeLabel->setText(QApplication::translate("MainWindow", "Width / Height", 0));
#ifndef QT_NO_TOOLTIP
        pssmltSize->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_10->setText(QApplication::translate("MainWindow", "The width and height of the image.\n"
"Entering 400 creates a 400x400 image.", 0));
        pssmltSamplesLabel->setText(QApplication::translate("MainWindow", "Samples", 0));
#ifndef QT_NO_TOOLTIP
        pssmltSamples->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_11->setText(QApplication::translate("MainWindow", "The number of samples per pixel that \n"
"are used to render the image.", 0));
        pssmltRefractionLabel->setText(QApplication::translate("MainWindow", "Refraction index", 0));
#ifndef QT_NO_TOOLTIP
        pssmltRefraction->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_12->setText(QApplication::translate("MainWindow", "The refraction index for refractive\n"
"spheres. (Water 1.3; Diamond 2.4)", 0));
        smallmediaSizeLabel->setText(QApplication::translate("MainWindow", "Width / Height", 0));
#ifndef QT_NO_TOOLTIP
        smallmediaSize->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_13->setText(QApplication::translate("MainWindow", "The width and height of the image.\n"
"Entering 400 creates a 400x400 image.", 0));
        smallmediaSamplesLabel->setText(QApplication::translate("MainWindow", "Samples", 0));
#ifndef QT_NO_TOOLTIP
        smallmediaSamples->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_14->setText(QApplication::translate("MainWindow", "The number of samples per pixel that \n"
"are used to render the image.", 0));
        smallmediaRefractionLabel->setText(QApplication::translate("MainWindow", "Refraction index", 0));
#ifndef QT_NO_TOOLTIP
        smallmediaRefraction->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_15->setText(QApplication::translate("MainWindow", "The refraction index for refractive\n"
"spheres. (Water 1.3; Diamond 2.4)", 0));
        ppmSizeLabel->setText(QApplication::translate("MainWindow", "Width / Height", 0));
#ifndef QT_NO_TOOLTIP
        ppmSize->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Enter a number (min 100, max 1500) to specify the size of the image. If you don't enter a number, 400 is chosen.</p><p>Example: Entering 400 creates a 400x400 image.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_16->setText(QApplication::translate("MainWindow", "The width and height of the image.\n"
"Entering 400 creates a 400x400 image.", 0));
        ppmSamplesLabel->setText(QApplication::translate("MainWindow", "Photons (*1k)", 0));
#ifndef QT_NO_TOOLTIP
        ppmSamples->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Enter a number to specify the photons that will be used. If you don't enter a number, 1000000 will be calculated.</p><p>The entered number will be multiplied by 1000 for the final photon amount.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_17->setText(QApplication::translate("MainWindow", "The number of photons that are used to \n"
"render the image. The entered number \n"
"will be multiplied by 1000.", 0));
        ppmRefractionLabel->setText(QApplication::translate("MainWindow", "Refraction index", 0));
#ifndef QT_NO_TOOLTIP
        ppmRefraction->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Enter a number (min 1, max 4) to specify the refraction index for objects in the scene. If you don't enter a number, 1.5 will be chosen.</p><ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Water: 1.333</li><li style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Ice: 1.31</li><li style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Diamond: 2.42</li></ul></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_18->setText(QApplication::translate("MainWindow", "The refraction index for refractive\n"
"spheres. (Water 1.3; Diamond 2.4)", 0));
        fixedTest->setText(QApplication::translate("MainWindow", "Path Tracing (Fixed)", 0));
        painterlyTest->setText(QApplication::translate("MainWindow", "Path Tracing (Painterly)", 0));
        bvhTest->setText(QApplication::translate("MainWindow", "Bounding Volume Hierarchy", 0));
        pssmltTest->setText(QApplication::translate("MainWindow", "Primary Sample Space MLT", 0));
        smallmediaTest->setText(QApplication::translate("MainWindow", "Volumetric Path Tracing", 0));
        ppmTest->setText(QApplication::translate("MainWindow", "Progressive Photon Mapping", 0));
        renderedImage->setText(QString());
        renderButton->setText(QApplication::translate("MainWindow", "Render", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
