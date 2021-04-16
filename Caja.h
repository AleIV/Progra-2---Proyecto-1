// Created by aleja on 12/04/2021.

#ifndef INC_1ERPROYECTO_CAJA_H
#define INC_1ERPROYECTO_CAJA_H

#include <sstream>
#include <iostream>

using namespace std;

class Caja
{
private:
    float dineroTotal = 0;

public:
    Caja();
    Caja(float);
    virtual ~Caja();

    void setDinero(float);

    float getVuelto(float, float);
    float getDinero() const;

    string toString();

    void depositarDinero(float);
    void retirarDinero(float);
    string desgloceVuelto(float, float);
};

#endif //INC_1ERPROYECTO_CAJA_H