// Created by jordy on 04/04/2021.

#include <iostream>
#include "ListaProducto.h"

ListaProducto::ListaProducto()
{
    primer = nullptr;
    actual = nullptr;
    ultimo = nullptr;
}

[[maybe_unused]] ListaProducto::ListaProducto(NodoProducto *xPrimer)
{
    primer = xPrimer;
    actual = nullptr;
    ultimo = nullptr;
}

ListaProducto::~ListaProducto()
{
    while (!listaVacia())
    {
        eliminarUltimo();
    }
}

[[maybe_unused]] void ListaProducto::setPrimer(NodoProducto *xPrimer)
{
    primer = xPrimer;
}

[[maybe_unused]] void ListaProducto::setActual(NodoProducto *xActual)
{
    actual = xActual;
}

[[maybe_unused]] void ListaProducto::setUltimo(NodoProducto *xUltimo)
{
    ultimo = xUltimo;
}

[[maybe_unused]] NodoProducto *ListaProducto::getPrimer() const
{
    return primer;
}

[[maybe_unused]] NodoProducto *ListaProducto::getActual() const
{
    return actual;
}

[[maybe_unused]] NodoProducto *ListaProducto::getUltimo() const
{
    return ultimo;
}

void ListaProducto::agregar(Producto &xProducto)
{
    if (listaVacia())
    {
        primer = new NodoProducto(xProducto, nullptr);
        ultimo = primer;
        return;
    }
    else
    {//La condición evita duplicar productos en la lista
        auto *nuevoNodo = new NodoProducto(xProducto, nullptr);
        ultimo->setSiguiente(nuevoNodo);
        ultimo = nuevoNodo;
    }
}

void ListaProducto::eliminarPrimer()
{
    NodoProducto *anterior;
    anterior = primer;
    primer = primer->getSiguiente();
    delete anterior;
}

bool ListaProducto::eliminarUltimo()
{
    if (listaVacia()) { return false; }

    if (primer->getSiguiente() == nullptr)
    {
        delete primer;
        primer = nullptr;
        return true;
    }

    NodoProducto *anterior = nullptr;
    actual = primer;
    while(actual->getSiguiente()!= nullptr)
    {
        anterior = actual;
        actual = actual->getSiguiente();
    }
    ultimo = anterior;
    anterior->setSiguiente(nullptr);
    delete actual;
    return true;
}

bool ListaProducto::eliminar(const string &xNombre)
{
    if(primer->getProducto()->getNombre() == xNombre)
    { eliminarPrimer(); return true; }

    if(ultimo->getProducto()->getNombre()==xNombre)
    { if(eliminarUltimo()){ return true; } return false; }

    NodoProducto *anterior;
    actual = primer;

    while(actual!=nullptr)
    {
        //"Si el nombre no coincide, siguiente nodo"
        if(actual->getProducto()->getNombre() != xNombre)
        {
            anterior = actual;
            actual = actual->getSiguiente();
            continue;
        }
        else
        {
            anterior->setSiguiente(actual->getSiguiente());
            delete actual;
            actual = anterior->getSiguiente();
            return true;
        }
    }
    return false;
}

bool ListaProducto::listaVacia()
{
    if (primer == nullptr) { return true; } return false;
}

Producto* ListaProducto::obtenerProductoPorNombre(const string& xNombre)
{
    //  ALGORITHM CASE SENSITIVE (Aún no funciona con espacios)
	actual = primer;

	while (actual != nullptr)
	{
		if (actual->getProducto()->getNombre() == xNombre)
		{
			return actual->getProducto();
		}

		actual = actual->getSiguiente();
	}

	return nullptr;
}

void ListaProducto::ordenaPrecioAscendente()
{
	Producto* auxiliar;
	NodoProducto* actualInterno;
	actual = primer;

	while (actual != nullptr)
	{
		actualInterno = actual->getSiguiente();

		while (actualInterno != nullptr)
		{
			if (actual->getProducto()->getPrecio() > actualInterno->getProducto()->getPrecio())
			{
				auxiliar = actualInterno->getProducto();
				actualInterno->setProducto(*actual->getProducto());
				actual->setProducto(*auxiliar);
			}
			actualInterno = actualInterno->getSiguiente();
		}
		actual = actual->getSiguiente();
	}
}

string ListaProducto::toStringListaProducto()
{
    stringstream s;

    if (listaVacia()) { s << "[AÚN NO HAY PRODUCTOS]" << endl; return s.str(); }

    actual = primer;
    int cuentaProductos = 0;

    s << "Lista de productos" << endl;
    while (actual != nullptr)
    {
        s << "Producto N" << cuentaProductos + 1 << endl;
        s << actual->toStringNodoProducto();
        actual = actual->getSiguiente();
        cuentaProductos++;
        s << endl;
    }

    return s.str();
}