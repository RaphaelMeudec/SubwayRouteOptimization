




///------------------------on n'en a pas besoin---------------------------------------------------------------
/*
#ifndef reseau_H_INCLUDED
#define reseau_H_INCLUDED
#include<iostream>
#include<vector>
#include<string>
#include "station.h"
#include "ligne.h"

using namespace std;

class reseau
{
private:
    int dim;
    vector<line> lines;
public:
    reseau(int dimension, vector<line>& lignes)
    {
        dim = dimension;
        lines = lignes;
        for (unsigned i=0;i<lignes.size();i++ )
        {
            lines[i] = lignes[i];
        }
        cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
        for (unsigned i=0;i<lines.size();i++ )
        {
            cout<<"je suis lines!!!!: ";
            lines[i].print();
        }
        cout << "Le réseau a bien été initilialisé" << endl;
    }
    void add_line(line ligne) ;
//----------------------- à modifier--------------------------------------------------------------------------------------------------

    void init_reseau(int const count_line);

};


#endif // Reseau_H
*/
///------------------------on n'en a pas besoin---------------------------------------------------------------
