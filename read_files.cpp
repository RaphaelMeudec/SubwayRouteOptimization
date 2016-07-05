#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "station.h"
#include "ligne.h"
#include "ligne.h"

//la fonction suivante est pour lire le fichier des stations
void in_stat (ifstream& file,vector<station>& S, int& N)
{
    int x,y;
    string name;
    string aline;
    while (!file.eof())
    {
        file>>x>>y;  //lire les coordonnees
        getline (file,aline); //lire son nom
        name = aline.erase (0,1);
        station temp(x,y,name,N); //initialiser une station S
        //temp.print();
        S.push_back(temp);
        N++;
        //cout<<"N: "<<N<<endl;
    }
}

//la fonction suivante est pour lire le fichier des lignes
void in_line(ifstream &file, vector<line>& L,int& N,int const count_stat,vector<station>& S)
{
    string str;
    char c;
    string line_num; // Comme 1-a
    string line_name; //Comme A-B
    string station_name; //Nom d'une station en ligne
    string aline;

    while(!file.eof())
    {
        file>>c;
        if (c=='#')  // S'il indique le nom de la ligne
        {
            getline (file,aline);
            size_t first = aline.find(' ');
            size_t middle = aline.find(':');
            size_t last = aline.rfind('\n');
            line_num = aline.substr(first, middle-first);
            line_name = aline.substr(middle+1, last-middle);
            line temp_line;
            temp_line.init(line_num, line_name, N);
            L.push_back(temp_line);
            //L[N].init(line_num, line_name, N);
            N++;
            //cout<<"N of line: "<<N<<endl;

        }
        else // S'il montre les stations
        {
            getline(file, aline);
            size_t middle = aline.find(':');
            size_t last = aline.rfind('\n');
            station_name = aline.substr(middle+1, last-middle);
            L[N-1].add_station(find_station(station_name, count_stat, S)); //Ajouter une station dans une ligne
            //cout<<"station well added"<<endl;
        }
        //cout<<"is that good here?"<<endl;
    }
    L[N-1].delete_station(find_station(station_name,count_stat, S));
    return ;
}

//la fonction suivante est pour creer le fichier "retard" des stations
void write_retard_station(ostream& file, int count_stat, int count_line,vector<line> L)
{
    srand (time(NULL));
    int num = rand() % count_stat + 1;  //determiner le nombre de stations qui sont en retard; le nombre doit etre moins que le nombre de station
    //cout<<"num: "<<num<<endl;
    file<<num<<endl;
    //cout<<"count_line: "<<count_line<<endl;
    for (int i=0; i<num; i++ )
    {
        int ligne = rand() % count_line; //determiner elle est dans quelle ligne
        file<<ligne<<" ";
        //cout<<"ligne: "<<ligne<<endl;
        //cout<<"L[ligne].Get_length()-1 "<<L[ligne].Get_length()-1<<endl;
        int num_station = rand() % (L[ligne].Get_length()-1); //determiner quelles stations sont en retard, sauf la derniere station
        file<<num_station<<" ";
        //cout<<"num_station: "<<num_station<<endl;
        int retard_station = rand() % 27 +3; // le temps de retard, moins de 30 minutes
        file<<retard_station<<endl;
        //cout<<"retard_station: "<<retard_station<<endl;
    }
    //cout<<"retard de station terminé"<<endl;
    return ;
}

void read_retard_station(ifstream& file, vector<line>& L, vector<station>& S, int const N)
{
    int num;
    file>>num;
    int ligne, num_station, retard_station;
    for (int i=0; i<num; i++)
    {
        file>>ligne>>num_station>>retard_station;
        find_station(L[ligne].Get_station(num_station).Get_Name(), N, S).change_voisin(L[ligne].Get_station(num_station+1),L[ligne],retard_station);
    }
    return ;
}


//la fonction suivante est pour creer le fichier "retard" des lignes
void write_retard_ligne(ostream& file, int count_line)
{
    srand(time(NULL));
    int num = rand() % count_line +1; //nombre de ligne qui sont en retard
    file<<num<<endl;
    for ( int i=0; i<num; i++ )
    {
        int ligne = rand() % count_line;
        file<<ligne<<endl;
    }
    return ;
}

void read_retard_ligne(ifstream& file, vector<line>& L, vector<station>& S, int const N)
{
    int num;
    file>>num;
    //cout<<"num de retard: "<<num<<endl;
    int ligne;
    for (int i=0; i<num; i++)
    {
        file>>ligne;
        //cout<<"sur "<<ligne<<" eme ligne"<<endl;
        for (int j=0; j<L[ligne].Get_length()-1; j++)
        {
            //cout<<"L[ligne].Get_station(j).Get_Name(): "<<L[ligne].Get_station(j).Get_Name()<<endl;
            find_station(L[ligne].Get_station(j).Get_Name(), N, S).change_voisin(L[ligne].Get_station(j+1),L[ligne],-1);
        }
    }
    return;
}
