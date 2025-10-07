//EJERCICIO 3. MATRIZ CON VALORES ALEATORIOS
//1. Llene una matriz de 4x4 con números aleatorios entre 0 y 9
//2. Imprima la matriz
//3. Muestre cuántos números pares e impares hay

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Definimos las constantes para filas y columnas
#define MAX_FILAS 4
#define MAX_COLS 4

//Declaramos las funciones antes del main
void llenarMatrizAleatoria(int matriz[MAX_FILAS][MAX_COLS]);
void imprimirMatriz(int matriz[MAX_FILAS][MAX_COLS]);
void contarParesImpares(int matriz[MAX_FILAS][MAX_COLS], int *pares, int *impares);

//Funcion principal
int main(){
	int matriz[MAX_FILAS][MAX_COLS];
	int pares = 0, impares = 0;

	//Inicializar la semilla para los numeros aleatorios
	srand(time(NULL));

	llenarMatrizAleatoria(matriz);
	imprimirMatriz(matriz);
	contarParesImpares(matriz, &pares, &impares);

	//Imprimimos la cantidad de pares e impares
	printf("\n---- RESULTADO ----");
	printf("\nCantidad de numeros pares: %d\n", pares);
	printf("Cantidad de numeros impares: %d\n", impares);

	return 0;
}

//Funcion para generar numeros aleatorios del 0 al 9
void llenarMatrizAleatoria(int matriz[MAX_FILAS][MAX_COLS]){
	for(int i = 0; i < MAX_FILAS; i++){
		for(int j = 0; j < MAX_COLS; j++){
			matriz[i][j] = rand() % 10; //Genera los numeros entre 0 y 9
		}
	}
}

//Funcion para imprimir la matriz
void imprimirMatriz(int matriz[MAX_FILAS][MAX_COLS]){
	printf("Matriz generada con valores aleatorios entre 0 y 9:\n\n");
	for(int i = 0; i < MAX_FILAS; i++){
		for(int j = 0; j < MAX_COLS; j++){
			printf("%3d  ", matriz[i][j]);
		}
		printf("\n");
	}
}

//Funcion para contar los pares e impares recorriendo la matriz
void contarParesImpares(int matriz[MAX_FILAS][MAX_COLS], int *pares, int *impares){
	for(int i = 0; i < MAX_FILAS; i++){
		for(int j = 0; j < MAX_COLS; j++){
			if(matriz[i][j] % 2 == 0)
				(*pares)++;
			else
				(*impares)++;
		}
	}
}
