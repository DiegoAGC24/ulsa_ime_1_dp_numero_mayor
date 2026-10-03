# Práctica 5: El mayor de tres números

> **En esta práctica todo es tuyo:** el análisis, la receta, el código y las pruebas. Llena cada sección en la fase que se indica.

## 1. Descripción del problema (Fase 1)
Mi programa pide tres números al usuario y determina cuál de los tres es el mayor. Puede servir en mecatrónica para comparar tres mediciones, por ejemplo, para detectar cuál sensor registra el valor más alto.

## 2. Entradas y salidas (Fase 1)
<!-- Define cada entrada y cada salida, con su tipo de dato y su objetivo. -->

**Entradas:**
1. Número 1: tipo double, primer número que introduce el usuario.
2. Número 2: tipo double, segundo número que introduce el usuario.
3. Número 3: tipo double, tercer número que introduce el usuario.

**Salida:**
1. El número mayor: tipo double, muestra el valor más grande de los tres números.

**¿Muestro el valor del mayor o cuál de los tres fue (primero, segundo o tercero)? ¿Por qué?**
Muestro el valor del mayor porque el objetivo principal del programa es saber cuál de los tres números tiene el valor más alto.

**¿Qué función de `utilerias.h` uso para leer los números? ¿Por qué esa y no la otra?**
Uso leerDecimal() porque permite ingresar números enteros y números con decimales. La función leerEntero() solamente permite números enteros.

## 3. Restricciones e invariante (Fases 1 y 2)

**Restricciones** (¿qué debe cumplirse?):
- El usuario debe introducir tres números válidos.
- Los tres números deben poder ser leídos correctamente como valores double.

**¿Hace falta validar el rango de los números (por ejemplo, rechazar el 0 o los negativos)? ¿Por qué?**
No hace falta validar un rango porque cualquier número puede ser comparado, incluyendo el 0, números negativos y números positivos.

**¿Qué hace mi programa cuando dos números son iguales y son los mayores? ¿Y cuando los tres son iguales?**
Si dos números son iguales y son los mayores, el programa muestra ese valor una sola vez. Si los tres números son iguales, también muestra ese mismo valor una sola vez.

**¿Quién detecta cada error?** (¿qué revisa la función de `utilerias.h` y qué reviso yo?)
leerDecimal() se encarga de detectar cuando el usuario introduce un dato que no puede convertirse correctamente en un número decimal y vuelve a pedir el dato. Mi programa se encarga de comparar los tres números y encontrar el mayor.

**Invariante** (justo antes de mostrar el resultado, ¿qué es seguro sobre el valor que voy a mostrar?):
Justo antes de mostrar el resultado, la variable mayor contiene uno de los tres números y su valor es mayor o igual que los otros dos.

## 4. Casos resueltos a mano (Fase 1)

| Caso | Número 1 | Número 2 | Número 3 | Mayor calculado a mano |
|---|---|---|---|---|
| 1 (el mayor en primera posición) | 9 | 4 | 2 | 9 |
| 2 (el mayor en segunda posición) | 4 | 9 | 2 | 9 |
| 3 (el mayor en tercera posición) | 2 | 4 | 9 | 9 |
| 4 (con un empate) | 7 | 7 | 3 | 7 |
| 5 (con negativos) | -4 | -1 | -9 | -1 |

## 5. Receta en pseudocódigo (Fase 2)
<!-- Tu receta va en el archivo RECETA.md. Aquí solo responde las preguntas. -->

**¿Probé mi receta a mano con mis 5 casos?** Sí 
**¿Tuve que corregirla? ¿Qué cambié?** Sí. Revisé las condiciones para asegurarme de que funcionaran también cuando hubiera números iguales.
**¿Cuántas versiones de mi receta escribí hasta la final?** 2 versiones.
**¿Se me ocurrió otra forma de resolver el problema? ¿Cuál? ¿Por qué elegí la que usé?**
Sí. También pensé en comparar cada número con los otros dos directamente. Elegí usar una variable mayor y revisar los números mediante if, else if y else porque me pareció una forma clara de seguir paso por paso cuál es el mayor.

## 6. Cómo compilar y ejecutar (Fase 3)

```bash
g++ -Wall -Wextra -std=c++17 main.cpp -o numero_mayor
./numero_mayor
```

## 7. Ejemplo de ejecución (Fase 3)
Bienvenido a mi programa para encontrar el mayor de tres numeros
Ingresa el primer numero: 7 
Ingresa el segundo numero: 7 
Ingresa el tercer numero: 3 
El numero mayor es: 7

## 8. De la receta al código (Fase 3)
<!-- Para cada paso de TU receta, escribe la instrucción (o instrucciones) de C++ que lo implementa. Agrega las filas que necesites. -->

| Paso de la receta | Instrucción de C++ que lo implementa |
|---|---|
| 1. Mensaje de bienvenida | std::cout << "Bienvenido a mi programa para encontrar el mayor de tres numeros\n"; |
| 2. Leer el primer número | numero1 = leerDecimal("Ingresa el primer numero: "); |
| 3. Leer el segundo número | numero2 = leerDecimal("Ingresa el segundo numero: "); |
| 4. Leer el tercer número | numero3 = leerDecimal("Ingresa el tercer numero: "); |
| 5. Comparar los tres números y guardar el mayor | if, else if y else para asignar el valor a mayor |
| 6. Mostrar el resultado | std::cout << "El numero mayor es: " << mayor << "\n"; |

