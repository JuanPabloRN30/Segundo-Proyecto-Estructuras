#ifndef ArbolHuffman_HXX_INCLUDED
#define ArbolHuffman_HXX_INCLUDED

ArbolHuffman::ArbolHuffman()
{

}

ArbolHuffman::ArbolHuffman(NodoHuffman* nraiz)
{
    raiz = nraiz;
}

ArbolHuffman::~ArbolHuffman()
{

}

NodoHuffman* ArbolHuffman::getRaiz()
{
    return raiz;
}

void ArbolHuffman::setRaiz(NodoHuffman* nraiz)
{
    raiz = nraiz;
}

void ArbolHuffman::inOrden(NodoHuffman* inicio)
{
    if(inicio == NULL)
        return;
    else
    {
        inOrden(inicio->getIzquierda());
//        cout << inicio->getDato() << " ";
        inOrden(inicio->getDerecha());
    }
}


void ArbolHuffman::preOrden(NodoHuffman* inicio)
{
    if(inicio == NULL)
    {
        return;
    }
    else
    {
 //       cout << inicio->getDato() << " ";
        preOrden(inicio->getIzquierda());
        preOrden(inicio->getDerecha());
    }
}

void ArbolHuffman::posOrden(NodoHuffman* inicio)
{
    if(inicio == NULL)
        return;
    else
    {
        posOrden(inicio->getIzquierda());
        posOrden(inicio->getDerecha());
    //    cout << inicio->getDato() << " ";
    }
}


void ArbolHuffman::nivelOrden(NodoHuffman* inicio)
{
    queue< NodoHuffman* > cola;
    cola.push(inicio);
    while(!cola.empty())
    {
       // cout << cola.front()->getDato() << " ";
        if(cola.front()->getIzquierda() != NULL)
            cola.push(cola.front()->getIzquierda());
        if(cola.front()->getDerecha() != NULL)
            cola.push(cola.front()->getDerecha());

        cola.pop();
    }
}

#endif // ARBOLBINARIO_HXX_INCLUDED

