#include "station.h"
#include <list>
#include <string>
#include <vector>

using namespace std;

void line::init(string num, string name, int number)
{
    line_number = num;
    line_name = name;
    line_ordre = number;
}

void line::add_station (station& S)
{
    list_stat.push_back(S);
    //S.print();
    length++;
}

void line::delete_station (station& S)
{

    list_stat.erase(list_stat.end());
    length--;
    return ;
}

int line::Get_length () const
{
    return length;
}
station& line::Get_station (int i)
{
    return list_stat[i];
}
string line::Get_line_number()
{
    return line_number;
}
int line::Get_line_ordre()
{
    return line_ordre;
}
void line::print()
{
    cout<<line_name<<endl;
}
