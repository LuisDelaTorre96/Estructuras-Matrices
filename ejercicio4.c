//EJERCICIO 4. SUMA DE ELEMENTOS
//1. Cree una matriz de 4x4 con valores aleatorios
//2. Calcule la suma de todos los elementos
//3. Calcule el promedio de los elementos
//4. Muestre ambos resultados

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Definimos las constantes para las filas y columnas
#define MAX_FILAS 4
#define MAX_COLS 4

//Declaramos las funciones antes del main
void llenarMatrizAleatoria(int matriz[MAX_FILAS][MAX_COLS]);
void imprimirMatriz(int matriz[MAX_FILAS][MAX_COLS]);
int sumarElementos(int matriz[MAX_FILAS][MAX_COLS]);
float calcularPromedio(int sumaTotal, int totalElementos);

//Funcion principal
int main(void) {
    int matriz[MAX_FILAS][MAX_COLS];
    int suma;
    float promedio;

	srand(time(NULL)); //Inicializar semilla aleatoria

	llenarMatrizAleatoria(matriz);
	imprimirMatriz(matriz);

	suma = sumarElementos(matriz);
	promedio = calcularPromedio(suma, MAX_FILAS * MAX_COLS);

	printf("\nLa suma total de los numeros es %d\n", suma);
	printf("El promedio de los numeros es %.2f\n", promedio);

	return 0;
}

//Funciones

//Llenar la matriz con numeros aleatorios
void llenarMatrizAleatoria(int matriz[MAX_FILAS][MAX_COLS]){
	for(int i = 0; i < MAX_FILAS; i++){
		for(int j = 0; j < MAX_COLS; j++){
			matriz[i][j] = rand() % 10; //Generamos numeros de 0 a 9
		}
	}
}

//Imprime la matriz
void imprimirMatriz(int matriz[MAX_FILAS][MAX_COLS]){
	printf("Matriz generada con valores aleatorios entre 0 y 9:\n\n");
	for(int i = 0; i < MAX_FILAS; i++){
		for(int j = 0; j < MAX_COLS; j++){
			printf("%3d  ", matriz[i][j]);
		}
		printf("\n");
	}
}

//Sumar elementos
int sumarElementos(int matriz[MAX_FILAS][MAX_COLS]){
	int suma = 0; //Variable para acumular elementos
	for(int i = 0; i < MAX_FILAS; i++){
		for(int j = 0; j < MAX_COLS; j++){
			suma += matriz[i][j]; //Suma cada elemento de la matriz
		}
	}
	return suma;
}

//Promedio de los elementos
float calcularPromedio(int sumaTotal, int totalElementos){
	return(float)sumaTotal / totalElementos;
}
