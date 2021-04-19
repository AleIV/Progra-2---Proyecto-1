#include "MenuPrincipal.h"

int main()
{
    auto *menuPrincipal = new MenuPrincipal();
    menuPrincipal->mostrarMenuPrincipal();
    return 0;
}

/* NOTA IMPORTANTE: Lo siguiente está repartido en los archivos,
 *                  pero aquí está tödo junto para facilitarlo
 *                  y no navegar entre todos los archivos
 *
 * S – Single Responsibility Principle (SRP)
 *    1) Cada clase debe tener una sola responsabilidad.
 *          Este principio se aplica en todas las clases del programa.
 *          Ejemplo:
 *             -Clase Fecha funciona para crear objetos que manejen solo fechas específicas,
 *             esto utilizando sus atributos (dia, mes año) para indicar la fecha exacta
 *             Incluye algunos métodos para solicitar información mas especifica,
 *             como la diferencia de días entre una fecha y otra
 *             pero siempre manteniendo el principio de su única responsabilidad
 *
 * O – Open/Closed Principle (OCP)
 *    1) Un programa debe estar abierto a su extensión y cerrado para su modificación.
 *          Este principio se puede visualizar mejor en programas mucho mas completos
 *          y construidos desde un principio para ser escalables.
 *          Ejemplos:
 *             -En Articulo y Servicio se pueden añadir funciones sin alterar Producto
 *             -A ListaProducto se le pueden extender funcionalidades que Inventario (sin ser modificado) puede aprovechar
 *             -Fecha puede ampliar funciones para no solo guardar una fecha
 *             por ejemplo, métodos para desplegar mas información de la fecha
 *             Eso no cambia el principio S, pues solo extiende función mas no responsabilidad.
 *
 * L - Liskov (No se solicitó)
 *
 * I – Interface Segregation Principle (ISP)
 *    1) Es mejor muchas clases pequeñas y especializadas para cubrir mejor las necesidades del programa.
 *          Este principio se puede observar en las clases de los menú: menuAdministrador, menuVenta y menuPrincipal.
 *          A pesar de ser todas menú, al estar separadas en secciones pueden cubrir cada necesidad
 *          sin sobrecargar al usuario con opciones de otro menú que no necesitaría si todos los menú fuesen uno.
 *
 * D – Dependency Inversion Principle (DIP)
 *    1) Los módulos de alto nivel no deben depender de los módulos de bajo nivel. Ambos deben depender de abstracciones.
 *    2) Abstracciones no deben depender de detalles. Detalles debe depender de abstracciones.
 *          Este principio se puede apreciar (Al menos el segundo punto) en la relación de Producto y sus hijas
 *          Los detalles (Articulo y Servicio) deben depender de los métodos heredados (abstractos) de Producto para ser útiles en el proyecto
 */