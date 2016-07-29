#include <vector>
#include "path.h"
#include "station.h"
#define Time_MAX 10000
//functions for Dijkstra's algorithm

//Return the position of an int value in a vector<int>
int find_pos (vector<int>& Q, int min_pos) {
    for (unsigned i=0; i<Q.size(); i++) {
        if (Q[i] == min_pos) {
            return i;
        }
    }
    cout<<"cannot find this station"<<endl;
    return -1;
}

//Return the id of the closest station in Q
int find_time_min (vector<int>& Q, const path& P) {
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

//Dijkstra algorithm
bool Dijkstra (vector<station> S, path& P, int count_stat, int start, int dest) {
    P.change_time(start) = 0;
    P.change_line(start) = "Depart";

    vector<int> remainingStations;
    //Adding all stations to the vector of stations to test
    for (int i=0; i<count_stat; i++ ) {
        remainingStations.push_back(i);
    }

    double Examine;
    while (!remainingStations.empty()) {
        int i = find_time_min(remainingStations,P);
        if (P.read_time(i)==Time_MAX) {
            break;
        }
        if (i == dest) {
            start = dest;
            break;
        }
        for (unsigned j=0; j<remainingStations.size(); j++) {
            Examine = S[i].Existence_arc(i,Q[j],P);
            if (Examine>0) {
                if (P.read_time(remainingStations[j])>P.read_time(i)+Examine) {
                    P.change_time(remainingStations[j]) = P.read_time(i)+Examine;
                    P.change_pre(remainingStations[j]) = i;
                    P.change_line(remainingStations[j]) = S[i].Ligne_Between(remainingStations[j]);
                }
            }
        }
    }
    if (start != dest) {
        return false;
    }
    return true;
}
