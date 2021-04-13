//
// Created by aleja on 12/04/2021.
//

#include "Servicio.h"

string Servicio::toString() {
    stringstream s;
    s << "=============================\n";
    s << "Nombre del servicio: "<< nombre << "\n";
    s << "Precio: "<< precio << " colones\n";
    s << "Cantidad: "<< cantidad << "\n";
    s << "Porcentaje de descuento: "<< porcentajeDescuento << "%\n";
    s << "=============================\n";
    return s.str();
}

Servicio::Servicio() {

}

float Servicio::getPorcentajeDescuento() const {
    return porcentajeDescuento;
}

void Servicio::setPorcentajeDescuento(float porcentajeDescuento) {
    Servicio::porcentajeDescuento = porcentajeDescuento;
}

Servicio::Servicio(const string &nombre, float precio, int cantidad, float porcentajeDescuento) : Producto(nombre, precio, cantidad) {
    this->porcentajeDescuento = porcentajeDescuento;
}

Servicio::~Servicio() {

}
