/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCharts/chartsnamespace.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QFormLayout *cpuTempMainLayout;
    QLabel *maxTempLabel;
    QLineEdit *maxTempInput;
    QFormLayout *formLayout;
    QLabel *avgCoreLabel;
    QLineEdit *avgCoreInput;
    QSpacerItem *horizontalSpacer;
    QtCharts::QChartView *cpuTempChartView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(897, 638);
        MainWindow->setAcceptDrops(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cpuTempMainLayout = new QFormLayout();
        cpuTempMainLayout->setObjectName(QString::fromUtf8("cpuTempMainLayout"));
        maxTempLabel = new QLabel(centralwidget);
        maxTempLabel->setObjectName(QString::fromUtf8("maxTempLabel"));

        cpuTempMainLayout->setWidget(0, QFormLayout::LabelRole, maxTempLabel);

        maxTempInput = new QLineEdit(centralwidget);
        maxTempInput->setObjectName(QString::fromUtf8("maxTempInput"));
        maxTempInput->setReadOnly(true);

        cpuTempMainLayout->setWidget(0, QFormLayout::FieldRole, maxTempInput);


        horizontalLayout->addLayout(cpuTempMainLayout);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        avgCoreLabel = new QLabel(centralwidget);
        avgCoreLabel->setObjectName(QString::fromUtf8("avgCoreLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, avgCoreLabel);

        avgCoreInput = new QLineEdit(centralwidget);
        avgCoreInput->setObjectName(QString::fromUtf8("avgCoreInput"));
        avgCoreInput->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, avgCoreInput);


        horizontalLayout->addLayout(formLayout);

        horizontalSpacer = new QSpacerItem(368, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        cpuTempChartView = new QtCharts::QChartView(centralwidget);
        cpuTempChartView->setObjectName(QString::fromUtf8("cpuTempChartView"));
        cpuTempChartView->setRenderHints(QPainter::Antialiasing|QPainter::HighQualityAntialiasing);

        verticalLayout->addWidget(cpuTempChartView);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 897, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "CPU Core Temperature", nullptr));
        maxTempLabel->setText(QApplication::translate("MainWindow", "Max:", nullptr));
        avgCoreLabel->setText(QApplication::translate("MainWindow", "Average:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
