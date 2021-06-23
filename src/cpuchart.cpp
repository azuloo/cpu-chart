#include "cpuchart.h"
#include "cpudataprovider.h"

CPUChart::CPUChart(QGraphicsItem *parent)
     : QChart(parent), m_chartName(DEFAULT_CHART_NAME),
       m_xAxisMax(X_AXIS_MAX), m_yAxisMax(Y_AXIS_MAX), m_dataPollInterval(DATA_POLL_INTERVAL),
       m_chartData(nullptr), m_chartType(CPUChart::Temp), m_dataUpdateTimer(new QTimer(this)) {}

CPUChart::~CPUChart()
{
    delete m_chartData;
}

void CPUChart::setUpChart()
{
    QChart *cpuTempChart = initCPUChart();
    QChartView *cpuTempChartView = initCPUChartView(cpuTempChart);

    m_chartData = new CPUChartData;
    m_chartData->chart = cpuTempChart;
    m_chartData->chartView = cpuTempChartView;
}

void CPUChart::setUpChartUpdateRoutine(CPUChartSeries *series)
{
    switch (m_chartType)
    {
    default:
    case CPUChart::Temp:                                            // Temperature chart (default)
        connect(m_dataUpdateTimer, &QTimer::timeout, this, std::bind(&CPUChart::updateTempChart, this, series));
        m_dataUpdateTimer->start(m_dataPollInterval);
        break;
    }
}

QChart *CPUChart::initCPUChart()
{
    QChart *cpuTempChart = new QChart(this);
    cpuTempChart->setTitle(m_chartName);

    return cpuTempChart;
}

QChartView *CPUChart::initCPUChartView(QChart *chart)
{
    QChartView *cpuTempChartView = new QChartView(chart);
    cpuTempChartView->setRenderHint(QPainter::Antialiasing);

    return cpuTempChartView;
}

void CPUChart::addSeries(int cpuIdx, QSplineSeries *s)
{
    m_chartData->chart->addSeries(s);
    m_chartData->chart->createDefaultAxes();
    m_chartData->chart->axes(Qt::Horizontal).first()->setRange(0, m_xAxisMax);
    m_chartData->chart->axes(Qt::Vertical).first()->setRange(0, m_yAxisMax);

    CPUChartSeries series;
    series.series = s;
    series.cpuIdx = cpuIdx;

    m_chartData->cpuCharts.push_back(series);
}

void CPUChart::updateTempChart(CPUChartSeries *series)
{
    // Reset series after X_AXIS_MAX ticks
    if (series->currSeriesIdx == X_AXIS_MAX) {
        series->currSeriesIdx = 0;
        series->series->clear();
    }

    double cpuTemp = CPUDataProvider::getCPUTempByIdx(series->cpuIdx);

    m_tempInputs.push_back(cpuTemp);
    if (m_tempInputs.size() >= CPUDataProvider::getCPUNum()) {
        emit(tempUpdateCompleted());
        m_tempInputs.clear();
    }

    series->series->append(series->currSeriesIdx++, cpuTemp);
}

double CPUChart::getMaxTemp()
{
    return *std::max_element(m_tempInputs.begin(), m_tempInputs.end());
}

double CPUChart::getAvgTemp()
{
    double initialTemp = 0.0;
    if (m_tempInputs.size() > 0) {
        QVector<double> tempInputs;
        std::back_insert_iterator<QVector<double>> it(tempInputs);
        std::copy_if(
            m_tempInputs.begin(),
            m_tempInputs.end(),
            it,
            [](double t) { return t != 0; });
        return std::accumulate(
            tempInputs.begin(),
            tempInputs.end(),
            initialTemp) / tempInputs.size();
    }

    return initialTemp;
}

void CPUChart::start()
{
    auto it = m_chartData->cpuCharts.begin();
    for (; it != m_chartData->cpuCharts.end(); it++) {
        this->setUpChartUpdateRoutine(it);
    }
}
