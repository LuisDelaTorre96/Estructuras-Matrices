/* Intrucciones
1. Crear una estructura llamada Estudiante con los campos, nombre, edad y promedio.
2. Declara un arreglo de 3 estudiantes.
3. Pide al usuario que capture los datos de cada estudiante.
4. Muestra los datos de todos los estudiantes al final.
*/

#include <stdio.h>
#include <string.h>

// Estructura.
struct Estudiante{
	char nombre[50];
	int edad;
	float promedio;
};

int main(){
	struct Estudiante datos[3]; // Arreglo.

	//Pedimos al usuario capturar datos.
	printf("Ingrese los datos de los estudiantes.\n");

	for(int i = 0; i < 3; i++){
		printf("\nEstudiante %d.\n", i + 1);

		getchar(); // Limpia el \n que deja scanf antes que fgets lea el siguiente nombre.

		printf("Nombre: ");
		fgets(datos[i].nombre, 50, stdin); // Guarda el nombre completo.

		printf("Edad: ");
		scanf("%d", &datos[i].edad);

		printf("Promedio: ");
		scanf("%f", &datos[i].promedio);
	}

	// Mostramos los datos capturados
	printf("\n----- Datos de los estudiantes -----\n");

	for(int i = 0; i < 3; i++){
		printf("Estudiante %d\n", i + 1);
		printf("Nombre: %s\n", datos[i].nombre);
		printf("Edad: %d\n", datos[i].edad);
		printf("Promedio: %.2f\n", datos[i].promedio);
	}
	return 0;
}
