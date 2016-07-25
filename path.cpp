#include "path.h"
#define Time_MAX 10000
#include "station.h"

//Constructor for path
path::path(int N) {
    time = new double[N];
    for (int i=0; i<N; i++)  time[i] = Time_MAX;
    previous = new int[N];
    line = new string[N];
}

//Getter for the time of the i-th element
double path::read_time (int i) const {
    return time[i];
}

//Getter for the time of the i-th element
double& path::change_time (int i) {
    return time[i];
}

//Getter for the i-th previous element of the path
int& path::change_pre (int i) {
    return previous[i];
}

//Getter for the i-th line used in the path
string path::read_line(int i) const {
    return line[i];
}

//Getter for the i-th line used in the path
string& path::change_line (int i) {
    return line[i];
}

//printer
void path::print (int start, int dest, int count_stat, vector<station>& S) {
    station T;
    T = find_station(dest, count_stat, S);
    T.print();
    cout<<"sur la ligne: "<<line[dest]<<endl;

    while (previous[dest] != start) {
        T = find_station(previous[dest],count_stat,S);
        T.print();
        dest = previous[dest];
    }

    T = find_station(start, count_stat, S);
    T.print();
    cout<<"sur la ligne: "<<line[start]<<endl;
}

//Return html code for the output text
QString path::QStringTrajet (int start, int dest, int count_stat, vector<station>& S) {
    QString outputText;
    outputText += "Temps de trajet: ";
    outputText += QString::number(time[dest]);
    outputText += "<br>";
    outputText += "Vous trouverez ci-dessous le chemin a suivre: <br>";
    station T;
    T = find_station(dest, count_stat, S);
    T.print();
    outputText += T.QStringStation();
    outputText += "sur la ligne: ";
    outputText += QString::fromUtf8(line[dest].c_str());
    outputText += "<br>";

    while (previous[dest] != start) {
        //find_station par numero;
        T = find_station(previous[dest],count_stat,S);
        outputText += T.QStringStation();
        outputText += "sur la ligne: ";
        string lineName = line[previous[dest]].c_str();
        outputText += QString::fromStdString(lineName);
        outputText += "<br>";

        //station.print();
        dest = previous[dest];
    }
    cout << "sortie de boucle" << endl;

    T = find_station(start, count_stat, S);
    outputText += T.QStringStation();
    outputText += "sur la ligne: ";
    outputText += QString::fromUtf8(line[start].c_str());
    outputText += "<br>";

    return outputText;
}

