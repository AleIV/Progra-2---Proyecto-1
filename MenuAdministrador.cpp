// Created by jordy on 31/03/2021.

#include "MenuAdministrador.h"

MenuAdministrador::MenuAdministrador(Inventario &xInventario)
{
    administrador = &xInventario;
}

void MenuAdministrador::mostrar()
{
    if(!menuIngresoClave()) { return; }

    Producto *producto;
    Fecha *fecha;
    string nombre;
    float precio, monto, descuento;
    int cantidad, dia, mes, anho;

    char opcion[100];
    do
    {
        cout << endl << "   << Menu Administrador >>" << endl;
        cout << "   ( 1 ) Agregar un producto nuevo" << endl;
        cout << "   ( 2 ) Aumentar cantidad de un producto" << endl;
        cout << "   ( 3 ) Disminuir cantidad de un producto" << endl;
        cout << "   ( 4 ) Eliminar un producto" << endl;
        cout << "   ( 5 ) Consultar datos de un producto" << endl;
        cout << "   ( 6 ) Consultar dinero en caja" << endl;
        cout << "   ( 7 ) Ingresar dinero a caja" << endl;
        cout << "   ( 8 ) Retirar dinero de caja" << endl;
        cout << "   ( 9 ) Volver..." << endl;
        cout<<"-->Opcion: ";
        cin.getline(opcion,sizeof(opcion));

        switch(opcion[0])
        {
            case '1'://Agregar un producto nuevo

                do
                {
                    cout << endl << "Ingrese los datos del producto..." << endl;
                    cout << "   Tipo de producto" << endl;
                    cout << "      ( 1 ) Articulo" << endl;
                    cout << "      ( 2 ) Servicio" << endl;
                    cout << "-> Opcion: ";
                    cin.getline(opcion, sizeof(opcion));
                    if (opcion[0] != '1' && opcion[0] != '2') { cout << "Opcion incorrecta." << endl; }
                } while (opcion[0] != '1' && opcion[0] != '2');

                cout<<"-> Nombre: "; cin>>nombre;
                cout<<"-> Precio: "; cin>>precio; //PRECAUCION
                cout<<"-> Cantidad: "; cin>>cantidad; //PRECAUCION

                if(opcion[0]=='1')
                {//PRECAUCION
                    cout<<"   Fecha inicial de puesta en venta"<<endl;
                    cout<<"-> Dia: "; cin>>dia;
                    cout<<"-> Mes: "; cin>>mes;
                    cout<<"-> Anho: "; cin>>anho;

                    fecha = new Fecha(dia, mes, anho);
                    producto = new Articulo(nombre, precio, cantidad, fecha);
                    administrador->insertar(*producto);
                }
                else
                {//PRECAUCION
                    cout << "-> Descuento: "; cin >> descuento;
                    producto = new Servicio(nombre, precio, cantidad, descuento);
                    administrador->insertar(*producto);
                }

                cin.ignore();
                break;

            case '2'://Aumentar cantidad de un producto

                cout<<"Nombre del producto: "; cin>>nombre;
                if (administrador->consultar(nombre) == nullptr)
                { cout << "Producto no registrado." << endl; cin.ignore(); break;}
                else
                {
                    cout<<"Cantidad a aumentar: "; cin>>cantidad;//PRECAUCION
                    administrador->agregarCantidades(nombre,cantidad);
                }
                cin.ignore();
                break;

            case '3'://Disminuir cantidad de un producto

                cout<<"Nombre del producto: "; cin>>nombre;
                if (administrador->consultar(nombre) == nullptr)
                { cout << "Producto no registrado." << endl; cin.ignore(); break;}
                else
                {
                    cout<<"Cantidad a disminuir: "; cin>>cantidad;//PRECAUCION
                    administrador->disminuirCantidades(nombre,cantidad);
                }
                cin.ignore();
                break;

            case '4'://Eliminar un producto

                cout<<"Nombre del producto: "; cin>>nombre;
                if (administrador->consultar(nombre) == nullptr)
                { cout << "Producto no registrado." << endl; cin.ignore(); break;}
                else
                {
                    administrador->borrar(nombre);
                }
                cin.ignore();
                break;

            case '5'://Consultar datos de un producto

                cout<<"Nombre del producto: "; cin>>nombre;
                if (administrador->consultar(nombre) == nullptr)
                { cout << "Producto no registrado." << endl; cin.ignore(); break;}
                else
                {
                    cout<<administrador->consultar(nombre)->toString();
                }
                cin.ignore();
                break;

            case '6'://Consultar dinero en caja

                cout << "Monto en caja: " << administrador->consultarDinero()<<" colones"<<endl;
                break;

            case '7'://Ingresar dinero a caja

                cout<<"Monto a ingresar: "; cin>>monto;
                administrador->ingresarDinero(monto);
                cin.ignore(); break;

            case '8'://Retirar dinero de caja

                cout<<"Monto a retirar: "; cin>>monto;
                administrador->retirarDinero(monto);
                cin.ignore(); break;

            case '9': break;//Volver al menu principal

            default: cout<<"Opcion incorrecta, intente de nuevo"<<endl; break;
        }

    }while(opcion[0]!='9');

}

bool MenuAdministrador::menuIngresoClave()
{
    string clave;
    cout<<"Digite la clave de administrador..."<<endl;
    cout<<"-->Clave: "; cin>>clave; cin.ignore();

    if(clave != "1234")
    { cout << "Clave incorrecta..." << endl; return false; }

    return true;
}