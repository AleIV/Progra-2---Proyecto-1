// Created by jordy on 31/03/2021.

#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal()
{
    Inventario *inventario = new Inventario();
    menuAdministrador = new MenuAdministrador(*inventario);
    menuVenta = new MenuVenta(*inventario);
}

void MenuPrincipal::mostrarMenuPrincipal()
{
    char opcion[100];
    do
    {
        cout << endl << "   << Menu Principal >>" << endl;
        cout << "   ( 1 ) Ir a menu de administrador" << endl;
        cout << "   ( 2 ) Ir a menu de venta" << endl;
        cout << "   ( 3 ) Salir de la aplicacion" << endl;
        cout<<"-> Opcion: ";
        cin.getline(opcion,sizeof(opcion));

        switch(opcion[0])
        {
            case '1':
                mostrarMenuAdministrador(); break;

            case '2':
                mostrarMenuVenta(); break;

            case '3': return;//Sale de menuPrincipal

            default: cout<<"(!) Opcion incorrecta, intente de nuevo..."<<endl; break;
        }

    }while(opcion[0]!='3');
}

void MenuPrincipal::mostrarMenuAdministrador()
{
    menuAdministrador->mostrar();
}

void MenuPrincipal::mostrarMenuVenta()
{
    menuVenta->mostrar();
}