# Práctica de Laboratorio: Manejo de Matrices en C
*A este repositorio hacerle fork*

- https://youtu.be/-n8Wildyg8s?list=TLPQMDExMDIwMjWfVzvy6j5usQ

## Objetivo
Aprender y dominar el manejo de matrices (arreglos bidimensionales) en lenguaje C, incluyendo declaración, inicialización, recorrido y operaciones básicas y avanzadas.

---

## Conocimientos Previos Necesarios
- Variables y tipos de datos
- Estructuras de control (if, for, while)
- Arreglos unidimensionales
- Funciones básicas

---

## Ejercicio 1: Declaración e Inicialización

Crea un programa que:
1. Declare una matriz de 4x4 de tipo `int`
2. Inicialice todos los elementos en 0 usando ciclos anidados
3. Imprima la matriz en formato de tabla

**Conceptos a practicar:**
- Declaración: `int matriz[4][4];`
- Ciclos anidados para recorrer filas y columnas
- Función `printf()` para imprimir con formato

**Salida esperada:**
```
0  0  0
0  0  0
0  0  0
```

---

## Ejercicio 2: Llenar Matriz Manualmente

Crea un programa que:
1. Pida al usuario ingresar los 16 valores de la matriz
2. Almacene cada valor en su posición correspondiente
3. Imprima la matriz completa al finalizar

**Pista:** Usa `scanf("%d", &matriz[i][j]);` dentro de los ciclos anidados.

---

### Ejercicio 3: Matriz con Valores Aleatorios

Crea un programa que:
1. Llene una matriz de 4x4 con números aleatorios entre 0 y 9
2. Imprima la matriz
3. Muestre cuántos números pares e impares hay

**Funciones necesarias:**
```c
#include <stdlib.h>
#include <time.h>

srand(time(NULL));  // Inicializar semilla
int num = rand() % 9 + 1;  // Número aleatorio entre 1 y 50
```

---

## Ejercicio 4: Suma de Elementos

Escribe un programa que:
1. Cree una matriz de 4x4 con valores aleatorios
2. Calcule la suma de todos los elementos
3. Calcule el promedio de los elementos
4. Muestre ambos resultados

---

## Ejercicio 5: Máximo y Mínimo

Desarrolla un programa que:
1. Llene una matriz de 4x4 con números aleatorios
2. Encuentre el valor máximo y su posición (fila, columna)
3. Encuentre el valor mínimo y su posición
4. Muestre los resultados

**Ejemplo de salida:**
```
Máximo: 95 en posición [2][3]
Mínimo: 7 en posición [0][1]
```

---

## Ejercicio 6: Suma por Filas y Columnas

Crea un programa que:
1. Genere una matriz de 4x4
2. Calcule la suma de cada fila
3. Calcule la suma de cada columna
4. Presente los resultados de forma clara

**Salida esperada:**
```
Matriz:
 5  8  3  2  | Suma fila 0: 18
 1  9  4  7  | Suma fila 1: 21
 6  2  5  3  | Suma fila 2: 16
 4  7  1  8  | Suma fila 3: 20
---
Suma columnas: 16  26  13  20
```

---


## Ejercicio 7: Suma de Matrices

Implementa un programa que:
1. Cree dos matrices A y B de 4x4
2. Sume ambas matrices: C[i][j] = A[i][j] + B[i][j]
3. Muestre las tres matrices (A, B y C)

**Nota:** La suma de matrices requiere que ambas tengan las mismas dimensiones.

---

## Ejercicio 8: Resta de Matrices

Similar al ejercicio anterior (7), pero realizando la resta: C[i][j] = A[i][j] - B[i][j]

---

## Ejercicio 9: Multiplicación de Matrices

Desarrolla un programa que multiplique dos matrices siguiendo las reglas del álgebra lineal:

**Reglas:**
- Una matriz A de dimensión (m×n) solo puede multiplicarse por una matriz B de dimensión (n×p)
- El resultado C será de dimensión (m×p)
- Fórmula: C[i][j] = Σ(A[i][k] × B[k][j]) para k de 0 a n-1

**Ejemplo:**
```
A (2×3)     B (3×2)     C (2×2)
1 2 3       1 4         22 28
4 5 6   ×   2 5    =    49 64
            3 6
```

**Desafío:** Primero verifica que las dimensiones permitan la multiplicación.

---


## Ejercicio 10: Matriz Transpuesta

La transpuesta de una matriz intercambia filas por columnas.

Crea un programa que:
1. Genere una matriz A de 3x4
2. Calcule su transpuesta AT (que será 4x3)
3. Muestre ambas matrices

**Fórmula:** AT[j][i] = A[i][j]

---

## Ejercicio 11: Diagonal Principal y Secundaria

Para matrices cuadradas (n×n):

Desarrolla un programa que:
1. Cree una matriz cuadrada de 4x4
2. Imprima los elementos de la diagonal principal (donde i == j)
3. Imprima los elementos de la diagonal secundaria (donde i + j == n-1)
4. Calcule la suma de cada diagonal

---


## Ejercicio 12: Buscar Elemento

Crea un programa que:
1. Genere una matriz de 4x4
2. Pida al usuario un número a buscar
3. Indique si existe y muestre todas las posiciones donde aparece
4. Si no existe, muestre un mensaje apropiado

---


**Requisitos:**
- Usar funciones para cada operación
- Validar dimensiones antes de operar
- Manejar errores (divisiones, dimensiones incompatibles)
- Código bien comentado
- Entrega via url del codigo en github
- Archivo de la practica matrices.cpp
- Crear si es necesario una libreria


---

## Rúbrica de Evaluación

https://github.com/pakoite/ite/blob/main/Rubrica_Evaluacion_C.md

---

## Consejos y Buenas Prácticas

1. **Usa constantes para dimensiones:**
   ```c
   #define MAX_FILAS 10
   #define MAX_COLS 10
   ```

2. **Crea funciones reutilizables:**
   - Cada operación debe ser una función separada
   - Facilita el debugging y mantenimiento

3. **Valida entradas del usuario:**
   - Verifica que las dimensiones sean válidas
   - Comprueba compatibilidad antes de operar

4. **Comenta tu código:**
   - Explica qué hace cada función
   - Documenta algoritmos complejos

5. **Prueba con casos extremos:**
   - Matrices de 1x1
   - Matrices grandes
   - Valores negativos

---

## Recursos Adicionales

**Para profundizar:**
- Matrices dispersas (sparse matrices)
- Determinantes de matrices
- Inversas de matrices
- Matrices tridimensionales

**Documentación:**
- Manual de referencia de C: cppreference.com
- https://www.programiz.com/c-programming/c-multi-dimensional-arrays

---

## Entrega

**Formato:** Archivo .c o .cpp compilable con comentarios

**Plazo:** 4 de Octubre del 2025, hora 11:59 PM

**Forma:** Repositorio de git

**Incluir:**
- Código fuente completo
- Capturas de pantalla de ejecución
- Breve reporte (1-2 páginas) explicando los desafíos encontrados

---

