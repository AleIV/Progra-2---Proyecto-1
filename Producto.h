// Created by aleja on 09/04/2021.

#ifndef INC_1ERPROYECTO_PRODUCTO_H
#define INC_1ERPROYECTO_PRODUCTO_H

#include <sstream>
#include <iostream>

using namespace std;

/*
 * O – Open/Closed Principle (OCP)
 *    1) Un programa debe estar abierto a su extensión y cerrado para su modificación.
 *        Producto está cerrado a modificarse, pero abierto a extenderse en sus clases hijas.
 *        Es decir, en Articulo y Servicio se pueden añadir funciones sin alterar Producto.
 *
 * D – Dependency Inversion Principle (DIP)
 *    1) Abstracciones no deben depender de detalles. Detalles debe depender de abstracciones.
 *          los detalles (Articulo y Servicio) deben depender
 *          de los métodos heredados (abstractos) de Producto para ser útiles en el proyecto
 */

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