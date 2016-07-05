#ifndef LIGNE_H_INCLUDED
#define LIGNE_H_INCLUDED
#include "station.h"
#include <list>
#include <string>
#include <vector>

using namespace std;

class station;

//------------- Création de la class ligne de métro ---------------------------------------------------
class line
{
 private:
    string line_number;          // Numéro d'une ligne de métro, ( ex :"3-a" )
    string line_name;            // Nom de la ligne ( ex : "La Défense -- Château de Vincennes" )
    int line_ordre;              // On numérote les lignes ( 1,2 ...etc. Ne correspond pas au num de la ligne)
    vector <station> list_stat;  // Vecteur contenant les stations de la ligne
    int length;                  // Longueur de la ligne ( nombre de stations )

 public:
    line (string num="0-0", string name="NULL")  //Constructeur
    {
        line_number = num;
        line_name = name;
        line_ordre = 0;
        length=0;
    }
    void init(string , string , int );  //Initialiser une ligne avec son numéro, son nom et son nombre ordinal
    void add_station (station& S);      //Ajouter une station à la fin d'une ligne
    void delete_station (station& S);   //Supprimer une station à la fin d'une ligne
    int Get_length () const ;           //Retourne la longueur d'une ligne
    station & Get_station (int i);      //Retourne la i_ième station de la ligne
    string Get_line_number();           //Retourne le numéro de cette ligne
    int Get_line_ordre();               //Retourne le nombre ordinal de cette ligne
    void print();
};
//-----------------------------------------------------------------------------------------------------------------
#endif
