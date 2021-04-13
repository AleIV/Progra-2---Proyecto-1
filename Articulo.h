//
// Created by aleja on 09/04/2021.
//

#ifndef PROGRA2_ARTICULO_H
#define PROGRA2_ARTICULO_H
#include "Producto.h"
#include "Fecha.h"

class Articulo : public Producto{
private:
    Fecha* fechaRegistro = nullptr;
public:
    Fecha *getFechaRegistro() const;

    void setFechaRegistro(Fecha *fechaRegistro);

    Articulo();

    Articulo(const string &nombre, float precio, int cantidad, Fecha* fecha);

    virtual ~Articulo();

    string toString() override;
};


#endif //PROGRA2_ARTICULO_H
