//
// Created by aleja on 12/04/2021.
//

#include "Caja.h"

Caja::Caja() {

}

Caja::Caja(float dineroTotal) {
    this->dineroTotal = dineroTotal;
}

Caja::~Caja() {

}

void Caja::depositarDinero(float dinero) {
    setDinero(getDinero()+dinero);
}

void Caja::retirarDinero(float dinero) {
    setDinero(getDinero()-dinero);
}

string Caja::toString(){
    stringstream s;
    s << "=============================\n";
    s << "Dinero en caja: " << dineroTotal << " colones \n";
    s << "=============================\n";
    return s.str();
}


float Caja::getVuelto(float pago, float costo) {
    return pago-costo;
}

string Caja::desgloceVuelto(float pago, float costo) {
    stringstream s;
    float vuelto = pago-costo;
    int billetes2000 = 0;
    int billetes1000 = 0;
    int monedas500 = 0;
    int monedas100 = 0;
    s << "=============================\n";
    s << "Desglose del vuelto\n";
    s << "Paga con: "<< pago << " colones\n";
    s << "Costo: "<< costo << " colones\n";
    s << "=============================\n";

    bool finish = false;

    while (!finish)
    {
        if(vuelto - 2000 >= 0) {
            vuelto -= 2000;
            billetes2000++;

        }else if(vuelto - 1000 >= 0){
            vuelto -= 1000;
            billetes1000++;

        }else if(vuelto - 500 >= 0){
            vuelto -= 1000;
            monedas500++;

        }else if(vuelto - 100 >= 0){
            vuelto -= 1000;
            monedas100++;
        }else{
            finish = true;
        }
    }


    if(billetes2000 != 0) s << "Billetes de 2000: " << billetes2000 <<"\n";
    if(billetes1000 != 0) s << "Billetes de 1000: " << billetes1000 <<"\n";
    if(monedas500 != 0) s << "Monedas de 500: " << monedas500 <<"\n";
    if(billetes2000 != 0) s << "Monedas de 100: " << billetes2000 <<"\n";

    s << "=============================\n";
    s << "Vuelto total: "<< pago-costo << " colones\n";
    s << "=============================\n";
    return s.str();
}

float Caja::getDinero() const {
    return dineroTotal;
}

void Caja::setDinero(float dinero) {
    dineroTotal = dinero;
}
