// Created by aleja on 09/04/2021.

#ifndef INC_1ERPROYECTO_ARTICULO_H
#define INC_1ERPROYECTO_ARTICULO_H

#include "Producto.h"
#include "Fecha.h"

class Articulo : public Producto
{
private:
    Fecha *fechaRegistro = nullptr;

public:
    Articulo();
    Articulo(const string &nombre, float precio, int cantidad, Fecha* fecha);
    virtual ~Articulo();

    void setFechaRegistro(Fecha *fechaRegistro);

    Fecha *getFechaRegistro() const;

    string toString() override;
};

#endif //INC_1ERPROYECTO_ARTICULO_H