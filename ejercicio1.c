//EJERCICIO 1. DECLARACION E INICIALIZACION
//1. Declare una matriz 4x4 de tipo int.
//2. Inicialice todos los elementos en 0 usando ciclos anidados.
//3. Imprima la matriz en formato de tabla.

#include <stdio.h>

//Definimos las constantes para filas y columnas
#define MAX_FILAS 4
#define MAX_COLS 4

//Declaramos las funciones antes del main
void inicializarMatriz(int matriz[MAX_FILAS][MAX_COLS]);
void imprimirMatriz(int matriz[MAX_FILAS][MAX_COLS]);

//Funcion principal
int main(void){
	int matriz[MAX_FILAS][MAX_COLS];

	inicializarMatriz(matriz);
	imprimirMatriz(matriz);

	return 0;
}

//Funcion para inicializar la matriz en 0
void inicializarMatriz(int matriz[MAX_FILAS][MAX_COLS]){
	for(int i = 0; i < MAX_FILAS; i++){		//Recorre las filas
		for(int j = 0; j < MAX_COLS; j++){	//Recorre las columnas
			matriz[i][j] = 0;		//Asigna un valor 0 a cada elemento
		}
	}
}

//Funcion para imprimir la matriz
void imprimirMatriz(int matriz[MAX_FILAS][MAX_COLS]){
	printf("Matriz %d x %d:\n\n",MAX_FILAS, MAX_COLS);

	//De nuevo recorre filas y columnas con los dos ciclos for
	for(int i = 0; i < MAX_FILAS; i++){
		for(int j = 0; j < MAX_COLS; j++){
			printf("%d  ", matriz[i][j]);	//Imprime cada numero de la matriz
		}
		printf("\n");				//Salto de linea al terminar cada fila
	}
}
