/*
#include <iostream>
#include "matrice.h"
using namespace std;

int matrice_creuse::recherche_station(station S)
{
    //cout << "Utilisation de la fonction recherche_station" << endl;
    //cout << "La dimension de la matrice creuse est " << dim << endl;
    for (int i =0; i<dim; i++)
    {
        cout << "Entree en boucle, recherche station, la valeur de i est: " << i << endl;
        int tmp1=S.Get_No();
        cout << "tmp1 est bien définie et vaut"<< tmp1<< endl;
        station S =liste[i];
        cout << "La station test est bien définie" << endl;
        int tmp2=liste[i].Get_No();
        cout << "tmp2 est bien définie et vaut" <<tmp2<< endl;
        if (tmp1==tmp2)
        {
            return i;
        }
    }
    return -2;
}


void matrice_creuse::set_dimension(int i)
{
    dim=i;
}
vector<station> & matrice_creuse::get_liste()
{
    return liste;
}
void matrice_creuse::increase_dim()
{
    dim=dim+1;
}

int matrice_creuse::get_dim ()
{
    return dim;
}
*/
