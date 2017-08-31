#include "figura.hpp"
#include <iostream>
#include <string>

using namespace std;

figura::figura(){}

figura::figura(char* Nnombre, int Nvertices, list<vertice> NListaVertices, list< list <int> > NListaCaras, list<arista> lAristas)
{
    nombre = Nnombre;
    vertices = Nvertices;
    lVertices = NListaVertices;
    lCaras = NListaCaras;
    lAristas = lAristas;
}

char* figura::getNombre(){
    return this->nombre;
}

int figura::getVertices(){
    return this->vertices;
}

list <vertice> figura::getlVertices(){
    return this->lVertices;
}

list <list <int> > figura::getlCaras(){
    return this->lCaras;
}

list<arista> figura::getAristas(){
    return this->lAristas;
}

void figura::setNombre(char* Nnombre){
    this->nombre = Nnombre;
}

void figura::setVertices(int Nvertices){
    this->vertices = Nvertices;
}

void figura::setlVertices(list<vertice> NlistaVertices){
    this->lVertices = NlistaVertices;
}

void figura::setlCaras( list < list<int> > NlistaCaras){
    this->lCaras = NlistaCaras;
}

void figura::setAristas(list<arista> NlistaArista){
    this->lAristas=NlistaArista;
}

void figura::agregarVertice(vertice v)
{
    this->lVertices.push_back(v);
}

void figura::agregarArista(arista a)
{
    this->lAristas.push_back(a);
}

void figura::agregarCara(list<int> cara)
{
    this->lCaras.push_back(cara);
}
