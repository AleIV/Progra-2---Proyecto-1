// Created by aleja on 12/04/2021.

#include "Fecha.h"
#include <cstdlib>

Fecha::Fecha(int dia, int mes, int annio) {
    this->dia = dia;
    this->mes = mes;
    this->annio = annio;
}

Fecha::~Fecha() {

}

void Fecha::setDia(int dia) {
    Fecha::dia = dia;
}

void Fecha::setMes(int mes) {
    Fecha::mes = mes;
}

void Fecha::setAnnio(int annio) {
    Fecha::annio = annio;
}

int Fecha::getDia() const {
    return dia;
}

int Fecha::getMes() const {
    return mes;
}

int Fecha::getAnnio() const {
    return annio;
}

string Fecha::toString() {
    stringstream s;

    getDia() <= 9 ? s << "0" << getDia() <<"/" : s << getDia() <<"/";
    getMes() <= 9 ? s << "0" << getMes() <<"/" : s << getMes() <<"/";
    s << getAnnio();
    return s.str();
}

string Fecha::diferenciaToString(int dias) {
    stringstream s;
    int d = dias;
    int annios = 0;
    int meses = 0;
    bool finished = false;

    while (!finished)
    {
        if(d-365 >= 0){
            d-=365;
            annios++;
        }else if(d-30 >= 0){
            d-=30;
            meses++;
        }else{
            finished = true;
        }
    }
    s<< annios <<" annios, " << meses << " meses y " << d << " dias";
    return s.str();
}

int Fecha::diferencia(Fecha * fecha) {

    int dia = abs(fecha->getDia()-getDia());
    int mes = abs(fecha->getMes()-getMes());
    int annio = abs(fecha->getAnnio()-getAnnio());

    int dias = (mes*30) + (annio*365) + dia;
    return dias;
}