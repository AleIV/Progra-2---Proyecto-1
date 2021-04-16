// Created by jordy on 31/03/2021.

#ifndef INC_1ERPROYECTO_MENUVENTA_H
#define INC_1ERPROYECTO_MENUVENTA_H

#include "IVendedor.h"
#include "Inventario.h"
#include <iostream>
#include <string>
using namespace std;

class MenuVenta
{
private:
    IVendedor *vendedor;

    static bool esNumero(string &, char);

public:
    explicit MenuVenta(Inventario &);

    void mostrar();
};

#endif //INC_1ERPROYECTO_MENUVENTA_H