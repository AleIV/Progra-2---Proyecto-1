//
// Created by aleja on 09/04/2021.
//

#include "Producto.h"

Producto::Producto() {

}

Producto::Producto(string nombre, float precio, int cantidad) {
    this->nombre = nombre;
    this->precio = precio;
    this->cantidad = cantidad;
}

Producto::~Producto() {

}

const string &Producto::getNombre() const {
    return nombre;
}

float Producto::getPrecio() const {
    return precio;
}

int Producto::getCantidad() const {
    return cantidad;
}

void Producto::setNombre(const string &nombre) {
    Producto::nombre = nombre;
}

void Producto::setPrecio(float precio) {
    Producto::precio = precio;
}

void Producto::setCantidad(int cantidad) {
    Producto::cantidad = cantidad;
}
