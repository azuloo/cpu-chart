#ifndef CPUDATAGROUP_H
#define CPUDATAGROUP_H

#include <QGroupBox>
#include <QtCharts>
#include <QLabel>

#define X_AXIS_MAX 10
#define Y_AXIS_MAX 100
#define DATA_POLL_INTERVAL 2000
#define DEFAULT_CHART_NAME "Chart"

struct CPUChartSeries {
    QSplineSeries     *series;
    int cpuIdx        = 1;
    int currSeriesIdx = 0;
};

struct CPUChartData {
    QChart *chart;
    QChartView *chartView;
    QVector<CPUChartSeries> cpuCharts;
};

class CPUChart : public QChart
{
    Q_OBJECT

public:
    enum CPUChartType { Temp };

    CPUChart(QGraphicsItem *parent = nullptr);
    ~CPUChart();

    void setUpChart();

    void setCPUIdx(int i) { m_CPUIdx = i; }
    void setChartName(QString name) { m_chartName = name; }
    void setXAxisMax(int max) { m_xAxisMax = max; }
    void setYAxisMax(int max) { m_yAxisMax = max; }
    void setDataPollInterval(int i) { m_dataPollInterval = i; }
    void setChartPen(QPen pen) { m_chartPen = pen; }
    void setChartType(int t) { m_chartType = t; }

    int CPUIdx() const { return m_CPUIdx; }
    QString chartName() const { return m_chartName; }
    int xAxisMax() const { return m_xAxisMax; }
    int yAxisMax() const { return m_yAxisMax; }
    int dataPollInterval() const { return m_dataPollInterval; }
    QPen chartPen() const { return m_chartPen; }
    int chartType() const { return m_chartType; }

    QChartView *chartView() const { return m_chartData->chartView; }
    QChart *chart() const { return m_chartData->chart; }

    double getMaxTemp();
    double getAvgTemp();
    void addSeries(int cpuIndex, QSplineSeries *s);
    void start();

public Q_SLOTS:
    void updateTempChart(CPUChartSeries *series);

Q_SIGNALS:
    void tempUpdateCompleted();

private:
    int m_CPUIdx;
    QString m_chartName;
    int m_xAxisMax;
    int m_yAxisMax;
    int m_dataPollInterval;
    CPUChartData *m_chartData;
    QPen m_chartPen;
    int m_chartType;

    QTimer *m_dataUpdateTimer;
    QVector<double> m_tempInputs;

    void setUpChartUpdateRoutine(CPUChartSeries *series);

    QChart *initCPUChart();
    QChartView *initCPUChartView(QChart *chart);
};

#endif // CPUDATAGROUP_H
