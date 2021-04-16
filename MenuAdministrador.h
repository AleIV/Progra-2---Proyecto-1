// Created by jordy on 31/03/2021.

#ifndef INC_1ERPROYECTO_MENUADMINISTRADOR_H
#define INC_1ERPROYECTO_MENUADMINISTRADOR_H

#include "IAdministrador.h"
#include "Inventario.h"
#include "Fecha.h"
#include "Articulo.h"
#include "Servicio.h"
#include <iostream>
using namespace std;

class MenuAdministrador
{
private:
    IAdministrador *administrador;

public:
    explicit MenuAdministrador(Inventario &);

    void mostrar();
    static bool menuIngresoClave();
};

#endif //INC_1ERPROYECTO_MENUADMINISTRADOR_H