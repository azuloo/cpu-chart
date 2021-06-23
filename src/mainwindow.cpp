#include "mainwindow.h"
#include "cpuchart.h"
#include "cpudataprovider.h"
#include <QHBoxLayout>
#include <QWidget>
#include <QtCharts>
#include <QTimer>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), cpuChart(new CPUChart)
{
    this->setupUi(this);
    initCPUCharts();

    cpuTempChartView->setChart(cpuChart->chart());

    connect(cpuChart, &CPUChart::tempUpdateCompleted, this, &MainWindow::updateTempInputs);
}

MainWindow::~MainWindow()
{
    delete cpuChart;
}

void MainWindow::initCPUCharts()
{
    cpuChart->setChartName(
        "Core Temperature (" +
        QString::number(CPUDataProvider::getCPUNum())
        + " cores)"
    );
    cpuChart->setUpChart();

    for (int i = 1; i <= CPUDataProvider::getCPUNum(); i++) {
        // Chart itself is responsible for deleting its series
        QSplineSeries *series = new QSplineSeries;
        series->setName("Core #" + QString::number(i));
        cpuChart->addSeries(i, series);
    }

    cpuChart->start();
}

void MainWindow::updateTempInputs()
{
    maxTempInput->setText(QString::number(cpuChart->getMaxTemp()));
    avgCoreInput->setText(QString::number(cpuChart->getAvgTemp(), 'f', 2));
}
