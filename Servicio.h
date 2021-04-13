//
// Created by aleja on 12/04/2021.
//

#ifndef PROGRA2_SERVICIO_H
#define PROGRA2_SERVICIO_H
#include "Producto.h"

class Servicio : public Producto{
private:
    float porcentajeDescuento = 0;
public:
    void setPorcentajeDescuento(float porcentajeDescuento);

    float getPorcentajeDescuento() const;

    Servicio(const string &nombre, float precio, int cantidad, float porcentajeDescuento);

    virtual ~Servicio();

    Servicio();

    string toString() override;
};


#endif //PROGRA2_SERVICIO_H
