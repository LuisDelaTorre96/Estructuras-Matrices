//EJERCICIO 7. SUMA DE MATRICES
//1. Cree dos matrices A y B de 4x4
//2. Sume ambas matrices: C[i][j] = A[i][j] + B[i][j]
//3. Muestre las tres matrices (A, B y C)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Definicion de constantes para filas y columnas
#define MAX_FILAS 4
#define MAX_COLS 4

// Declaramos las funciones antes del Main
void llenarMatrizAleatoria(int matriz[MAX_FILAS][MAX_COLS]);
void imprimirMatriz(int matriz[MAX_FILAS][MAX_COLS], char nombre);
void sumarMatrices(int A[MAX_FILAS][MAX_COLS], int B[MAX_FILAS][MAX_COLS], int C[MAX_FILAS][MAX_COLS]);

//Funcion principal
int main(void) {
    	int A[MAX_FILAS][MAX_COLS];
    	int B[MAX_FILAS][MAX_COLS];
    	int C[MAX_FILAS][MAX_COLS];

    	srand(time(NULL)); // Inicializa la semilla aleatoria

    	// Llenamos la matriz
    	llenarMatrizAleatoria(A);
    	llenarMatrizAleatoria(B);

    	// Calcular la suma: C = A + B
    	sumarMatrices(A, B, C);

    	// Mostrar las tres matrices
	printf("==== SUMA DE MATRICES ====\n\n");
    	printf("---- MATRIZ A ----\n");
    	imprimirMatriz(A, 'A');

    	printf("\n---- MATRIZ B ----\n");
    	imprimirMatriz(B, 'B');

    	printf("\n---- MATRIZ C (A + B) ----\n");
    	imprimirMatriz(C, 'C');

    	return 0;
}

//Funciones

//Llenar la matriz con numeros aleatorios
void llenarMatrizAleatoria(int matriz[MAX_FILAS][MAX_COLS]) {
    	for (int i = 0; i < MAX_FILAS; i++) {
        	for (int j = 0; j < MAX_COLS; j++) {
            		matriz[i][j] = rand() % 10; // Genera números de 0 a 9
        	}
    	}
}

//Imprimir las matrices (A, B y C)
void imprimirMatriz(int matriz[MAX_FILAS][MAX_COLS], char nombre) {
    	for (int i = 0; i < MAX_FILAS; i++) {
        	for (int j = 0; j < MAX_COLS; j++) {
            		printf("%3d", matriz[i][j]);
        	}
        	printf("\n");
    	}
}

//Sumamos las matrices A + B = C
void sumarMatrices(int A[MAX_FILAS][MAX_COLS], int B[MAX_FILAS][MAX_COLS], int C[MAX_FILAS][MAX_COLS]) {
    	for (int i = 0; i < MAX_FILAS; i++) {
        	for (int j = 0; j < MAX_COLS; j++) {
            		C[i][j] = A[i][j] + B[i][j];
        	}
    	}
}
