//
// Created by aleja on 12/04/2021.
//

#ifndef PROGRA2_FECHA_H
#define PROGRA2_FECHA_H

#include <iostream>
#include <sstream>

using namespace std;
class Fecha {

private:
    int dia;
    int mes;
    int annio;

public:

    int diferencia(Fecha*); // le das una fecha y te da la cantidad en dias que han pasado con respecto a la primera fecha
    string diferenciaToString(int); // le das la diferencia en dias y te da los dia, mes y ano

    Fecha(int, int, int);

    virtual ~Fecha();

    string toString();

    int getDia() const;

    int getMes() const;

    int getAnnio() const;

    void setDia(int dia);

    void setMes(int mes);

    void setAnnio(int annio);

};


#endif //PROGRA2_FECHA_H
