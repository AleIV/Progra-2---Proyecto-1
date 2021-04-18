// Created by jordy on 31/03/2021.

#include "MenuVenta.h"

bool MenuVenta::esNumero(string &numeroString, char tipoNumero)
{
    for (char const &iterador : numeroString)
    {
        if(tipoNumero=='Q' && !isdigit(iterador) && iterador!='.') { return false; }//Permite racionales >= 0
        if (tipoNumero!='Q' && !isdigit(iterador)) { return false; }//Permite naturales ∪ 0
    }
    return true;
}

MenuVenta::MenuVenta(Inventario &xInventario)
{
    vendedor = &xInventario;
}

void MenuVenta::mostrar()
{
    size_t tamanhoBytes;
    string nombre, numeroString;
    float pago;
    int cantidad;

    char opcion[100];
    do
    {
        cout << endl << "   << Menu Venta >>" << endl;
        cout << "   ( 1 ) Realizar compra" << endl;
        cout << "   ( 2 ) Volver..." << endl;
        cout << "->Opcion: ";
        cin.getline(opcion, sizeof(opcion));

        switch(opcion[0])
        {
            case '1'://Realizar compra
                cout << "-> Nombre del producto: "; cin >> nombre;
                while(true)
                {
                    cout<<"-> Cantidad a comprar: "; cin>>numeroString;
                    if(esNumero(numeroString,'e')){ cantidad = stoi(numeroString,&tamanhoBytes); break;}
                    else { cout<<"(!) Digite un numero valido..."<<endl; continue;}
                }

                while(true)
                {
                    cout<<"-> Paga con: "; cin>>numeroString;
                    if(esNumero(numeroString,'Q')) { pago = stof(numeroString,&tamanhoBytes); break;}
                    else { cout<<"(!) Digite un numero valido..."<<endl; continue;}
                }

                cout << vendedor->realizarCompra(nombre, cantidad, pago);

                cin.ignore();
                break;

            case '2': break;//Volver al menu principal

            default: cout<<"(!) Opcion incorrecta, intente de nuevo..."<<endl; break;
        }

    }while(opcion[0]!='2');
}