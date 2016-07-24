#include <iostream>
#include "station.h"
#include "ligne.h"
///-----------------------------------------------------------------------------------------------------
#include "path.h"
///------------------------------------------------------------------------------------------------------
//#include "matrice.h"
using namespace std;

//Override = operator for station class
station& station::operator = (const station & S) { 
    if(this==&S) return *this;
    x = S.x;
    y = S.y;
    name = S.name;
    No = S.No;
    fils = S.fils;
    return * this;
}

//Simple print for station class
void station::print() {
    cout<<x<<" "<<y<<" "<<name<<" "<<No<<endl;
    return;
}

//Return a QString with the name of the station
QString station::QStringStation() {
    QString s;
    s = QString::fromUtf8(name.c_str());
    return s;
}

//Name getter
string station::Get_Name() const {
    return name;
}

//X position getter
int station::Get_Coorx() const {
    return x;
}

//Y position getter
int station::Get_Coory() const {
    return y;
}

//Id getter
int station::Get_No() const {
    return No;
}

//Add an arc to the possible arcs of this station
void station::voisin(station& T, line& ligne) {
    int i=T.Get_No();
    arc A(i, ligne,2.);
    //Add the A arc to the list of possible arcs from this station
    fils.push_back(A);
}

//Change time value of all arcs of a line
void station::change_voisin(station& T, line& ligne, int temps) {
    for (unsigned i=0; i<fils.size(); i++) {
        if (ligne.Get_line_ordre()==fils[i].Get_line_ordre()) {
            fils[i].Change_Temps() = temps;
        }
    }
}


//Station finder by name
station& find_station (string str,int count_stat, vector<station>& S)
{
    string tmp_name ="NULL";
    //cout<<"S:"<<S<<endl;
    for (int i=0; i<count_stat; i++) {
        tmp_name=S[i].Get_Name();
        //cout<<tmp_name<<endl;
        if (tmp_name==str) {
            return S[i];
        }
    }
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
