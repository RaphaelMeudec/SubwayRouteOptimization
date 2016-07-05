#include "mainwindow.h"
#include "resultwindow.h"
#include <QHBoxLayout>
#include <QMessageBox>
#include "path.h"
#include "initialize.cpp"
#include "errorwindow.h"
#include <string>
#include <QtGui>
#include <QPixmap>
#include <QLabel>
using namespace std;

mainwindow::mainwindow(QString str_stations, QString str_lignes)
{
    //stations_file = new QString(str_stations);
    printf(QDir::currentPath().toLatin1().data());
    stations_file = new QString(QDir::currentPath() + "Stations.data");
    //lignes_file = new QString(str_lignes);
    lignes_file = new QString("C:\\Users\\Raphael\\Documents\\Github\\MetroTest\\MetroTest\\lignes.data");
    /* Initialisation  des Widgets*/
    QLabel *carte = new QLabel(this);

    /* Chemin d'acces Windows */
    QPixmap *carte_img = new QPixmap("C:\\Users\\Raphael\\Documents\\Github\\MetroTest\\MetroTest\\carte.jpg");
    /* Chemin d'acces Linux */
    //QPixmap *carte_img = new QPixmap("/home/m/meudec/Documents/MetroTest/carte.jpg");
    carte->setPixmap(*carte_img);

    depart = new QComboBox;
    depart->setToolTip("Station de depart");
    arrivee = new QComboBox;
    arrivee->setToolTip("Station d'arrivee");
    calculer = new QPushButton("&Calculer !");
    calculer->setToolTip("Calculer votre itineraire");
    quitter = new QPushButton("&Quitter");
    quitter->setToolTip("Quitter le programme");

    depart_txt = new QLabel("Station de depart:");
    arrivee_txt = new QLabel("Station d'arrivee:");


    /* Initialisation du réseau */
    int count_stat = 0; //Enregistrer le nombre de station
    //int count_line = 0; //Enregistrer le nombre de ligne

    std::vector<station> station_vector_originale;

    ifstream read_station;

    /* Chemin d'accès Windows */
    read_station.open(stations_file->toLocal8Bit().data());

    /* Chemin d'accès Linux, ordi ecole */
    //read_station.open(stations_file.toLocal8Bit().data());


    if(read_station.is_open()) //Commencer a lire les station
    {
        int x,y;
        string name;
        string aline;
        depart->addItem("");
        arrivee->addItem("");
        while (!read_station.eof())
        {
            /* Récupération de la ligne du fichier texte */
            read_station>>x>>y;  //lire les coordonnees
            getline (read_station,aline); //lire son nom
            name = aline.erase (0,1);
            /* Initialisation de la liste des stations */
            station temp(x,y,name,count_stat); //initialiser une station S
            station_vector_originale.push_back(temp);
            count_stat++;

            /* Ajout des stations à la liste des choix possibles */
            QString tmp;
            tmp += QString::number(count_stat) + " " +QString::fromUtf8(name.c_str());
            depart->addItem(tmp);
            arrivee->addItem(tmp);
        }
        read_station.close();
    }
    else
    {
        cout<<"Stations.data file NOT Found!"<<endl;
    }
    /* Mise en place sur une QGridLayout */
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(carte, 0, 0, 1, 5, 0);
    mainLayout->addWidget(depart_txt, 1, 0);
    mainLayout->addWidget(arrivee_txt, 1, 1);
    mainLayout->addWidget(depart, 2, 0);
    mainLayout->addWidget(arrivee, 2, 1);
    mainLayout->addWidget(calculer, 2, 3);
    mainLayout->addWidget(quitter, 2, 4);

    setLayout(mainLayout);
    setWindowTitle("ViaUnderground");
    //resize(400,450);
    this->setFixedSize(800,620);

    /* Connexion des signaux et des slots */
    connect(calculer, SIGNAL(clicked()), this, SLOT(genererTrajet()));
    connect(quitter, SIGNAL(clicked()),qApp,SLOT(quit()));
    /* Fin des connexions */
}

void mainwindow::genererTrajet()
{
    if (depart->currentText().isEmpty())
    {
        string erreur = "Veuillez entrer le nom de la station de depart";
        QString error(erreur.c_str());
        ErrorWindow *errorwindow = new ErrorWindow(error, this);
        errorwindow->show();
        return;
    }
    if (arrivee->currentText().isEmpty())
    {
        string erreur = "Veuillez entrer le nom de la station d'arrivee";
        QString error(erreur.c_str());
        ErrorWindow *errorwindow = new ErrorWindow(error, this);
        errorwindow->show();
        return;
    }
    if (depart->currentText() == arrivee->currentText())
    {
        string erreur = "Les stations de depart et d'arrivee sont les memes.";
        QString error(erreur.c_str());
        ErrorWindow *errorwindow = new ErrorWindow(error, this);
        errorwindow->show();
        return;
    }


    /* Initialisation du réseau */
    int count_stat = 0; //Enregistrer le nombre de stations
    int count_line = 0; //Enregistrer le nombre de lignes

    std::vector<station> station_vector_originale;

    ifstream read_station;
    read_station.open(stations_file->toLocal8Bit().data());
    if(read_station.is_open()) //Commencer a lire les stations
    {
        int x,y;
        string name;
        string aline;
        while (!read_station.eof())
        {
            /* Récupération de la ligne du fichier texte */
            read_station>>x>>y;  //lire les coordonnees
            getline (read_station,aline); //lire son nom
            name = aline.erase (0,1);
            /* Initialisation de la liste des stations */
            station temp(x,y,name,count_stat); //initialiser une station S
            station_vector_originale.push_back(temp);
            count_stat++;

            }
        read_station.close();
    }
    else
    {
        cout<<"Stations.data file NOT Found!"<<endl;
    }

    QString itineraire;

    /* Calcul de l'itineraire par Dijkstra */
    QString str = depart->currentText();
    cout << "initialisation str" << endl;
    QStringList list = str.split(" ");
    cout << "splitage list" << endl;
    int i = list[0].toInt();
    cout << "conversion int" << endl;
    QString str2 = arrivee->currentText();
    QStringList list2 = str2.split(" ");
    int j = list2[0].toInt();
    cout << j << endl;

    //int i=searchStation(depart->currentText().toStdString(), station_vector_originale);
    //int j=searchStation(arrivee->currentText().toStdString(), station_vector_originale);
    cout << "conversion int 2" << endl;
    QString P = test(i-1,j-1, stations_file, lignes_file);
    cout << "sortie du test" << endl;
    itineraire += P;
    cout << "" << endl;
/*
    itineraire += "Bienvenue dans le calcul d'itin&eacute;raires<br>";
    itineraire += "La station de d&eacute;part est " + depart->currentText() + "<br>";
    itineraire += "La station d'arriv&eacute;e est " + arrivee->currentText() + "<br>";
    itineraire += "<br> <br>";
*/
    ResultWindow *secondwindow = new ResultWindow(itineraire, stations_file, lignes_file, i-1, j-1, this);
    secondwindow->show();
}
