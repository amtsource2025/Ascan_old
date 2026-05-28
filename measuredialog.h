#ifndef MEASUREDIALOG_H
#define MEASUREDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTimer>
#include <QTime>
#include <QDebug>
#include <QUuid>
#include "Services/qcustomplot.h"

namespace Ui { class MeasureDialog; }

class MeasureDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MeasureDialog(const QString &patientId,
                           const QString &doctorId,
                           QWidget *parent = nullptr);
    ~MeasureDialog();

private slots:
    void updateTime();
    void on_btn_home_clicked();
    void on_btn_calculator_clicked();
    void on_btn_eye_clicked();
    void on_btn_lensType_clicked();
    void on_btn_opMode_clicked();
    void updateOpModeUI();
    void updateLensTypeUI();
    void on_btn_startMeasure_clicked();
    void on_btn_play_clicked();
    void on_butDelete_clicked();

    void on_btn_graphOne_clicked();
    void on_btn_graphTwo_clicked();
    void on_btn_graphThree_clicked();
    void on_btn_graphFour_clicked();
    void on_btn_graphFive_clicked();
    void on_btn_graphSix_clicked();
    void on_btn_graphSeven_clicked();
    void on_btn_graphEight_clicked();
    void on_btn_graphNine_clicked();
    void on_btn_graphTen_clicked();

private:
    Ui::MeasureDialog *ui;
    QSqlDatabase       db;
    QTimer            *clockTimer;

    QString m_patientId;
    QString m_doctorId;
    QString m_scanId;

    int m_currentEye;       // 0=OD(Right), 1=OS(Left)
    int m_lensType;         // 0=Phakic, 1=APhakic, 2=Dense Cataract
    int m_opMode;           // 0=Contact, 1=Immersion
    int m_selectedReading;  // 1-10

    // ── DB helpers ────────────────────────────────────────────
    bool openDatabase();
    void loadPatientInfo();
    void loadDoctorInfo();
    void loadReadings();
    void selectReading(int readingNo);
    void updateAverageAndSD();
    void highlightGraphButton(int readingNo);
    void clearAllReadingLabels();

    // ── Plot helpers ──────────────────────────────────────────
    void            setupPlot();
    void            plotReading(int readingNo);
    void            clearPlot();
    QVector<double> decodeReadingData(const QString &csv);
    void            updateMarkerPositions(double xCornea,
                               double xLens1,
                               double xLens2,
                               double xRetina,
                               double totalMm);

    void drawMiniWaveformOnButton(QPushButton *btn, int readingNo);
    void refreshAllButtonWaveforms();
    void updatePlayButtonVisibility();   // show play only when no data

    QCustomPlot *m_plot;

    void bindReadingFilters(QSqlQuery &q) const;
};

#endif // MEASUREDIALOG_H
