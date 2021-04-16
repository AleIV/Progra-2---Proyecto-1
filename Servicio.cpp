// Created by aleja on 12/04/2021.

#include "Servicio.h"

Servicio::Servicio() {

}

Servicio::Servicio(const string &nombre, float precio, int cantidad, float porcentajeDescuento) : Producto(nombre, precio, cantidad) {
    this->porcentajeDescuento = porcentajeDescuento;
}

Servicio::~Servicio() {

}

void Servicio::setPorcentajeDescuento(float porcentajeDescuento) {
    Servicio::porcentajeDescuento = porcentajeDescuento;
}

float Servicio::getPorcentajeDescuento() const {
    return porcentajeDescuento;
}

string Servicio::toString() {
    stringstream s;
    s << "=============================\n";
    s << "-< Nombre del servicio: "<< nombre << "\n";
    s << "-< Precio: "<< precio << " colones\n";
    s << "-< Cantidad: "<< cantidad << "\n";
    s << "-< Porcentaje de descuento: "<< porcentajeDescuento << "%\n";
    s << "=============================\n";
    return s.str();
}