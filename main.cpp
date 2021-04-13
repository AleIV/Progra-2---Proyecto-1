#include <iostream>
//#include <unistd.h>
//#elif _WIN32_
#include <Windows.h>
#include "Caja.h"
#include "Fecha.h"
#include "Test.h"
#include "Articulo.h"
#include "Servicio.h"

int main() {

    Test *derivado = new Test();
    //delete derivado;
    Caja* caja = new Caja(30000);
    Fecha* fecha = new Fecha(02,04,2001);

    cout<< (derivado->password("corrales1!") ? "CONTRASENA OK" : "CONTRASENA OKN'T") <<endl;


    caja->depositarDinero(20000);
    caja->depositarDinero(10000);
    cout << caja->desgloceVuelto(10000, 3400);
    caja->retirarDinero(caja->getVuelto(10000, 3400));
    cout << caja->toString();

    cout<< fecha->toString() << "\n";


    cout<< fecha->diferencia(new Fecha(06,11,2007)) <<"\n";
    cout<< fecha->diferenciaToString(fecha->diferencia(new Fecha(06,11,2007))) <<"\n";

    Articulo* articulo = new Articulo("Chocolate", 3000, 4, new Fecha(02,04,2001));
    cout << articulo->toString();

    Servicio* servicio = new Servicio("Netflix", 15000, 20041, 30);
    cout << servicio->toString();

    int var;
    cin>>var;
    cin.fail();
    Sleep(2000);
    return 0;
}
