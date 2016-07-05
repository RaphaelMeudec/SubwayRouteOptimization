#ifndef ERROR_BOX_H
#define ERROR_BOX_H

#include <QtGui>
#include <QPainter>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include "renderarea.h"

class ErrorWindow : public QWidget
{
    public:
        ErrorWindow(QString &erreur, QWidget *parent);
    protected:
        //void paintEvent(QPaintEvent* evt);
    private:
        QLabel *Error_Text;
        QLabel *Error_img;
        QPushButton *close;
};


#endif // ERROR_BOX_H
