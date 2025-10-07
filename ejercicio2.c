//EJERCICIO 2. LLENAR MATRIZ MANUALMENTE
//1. Pida al usuario ingresar los 16 valores de la matriz
//2. Almacene cada valor en su posicion correspondiente
//3. Imprima la matriz completa al finalizar

#include <stdio.h>

//Definimos las constantes para filas y columnas
#define MAX_FILAS 4
#define MAX_COLS 4

//Declaramos las funciones antes del main
void ingresarMatriz(int matriz[MAX_FILAS][MAX_COLS]);
void imprimirMatriz(int matriz[MAX_FILAS][MAX_COLS]);

//Funcion principal
int main(){
	int matriz[MAX_FILAS][MAX_COLS];

	ingresarMatriz(matriz);
	imprimirMatriz(matriz);

	return 0;
}

//Funcion para ingresar los datos a la matriz
void ingresarMatriz(int matriz[MAX_FILAS][MAX_COLS]){
	printf("Ingrese los valores de la matriz segun su posicion: \n");
	for(int i = 0; i < MAX_FILAS; i++){
		for(int j = 0; j < MAX_COLS; j++){
			printf("[%d][%d] = ", i + 1, j + 1); //Se utiliza + 1 para que el usuario visualmente vea que la matriz empieza en la posicion [1][1]
			scanf("%d", &matriz[i][j]); //Guarda el valor ingresado en la posicion correcta
		}
	}
}

//Funcion para imprimir la matriz
void imprimirMatriz(int matriz[MAX_FILAS][MAX_COLS]){
	printf("\nMatriz ingresada %d x %d\n\n", MAX_FILAS, MAX_COLS);
	for(int i = 0; i < MAX_FILAS; i++){
		for(int j = 0; j < MAX_COLS; j++){
			printf("%d  ", matriz[i][j]);
		}
		printf("\n");
	}
}
