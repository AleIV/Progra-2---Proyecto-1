//
// Created by aleja on 12/04/2021.
//

#ifndef PROGRA2_CAJA_H
#define PROGRA2_CAJA_H

#include <sstream>
#include <iostream>

using namespace std;
class Caja {
private:
    float dineroTotal = 0;
public:
    void setDinero(float);
    void depositarDinero(float);
    void retirarDinero(float);
    float getVuelto(float, float);
    float getDinero() const;

    string toString();
    string desgloceVuelto(float, float);
    virtual ~Caja();

    Caja();
    Caja(float);
};


#endif //PROGRA2_CAJA_H
