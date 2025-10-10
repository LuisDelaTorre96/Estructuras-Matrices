// EJERCICIO 11. DIAGONAL PRINCIPAL Y SECUNDARIA
//1. Cree una matriz cuadrada de 4x4
//2. Imprima los elementos de la diagonal principal (donde i == j)
//3. Imprima los elementos de la diagonal secundaria (donde i + j == n-1)
//4. Calcule la suma de cada diagonal

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definimos las constantes para las filas y columnas
#define MAX_FILAS 4
#define MAX_COLS 4

// Declaramos funciones antes del main
void llenarMatrizAleatoria(int [MAX_FILAS][MAX_COLS]);
void imprimirMatriz(int [MAX_FILAS][MAX_COLS], const char *titulo);
void diagonalPrincipal(int A[MAX_FILAS][MAX_COLS]);
void diagonalSecundaria(int A[MAX_FILAS][MAX_COLS]);
int sumaDiagonalPrincipal(int A[MAX_FILAS][MAX_COLS]);
int sumaDiagonalSecundaria(int A[MAX_FILAS][MAX_COLS]);

// Funcion principal
int main(){
	int A[MAX_FILAS][MAX_COLS];

	srand(time(NULL)); // Inicializar semilla para numero aleatorio

	// Generamos la matriz 4 x 4
	llenarMatrizAleatoria(A);

	// Imprimimos la matriz
	imprimirMatriz(A, "Matriz A (4 x 4)");

	// Imprimimos las diagonales
	diagonalPrincipal(A);
	diagonalSecundaria(A);

	// Sumamos las diagonales
	int suma1 = sumaDiagonalPrincipal(A);
	int suma2 = sumaDiagonalSecundaria(A);

	printf("\nLa suma de la diagonal principal es: %d\n", suma1);
	printf("\nLa suma de la diagonal secundaria es: %d\n", suma2);

	return 0;
}

// Funciones

// Generar la matriz aleatoria con numeros de 0 a 9
void llenarMatrizAleatoria(int A[MAX_FILAS][MAX_COLS]){
	for(int i = 0; i < MAX_FILAS; i++){
		for(int j = 0; j < MAX_COLS; j++){
			A[i][j] = rand() % 10; // Generamos numeros de 0 a 9
		}
	}
}

// Imprimimos la matriz aleatoria
void imprimirMatriz(int A[MAX_FILAS][MAX_COLS], const char *titulo){
	printf("%s:\n", titulo);
	for(int i = 0; i < MAX_FILAS; i++){
		for(int j = 0; j < MAX_COLS; j++){
			printf("%5d", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// Mostramos la diagonal principal
void diagonalPrincipal(int A[MAX_FILAS][MAX_COLS]){
	printf("La diagonal principal es: ");
	for(int i =0; i < MAX_FILAS; i++){
		printf("%d%s", A[i][i], (i < MAX_FILAS - 1 ? " " : ""));
	}
	printf("\n");
}

// Mostramos la diagonal secundaria
void diagonalSecundaria(int A[MAX_FILAS][MAX_COLS]){
	printf("La diagonal secundaria es: ");
	for(int i = 0; i < MAX_FILAS; i++){
		int j = MAX_FILAS - 1 - i;
		printf("%d%s", A[i][j], (i < MAX_FILAS - 1 ? " " : ""));
	}
	printf("\n");
}

// Realiza la suma de la diagonal principal
int sumaDiagonalPrincipal(int A[MAX_FILAS][MAX_COLS]){
	int suma = 0;
	for (int i = 0; i < MAX_FILAS; i++){
		suma += A[i][i];
	}
	return suma;
}

// Realiza la suma de la diagonal secundaria
int sumaDiagonalSecundaria(int A[MAX_FILAS][MAX_COLS]){
	int suma = 0;
	for (int i = 0; i < MAX_FILAS; i++){
		suma += A[i][MAX_FILAS - 1 - i];
	}
	return suma;
}
