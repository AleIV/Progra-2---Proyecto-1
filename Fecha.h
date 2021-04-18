// Created by aleja on 12/04/2021.

#ifndef INC_1ERPROYECTO_FECHA_H
#define INC_1ERPROYECTO_FECHA_H

#include <iostream>
#include <sstream>

using namespace std;

/*
 * S – Single Responsibility Principle (SRP)
 *    1) Cada clase debe tener una sola responsabilidad.
 *          -Clase Fecha funciona para crear objetos que manejen solo fechas específicas,
 *          esto utilizando sus atributos (dia, mes año) para indicar la fecha exacta
 *          Incluye algunos métodos para solicitar información mas especifica,
 *          como la diferencia de días entre una fecha y otra
 *          pero siempre manteniendo el principio de su única responsabilidad
 */

class Fecha
{
private:
    int dia;
    int mes;
    int annio;

public:
    Fecha(int, int, int);
    virtual ~Fecha();

    void setDia(int dia);
    void setMes(int mes);
    void setAnnio(int annio);

    int getDia() const;
    int getMes() const;
    int getAnnio() const;

    string toString();

    int diferencia(Fecha*); // le das una fecha y te da la cantidad en dias que han pasado con respecto a la primera fecha
    string diferenciaToString(int); // le das la diferencia en dias y te da los dia, mes y ano
};

#endif //INC_1ERPROYECTO_FECHA_H