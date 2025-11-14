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
	struct Estudiante datosCargados[N];

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
		printf("Promedio: %.2f\n", datos[i].promedio);
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

	// Guardar los datos
	FILE *f = fopen("datosEstudiantes.txt", "w"); // Se utiliza "w" para abrir el archivo para escritura.

	for(int i = 0; i < N; i++){
		fprintf(f, "%s\n", datos[i].nombre);
		fprintf(f, "%d\n", datos[i].edad);
		fprintf(f, "%.2f\n", datos[i].promedio);
	}

	fclose(f);
	printf("\nDatos guardados en datosEstudiantes.txt ...");

	// Cargar datos
	f = fopen("datosEstudiantes.txt", "r"); // Se utiliza "r" para abrir el archivo para lectura.

	int i = 0;
	while(i < N && fgets(datosCargados[i].nombre, 50, f) != NULL){
		datosCargados[i].nombre[strcspn(datosCargados[i].nombre, "\n")] = '\0';
		fscanf(f, "%d", &datosCargados[i].edad);
		fscanf(f, "%f", &datosCargados[i].promedio);
		fgetc(f); // Limpia \n despues del promedio
		i++;
	}

	fclose(f);

	printf("\n--- Datos cargados desde el archivo ---\n");
	for(int j = 0; j < i; j++){
		printf("\nEstudiante %d\n", j + 1);
		printf("Nombre %s\n", datosCargados[j].nombre);
		printf("Edad: %d\n", datosCargados[j].edad);
		printf("Promedio: %.2f\n", datosCargados[j].promedio);
	}

	return 0;
}

/* Referencias de guardar y cargar datos en archivo de texto
https://www.youtube.com/watch?v=4Ob7tCFaMHw&t=142s
https://www.youtube.com/watch?v=CtOaZExHUOw
*/
