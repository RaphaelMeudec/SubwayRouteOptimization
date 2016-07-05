#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <vector>
#include <QLabel>
#include "station.h"
class station;

class mainwindow : public QWidget
{
    Q_OBJECT
public:
       mainwindow(QString str_stations, QString str_lignes);

signals:

public slots:


private slots:
    void genererTrajet();

private:
    QLabel *carte;
    QComboBox *depart;
    QComboBox *arrivee;
    QPushButton *calculer;
    QPushButton *quitter;
    QLabel *depart_txt;
    QLabel *arrivee_txt;
    QString *stations_file;
    QString *lignes_file;
};



#endif // MAINWINDOW_H
