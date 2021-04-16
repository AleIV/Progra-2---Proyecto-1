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

    static bool menuIngresoClave();
    static bool esNumero(string &, char);

public:
    explicit MenuAdministrador(Inventario &);

    void mostrar();
};

#endif //INC_1ERPROYECTO_MENUADMINISTRADOR_H