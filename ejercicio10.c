//EJERCICIO 10. MATRIZ TRANSPUESTA
//1. Genere una matriz A de 3 x 4
//2. Calcule su transpuesta AT (que sera 4 x 3)
//3. Muestre ambas matrices

//Formula: AT[j][i] = A[i][j]

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definicion de constantes para filas y columnas
#define MAX_FILAS 4
#define MAX_COLS 4

// Declaramos las funciones
void llenarMatrizAleatoria(int filas, int cols, int matriz[MAX_FILAS][MAX_COLS]);
void imprimirMatriz(int filas, int cols, int matriz[MAX_FILAS][MAX_COLS], const char *titulo);
void transponerMatriz(int filas, int cols, int A[MAX_FILAS][MAX_COLS], int AT[MAX_FILAS][MAX_COLS]);

int main(){
	int filas = 3, cols = 4;

	int A[MAX_FILAS][MAX_COLS];
	int AT[MAX_FILAS][MAX_COLS];

	srand(time(NULL)); //Inicializar semilla

	printf("---- MATRIZ TRANSPUESTA ----\n\n");

	// Llenamos la matriz con numeros aleatorios
	llenarMatrizAleatoria(filas, cols, A);

	// Calculamos las transpuesta
	transponerMatriz(filas, cols, A, AT);

	// Mostramos las matrices
	imprimirMatriz(filas, cols, A, "Matriz original A (3 x 4)");
	imprimirMatriz(cols, filas, AT, "Matriz transpuesta (4 x 3)");

	return 0;
}

// Funciones

//Llenamos la matriz con numeros aleatorios de 0 a 9
void llenarMatrizAleatoria(int filas, int cols, int matriz[MAX_FILAS][MAX_COLS]){
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < cols; j++){
			matriz[i][j] = rand() % 10; // Generamos numeros aleatorios de 0 a 9
		}
	}
}

// Imprimimos la matriz
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

// Calculamos la transpuesta
void transponerMatriz(int filas, int cols, int A[MAX_FILAS][MAX_COLS], int AT[MAX_FILAS][MAX_COLS]){
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < cols; j++){
			AT[j][i] = A[i][j];
		}
	}
}
