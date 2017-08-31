using namespace std;
#include <iostream>
#include "vertice.hpp"

vertice::vertice(int X1, int Y1, int Z1)
{
    x = X1;
    y = Y1;
    z = Z1;
}

int vertice::getVerticeX()
{
    return this->x;
}


int vertice::getVerticeY()
{
    return this->y;
}

int vertice::getVerticeZ()
{
    return this->z;
}

void vertice::setVerticeX(int a)
{
    this->x = a;
}
void vertice::setVerticeY(int a)
{
    this->y = a;
}

void vertice::setVerticeZ(int a)
{
    this->z = a;
}
