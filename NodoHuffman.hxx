#ifndef NodoHuffman_HXX_INCLUDED
#define NodoHuffman_HXX_INCLUDED

NodoHuffman::NodoHuffman()
{

}

NodoHuffman::~NodoHuffman()
{

}

NodoHuffman::NodoHuffman(unsigned long long int f,char d)
{
    frecuencia = f;
    caracter = d;
    izq = NULL;
    der = NULL;
}

NodoHuffman* NodoHuffman::crearPadre(NodoHuffman* nIzq, NodoHuffman* nDer)
{
    NodoHuffman* padre = new NodoHuffman((nDer->frecuencia + nIzq->frecuencia),'@');
    padre->setDerecha(nDer);
    padre->setIzquierda(nIzq);
    return padre;
}

void NodoHuffman::setFrecuencia(unsigned long long int f)
{
    frecuencia = f;
}

unsigned long long int NodoHuffman::getFrecuencia()
{
    return frecuencia;
}

void NodoHuffman::setCaracter(char c)
{
    caracter = c;
}

char NodoHuffman::getCaracter()
{
    return caracter;
}

NodoHuffman* NodoHuffman::getDerecha()
{
    return der;
}


NodoHuffman* NodoHuffman::getIzquierda()
{
    return izq;
}


void NodoHuffman::setDerecha(NodoHuffman* nderecha)
{
    der = nderecha;
}


void NodoHuffman::setIzquierda(NodoHuffman* nizquierda)
{
    izq = nizquierda;
}

string NodoHuffman::buscar(char c)
{
/*    if(c != '@')
    {
        if(izq != NULL)
        {

        }
        return true;
    }
    else
    {
        return;
    }*/
}

#endif // NodoHuffman_HXX_INCLUDED

