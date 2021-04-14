// Created by aleja on 09/04/2021.

#ifndef INC_1ERPROYECTO_PRODUCTO_H
#define INC_1ERPROYECTO_PRODUCTO_H

#include <sstream>
#include <iostream>

using namespace std;

class Producto
{
protected:
    string nombre;
    float precio;
    int cantidad;

public:
    Producto();
    Producto(const string &, float, int);
    virtual ~Producto();

    void setNombre(const string &);
    void setPrecio(float);
    void setCantidad(int);

    string getNombre() const;
    float getPrecio() const;
    int getCantidad() const;

    virtual string toString() = 0;
};

#endif //INC_1ERPROYECTO_PRODUCTO_H