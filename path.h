#ifndef PATH_H_INCLUDED
#define PATH_H_INCLUDED
#include <list>
#include <string>
#include "station.h"
#include <QString>

//------------- Création de la class chemin dans un graphe-------------------------------------------------------
class chemin
{

private:
    int *previous;   // Pointeur sur un tableau dans lequel on stocke la station précedente pour atteindre la station courante
    double *time;       // Pointeur sur un tableau dans lequel on stocke le temps le plus court pour atteindre la station courante
    string *line;    // Pointeur sur un tableau dans lequel on stocke le nom de la ligne ( par ex: "3-a" )

public:
    chemin (int N);             // Constructeur des trois tableaux
    double read_time (int ) const; // Retourne le temps pour atteindre la station courante
    double& change_time (int );    // Retourne la référence du temps pour atteindre la station courante
    int& change_pre (int );     // Retourne la référence numéro de la station precedente
    string& change_line(int );  // Retourne la référence du nom de la ligne
    string read_line(int ) const;
    void print (int start, int dest, int count_stat, vector<station>& S); // Imprimer un chemin (départ, arrivée, stations)
    QString QStringTrajet (int start, int dest, int count_stat, vector<station>& S); // Retourne un QString avec les indications
};
//--------------------------------------------------------------------------------------------------------------------

#endif
