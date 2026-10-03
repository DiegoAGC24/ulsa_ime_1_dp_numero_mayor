# Receta: El mayor de tres números

<!-- Escribe aquí tu receta completa en pseudocódigo, ANTES de programar.
     El primer paso es solo un ejemplo del formato; el resto de la receta es completamente tuyo.
     Si la corriges después de probarla a mano, deja aquí la versión final. -->

``` text
1. MOSTRAR "Bienvenido a mi programa"

```
2. LEER numero1 usando leerDecimal("Ingresa el primer numero: ")
3. LEER numero2 usando leerDecimal("Ingresa el segundo numero: ")
4. LEER numero3 usando leerDecimal("Ingresa el tercer numero: ")
5. SI numero1 >= numero2 Y numero1 >= numero3 ENTONCES
   mayor ← numero1 
SINO SI numero2 >= numero1 Y numero2 >= numero3 ENTONCES
   mayor ← numero2 
SINO 
   mayor ← numero3
FIN SI
6. MOSTRAR "El numero mayor es: " + mayor
7. FIN