#ifndef __FIGURA_HPP__
#define __FIGURA_HPP__

#include <iostream>
#include <list>
#include "vertice.hpp"
#include "aristas.hpp"
using namespace std;
class figura{
private:

    char* nombre;

    int vertices;

    list<vertice> lVertices;

    list< list <int> > lCaras;

    list<arista> lAristas;

public:

    figura();

    figura(char* Nnombre, int Nvertices, list<vertice> NListaVertices, list< list <int> > NListaCaras, list<arista> lAristas);

    char* getNombre();

    int getVertices();

    list<vertice> getlVertices();

    list<list<int> > getlCaras();

    list<arista> getAristas();

    void setNombre(char* Nnombre);

    void setVertices(int Nvertices);

    void setlVertices(list<vertice> NlistaVertices);

    void setlCaras( list< list<int> > NlistaCaras);

    void setAristas(list <arista> NlistaAristas);

    void agregarVertice(vertice v);

    void agregarArista(arista a);

    void agregarCara(list<int> cara);
};


#endif // __FIGURA_HPP__
