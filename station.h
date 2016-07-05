 #ifndef STATION_H_INCLUDED
#define STATION_H_INCLUDED
#include<string>
#include <list>
#include<vector>
#include "ligne.h"
#include "arc.h"
#include "path.h"
#include <QString>
using namespace std;

class arc;
class chemin;

//------------- Création de la station de métro-----------------------------------------------------------
class station
{

private:
    string name;      // Nom de la station ( ex:"Abbesses" )
    int x,y;          // Coordonnées GPS de la station
    int No;           // On numérote toutes les stations du fichier stations.data ( 1,2,3, .....)
                      // Chaque station est donc identifiée par un entier
    vector<arc> fils; // Vecteur des arcs qui partent de cette station

public:
    station (int coor1=0, int coor2=0, string S="NULL", int num=0) // Constructeur
    {
        x = coor1;
        y = coor2;
        name = S;
        No=num;
    }
    string Get_Name() const;                   // Retourne le nom de la station courante
    int Get_Coorx() const;                     // Retourne la  coordonnée x
    int Get_Coory() const;                     // Retourne la coordonnée y
    int Get_No() const;                        // Retourne le numéro qui caractérise la station
    station& operator = (const station &S );   // Opérateur = pour une station
    void voisin(station& T, line& ligne);      // Ajout d'un arc entre deux stations qui se suivent sur une ligne
    void change_voisin(station& , line&, int); // Change le temps lorsque nécessaire ( ex : retard, ...)
    void print();                              // Affiche coordonnées, nom, numéro de la station
    QString QStringStation();                  // Récupère l'équivalent du print en QString
    double Existence_arc (int No1);            // Retourne le temps entre deux stations s'il existe un arc, retourne -1 sinon
    double Existence_arc (int , int , chemin );
    string Ligne_Between (int No);             // Retourne le nom de la ligne s'il existe un arc entre deux stations
    vector<arc> get_fils();                    // Retourne le vecteur des arc de la station
};
//--------------------------------------------------------------------------------------------------------------------


station& find_station (string ,int , vector<station>& ); // Trouver une station par son nom
station& find_station (int , int , vector<station>& );   // Trouver une station par son numéro No
int searchStation(string s, vector<station> vect); // Cherche une station à partir de son nom, et renvoie son numéro

#endif


