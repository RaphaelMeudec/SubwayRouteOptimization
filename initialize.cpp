#ifndef TEST_CPP
#define TEST_CPP


#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <QString>
#include "station.h"
#include "ligne.h"
#include "path.h"
#include "arc.h"
#include "Dijkstra.h"
#include "read_files.h"
#include "mainwindow.h"
#define Time_MAX 1000


using namespace std;

QString test(int start, int dest, QString *stations_file, QString *lignes_file)
{
    int count_stat = 0; //Enregistrer le nombre de station
    int count_line = 0; //Enregistrer le nombre de ligne

    vector<station> station_vector_originale;

    ifstream read_station;
    /* Chemin d'acces Windows */
    read_station.open(stations_file->toLocal8Bit().data());
    /* Chemin d'acces Linux */
    //read_station.open(stations_file->toLocal8Bit().data());

    if(read_station.is_open()) //Commencer a lire les station
    {
        in_stat (read_station, station_vector_originale, count_stat);
        read_station.close();
    } else {
        cout<<"Stations.data file NOT Found!"<<endl;
        return 0;
    }

    station_vector_originale.pop_back();
    count_stat--;
    cout << "stations initialisées" << endl;
    vector<line> line_vector_original;
    ifstream read_line;
    /* Cheminx d'accès Windows */
    read_line.open(lignes_file->toLocal8Bit().data()); // Commencer a lire les lignes
    /* Cheminx d'accès Linux */
    //read_line.open(lignes_file->toLocal8Bit().data();

    if(read_line.is_open()) {
        in_line(read_line, line_vector_original, count_line, count_stat, station_vector_originale);
        read_line.close();
    } else {
        cout<<"lignes.data file NOT Found!";
        return 0;
    }
    cout << "lignes initialisées" << endl;

    path P(count_stat);

    for(int i=0; i<count_line; i++) {
        for(int j=0; j<line_vector_original[i].Get_length()-1; j++) {
            find_station(line_vector_original[i].Get_station(j).Get_Name(), count_stat, station_vector_originale).voisin(line_vector_original[i].Get_station(j+1),line_vector_original[i]);
        }
    }

    ifstream read_station_retard;
    read_station_retard.open("stations_retard.data");
    if(read_station_retard.is_open()) //Commencer a lire les station
    {
        //read_retard_station(read_station_retard, line_vector_original, station_vector_originale, count_stat);
        read_station_retard.close();
        //cout<<"retard station bien lu!"<<endl;
    }
    ifstream read_line_retard;
    read_line_retard.open("ligne_retard.data");
    if(read_line_retard.is_open())
    {
        //read_retard_ligne(read_line_retard,line_vector_original,station_vector_originale, count_stat);
        read_line_retard.close();
        //cout<<"retard line bien lu!"<<endl;
    }

    cout<<"retard bien lu!"<<endl;

    if (Dijkstra (station_vector_originale, P, count_stat, start, dest)) {
        cout<<"path found: "<<endl;
        //P.print(start, dest, count_stat, station_vector_originale);
    } else {
        cout<<"can't find a path from "<<start<<" to "<<dest<<endl;
    }
    QString ans = P.QStringTrajet(start, dest, count_stat, station_vector_originale);
    return ans;
}

#endif // definition INITIALIZE_CPP
