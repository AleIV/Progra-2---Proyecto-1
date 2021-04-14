// Created by jordy on 31/03/2021.

#ifndef INC_1ERPROYECTO_INVENTARIO_H
#define INC_1ERPROYECTO_INVENTARIO_H

#include "IAdministrador.h"
#include "IVendedor.h"
#include "ListaProducto.h"
#include "Caja.h"

class Inventario : public IAdministrador, public IVendedor
{
private:
    int identificador;
    string nombre;
    ListaProducto* listaProducto;
    Caja* caja;

public:
    //      Constructor + Destructor
    Inventario();
    Inventario(int, const string &, ListaProducto &, Caja &);
    ~Inventario();

    //      Setters
    void setIdentificador(int);
    void setNombre(const string &) override;//implements from IA
    void setListaProducto(ListaProducto &);
    void setCaja(Caja &);

    //      Getters + toString
    [[nodiscard]] int getIdentificador() const override;//implements from IA
    [[nodiscard]] string getNombre() const override;//implements from IA,IV
    ListaProducto *getListaProducto() const;
    Caja *getCaja() const;

    [[nodiscard]] string toString() const override;//implements from IA,IV

    /*---------------------------------*/

    //   HERENCIAS DE IADMINISTRADOR
    void insertar(Producto &) override;//Producto
    bool agregarCantidades(const string &, int) override;//Producto
    bool disminuirCantidades(const string &, int) override;//Producto
    void borrar(const string &) override;//Producto
    Producto *consultar(const string &) override;//Producto
    [[nodiscard]] float consultarDinero() const override;//implements from IA
    void ingresarDinero(float) override;//Caja
    void retirarDinero(float) override;//Caja

    /*---------------------------------*/

    //   HERENCIAS DE IVENDEDOR
    string realizarCompra(const string &, int, float) override;
};

#endif //INC_1ERPROYECTO_INVENTARIO_H