**¿Hubo algún paso de mi receta que me costó traducir a C++? ¿Cuál y por qué?**
Sí. La parte que más me costó fue convertir la comparación de los tres números en condiciones if y else if, porque tenía que considerar también los empates.

## 9. Experimentos (Fase 3)

**Experimento A: ¿qué te dijo el compilador con `if (a > b > c)`? ¿Qué mostró el programa con 3, 2 y 1? ¿Por qué?**
El compilador mostró una advertencia porque a > b > c no funciona como una comparación matemática de los tres números. Primero se calcula a > b, que produce true o false, y después ese resultado se compara con c. Con 3, 2 y 1 puede producir un resultado incorrecto. La forma correcta es utilizar condiciones unidas con &&.

**Experimento B: al cambiar `>=` por `>` (o al revés), ¿qué mostró el programa con 7, 7, 3 y con 5, 5, 5? ¿Por qué?**
Al usar >=, los casos de empate siguen entrando en una condición y el programa muestra el valor mayor. Al usar solamente >, una condición puede dejar de cumplirse cuando los números son iguales, por lo que los empates pueden producir un resultado incorrecto o hacer que se ejecute otra condición. Por eso dejé >= en la versión final.

**Experimento C (opcional): con `if (a = b)`, ¿qué te dijo el compilador? ¿Qué le pasó al valor de `a`?**
No realicé este experimento porque era opcional.

## 10. Tabla de pruebas (Fase 4)

| Caso | Entradas | Esperado | Obtenido | ¿Pasó? |
|---|---|---|---|---|
| Mayor primero | 9, 4, 2 | 9 | 9 | Sí |
| Mayor en medio | 4, 9, 2 | 9 | 9 | Sí |
| Mayor al final | 2, 4, 9 | 9 | 9 | Sí |
| Empate arriba (1.º y 2.º) | 7, 7, 3 | 7 | 7 | Sí |
| Empate arriba (1.º y 3.º) | 7, 3, 7 | 7 | 7 | Sí |
| Empate abajo | 8, 3, 3 | 8 | 8 | Sí |
| Los tres iguales | 5, 5, 5 | 5 | 5 | Sí |
| Todos negativos | -4, -1, -9 | -1 | -1 | Sí |
| Con cero | -2, 0, -5 | 0 | 0 | Sí |
| Decimales cercanos | 2.5, 2.7, 2.6 | 2.7 | 2.7 | Sí |
| Texto | `abc` (luego 3), 1, 2 | vuelve a pedir el dato; 3 | vuelve a pedir el dato; 3 | Sí |
| Caso propio 1 | 100, 50, 75 | 100 | 100 | Sí |
| Caso propio 2 | -10, -20, -5 | -5 | -5 | Sí |

## 11. Bitácora de mejoras (Fase 4)

| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | Quise asegurarme de que los empates funcionaran correctamente. | Utilicé >= en las comparaciones. | Sí |
| 2 | Quise comprobar que el programa aceptara números negativos y decimales. | Utilicé variables double y leerDecimal(). | Sí |

**Reto elegido (opcional):** _____

## 12. Dudas para el profesor (Fase 3)

| Duda | Lo que ya intenté |
|---|---|
| ¿Cuál sería la forma más sencilla de generalizar este programa para encontrar el mayor de varios números? | Ya resolví el problema comparando los tres números mediante if, else if y else. |

## 13. Reflexión final

**¿Qué aprendí con esta práctica?**
Aprendí a utilizar if, else if y else para tomar decisiones y a utilizar operadores de comparación y lógicos. También aprendí que es importante considerar casos como empates, números negativos, cero y decimales antes de programar.

**Ahora que terminé, ¿qué cambiaría de mi proceso?**
Primero pensaría en más casos de prueba antes de comenzar a programar para asegurarme de que mi receta considere todas las posibilidades.

**¿Qué fue lo más difícil y cómo lo resolví?**
Lo más difícil fue pensar en las condiciones para los empates. Lo resolví probando diferentes casos y utilizando >= para que los valores iguales también fueran considerados.

**¿Qué pregunta me quedó sin responder?**
Me quedó la duda de cuál sería la forma más eficiente de encontrar el mayor cuando se tienen muchos números.

**¿Qué fue más fácil para mí: la Práctica 3 (receta propia con un paso de ejemplo), la 4 (receta ajena) o esta (todo desde cero)? ¿Por qué?**
La Práctica 4 fue más fácil porque la receta ya estaba hecha. Esta práctica fue un poco más difícil porque tuve que pensar y diseñar la solución desde cero.

**¿Pensé en los empates antes de programar o los descubrí al probar?**
Sí pensé en los empates antes de programar porque la práctica indicaba que era uno de los casos que debía considerar.

## 14. Lista de verificación antes de entregar (Fase 5)

- [x ] Llené las secciones 1 a 13 (no quedan `_____`)
- [x ] Escribí mi receta completa en `RECETA.md` antes de programar
- [x ] Cada bloque de `main.cpp` tiene su comentario `// Paso N`, de acuerdo con mi receta
- [x ] Mi programa compila sin advertencias
- [x ] Probé todos los casos de la tabla, incluidos los empates
- [x ] Hice los Experimentos A y B y dejé el código correcto al terminar
- [x ] No modifiqué `utilerias.h`
- [x ] Hice al menos 3 commits con mensajes claros
- [x ] Hice `git push` y verifiqué mi fork en GitHub
- [x ] Mi fork se llama `ulsa_ime_1_dp_numero_mayor` y el código está en `main.cpp`
- [x ] Entregué el enlace de mi fork en Classroom