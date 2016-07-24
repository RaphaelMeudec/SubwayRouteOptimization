#include <iostream>
#include "matrice.h"
#include "arc.h"
using namespace std;

//Return the position of the station in the line
int Get_ieme_station(int No, line ligne) {
    int m ;
    for (int i=0; i<ligne.Get_length(); i++)
    {
        int g = ligne.Get_station(i).Get_No();
        if (g==No) {
            m=i;
            return m;
        } else {
            m = 0 ;
        }
    }
    if (m==0) {
        cout << "La station n'est pas sur cette ligne" << endl;
        return -1;
    }
}

//printer
void arc::print() {
    cout << "Entree en print de l'arc" << endl;
    string ligneName = N_ligne.Get_line_number();
    int stationPosition = Get_ieme_station(fin, N_ligne);
    string stationOne = N_ligne.Get_station(stationPosition).Get_Name();
    string stationTwo = N_ligne.Get_station(stationPosition-1).Get_Name();

    cout<<"Arc créé de "<<stationOne<<" vers "<<stationTwo<<" avec la ligne "<<ligneName<<" de durée "<<tps<<endl;
}

//Getter of the final station of the arc
int arc::Get_Fin() const {
    return fin;
}

//Getter for the id of the line used by the arc
int arc::Get_line_ordre() {
    return N_ligne.Get_line_ordre();
}

//Getter for the time of travel
double arc::Get_Temps() const {
    return tps;
}

//Setter for the time of travel
double& arc::Change_Temps() {
    return tps;
}

//Getter for the name of the line used by the arc
string arc::Get_line_number() {
    return N_ligne.Get_line_number();
}
