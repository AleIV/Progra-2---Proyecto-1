// Created by jordy on 31/03/2021.

#ifndef INC_1ERPROYECTO_IADMINISTRADOR_H
#define INC_1ERPROYECTO_IADMINISTRADOR_H

#include <iostream>
#include "Producto.h"
using namespace std;

class IAdministrador
{
public:
    //      Destructor
    virtual ~IAdministrador() = default;

    //      Setters
    virtual void setNombre(const string &) = 0;

    //      Getters + toString
    virtual string getNombre() const = 0;
    virtual int getIdentificador() const = 0;

    virtual string toString() const = 0;

    //      Others
    virtual void insertar(Producto &) = 0;
    virtual bool agregarCantidades(const string &, int) = 0;
    virtual bool disminuirCantidades(const string &, int) = 0;
    virtual void borrar(const string &) = 0;
    virtual Producto *consultar(const string &) = 0;
    virtual float consultarDinero() const = 0;
    virtual void ingresarDinero(float) = 0;
    virtual void retirarDinero(float) = 0;
};

#endif //INC_1ERPROYECTO_IADMINISTRADOR_H