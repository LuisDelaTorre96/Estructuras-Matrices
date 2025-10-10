//EJERCICIO 12. BUSCAR ELEMENTO
//1. Genere una matriz de 4x4
//2. Pida al usuario un número a buscar
//3. Indique si existe y muestre todas las posiciones donde aparece
//4. Si no existe, muestre un mensaje apropiado


// NOTA: NO ME QUEDO CLARO SI SE DEBE MOSTRAR LA MATRIZ O NO, ANTES DE PEDIR BUSCAR UN NUMERO
// OPTE POR PRIMERO PEDIR UN NUMERO A BUSCAR, DESPUES MOSTRAR LA MATRIZ Y LUEGO MOSTRAR SI ESTA O NO, EL NUMERO INGRESADO

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definimos las constantes para la matriz
#define MAX_FILAS 4
#define MAX_COLS 4

// Funciones antes del main
void generarMatrizAleatoria(int A[MAX_FILAS][MAX_COLS]);
int buscarElemento(int A[MAX_FILAS][MAX_COLS], int num);
void imprimirMatriz(int A[MAX_FILAS][MAX_COLS], const char *titulo);

// Funcion principal
int main(){
	int A[MAX_FILAS][MAX_COLS];
	int num;

	printf("--- BUSCAR ELEMENTO EN UNA MATRIZ 4 x 4 ---\n\n");

	// Sembramos la semilla para numeros aleatorios
	srand(time(NULL));

	// Generamos la matriz
	generarMatrizAleatoria(A);

	// Pedimos al usuario un elemento a buscar
	printf("Ingrese un numero a buscar en la matriz: ");
	scanf("%d", &num);

	// Mostramos la matriz
	imprimirMatriz(A, "MATRIZ A (4 x 4)");

	// Buscamos el elemento
	int apariciones = buscarElemento(A, num);

	if (apariciones == 0){
		printf("\nEl numero %d NO se encuentra en la matriz.\n", num);
	} else {
		printf("\nEl numero %d aparece %d %s.\n", num, apariciones, (apariciones == 1 ? "vez" : "veces"));
	}

	return 0;
}

// Funciones

// Generamos la matriz con numeros aleatorios de 0 a 9
void generarMatrizAleatoria(int A[MAX_FILAS][MAX_COLS]){
	for(int i = 0; i < MAX_FILAS; i++){
		for(int j = 0; j < MAX_COLS; j++){
			A[i][j] = rand() % 10;
		}
	}
}

//Imprimimos la matriz
void imprimirMatriz(int A[MAX_FILAS][MAX_COLS], const char *titulo){
	printf("\n%s:\n", titulo);
	for(int i = 0; i < MAX_FILAS; i++){
		for(int j = 0; j < MAX_COLS; j++){
			printf("%5d", A[i][j]);
		}
		printf("\n");
	}
}

// Recorre la matriz y muestra todas las posiciones donde aparece el numero ingresado
int buscarElemento(int A[MAX_FILAS][MAX_COLS], int num){
	int contador = 0;
	printf("\nBuscando el numero %d...\n", num);
	for(int i = 0; i < MAX_FILAS; i++){
		for(int j = 0; j < MAX_COLS; j++){
			if(A[i][j] == num){
				if(contador = 0){
					printf("El numero se encontro en las posiciones:\n");
				}
				printf("A[%d][%d]\n", i + 1, j + 1);

				contador++;
			}
		}
	}
	return contador;
}
