#include <iostream>

#ifndef __VERTICE_HPP__
#define __VERTICE_HPP__
using namespace std;

class vertice
{
private:
    int x;
    int y;
    int z;
public:

    vertice(int X1, int Y1, int Z1);

    int getVerticeX();

    int getVerticeY();

    int getVerticeZ();

    void setVerticeX(int a);

    void setVerticeY(int a);

    void setVerticeZ(int a);
};

#endif
