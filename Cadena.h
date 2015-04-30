#ifndef __CADENA__H__
#define __CADENA__H__
using namespace std;


class Cadena {
public:
    Cadena(string , string , bool , map < char , int >);
    string getTipo();
    string getCadena();
    bool isComplete();
    map < char , int > getBases();
    void setTipo(string);
    void setCadena(string);
    vector < int > contarBases();
    int subCadenas(string , bool );
protected:
    string tipo;
    string cadena;
    bool complete;
    map < char , int > bases;
};

#include "Cadena.hxx"

#endif //
