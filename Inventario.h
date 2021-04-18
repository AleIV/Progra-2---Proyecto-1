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
    [[maybe_unused]] Inventario(int, const string &, ListaProducto &, Caja &);
    ~Inventario();

    //      Setters
    [[maybe_unused]] void setIdentificador(int);
    [[maybe_unused]] void setNombre(const string &) override;//implements from IA
    [[maybe_unused]] void setListaProducto(ListaProducto &);
    [[maybe_unused]] void setCaja(Caja &);

    //      Getters + toString
    [[maybe_unused]] [[nodiscard]] int getIdentificador() const override;//implements from IA
    [[maybe_unused]] [[nodiscard]] string getNombre() const override;//implements from IA,IV
    [[maybe_unused]] [[nodiscard]] ListaProducto *getListaProducto() const;
    [[maybe_unused]] [[nodiscard]] Caja *getCaja() const;

    [[maybe_unused]] [[nodiscard]] string toString() const override;//implements from IA,IV

    /*---------------------------------*/

    //   HERENCIAS DE IADMINISTRADOR
    void insertar(Producto &) override;
    bool agregarCantidades(const string &, int) override;
    bool disminuirCantidades(const string &, int) override;
    void borrar(const string &) override;
    Producto *consultar(const string &) override;
    float consultarDinero() const override;
    void ingresarDinero(float) override;
    void retirarDinero(float) override;

    /*---------------------------------*/

    //   HERENCIAS DE IVENDEDOR
    string realizarCompra(const string &, int, float) override;
};

#endif //INC_1ERPROYECTO_INVENTARIO_H