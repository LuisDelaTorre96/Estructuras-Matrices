//EJERCICIO 5. MAXIMO Y MINIMO
//1. Llene una matriz de 4x4 con números aleatorios
//2. Encuentre el valor máximo y su posición (fila, columna)
//3. Encuentre el valor mínimo y su posición
//4. Muestre los resultados

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Definimos las constantes para las filas y columnas
#define MAX_FILAS 4
#define MAX_COLS 4

//Declaramos las funciones antes del main
void llenarMatrizAleatoria(int matriz[MAX_FILAS][MAX_COLS]);
void imprimirMatriz(int matriz[MAX_FILAS][MAX_COLS]);
void encontrarMaxMin(int matriz[MAX_FILAS][MAX_COLS], int *max, int *min, int *filaMax, int*colMax, int *filaMin, int *colMin);

//Funcion principal
int main(void) {
    int matriz[MAX_FILAS][MAX_COLS];
    int max, min;
    int filaMax, colMax, filaMin, colMin;

	srand(time(NULL)); //Inicializar semilla aleatoria

	//Llenamos y mostramos la matriz
	llenarMatrizAleatoria(matriz);
	imprimirMatriz(matriz);

	//Buscamos el maximo y minimo en la matriz
	encontrarMaxMin(matriz, &max, &min, &filaMax, &colMax, &filaMin, &colMin);

	//Mostramos los resultados finales
	printf("\nMaximo: %d en posicion [%d][%d]\n", max, filaMax + 1, colMax + 1); //Sumamos 1 para la vizualizacion las posiciones empezando en la posicion [1][1]
	printf("Minimo: %d en posicion [%d][%d]\n", min, filaMin + 1, colMin + 1);

	return 0;
}

//Funciones

//Llenar la matriz con numeros aleatorios
void llenarMatrizAleatoria(int matriz[MAX_FILAS][MAX_COLS]){
	for(int i = 0; i < MAX_FILAS; i++){
		for(int j = 0; j < MAX_COLS; j++){
			matriz[i][j] = rand() % 50; //Generamos numeros de 0 a 50
		}
	}
}

//Imprime la matriz
void imprimirMatriz(int matriz[MAX_FILAS][MAX_COLS]){
	printf("Matriz generada con valores aleatorios entre 0 y 9:\n\n");
	for(int i = 0; i < MAX_FILAS; i++){
		for(int j = 0; j < MAX_COLS; j++){
			printf("%4d  ", matriz[i][j]);
		}
		printf("\n");
	}
}

//Recorre la matriz para encontrar el valor minimo y maximo
void encontrarMaxMin(int matriz[MAX_FILAS][MAX_COLS], int *max, int *min, int *filaMax, int*colMax, int *filaMin, int *colMin){

	//Inicializamos con el primer elemento de la matriz
	*max = *min = matriz[0][0];
	*filaMax = *colMax = *filaMin = *colMin = 0;

	//Recorremos la matriz
	for(int i = 0; i < MAX_FILAS; i++){
		for(int j = 0; j < MAX_COLS; j++){
			if(matriz[i][j] > *max){
				*max = matriz[i][j];
				*filaMax = i;
				*colMax = j;
			}
			if(matriz[i][j] < *min){
				*min = matriz[i][j];
				*filaMin = i;
				*colMin = j;
			}
		}
	}
}
