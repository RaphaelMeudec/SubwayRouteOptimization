#include "path.h"
#define Time_MAX 10000
#include "station.h"
chemin::chemin(int N)
{
    time = new double[N];
    for (int i=0; i<N; i++)  time[i] = Time_MAX;
    previous = new int[N];
    line = new string[N];
}

double chemin::read_time (int i) const
{
    return time[i];
}

double& chemin::change_time (int i)
{
    return time[i];
}

int& chemin::change_pre (int i)
{
    return previous[i];
}
string chemin::read_line(int i) const
{
    return line[i];
}
string& chemin::change_line (int i)
{
    return line[i];
}
void chemin::print (int start, int dest, int count_stat, vector<station>& S)
{
    station T;
    T = find_station(dest, count_stat, S);
    T.print();
    cout<<"sur la ligne: "<<line[dest]<<endl;

    while (previous[dest] != start)
    {
        //find_station par numero;
        T = find_station(previous[dest],count_stat,S);
        T.print();
        dest = previous[dest];
    }

    T = find_station(start, count_stat, S);
    T.print();
    cout<<"sur la ligne: "<<line[start]<<endl;

    return ;
}

QString chemin::QStringTrajet (int start, int dest, int count_stat, vector<station>& S)
{
    QString s;
    s += "Temps de trajet: ";
    s += QString::number(time[dest]);
    s += "<br>";
    s += "Vous trouverez ci-dessous le chemin a suivre: <br>";
    station T;
    T = find_station(dest, count_stat, S);
    T.print();
    s += T.QStringStation();
    s += "sur la ligne: ";
    s += QString::fromUtf8(line[dest].c_str());
    s += "<br>";

    while (previous[dest] != start)
    {
        //find_station par numero;
        T = find_station(previous[dest],count_stat,S);
        s += T.QStringStation();
        s += "sur la ligne: ";
        string tmp = line[previous[dest]].c_str();
        s += QString::fromUtf8(line[previous[dest]].c_str());
        s += "<br>";

        //station.print();
        dest = previous[dest];
    }
    cout << "sortie de boucle" << endl;

    T = find_station(start, count_stat, S);
    s += T.QStringStation();
    s += "sur la ligne: ";
    s += QString::fromUtf8(line[start].c_str());
    s += "<br>";

    return s;
}

