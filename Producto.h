//
// Created by aleja on 09/04/2021.
//

#ifndef PROGRA2_PRODUCTO_H
#define PROGRA2_PRODUCTO_H

#include <sstream>
#include <iostream>

using namespace std;


class Producto {

protected:
    string nombre;
    float precio;
    int cantidad;

public:

    Producto();
    Producto(string nombre, float precio, int cantidad);
    virtual ~Producto();

    void setNombre(const string &nombre);

    void setPrecio(float precio);

    void setCantidad(int cantidad);

    const string &getNombre() const;

    float getPrecio() const;

    int getCantidad() const;

    virtual string toString() = 0;

};


#endif //PROGRA2_PRODUCTO_H
