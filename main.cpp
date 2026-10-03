// Práctica 5: El mayor de tres números
// Traduce TU receta de RECETA.md a C++, paso por paso.
// Deja el comentario "// Paso N" sobre cada bloque, con la numeración de TU receta.

#include <iostream>
#include "utilerias.h"

int main() {
    // Variables
    double numero1 = 0;
    double numero2 = 0;
    double numero3 = 0;
    double mayor = 0;

    // Paso 1: mensaje de bienvenida
    std::cout << "Bienvenido a mi programa para encontrar el mayor de tres numeros\n";

    // Paso 2: leer los tres numeros
    numero1 = leerDecimal("Ingresa el primer numero: ");
    numero2 = leerDecimal("Ingresa el segundo numero: ");
    numero3 = leerDecimal("Ingresa el tercer numero: ");

    // Paso 3: determinar cual es el mayor
    if (numero1 >= numero2 && numero1 >= numero3) {
        mayor = numero1;
    } else if (numero2 >= numero1 && numero2 >= numero3) {
        mayor = numero2;
    } else {
        mayor = numero3;
    }

    // Paso 4: mostrar el resultado
    std::cout << "El numero mayor es: " << mayor << "\n";

    return 0;
}