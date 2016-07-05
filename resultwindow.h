#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QtGui>
#include <QPainter>
#include <QTextEdit>
#include <QPushButton>
#include <QPrinter>
#include <QPrintDialog>

#include "renderarea.h"

class ResultWindow : public QWidget
{
    Q_OBJECT
    public:
        ResultWindow(QString &itineraire, QString *stations_file, QString *lignes_file, int depart, int arrivee, QWidget *parent);
    protected:
        //void paintEvent(QPaintEvent* evt);
    private:
        QTextEdit *Trajet;
        QPushButton *close;
        QPushButton *print;
        RenderArea *area;
        QString *value;

        QPrinter *imprimante;
        QPrintDialog *dialogue;
        QTextEdit *Trajet_html;
    private slots:
        void Printwindow();
};

#endif
