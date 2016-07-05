#include "errorwindow.h"
#include <iostream>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
using namespace std;

ErrorWindow::ErrorWindow(QString &erreur, QWidget *parent=0)
{
    /* Initialisation des widgets */
    Error_img = new QLabel(this);
    Error_img->setFixedHeight(120);
    Error_img->setFixedWidth(120);
    /* Chemin d'acces Windows */
    QPixmap *error_img = new QPixmap("C:\\Users\\Raphael\\Documents\\MetroTest\\Warning.png");
    /* Chemin d'acces Linux */
    //QPixmap *error_img = new QPixmap("/home/m/meudec/Documents/MetroTest/Warning.png");
    Error_img->setPixmap(*error_img);
    Error_img->adjustSize();
    Error_img->setScaledContents(true);
    Error_Text = new QLabel(erreur);
    close = new QPushButton("Ok");

    /* Création du layout */
    QGridLayout *errorLayout = new QGridLayout;
    errorLayout->addWidget(Error_img, 0, 0);
    errorLayout->addWidget(Error_Text, 0, 1);
    errorLayout->addWidget(close, 1, 0, 1, 2);

    setLayout(errorLayout);
    resize(100,75);



    connect(close, SIGNAL(clicked()),this, SLOT(close()));

}
