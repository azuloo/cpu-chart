#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "cpuchart.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QHBoxLayout>

class MainWindow : public QMainWindow, public Ui_MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public Q_SLOTS:
    void updateTempInputs();

private:
    CPUChart *cpuChart;

    void initCPUCharts();
};

#endif // MAINWINDOW_H
