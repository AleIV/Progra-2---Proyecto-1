// Created by jordy on 04/04/2021.

#ifndef LISTAPRODUCTO_NODOPRODUCTO_H
#define LISTAPRODUCTO_NODOPRODUCTO_H

#include "Producto.h"

class NodoProducto
{
private:
    Producto* producto; //dato
    NodoProducto* siguiente; //enlace

public:
    NodoProducto();
    NodoProducto(Producto&, NodoProducto*);
    ~NodoProducto();

    void setProducto(Producto&);
    void setSiguiente(NodoProducto*);

    Producto* getProducto();
    NodoProducto* getSiguiente();

    string toStringNodoProducto();
};

#endif //LISTAPRODUCTO_NODOPRODUCTO_H