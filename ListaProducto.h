// Created by jordy on 04/04/2021.

#ifndef LISTAPRODUCTO_LISTAPRODUCTO_H
#define LISTAPRODUCTO_LISTAPRODUCTO_H

#include "NodoProducto.h"

class ListaProducto
{
private:
    NodoProducto* primer;
    NodoProducto* actual;
    NodoProducto* ultimo;

public:
    ListaProducto();
    [[maybe_unused]] explicit ListaProducto(NodoProducto*);
    ~ListaProducto();

    [[maybe_unused]] void setPrimer(NodoProducto*);
    [[maybe_unused]] void setActual(NodoProducto*);
    [[maybe_unused]] void setUltimo(NodoProducto*);

    [[maybe_unused]] [[nodiscard]] NodoProducto* getPrimer() const;
    [[maybe_unused]] [[nodiscard]] NodoProducto* getActual() const;
    [[maybe_unused]] [[nodiscard]] NodoProducto* getUltimo() const;

    void agregar(Producto &);
    void eliminarPrimer();
    bool eliminarUltimo();
    bool eliminar(const string &);
    bool listaVacia();
    Producto* obtenerProductoPorNombre(const string &);//(Case sensitive)
    void ordenaPrecioAscendente();

    string toStringListaProducto();
};

#endif //LISTAPRODUCTO_LISTAPRODUCTO_H