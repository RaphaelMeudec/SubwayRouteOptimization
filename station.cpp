#include <iostream>
#include "station.h"
#include "ligne.h"
///-----------------------------------------------------------------------------------------------------
#include "path.h"
///------------------------------------------------------------------------------------------------------
//#include "matrice.h"
using namespace std;

station& station::operator = (const station & S)
{
    if(this==&S) return *this;
    x = S.x;
    y = S.y;
    name = S.name;
    No = S.No;
    fils = S.fils;
    return * this;
}

void station::print()
{
    cout<<x<<" "<<y<<" "<<name<<" "<<No<<endl;
    return;
}

QString station::QStringStation()
{
    QString s;
    //s += x + "";
    s += /*y + "" + */QString::fromUtf8(name.c_str()) + " " /*+ No + "."*/;
    return s;
}

string station::Get_Name() const
{
    return name;
}

int station::Get_Coorx() const
{
    return x;
}

int station::Get_Coory() const
{
    return y;
}

/*
string * station::Get_Line() const
{
    return lignes;
}
*/
void station::voisin(station& T, line& ligne)
{
    //cout << "Utilisation de la fonction voisin" << endl;
    int i=T.Get_No();
    //cout << "L'acces au numéro se fait" << endl;
    arc A(i, ligne,2.);
    //cout << "l'arc est initialisé" << endl;
    fils.push_back(A);
    //cout << "l'arc est ajouté a la liste" << endl;
    //A.print();
    //cout<<"station presente: ";
    //print();
    //cout<<"fils.size: "<<fils.size()<<endl;
    //cout<<"fils.fin: "<<i<<endl;
}
void station::change_voisin(station& T, line& ligne, int temps)
{
    for (unsigned i=0; i<fils.size(); i++)
    {
        if (ligne.Get_line_ordre()==fils[i].Get_line_ordre()) fils[i].Change_Temps() = temps;
    }
    return ;
}

int station::Get_No() const
{
    return No;
}

// cette fonction est pour trouver une station et la lier dans une ligne
station& find_station (string str,int count_stat, vector<station>& S)
{
    string tmp_name ="NULL";
    //cout<<"S:"<<S<<endl;
    for (int i=0; i<count_stat; i++)
    {
        tmp_name=S[i].Get_Name();
        //cout<<tmp_name<<endl;
        if (tmp_name==str) return S[i];
    }
    //cout<<endl;
    cout<<"Cannot find this station! Cannot initialise the lines!"<<endl<<"The Unfound name is: "<<str;
    return S[count_stat-1];
}

station& find_station (int number,int count_stat, vector<station>& S)
{
    //string tmp_name ="NULL";
    //cout<<"S:"<<S<<endl;
    int tmp_number = 0;
    for (int i=0; i<count_stat; i++)
    {
        tmp_number=S[i].Get_No();
        //cout<<tmp_name<<endl;
        if (tmp_number==number) return S[i];
    }
    //cout<<endl;
    //cout<<"Cannot find this station! Cannot initialise the lines!"<<endl<<"The Unfound name is: "<<str;
    return S[count_stat-1];
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
vector<arc> station::get_fils()
{
    return fils;
}
*/


double station::Existence_arc (int No1, int No2, chemin const P)
{
    for (unsigned k=0; k<fils.size(); k++)
    {
        if(No2==fils[k].Get_Fin())
        {
            if (P.read_line(No1)=="Depart")
            {
                return fils[k].Get_Temps();
            }

            else if(P.read_line(No1)==Ligne_Between(No2))
            {
                return fils[k].Get_Temps();
            }
            else
            {
                return fils[k].Get_Temps()+3;
            }

        }
    }
    return -1;
}


double station::Existence_arc (int No1)
{
    for (unsigned k=0; k<fils.size(); k++)
    {
        if(No1==fils[k].Get_Fin())
        {
            return fils[k].Get_Temps() ;
        }
    }
    return -1;
}

string station::Ligne_Between(int N)
{
    for (unsigned k=0; k<fils.size(); k++)
    {
        if (N==fils[k].Get_Fin()) return fils[k].Get_line_number();
    }
    return "Error!! Can't find the line!";

}

int searchStation(string s, vector<station> vect)
{
    for (int i=0; i<vect.size(); i++)
    {
        station tmp=vect[i];
        if (tmp.Get_Name() == s)
        {
            return tmp.Get_No();
        }
    }
    return -1;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
