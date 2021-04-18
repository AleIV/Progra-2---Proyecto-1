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
    char opcion2[100];
    float pago;
    int cantidad, posicion;

    char opcion[100];
    do
    {
        cout << endl << "   << Menu Venta >>" << endl;
        cout << "   ( 1 ) Mostrar productos" << endl;
        cout << "   ( 2 ) Seleccionar producto" << endl;
        cout << "   ( 3 ) Volver..." << endl;
        cout << "-> Opcion: ";
        cin.getline(opcion, sizeof(opcion));

        switch(opcion[0])
        {
            case '1'://Mostrar productos
            cout<<vendedor->toString(); break;

            case '2'://Seleccionar producto
                cout<<"   - Digite la posicion del producto en la lista - "<<endl;
                while(true)
                {
                    cout<<"-> Posicion: "; cin>>numeroString;
                    if(esNumero(numeroString,'e')){ posicion = stoi(numeroString,&tamanhoBytes); break;}
                    else { cout<<"(!) Digite un numero valido..."<<endl; continue;}
                }

                if(vendedor->consultar(posicion)==nullptr) { cout<<"(!) No exite un producto en la posicion digitada..."<<endl; cin.ignore(); break;}

                cout<<vendedor->consultar(posicion)->toString();
                cin.ignore();
                cout<<"( 1 ) Proceder con el pago de < "<<vendedor->consultar(posicion)->getNombre()<<" >"<<endl;
                cout<<"( 2 ) Volver..."<<endl;
                cout << "-> Opcion: ";
                cin.getline(opcion2, sizeof(opcion2));
                switch(opcion2[0])
                {
                    case '1'://Proceder con el pago
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

                        cout << vendedor->realizarCompra(posicion, cantidad, pago);

                        cin.ignore();
                        break;

                    case '2': break;//Sale de switch interno

                    default: cout<<"(!) Opcion INCORRECTA, intente de nuevo..."<<endl; break;
                }

                break;//Sale de switch

            case '3': break;//Volver al menu principal

            default: cout<<"(!) Opcion incorrecta, intente de nuevo..."<<endl; break;
        }

    }while(opcion[0]!='3');
}