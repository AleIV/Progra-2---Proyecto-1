// Created by jordy on 04/04/2021.

#include "NodoProducto.h"

NodoProducto::NodoProducto()
{
    producto = nullptr;
    siguiente = nullptr;
}

NodoProducto::NodoProducto(Producto &xProducto, NodoProducto* xSiguiente)
{
    producto = &xProducto;
    siguiente = xSiguiente;
}

NodoProducto::~NodoProducto()
{
    delete producto;
}

void NodoProducto::setProducto(Producto &xProducto)
{
    producto = &xProducto;
}

void NodoProducto::setSiguiente(NodoProducto* xSiguiente)
{
    siguiente = xSiguiente;
}

Producto* NodoProducto::getProducto()
{
    return producto;
}

NodoProducto* NodoProducto::getSiguiente()
{
    return siguiente;
}

string NodoProducto::toStringNodoProducto()
{
    return producto->toString();
}