// constructor
CodigoGenetico::CodigoGenetico()
{
}

vector < Cadena > CodigoGenetico::getListaCadenas()
{
    return listaCadenas;
}

map < char , int > CodigoGenetico::getBasesTotales()
{
    return basesTotales;
}

bool CodigoGenetico::cargarDatos(string nombreArchivo)
{
    ifstream entrada;
    ofstream salida;
    bool bandera = false;
    entrada.open(nombreArchivo.c_str(),ios::in);
    if(!entrada)
        return false;
    string tipo;
    getline(entrada,tipo);
    map < char , int > mapa;
    while(!entrada.eof() && !bandera)
    {
        string cadena,cadTot;
        cadena = cadTot = "";
        while(cadena[0] != '>' && !bandera)
        {
            cadTot+= cadena;
            getline(entrada,cadena);
            if(cadena[0] != '>')
                cadena+='\n';
            if(entrada.eof())
                bandera = true;

        }
        bool bandera = true;
        for(int j = 0 ; j < cadTot.size(); j++)
        {
            mapa[cadTot[j]]++;
            basesTotales[cadTot[j]]++;
            if(cadTot[j] == '-')
            {
                bandera = false;
            }

        }
        Cadena cad(tipo.substr(1,tipo.size()-1),cadTot,bandera,mapa);
        listaCadenas.push_back(cad);
        tipo = cadena;
//        tipo = tipo + '\n';
    }
    entrada.close();
    return true;
}

int CodigoGenetico::contarSecuencias()
{
    return listaCadenas.size();
}

ArbolHuffman* CodigoGenetico::generarArbol()
{
    priority_queue<NodoHuffman*, vector<NodoHuffman*>, CompareNode > pq;
    map<char,int >::iterator it;
    for(it = basesTotales.begin() ; it != basesTotales.end() ; it++)
    {
        pq.push(new NodoHuffman(it->second,it->first));
    }
    if(pq.size() != 1)
    {
        while(pq.size() != 2)
        {
            NodoHuffman* padre;
            padre->izq = pq.top();
            pq.pop();
            padre->der = pq.top();
            pq.pop();
            pq.push(padre);
        }
        NodoHuffman* padre;
        padre->izq = pq.top();
        pq.pop();
        padre->der = pq.top();
        pq.pop();
        ArbolHuffman* arbol = new ArbolHuffman(padre);
        return arbol;
    }
    else
    {
        return NULL;
    }
}

void CodigoGenetico::listaSecuencias()
{
    ofstream salida("prueba.fa");
    for(int i = 0 ; i < contarSecuencias() ; i++)
    {
        Cadena c = listaCadenas[i];
        string tipo = c.getTipo();
        int cantBases = c.getCadena().size();
        printf("Secuencia: %s",tipo.c_str());
        salida << tipo;
        if(c.isComplete())
            printf(" tiene %d bases\n",cantBases);
        else
            printf(" tiene al menos %d bases\n",cantBases);
    }
}

Cadena* CodigoGenetico::buscarCadena(string descripcion)
{
    Cadena* cad = NULL;
    for(int i = 0 ; i < contarSecuencias() ; i++)
    {
        if(listaCadenas[i].getTipo() == descripcion)
        {
            cad = new Cadena(listaCadenas[i].getTipo(),listaCadenas[i].getCadena(),listaCadenas[i].isComplete(),listaCadenas[i].getBases());
        }
    }
    return cad;

}

bool CodigoGenetico::guardarDatos(string nombreArchivo)
{
    ofstream salida;
    salida.open(nombreArchivo.c_str(),ios::out);
    for(int i = 0 ; i < listaCadenas.size() ; i++)
    {
        salida << ">" << listaCadenas[i].getTipo().c_str() << endl;
        salida << listaCadenas[i].getCadena().c_str();
    }
    if(salida.fail())
        return false;
    else
        return true;
}

void CodigoGenetico::mostrarHistograma(string descripcion)
{
    Cadena* cadena = buscarCadena(descripcion);
    if(cadena == NULL)
        cout << "Secuencia invalida" << endl;
    else
    {
        vector < char > bases = ingresarBases();
        for(int i = 0 ; i < bases.size() ; i++)
        {
            printf("%5c : %5d\n",bases[i],cadena->getBases().find(bases[i])->second);
        }

    }
}

int CodigoGenetico::subCadenas(string subCadena, bool bandera)
{
    int cant = 0;
    for(int i = 0 ; i < listaCadenas.size() ; i++)
        cant += listaCadenas[i].subCadenas(subCadena, bandera);

    return cant;
}
