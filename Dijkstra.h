#ifndef DIJKASTRA_INCLUDED
#define DIJKASTRA_INCLUDED
#include <vector>
#include "path.h"
#include "station.h"

int find_pos (vector<int>& , int );
int find_time_min (vector<int>& ,const chemin& );
bool Dijkastra (vector<station> , chemin & , int , int , int );


#endif // DIJKASTRA_INCLUDED
