#include "choicewindow.h"
#include "errorwindow.h"
#include "mainwindow.h"
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QtGui>
using namespace std;

choicewindow::choicewindow()
{
    choix = new QComboBox;
    charger = new QPushButton("Charger");
    fermer = new QPushButton("Fermer");
    logo_img = new QLabel(this);
    //logo_img->setFixedHeight(120);
    //logo_img->setFixedWidth(120);
    /* Chemin d'acces Windows */
    QPixmap *logo = new QPixmap("C:\\Users\\Raphael\\Documents\\Github\\SubwayRouteOptimization\\logo.png");
    /* Chemin d'acces Linux */
    //QPixmap *error_img = new QPixmap("/home/m/meudec/Documents/MetroTest/Warning.png");
    logo_img->setPixmap(*logo);
    logo_img->adjustSize();
    logo_img->setScaledContents(true);


    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(choix);
    buttonsLayout->addWidget(charger);
    buttonsLayout->addWidget(fermer);

    choix->addItem("");
    choix->addItem("Paris");

    QVBoxLayout *choiceLayout = new QVBoxLayout;
    choiceLayout->addWidget(logo_img);
    choiceLayout->addLayout(buttonsLayout);

    setLayout(choiceLayout);
    this->setFixedSize(1000, 400);

    connect(fermer, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(charger, SIGNAL(clicked()), this, SLOT(chargerdata()));

}


void choicewindow::chargerdata() {
    if (choix->currentText().isEmpty()) {
        string erreur = "Veuillez entrer la ville qui vous intéresse";
        QString error(erreur.c_str());
        ErrorWindow *errorwindow = new ErrorWindow(error, this);
        errorwindow->show();
    } else {
        QString str_stations;
        QString str_lignes;

        /* Chemin d'acces Windows */
        str_stations += "C:\\Users\\Raphael\\Documents\\Github\\SubwayRouteOptimization\\";
        str_lignes += "C:\\Users\\Raphael\\Documents\\Github\\SubwayRouteOptimization\\";

        str_stations += choix->currentText();
        str_lignes += choix->currentText();
        str_stations += ".data";
        str_lignes += "_lignes.data";
        mainwindow *window = new mainwindow(str_stations, str_lignes);
        window->show();
    }
}
