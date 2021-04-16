// Created by jordy on 31/03/2021.

#include "MenuAdministrador.h"

bool MenuAdministrador::menuIngresoClave()
{
    string clave;
    cout<<"-> Clave administrador: "; cin>>clave; cin.ignore();
    if(clave != "1234") { cout << "(!) Clave incorrecta..." << endl; return false; } return true;
}

bool MenuAdministrador::esNumero(string &numeroString, char tipoNumero)
{
    for (char const &iterador : numeroString)
    {
        if(tipoNumero=='Q' && !isdigit(iterador) && iterador!='.') { return false; }//Permite racionales >= 0
        if (tipoNumero!='Q' && !isdigit(iterador)) { return false; }//Permite naturales ∪ 0
    }
    return true;
}

MenuAdministrador::MenuAdministrador(Inventario &xInventario)
{
    administrador = &xInventario;
}

void MenuAdministrador::mostrar()
{
    if(!menuIngresoClave()) { return; }

    size_t tamanhoBytes;
    Producto *producto;
    Fecha *fecha;
    string nombre, numeroString;
    float precio, monto, descuento;
    int cantidad, dia, mes, anio;

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
        cout<<"-> Opcion: ";
        cin.getline(opcion,sizeof(opcion));

        switch(opcion[0])
        {
            case '1'://Agregar un producto nuevo

                do
                {
                    cout << endl << "   < Tipo de producto >" << endl;
                    cout << "   ( 1 ) Articulo" << endl;
                    cout << "   ( 2 ) Servicio" << endl;
                    cout << "-> Tipo: ";
                    cin.getline(opcion, sizeof(opcion));
                    if (opcion[0] != '1' && opcion[0] != '2') { cout << "(!) Seleccione un tipo enlistado..." << endl; }
                } while (opcion[0] != '1' && opcion[0] != '2');

                cout<<"-> Nombre: "; cin>>nombre;

                while(true)
                {
                    cout<<"-> Precio: "; cin>>numeroString;
                    if(esNumero(numeroString,'Q')) { precio = stof(numeroString,&tamanhoBytes); break;}
                    else { cout<<"(!) Digite un numero valido..."<<endl; continue;}
                }

                while(true)
                {
                    cout<<"-> Cantidad: "; cin>>numeroString;
                    if(esNumero(numeroString,'e')){ cantidad = stoi(numeroString,&tamanhoBytes); break;}
                    else { cout<<"(!) Digite un numero valido..."<<endl; continue;}
                }


                if(opcion[0]=='1')
                {//EN CASO QUE EL PRODUCTO SEA ARTÍCULO
                    cout<<"   - Fecha inicial de puesta en venta -"<<endl;

                    while(true)
                    {
                        cout<<"-> Anio: "; cin>>numeroString;
                        if(esNumero(numeroString,'e'))
                        {
                            anio = stoi(numeroString, &tamanhoBytes);
                            if (anio < 1901 || anio > 2100) { cout << "(!) Anio debe ser del siglo XX o XXI..." << endl; continue; }
                            break;
                        }
                        else { cout<<"(!) Digite un numero valido..."<<endl; continue;}
                    }

                    while(true)
                    {
                        cout<<"-> Mes: "; cin>>numeroString;
                        if(esNumero(numeroString,'e'))
                        {
                            mes = stoi(numeroString, &tamanhoBytes);
                            if (mes > 12 || mes < 1) { cout << "(!) Mes debe ser de rango 1 a 12..." << endl; continue; }
                            break;
                        }
                        else { cout<<"(!) Digite un numero valido..."<<endl; continue;}
                    }

                    while(true)
                    {
                        cout<<"-> Dia: "; cin>>numeroString;
                        if(esNumero(numeroString,'e'))
                        {
                            dia = stoi(numeroString,&tamanhoBytes);
                            switch(mes)
                            {
                                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                                    if(dia>31){ cout<<"(!) Dia no puede ser mayor a 31 en el mes "<<mes<<"..."<<endl; continue; } break;

                                case 4: case 6: case 9: case 11:
                                    if(dia>30){ cout<<"(!) Dia no puede ser mayor a 30 en el mes "<<mes<<"..."<<endl; continue; } break;

                                case 2:
                                    if(dia>28){ cout<<"(!) Dia no puede ser mayor a 29 en febrero. Si es anio bisiesto, registrar como 28..."<<endl; continue; } break;

                                default: cout<<"(!) Ha ocurrido un error..."; return;
                            }
                            if(dia==0){ cout<<"(!) Dia no puede ser igual a 0..."<<endl; continue; }
                            break;
                        }
                        else { cout<<"(!) Digite un numero valido..."<<endl; continue;}
                    }

                    fecha = new Fecha(dia, mes, anio);
                    producto = new Articulo(nombre, precio, cantidad, fecha);
                    administrador->insertar(*producto);
                    cout<<"   - Se ha agregado < "<<nombre<<" > al inventario -"<<endl;
                }
                else
                {//EN CASO QUE EL PRODUCTO SEA SERVICIO
                    while(true)
                    {
                        cout<<"-> Descuento: "; cin>>numeroString;
                        if(esNumero(numeroString,'Q')) { descuento = stof(numeroString,&tamanhoBytes); break;}
                        else { cout<<"(!) Digite un numero valido..."<<endl; continue;}
                    }

                    producto = new Servicio(nombre, precio, cantidad, descuento);
                    administrador->insertar(*producto);
                    cout<<"   - Se ha agregado < "<<nombre<<" > al inventario -"<<endl;
                }

                cin.ignore();
                break;

            case '2'://Aumentar cantidad de un producto

                cout<<"-> Nombre del producto: "; cin>>nombre;
                if (administrador->consultar(nombre) == nullptr)
                { cout << "(!) Producto no registrado..." << endl; cin.ignore(); break;}
                else
                {
                    while(true)
                    {
                        cout<<"-> Cantidad a aumentar: "; cin>>numeroString;
                        if(esNumero(numeroString,'e')){ cantidad = stoi(numeroString,&tamanhoBytes); break;}
                        else { cout<<"(!) Digite un numero valido..."<<endl; continue;}
                    }
                    administrador->agregarCantidades(nombre,cantidad);
                    cout<<"   - Se ha aumentado la cantidad de < "<<nombre<<" > -"<<endl;
                }
                cin.ignore();
                break;

            case '3'://Disminuir cantidad de un producto

                cout<<"-> Nombre del producto: "; cin>>nombre;
                if (administrador->consultar(nombre) == nullptr)
                { cout << "(!) Producto no registrado..." << endl; cin.ignore(); break;}
                else
                {
                    while(true)
                    {
                        cout<<"-> Cantidad a disminuir: "; cin>>numeroString;
                        if(esNumero(numeroString,'e')){ cantidad = stoi(numeroString,&tamanhoBytes); break;}
                        else { cout<<"(!) Digite un numero valido..."<<endl; continue;}
                    }
                    administrador->disminuirCantidades(nombre,cantidad);
                    cout<<"   - Se ha disminuido la cantidad de < "<<nombre<<" > -"<<endl;
                }
                cin.ignore();
                break;

            case '4'://Eliminar un producto

                cout<<"-> Nombre del producto: "; cin>>nombre;
                if (administrador->consultar(nombre) == nullptr)
                { cout << "(!) Producto no registrado..." << endl; cin.ignore(); break;}
                else
                {
                    administrador->borrar(nombre);
                    cout<<"   - Se ha eliminado < "<<nombre<<" > del inventario -"<<endl;
                }
                cin.ignore();
                break;

            case '5'://Consultar datos de un producto

                cout<<"-> Nombre del producto: "; cin>>nombre;
                if (administrador->consultar(nombre) == nullptr)
                { cout << "(!) Producto no registrado..." << endl; cin.ignore(); break;}
                else
                {
                    cout<<administrador->consultar(nombre)->toString();
                }
                cin.ignore();
                break;

            case '6'://Consultar dinero en caja

                cout << "-< Monto en caja: " << administrador->consultarDinero()<<" colones"<<endl;
                break;

            case '7'://Ingresar dinero a caja

                while(true)
                {
                    cout<<"-> Monto a ingresar: "; cin>>numeroString;
                    if(esNumero(numeroString,'Q')) { monto = stof(numeroString,&tamanhoBytes); break;}
                    else { cout<<"(!) Digite un numero valido..."<<endl; continue;}
                }
                administrador->ingresarDinero(monto);
                cout<<"   - Se han ingresado < "<<monto<<" > colones a caja -"<<endl;
                cin.ignore(); break;

            case '8'://Retirar dinero de caja

                while(true)
                {
                    cout<<"-> Monto a retirar: "; cin>>numeroString;
                    if(esNumero(numeroString,'Q')) { monto = stof(numeroString,&tamanhoBytes); break;}
                    else { cout<<"(!) Digite un numero valido..."<<endl; continue;}
                }
                administrador->retirarDinero(monto);
                cout<<"   - Se han retirado < "<<monto<<" > colones de caja -"<<endl;
                cin.ignore(); break;

            case '9': break;//Volver al menu principal

            default: cout<<"(!) Opcion incorrecta, intente de nuevo..."<<endl; break;
        }

    }while(opcion[0]!='9');

}