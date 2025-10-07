//EJERCICIO 6. SUMA POR FILAS Y COLUMNAS
//1. Genere una matriz de 4x4
//2. Calcule la suma de cada fila
//3. Calcule la suma de cada columna
//4. Presente los resultados de forma clara

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Definicion de constantes para las filas y columnas
#define MAX_FILAS 4
#define MAX_COLS 4

// Declaramos las funciones antes del Main
void llenarMatrizAleatoria(int matriz[MAX_FILAS][MAX_COLS]);
void imprimirMatrizYSumas(int matriz[MAX_FILAS][MAX_COLS],int sumaFilas[MAX_FILAS], int sumaCols[MAX_COLS]);
void calcularSumas(int matriz[MAX_FILAS][MAX_COLS], int sumaFilas[MAX_FILAS], int sumaCols[MAX_COLS]);

//Funcion principal
int main(void) {
    	int matriz[MAX_FILAS][MAX_COLS];
    	int sumaFilas[MAX_FILAS] = {0};
    	int sumaCols[MAX_COLS] = {0};

	srand(time(NULL)); // Inicializar la semilla aleatoria

	//Llenamos la matriz
    	llenarMatrizAleatoria(matriz);
    	calcularSumas(matriz, sumaFilas, sumaCols);
    	imprimirMatrizYSumas(matriz, sumaFilas, sumaCols);

    	return 0;
}

//Funciones

//Llenar la matriz con numeros aleatorios
void llenarMatrizAleatoria(int matriz[MAX_FILAS][MAX_COLS]) {
	for (int i = 0; i < MAX_FILAS; i++) {
        	for (int j = 0; j < MAX_COLS; j++) {
            		matriz[i][j] = rand() % 10; // Números de 0 a 9
        	}
    	}
}

//Calculamos la suma de las filas y columnas
void calcularSumas(int matriz[MAX_FILAS][MAX_COLS], int sumaFilas[MAX_FILAS], int sumaCols[MAX_COLS]) {
    	// Recorremos la matriz
    	for (int i = 0; i < MAX_FILAS; i++) {
        	for (int j = 0; j < MAX_COLS; j++) {
            		sumaFilas[i] += matriz[i][j];
            		sumaCols[j] += matriz[i][j];
        	}
    	}
}

//Imprime la matriz de manera ordenada
void imprimirMatrizYSumas(int matriz[MAX_FILAS][MAX_COLS], int sumaFilas[MAX_FILAS], int sumaCols[MAX_COLS]) {
    	printf("Matriz generada con valores aleatorios entre 0 y 9:\n\n");
    	for (int i = 0; i < MAX_FILAS; i++) {
        	for (int j = 0; j < MAX_COLS; j++) {
            		printf("%3d  ", matriz[i][j]);
        	}
		//Imprime la suma aun lado de cada fila
        	printf("  | Suma fila %d: %d\n", i, sumaFilas[i]);
    	}
    	printf("---\n");

	//Imprime la suma de columnas
	for(int j = 0; j < MAX_COLS; j++){
		printf("%4d", sumaCols[j]);
	}
	printf("\n");
}
