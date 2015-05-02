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
        cout << inicio->caracter << " ";
        preOrden(inicio->izq);
        preOrden(inicio->der);
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
    queue< NodoHuffman* > currentLevel,nextLevel;
    currentLevel.push(inicio);
    while(!currentLevel.empty())
    {
	NodoHuffman* current = currentLevel.front();
	cout << current->caracter << "\t\t";
        currentLevel.pop();
        if(current->getIzquierda() != NULL)
            nextLevel.push(current->getIzquierda());
        if(current->getDerecha() != NULL)
            nextLevel.push(current->getDerecha());
	if(currentLevel.empty())
	{
	   cout << endl;
	   swap(currentLevel,nextLevel);
	}

    }
}

void ArbolHuffman::PrintAsPNG( const string& filename ) const
{
  stringstream str;
  str << "echo \"digraph G{";
  if( this->raiz != NULL )
  {
    if( this->raiz->IsLeaf( ) )
      str << this->raiz->caracter << " ";
    else
      str << this->raiz->PrintAsPNG( );

  }
  str << "}\" | dot -Tpng > " << filename;
  system( str.str( ).c_str( ) );
}

#endif // ARBOLBINARIO_HXX_INCLUDED

