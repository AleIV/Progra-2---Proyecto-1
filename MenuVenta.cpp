// Created by jordy on 31/03/2021.

#include "MenuVenta.h"

MenuVenta::MenuVenta(Inventario &xInventario)
{
    vendedor = &xInventario;
}

void MenuVenta::mostrar()
{
    string nombre;
    float pago;
    int cantidad;



    char opcion[100];
    do
    {
        cout << "   << Menu Venta >>" << endl;
        cout << "   ( 1 ) Realizar compra" << endl;
        cout << "   ( 2 ) Volver..." << endl;
        cout << "->Opcion: ";
        cin.getline(opcion, sizeof(opcion));

        switch(opcion[0])
        {
            case '1'://Realizar compra
                cout << "Nombre del producto: "; cin >> nombre;
                cout << "Cantidad a comprar: "; cin >> cantidad;
                cout << "Paga con: "; cin >> pago;
                cout << vendedor->realizarCompra(nombre, cantidad, pago);

                cin.ignore();
                break;

            case '2': break;//Volver al menu principal

            default: cout<<"Opcion incorrecta, intente de nuevo"<<endl; break;
        }

    }while(opcion[0]!='2');
}