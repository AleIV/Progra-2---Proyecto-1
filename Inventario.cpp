// Created by jordy on 31/03/2021.

#include "Inventario.h"

//      CONSTRUCTOR + DESTRUCTOR
Inventario::Inventario()
{
    identificador = 0;
    nombre = "Indefinido";
    listaProducto = new ListaProducto();
    caja = new Caja();
}

Inventario::Inventario(int xIdentificador, const string &xNombre, ListaProducto &xListaProducto, Caja &xCaja)
{
    identificador = xIdentificador;
    nombre = xNombre;
    listaProducto = &xListaProducto;
    caja = &xCaja;
}

Inventario::~Inventario()
{
    delete listaProducto;
    delete caja;
}


//      SETTERS
void Inventario::setIdentificador(int xIdentificador)
{
    identificador = xIdentificador;
}

void Inventario::setNombre(const string &xNombre)
{
    nombre = xNombre;
}

void Inventario::setListaProducto(ListaProducto &xListaProducto)
{
    listaProducto = &xListaProducto;
}

void Inventario::setCaja(Caja &xCaja)
{
    caja = &xCaja;
}


//      GETTERS + TOSTRING
int Inventario::getIdentificador() const
{
    return identificador;
}

string Inventario::getNombre() const
{
    return nombre;
}

ListaProducto *Inventario::getListaProducto() const
{
    return listaProducto;
}

Caja *Inventario::getCaja() const
{
    return caja;
}

string Inventario::toString() const
{
    stringstream s;

    s << "Inventario" << endl;
    s << "--< Identificador: " << identificador << endl;
    s << "--< Nombre: " << nombre << endl;
    s << listaProducto->toStringListaProducto() << endl;
    s<<caja->toString();

    return s.str();
}


//  HERENCIAS DE IADMINISTRADOR
void Inventario::insertar(Producto &xProducto)
{
    listaProducto->agregar(xProducto);
}

bool Inventario::agregarCantidades(const string &xNombre, int xCantidad)
{
    //"Si el producto no está en la lista"
    if(listaProducto->obtenerProductoPorNombre(xNombre) == nullptr)
    { return false; }
    else
    {
        int cantidadAnterior = listaProducto->obtenerProductoPorNombre(xNombre)->getCantidad();
        listaProducto->obtenerProductoPorNombre(xNombre)->setCantidad(cantidadAnterior + xCantidad);
    }
    return true;
}

bool Inventario::disminuirCantidades(const string &xNombre, int xCantidad)
{
    //"Si el producto no está en la lista"
    if(listaProducto->obtenerProductoPorNombre(xNombre) == nullptr)
    { return false; }
    else
    {
        int cantidadAnterior = listaProducto->obtenerProductoPorNombre(xNombre)->getCantidad();
        listaProducto->obtenerProductoPorNombre(xNombre)->setCantidad(cantidadAnterior - xCantidad);
        if(cantidadAnterior - xCantidad < 0)//Si cantidad da negativa
        { listaProducto->obtenerProductoPorNombre(xNombre)->setCantidad(0); }
    }
    return true;
}

void Inventario::borrar(const string &xNombre)
{
    listaProducto->eliminar(xNombre);
}

Producto *Inventario::consultar(const string &xNombre)
{
    return listaProducto->obtenerProductoPorNombre(xNombre);
}

float Inventario::consultarDinero() const
{
    return caja->getDinero();
}

void Inventario::ingresarDinero(float xDinero)
{
    caja->setDinero(caja->getDinero() + xDinero);
}

void Inventario::retirarDinero(float xDinero)
{
    if(caja->getDinero() - xDinero >= 0)
    { caja->setDinero(caja->getDinero() - xDinero); }
    else
    { caja->setDinero(0); }
}


//  HERENCIAS DE IVENDEDOR
string Inventario::realizarCompra(const string &xNombre, int xCantidad, float xPago)
{
    if (consultar(xNombre) == nullptr) { return "Producto no registrado\n"; }
    Producto &producto = *consultar((xNombre));

    if (producto.getCantidad() < xCantidad) { return "No hay suficiente en stock\n"; }
    if (producto.getPrecio()*xCantidad > xPago) { return "Pago insuficiente\n"; }

    //Realiza compra
    disminuirCantidades(xNombre,xCantidad);
    ingresarDinero(xPago);
    return caja->desgloceVuelto(xPago,producto.getPrecio()*xCantidad);
}