#pragma once

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVector>
#include <QByteArray>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QTimer>

QT_CHARTS_USE_NAMESPACE

    class WaveformDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WaveformDialog(const QString &patientId,
                            const QString &doctorId,
                            int            eye,
                            int            readingNo,
                            QWidget       *parent = nullptr);
    ~WaveformDialog() override;

private slots:
    void onReadingChanged(int index);
    void onExportClicked();

private:
    void setupUi();
    void loadAndPlot(int readingNo);
    QVector<double> decodeReadingData(const QByteArray &raw);

    QString         m_patientId;
    QString         m_doctorId;
    int             m_eye;

    QSqlDatabase    db;
    QChartView     *m_chartView  = nullptr;
    QChart         *m_chart      = nullptr;
    QLineSeries    *m_series     = nullptr;
    QValueAxis     *m_axisX      = nullptr;
    QValueAxis     *m_axisY      = nullptr;

    QLabel         *m_lblAL      = nullptr;
    QLabel         *m_lblACD     = nullptr;
    QLabel         *m_lblLT      = nullptr;
    QLabel         *m_lblVit     = nullptr;
    QLabel         *m_lblDev     = nullptr;
    QComboBox      *m_readingCbo = nullptr;

    // Peak marker lines
    QLineSeries    *m_peakCornea  = nullptr;
    QLineSeries    *m_peakLens1   = nullptr;
    QLineSeries    *m_peakLens2   = nullptr;
    QLineSeries    *m_peakRetina  = nullptr;
};
