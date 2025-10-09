// EJERCICIO 9. MULTIPLICACION DE MATRICES
// Desarrolla un programa que multiplique dos matrices siguiendo las reglas del álgebra lineal:
// Reglas:

// 1. Una matriz A de dimensión (m×n) solo puede multiplicarse por una matriz B de dimensión (n×p)
// 2. El resultado C será de dimensión (m×p)
// 3. Fórmula: C[i][j] = Σ(A[i][k] × B[k][j]) para k de 0 a n-1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definimos un limite maximo para las dimensiones
#define MAX_FILAS 20
#define MAX_COLS 20

// Declaramos las funciones
void leerMatriz(int filas, int cols, int matriz[MAX_FILAS][MAX_COLS], char nombre);
void imprimirMatriz(int filas, int cols, int matriz[MAX_FILAS][MAX_COLS], const char *titulo);
void multiplicarMatrices(int m, int n, int p, int A[MAX_FILAS][MAX_COLS], int B[MAX_FILAS][MAX_COLS], int C[MAX_FILAS][MAX_COLS]);

// Funcion principal
int main(){
	int filasA, colsA, filasB, colsB;

	printf("---- CALCULADORA DE MATRICES ----\n\n");

	// Pedimos las dimensiones al usuario
	printf("Ingrese las filas de A (max %d): ", MAX_FILAS);
	scanf("%d", &filasA);
	printf("Ingrese las columnas de A (max %d): ", MAX_COLS);
	scanf("%d", &colsA);

	printf("Ingrese las filas de B (max %d): ", MAX_FILAS);
	scanf("%d", &filasB);
	printf("Ingrese las columnas de B (max %d): ", MAX_COLS);
	scanf("%d", &colsB);

	// Validamos las dimensiones
	if(filasA <= 0 || colsA <= 0 || filasB <= 0 || colsB <= 0 || filasA > MAX_FILAS || colsA > MAX_COLS || filasB > MAX_FILAS || colsB > MAX_COLS){
		printf("\nERROR! Las dimensiones deben ser positivas y no mayores que %d.", MAX_FILAS);

		return 0;
	}

	// Validamos que pueda realizarse la multiplicacion
	if(colsA != filasB){
		printf("\nERROR! No se pueden multiplicar A(%d x %d) x B(%d x %d)\n", filasA, colsA, filasB, colsB);
		printf("Regla: columnas de A (%d) deben ser iguales a filas de B (%d).\n", colsA, filasB);

		return 0;
	}

	int A[MAX_FILAS][MAX_COLS];
	int B[MAX_FILAS][MAX_COLS];
	int C[MAX_FILAS][MAX_COLS];

	// Leemos las matrices
	printf("\n--- Ingrese los elemntos de A (%d x %d) ---\n", filasA, colsA);
	leerMatriz(filasA, colsA, A, 'A');

	printf("\n--- Ingrese los elemntos de B (%d x %d) ---\n", filasB, colsB);
	leerMatriz(filasB, colsB, B, 'B');

	// Multiplicamos las matrices
	multiplicarMatrices(filasA, colsA, colsB, A, B, C);

	// Mostramos el resultado
	printf("\n---- RESULTADO ----\n\n");

	imprimirMatriz(filasA, colsA, A, "MATRIZ A");
	imprimirMatriz(filasB, colsB, B, "MATRIZ B");
	imprimirMatriz(filasA, colsB, C, "MATRIZ C = A X B");

	return 0;
}

// Funciones
void leerMatriz(int filas, int cols, int matriz[MAX_FILAS][MAX_COLS], char nombre){
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < cols; j++){
			printf("%c[%d][%d]: ", nombre, i + 1, j + 1);
			scanf("%d", &matriz[i][j]);
		}
	}
}

void imprimirMatriz(int filas, int cols, int matriz[MAX_FILAS][MAX_COLS], const char *titulo){
	printf("%s:\n", titulo);
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < cols; j++){
			printf("%5d", matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void multiplicarMatrices(int m, int n, int p, int A[MAX_FILAS][MAX_COLS], int B[MAX_FILAS][MAX_COLS], int C[MAX_FILAS][MAX_COLS]){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < p; j++){
			C[i][j] = 0;
			for(int k = 0; k < n; k++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}
