#ifndef ARC_H_INCLUDED
#define ARC_H_INCLUDED
#include<iostream>
#include<vector>
#include<string>
#include "station.h"
#include "ligne.h"
using namespace std;

class station;

//------------- Création de la class arc entre deux stations ---------------------------------------------------
class arc
{
private:
    int fin;          // No de la station d'arrivée de l'arc
    line N_ligne;     // Ligne utilisée pour parcourir l'arc
    double tps ;      // Temps pour parcourir l'arc

public:
    arc (int arrivee, line n_ligne, double temps) //constructeur
    {
        fin = arrivee;
        N_ligne = n_ligne;
        tps = temps;
    }

    int Get_Fin() const;
    double Get_Temps() const;
    double & Change_Temps() ;
    int Get_line_ordre();
    string Get_line_number();
    void print();
};
//-----------------------------------------------------------------------------------------------------------------
#endif
