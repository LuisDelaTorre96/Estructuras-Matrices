/* Crea un programa que almacene informacion de varios estudiantes y las materias que cursan.
Cada estudiante tiene una matricula, nombre, edad, promedio y una lista de materias con sus calificaciones.
Materia: nombre, calificacion.
Estudiante: matricula, nombre, edad, promedio, materias[3].
Crear un menu con opciones:
1.capturar estudiantes
2.mostrar todos
3.buscar por matricula
4.salir
Guardar todos los datos en un archivo estudiantes.txt.
Cargar los datos desde un archivo y mostrarlos.
Mostrar el estudiante con el mejor promedio. */

#include <stdio.h>
#include <string.h>

#define MAX_ESTUDIANTES 100
#define MAX_MATERIAS 3

struct Materia{
	char nombre[30];
	float calificacion;
};

struct Estudiante{
	int matricula;
	char nombre[50];
	int edad;
	float promedio;
	struct Materia materias[MAX_MATERIAS]; // 3 materias por estudiante
};

int main(){
	struct Estudiante datos[MAX_ESTUDIANTES]; // Maximo 100 estudiantes
	int numeroEstudiantes = 0;
	int opcion;

	do{
		//Menu
		printf("---- Menu principal ----\n");
		printf("1. Capturar estudiantes\n");
		printf("2. Guardar datos capturados\n");
		printf("3. Cargar datos registrados\n");
		printf("4. Buscar estudiante por matricula por matricula\n");
		printf("5. Consultar promedios\n");
		printf("6. Salir\n");
		printf("Seleccione una opcion: ");
		scanf("%d", &opcion);

		switch(opcion){
			case 1: // Capturar estudiantes
				int cantidad;

				printf("\nIngrese el numero de estudiantes a capturar (maximo 100 estudiantes): ");
				scanf("%d", &cantidad);

				int total = numeroEstudiantes + cantidad;

				if(total > MAX_ESTUDIANTES){
					printf("\nError: excede el maximo de estudiantes a capturar (%d)", MAX_ESTUDIANTES);
				} else{
					printf("\nIngrese los datos de los estudiantes\n");
					for(int i = numeroEstudiantes; i < total; i++){
						float suma = 0.0f;

						printf("\nEstudiante %d.\n", i + 1);

						printf("Matricula: ");
						scanf("%d", &datos[i].matricula);

						getchar(); // Elimina el /n del scanf() anterior antes de leer el nombre con fgets()

						printf("Nombre: ");
						fgets(datos[i].nombre, 50, stdin);

						datos[i].nombre[strcspn(datos[i].nombre, "\n")] = '\0'; // Elimina el \n de fgets()

						printf("Edad: ");
						scanf("%d", &datos[i].edad);

						for(int j = 0; j < MAX_MATERIAS; j++){
							printf("Materia %d\n", j + 1);

							getchar();

							printf("Nombre de la materia: ");
							fgets(datos[i].materias[j].nombre, 30, stdin);
							datos[i].materias[j].nombre[strcspn(datos[i].materias[j].nombre, "\n")] = '\0';

							printf("Calificacion: ");
							scanf("%f", &datos[i].materias[j].calificacion);

							suma += datos[i].materias[j].calificacion;
						}

						datos[i].promedio = suma / MAX_MATERIAS;
						printf("Promedio del estudiante: %.2f\n", datos[i].promedio);
					}
					numeroEstudiantes = total;
				}
				printf("\n---- RECUERDA GUARDAR LOS ESTUDIANTES CAPTURADOS ----\n");

				break;

			case 2: // Guardar datos capturados en archivo.txt
				if(numeroEstudiantes == 0){
					printf("\nNo hay estudiantes capturados para guardar.\n");
				} else{
					FILE *f = fopen("estudiantes.txt", "w");

					fprintf(f, "Listado de estudiantes\n");

					for(int i = 0; i < numeroEstudiantes; i++){
						fprintf(f, "\nEstudiante %d\n", i + 1);
						fprintf(f, "%d\n", datos[i].matricula);
						fprintf(f, "%s\n", datos[i].nombre);
						fprintf(f, "%d\n", datos[i].edad);
						for(int j = 0; j < MAX_MATERIAS; j++){
							fprintf(f, "%s\n", datos[i].materias[j].nombre);
							fprintf(f, "%.2f\n", datos[i].materias[j].calificacion);
						}
						fprintf(f, "%.2f\n", datos[i].promedio);
					}

					fclose(f);
					printf("\nDatos guardados en 'Estudiantes.txt'.\n");
				}

				break;

			case 3: // Cargar datos desde archivo.txt
				FILE f* = fopen("Estudiantes.txt", "r");

				if(numeroEstudiantes == 0){
					printf("No hay estudiantes guardados para cargar.\n");
				} else{
					printf("Mostrando estudiantes capturados desde 'Estudiantes.txt'\n");
					for(int i = 0; i < numeroEstudiantes; i++){
						printf("\nEstudiante %d\n", i + 1);
						printf("Matricula: %d\n", datos[i].matricula);
						printf("Nombre: %s\n", datos[i].nombre);
						printf("Edad: %d\n", datos[i].edad);
						printf("Materias:\n");
						for(int j = 0; j < MAX_MATERIAS; j++){
							printf(" %d. %s | Calificacion: %.2f\n", j + 1, datos[i].materias[j].nombre, datos[i].materias[j].calificacion);
						}
						printf("Promedio: %.2f\n", datos[i].promedio);
					}
				}

				break;

			case 4: // Buscar estudiante por matricula
				if(numeroEstudiantes == 0){
					printf("\nNo hay estudiantes capturados.\n");
				} else{
					int buscarMatricula;
					int posicion = -1;

					printf("\nIngrese la matricua del estudiante: ");
					scanf("%d", &buscarMatricula);

					for(int i = 0; i < numeroEstudiantes; i++){
						if(datos[i].matricula == buscarMatricula){
							posicion = i;
							break;
						}
					}

					if(posicion == -1){
						printf("\nNo se encontro un estudiante con esa matricula.\n");
					} else{
						printf("\nEstudiante encontrado:\n");
						printf("Matricula: %d\n", datos[posicion].matricula);
						printf("Nombre: %s\n", datos[posicion].nombre);
						printf("Edad: %d\n", datos[posicion].edad);
						printf("Promedio: %.2f\n", datos[posicion].promedio);
						printf("Materias:\n");
						for(int j = 0; j < MAX_MATERIAS; j++){
							printf(" %d. %s - Calificacion: %.2f\n",
							j + 1, datos[posicion].materias[j].nombre, datos[posicion].materias[j].calificacion);
						}
					}
				}
				break;

			case 5: // Consultar promedios
				if(numeroEstudiantes == 0){
					printf("\nNo hay estudiantes capturados aun.\n");
				}else{
					int opcion2;
					printf("\n--- Consultar promedios ---\n");
					printf("1. Consultar el mejor promedio.");
					printf("2. Consultar el promedio general de los estudiantes capturados.\n");
					printf("Elija una opcion: ");
					scanf("%d", &opcion2);

					switch(opcion2){
						case 1: // Consultar el mejor promedio
							int indiceMayor = 0;
							float mejorPromedio = datos[0].promedio;

							for(int i = 0; i < numeroEstudiantes; i++){
								if(datos[i].promedio > mejorPromedio){
									mejorPromedio = datos[i].promedio;
									indiceMayor = i;
								}
							}

							printf("\nEstudiante con mejor promedio:\n");
							printf("Matricula: %d\n", datos[indiceMayor].matricula);
							printf("Nombre: %s\n", datos[indiceMayor].nombre);
							printf("Promedio: %.2f", datos[indiceMayor].promedio);

							break;
						case 2: // Consultar el promedio general de los estudiantes capturados
							float sumaPromedios = 0.0;
							float promedioGeneral = 0.0;

							for(int i = 0; i < numeroEstudiantes; i++){
								sumaPromedios += datos[i].promedio;
							}

							promedioGeneral = sumaPromedios / numeroEstudiantes;

							printf("\nEl promedio general de los %d estudiantes capturados es %.2f", numeroEstudiantes, promedioGeneral);

							break;
					}
					break;
			case 6:
				printf("\nSaliendo del programa...\n");

				break;
			default:
				printf("Opcion no valida. intente de nuevo.\n");

		}

	} while (opcion != 6);

	return 0;
}
