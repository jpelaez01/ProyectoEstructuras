#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <list>
#include <stdlib.h>
#include <iterator>
#include "figura.hpp"

using namespace std;

list<figura> cargarArchivo(char nombreArchivo [], list<figura> lFiguras );
bool confirmarArista(arista ar, list<arista> lAristas);
void descargar(char* nombre);
void listado(list<figura> lFiguras);
int main()
{

    list<figura> lFiguras;
    lFiguras = cargarArchivo("mesh_0.txt",lFiguras);
    listado(lFiguras);
    return 0;
}

list<figura> cargarArchivo(char nombreArchivo [], list<figura> lFiguras )
{
    string auxLinea;
    char linea[50];
    int vertices, tamCara;
    ifstream file(nombreArchivo);
    char separador[4] = " \n\t";
    figura fig;
    if(file.is_open())
    {
        file.getline(linea,50,'\n');
        int caras;
        fig.setNombre(strtok(linea, separador));
        file.getline(linea,50,'\n');
        fig.setVertices(atoi(strtok(linea, separador)) );
        bool yaEsta=false;
        for(int i=0; i<fig.getVertices(); i++)
        {
            vertice v(-1,-1,-1);
            file.getline(linea,50,'\n');
            v.setVerticeX( atoi(strtok(linea, separador)) );
            v.setVerticeY(atoi(strtok(NULL, separador)));
            v.setVerticeZ(atoi(strtok(NULL, separador)));
            fig.agregarVertice(v);
        }
        file.getline(linea,50,'\n');
        caras = atoi(strtok(linea, separador));
        while(caras != -1)
        {
            list<int> cara;
            for(int i=0; i<caras; i++)
            {
                int num = atoi(strtok(NULL, separador));
                cara.push_back(num);
            }
            fig.agregarCara(cara);
            file.getline(linea,50,'\n');
            caras = atoi(strtok(linea, separador));
        }
        //agregar aristas
        list<figura>::iterator it = lFiguras.begin();
        for(; it!=lFiguras.end(); it++)
        {
            if((*it).getNombre() == fig.getNombre())
                yaEsta=true;
        }
        if(yaEsta)
            cout<<"El Objeto ya existe";
        else
        {
            lFiguras.push_front(fig);
            cout<<"el objeto "<<fig.getNombre()<<" ha sido cargado";
            list<list<int> >::iterator itC = fig.getlCaras().begin();
            list<arista> lAristas;
            for(; itC != fig.getlCaras().end(); itC++)
            {
                list<int>::iterator itV = (*itC).begin();
                for(; itV != (*itC).end(); itV++)
                {
                    arista nueva;
                    list<int>::iterator itV2 = itV;
                    for(; itV2 !=(*itC).end(); itV2++)
                    {
                        nueva.setPuntoX((*itV));
                        nueva.setPuntoY((*itV2));
                        if(!confirmarArista(nueva, fig.getAristas()) )
                        {
                            fig.agregarArista(nueva);
                        }
                    }
                }
            }
        }
    }
    else
    {
        cout<< "\nEl archivo no existe";
    }
    return lFiguras;
}

bool confirmarArista(arista ar, list<arista> lAristas)
{
    list<arista>::iterator it = lAristas.begin();
    for(; it!= lAristas.end(); it++)
    {
        if (ar.getPuntoX()==(*it).getPuntoX() && ar.getPuntoY() == (*it).getPuntoY())
            return true;
        else if(ar.getPuntoY()==(*it).getPuntoX() && ar.getPuntoX() == (*it).getPuntoY())
            return true;
        else if(ar.getPuntoX()==ar.getPuntoY())
            return true;
        else
        {
            return false;
        }
    }
}

void listado(list<figura> lFiguras)
{
    list<figura>::iterator it=lFiguras.begin();
    if(it == lFiguras.end())
        cout<<"Ningun objeto ha sido cargado en memoria";
    else
        cout<<"\nHay "<<lFiguras.size()<<" objetos en memoria: ";
    for(; it!=lFiguras.end(); it++)
    {
        cout<<"\n" <<(*it).getNombre()<< "contiene "<< (*it).getVertices()<<" vertices, ";
        cout<<(*it).getlCaras().size()<<" caras";
        cout<<(*it).getAristas().size()<<" aristas";
    }
}

void descargar(char* nombre, list<figura> lFiguras)
{
    bool bad = false;
    list<figura>::iterator it = lFiguras.begin();
    for(;it != lFiguras.end(); it++)
    {
        if(strcmp((*it).getNombre(), nombre) == 0)
        {
            lFiguras.erase(it);
            cout<<"el objeto "<< nombre<< " ha sido borrado de la memoria de trabajo";
            bad = true;
        }
    }
    if(!bad)
        cout<<"el objeto "<< nombre<< " no ha sido cargado en memoria";
}

