#include <vector>
#include "path.h"
#include "station.h"
#define Time_MAX 10000
//fonctions concernant l'algorithme Dijkastra
//La fonction find_pos est pour trouver le nombre ordinal d'une station dans le vecteur Q
int find_pos (vector<int>& Q, int min_pos)
{
    for (unsigned i=0; i<Q.size(); i++)
    {
        if (Q[i] == min_pos) return i;
    }
    cout<<"cannot find this station"<<endl;
    return -1;
}

//La fonction find_time_min est pour trouver le temps minimale à atteindre parmi toutes les stations restants dans Q
int find_time_min (vector<int>& Q,const chemin& P)
{
    int min = Time_MAX;
    int min_pos = -1;
    for (unsigned i=0; i<Q.size(); i++) {
        if (P.read_time(Q[i])<=min) {
            min = P.read_time(Q[i]);
            min_pos = Q[i];
        }
    }
    Q.erase(Q.begin()+find_pos(Q,min_pos));
    return min_pos;
}

//L'algorithme Dijkstra
bool Dijkastra (vector<station> S, chemin & P, int count_stat, int start, int dest)
{

    P.change_time(start) = 0;
    P.change_line(start) = "Depart";
    vector<int> Q;
    for (int i=0; i<count_stat; i++ )  Q.push_back(i);

    double Examine;
    while (!Q.empty())
    {
        int i = find_time_min(Q,P);
        if (P.read_time(i)==Time_MAX) break;
        if (i == dest)
        {
            start = dest;
            break;
        }
        for (unsigned j=0; j<Q.size(); j++)
        {

            Examine = S[i].Existence_arc(i,Q[j],P);
            if (Examine>0)
            {
                if (P.read_time(Q[j])>P.read_time(i)+Examine)

                {
                    P.change_time(Q[j]) = P.read_time(i)+Examine;
                    P.change_pre(Q[j]) = i;
                    P.change_line(Q[j]) = S[i].Ligne_Between(Q[j]);
                }
            }

        }
    }
    if (start != dest) return false;
    return true;
}
