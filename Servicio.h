// Created by aleja on 12/04/2021.

#ifndef INC_1ERPROYECTO_SERVICIO_H
#define INC_1ERPROYECTO_SERVICIO_H

#include "Producto.h"

class Servicio : public Producto
{
private:
    float porcentajeDescuento = 0;

public:
    Servicio();
    Servicio(const string &nombre, float precio, int cantidad, float porcentajeDescuento);
    virtual ~Servicio();

    void setPorcentajeDescuento(float porcentajeDescuento);

    float getPorcentajeDescuento() const;

    string toString() override;
};

#endif //INC_1ERPROYECTO_SERVICIO_H