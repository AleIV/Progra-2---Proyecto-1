// Created by jordy on 31/03/2021.

#ifndef INC_1ERPROYECTO_IVENDEDOR_H
#define INC_1ERPROYECTO_IVENDEDOR_H

#include "Producto.h"
#include <iostream>
using namespace std;

class IVendedor
{
public:
    //      Destructor
    virtual ~IVendedor() = default;

    //      Getters + toString
    virtual string getNombre() const = 0;

    virtual string toString() const = 0;

    //      Others
    virtual string realizarCompra(int, int, float) = 0;
    virtual Producto *consultar(int) = 0;
};

#endif //INC_1ERPROYECTO_IVENDEDOR_H