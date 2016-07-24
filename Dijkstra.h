#ifndef DIJKSTRA_INCLUDED
#define DIJKSTRA_INCLUDED
#include <vector>
#include "path.h"
#include "station.h"

int find_pos (vector<int>& , int );
int find_time_min (vector<int>& ,const path& );
bool Dijkstra (vector<station> , path& , int , int , int );


#endif // DIJKSTRA_INCLUDED
