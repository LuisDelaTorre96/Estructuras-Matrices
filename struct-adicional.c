/*1. Calcula el promedio general del grupo.
2. Muestra el estudiante con el mejor promedio.
3. Guarda y carga los datos desde un archivo de texto usando fopen,fprintf, y fcanf.
*/

# include <stdio.h>
# include <string.h>

struct Estudiante{
	char nombre[50];
	int edad;
	float promedio;
};

int main(){
	const int N = 3;

	struct Estudiante datos[N];

	printf("Ingrese los datos de los estudiantes.\n");

	for(int i = 0; i < N; i++){
		printf("\nEstudiante %d", i + 1);

		printf("\nNombre: ");
		fgets(datos[i].nombre, 50, stdin);

		datos[i].nombre[strcspn(datos[i].nombre, "\n")] = '\0'; // Limpiamos el \n de fgets().

		printf("Edad: ");
		scanf("%d", &datos[i].edad);

		printf("Promedio: ");
		scanf("%f", &datos[i].promedio);

		getchar(); // Limpia el \n antes de leer el siguiente nombre.


	}

	// Mostramos los datos capturados
	printf("\n----- Datos de estudiantes -----\n\n");

	for(int i = 0; i < N; i++){
		printf("Estudiante %d\n", i + 1);
		printf("Nombre: %s\n", datos[i].nombre);
		printf("Edad: %d\n", datos[i].edad);
		printf("Promedio: %.2f\n\n", datos[i].promedio);
	}

	// Calculamos y mostramos el promedio
	float suma = 0;
	for(int i = 0; i < N; i++){
		suma += datos[i].promedio;
	}
	float promedioGrupo = suma / N;
	printf("El promedio general de los estudiantes es %.2f\n\n", promedioGrupo);

	// Mostramos el estudiante con el mejor promedio
	int mayorPromedio = 0;
	for(int i = 1; i < N; i++){
		if(datos[i].promedio > datos[mayorPromedio].promedio){
			mayorPromedio = i;
		}
	}
	printf("Estudiante con el mejor promedio\n");
	printf("Nombre: %s\n", datos[mayorPromedio].nombre);
	printf("Edad: %d\n", datos[mayorPromedio].edad);
	printf("Promedio: %.2f\n", datos[mayorPromedio].promedio);

	return 0;
}
