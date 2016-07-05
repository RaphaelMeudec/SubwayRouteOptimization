#ifndef READ_FILES_INCLUDED
#define READ_FILES_INCLUDED
#include <iostream>
#include <vector>
#include "station.h"
#include "ligne.h"

void in_stat (ifstream& ,vector<station>& , int& );
void in_line(ifstream &, vector<line>& ,int& ,int const ,vector<station>& );
void write_retard_station(ostream& , int , int ,vector<line> );
void read_retard_station(ifstream& , vector<line>& , vector<station>& , int const );
void write_retard_ligne(ostream& , int );
void read_retard_ligne(ifstream& , vector<line>& , vector<station>& , int const );


#endif // READ_FILES_INCLUDED
