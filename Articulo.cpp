//
// Created by aleja on 09/04/2021.
//

#include "Articulo.h"

string Articulo::toString() {
    stringstream s;
    s << "=============================\n";
    s << "Nombre del articulo: "<< nombre << "\n";
    s << "Precio: "<< precio << " colones\n";
    s << "Cantidad: "<< cantidad << "\n";
    s << "Fecha de registro: "<< fechaRegistro->toString() << "\n";
    s << "=============================\n";
    return s.str();
}

Articulo::Articulo() {

}

Articulo::~Articulo() {

}

Articulo::Articulo(const string &nombre, float precio, int cantidad, Fecha* fechaRegistro) : Producto(nombre, precio, cantidad) {
    this->fechaRegistro = fechaRegistro;
}

void Articulo::setFechaRegistro(Fecha *fechaRegistro) {
    Articulo::fechaRegistro = fechaRegistro;
}

Fecha *Articulo::getFechaRegistro() const {
    return fechaRegistro;
}
