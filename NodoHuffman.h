//Nodo Binario ord.h

#ifndef NODOHUFFMAN_H_INCLUDED
#define NODOHUFFMAN_H_INCLUDED

using namespace std;

class NodoHuffman
{
public:
    unsigned long long int frecuencia;
    char caracter;
    NodoHuffman*  der;
    NodoHuffman*  izq;

    NodoHuffman();
    ~NodoHuffman();
    NodoHuffman(unsigned long long int f,char d);
    NodoHuffman* crearPadre(NodoHuffman* nIzq, NodoHuffman* nDer);
    void setFrecuencia(unsigned long long int );
    unsigned long long int getFrecuencia();
    void setCaracter(char );
    char getCaracter();
    NodoHuffman* getDerecha();
    NodoHuffman* getIzquierda();
    void setDerecha(NodoHuffman* nderecha);
    void setIzquierda(NodoHuffman* nizquierda);
    string buscar(char n);
};

#include "NodoHuffman.hxx"


#endif // NODOHUFFMAN_H_INCLUDED

