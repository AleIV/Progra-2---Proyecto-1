// Created by jordy on 31/03/2021.

#ifndef INC_1ERPROYECTO_MENUPRINCIPAL_H
#define INC_1ERPROYECTO_MENUPRINCIPAL_H

#include "MenuAdministrador.h"
#include "MenuVenta.h"

/*
 * I – Interface Segregation Principle (ISP)
 *    1) Es mejor muchas clases pequeñas y especializadas para cubrir mejor las necesidades del programa.
 *          mmenuAdministrador y menuVenta, a pesar de ser todas menú, al estar separadas en secciones pueden cubrir cada necesidad
 *          sin sobrecargar al usuario con opciones de otro menú que no necesitaría si solo hubiese menuPrincipal.
 */

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