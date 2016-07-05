#include <iostream>
#include "matrice.h"
#include "arc.h"
using namespace std;

/*
arc& arc::operator = (const arc & A)
{
    if(this==&A) return *this;
    fin = A.fin;
    N_ligne = A.N_ligne;
    tps = A.tps;
    return * this;

}
*/

int Get_ieme_station(int No, line ligne)
{
    int m ;
    for (int i=0; i<ligne.Get_length(); i++)
    {
        int g = ligne.Get_station(i).Get_No();
        if (g==No)
        {
            m=i;
            return m;
        }
        else m = 0 ;
    }
    if (m==0)
    {
        cout << "La station n'est pas sur cette ligne" << endl;
        return -1;
    }
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
void arc::print()
{
    cout << "Entree en print de l'arc" << endl;
    string lili = N_ligne.Get_line_number();
    int valeur = Get_ieme_station(fin, N_ligne);
    string stasta = N_ligne.Get_station(valeur).Get_Name();
    string stasta1 = N_ligne.Get_station(valeur-1).Get_Name();

    cout<<"Arc créé de "<<stasta1<<" vers "<<stasta<<" avec la ligne "<<lili<<" de durée "<<tps<<endl;
    return;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------

int arc::Get_Fin() const
{
    return fin;
}

/*
line arc::Get_N_ligne() const
{
    return N_ligne;
}
*/
int arc::Get_line_ordre()
{
    return N_ligne.Get_line_ordre();
}
double arc::Get_Temps() const
{
    return tps;
}
double& arc::Change_Temps()
{
    return tps;
}
string arc::Get_line_number()
{
    return N_ligne.Get_line_number();
}
