// Created by jordy on 31/03/2021.

#ifndef INC_1ERPROYECTO_MENUPRINCIPAL_H
#define INC_1ERPROYECTO_MENUPRINCIPAL_H

#include "MenuAdministrador.h"
#include "MenuVenta.h"

class MenuPrincipal
{
private:
    MenuAdministrador *menuAdministrador;
    MenuVenta *menuVenta;

public:
    MenuPrincipal();

    void mostrarMenuPrincipal();
    void mostrarMenuAdministrador();
    void mostrarMenuVenta();
};

#endif //INC_1ERPROYECTO_MENUPRINCIPAL_H