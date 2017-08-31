#ifndef __ARISTAS_HPP__
#define __ARISTAS_HPP__

#include <iostream>
using namespace std;

class arista
{

private:

    int puntoX;
    int puntoY;

public:

    int getPuntoX();
    int getPuntoY();
    void setPuntoX(int n);
    void setPuntoY(int n);
};

#include "aristas.cpp"

#endif // ARISTAS_HPP_INCLUDED
