///------------------------on n'en a pas besoin---------------------------------------------------------------
/*
#include<iostream>
#include<vector>
#include<string>
#include "station.h"

#include "ligne.h"
#include "reseau.h"

using namespace std;

void reseau::add_line(line ligne)
{
    dim++;
    lines.push_back(ligne);
}

void reseau::init_reseau(int const count_line)
{

    //cout << "Utilisation de l'initialisation réseau " << endl;
    for(int i=0; i<count_line; i++)
    {
        //cout << " i " <<i<<endl;
        //cout << "LA TAILLE DE LA LIGNE EST : " << lines[i].Get_list_stat().size() << endl;
        //cout << " " << endl;
        for(int j=0; j<lines[i].Get_length()-1; j++)
        {

            //cout << "Entree dans la double boucle " << j <<" ième station de la "<< i <<" ième ligne"<< endl;
            cout<<"lines["<<i<<"].Get_station("<<j<<"): ";
            lines[i].Get_station(j).print();
            lines[i].Get_station(j).voisin(lines[i].Get_station(j+1),lines[i]);
            //cout << "Le calcul du voisin a été fait" << endl;
        }
    }

}
*/
///------------------------on n'en a pas besoin---------------------------------------------------------------
