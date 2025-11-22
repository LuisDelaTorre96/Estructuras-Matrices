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
		printf("4. Buscar estudiante por matricula\n");
		printf("5. Consultar promedios\n");
		printf("6. Salir\n");
		printf("Seleccione una opcion: ");
		scanf("%d", &opcion);

		switch(opcion){

			case 1:{ // Capturar estudiantes
				int cantidad;

				printf("\nIngrese el numero de estudiantes a capturar (maximo 100 estudiantes): ");
				scanf("%d", &cantidad);

				int total = numeroEstudiantes + cantidad;

				if(total > MAX_ESTUDIANTES){
					printf("\nError: excede el maximo de estudiantes a capturar (%d)\n\n", MAX_ESTUDIANTES);
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

							getchar(); // Elimina el salto de linea antes de leer el nombre de nuevo

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

					printf("\n---- RECUERDA GUARDAR LOS ESTUDIANTES CAPTURADOS ----\n\n");
				}

				break;
			}

			case 2:{ // Guardar datos capturados en archivo.txt
				if(numeroEstudiantes == 0){
					printf("\nNo hay estudiantes capturados para guardar.\n\n");
					break;
				}

				FILE *f = fopen("estudiantes.txt", "w");
				if(!f){
					printf("\nNo se pudo abrir el archivo para escritura.\n\n");
					break;
				}

				fprintf(f, "%d\n", numeroEstudiantes);

				for(int i = 0; i < numeroEstudiantes; i++){
					fprintf(f, "%d\n", datos[i].matricula);
					fprintf(f, "%s\n", datos[i].nombre);
					fprintf(f, "%d\n", datos[i].edad);
					for(int j = 0; j < MAX_MATERIAS; j++){
						fprintf(f, "%s\n", datos[i].materias[j].nombre);
						fprintf(f, "%.2f\n", datos[i].materias[j].calificacion);
					}
					fprintf(f, "%.2f\n\n", datos[i].promedio);
				}

				fclose(f);
				printf("\nGuardando datos...\nDatos guardados correctamente.\n\n");

				break;
			}
			case 3:{ // Cargar datos desde archivo.txt
				FILE *f = fopen("estudiantes.txt", "r");
				if(!f){
					printf("\nNo se pudo abrir 'estudiantes.txt'.\n\n");
					break;
				}

				fscanf(f, "%d\n", &numeroEstudiantes);

				for(int i = 0; i < numeroEstudiantes && i < MAX_ESTUDIANTES; i++){
					float suma = 0.0f;

					fscanf(f, "%d\n", &datos[i].matricula);
					fgets(datos[i].nombre, 50, f);
					datos[i].nombre[strcspn(datos[i].nombre, "\n")] = '\0';
					fscanf(f, "%d\n", &datos[i].edad);
					for(int j = 0; j < MAX_MATERIAS; j++){
						fgets(datos[i].materias[j].nombre, 30, f);
						datos[i].materias[j].nombre[strcspn(datos[i].materias[j].nombre, "\n")] = '\0';

						fscanf(f, "%f\n", &datos[i].materias[j].calificacion);

						suma += datos[i].materias[j].calificacion;
					}

					fscanf(f, "%f\n", &datos[i].promedio);
					datos[i].promedio = suma / MAX_MATERIAS;
				}

				fclose(f);
				printf("\nDatos cargados correctamente desde 'estudiantes.txt'.\n");

				// Mostramos los datos cargados
				printf("\n--- Mostrando estudiantes cargados ---\n");
				for(int i = 0; i < numeroEstudiantes; i++){
					printf("\nEstudiante %d\n", i + 1);
					printf("Matricula: %d\n", datos[i].matricula);
					printf("Nombre: %s\n", datos[i].nombre);
					printf("Edad: %d años\n", datos[i].edad);
					printf("Materias y calificaciones:\n");
					for(int j = 0; j < MAX_MATERIAS; j++){
						printf(" %d. %s: %.2f\n", j + 1, datos[i].materias[j].nombre, datos[i].materias[j].calificacion);
					}
					printf("Promedio general: %.2f\n", datos[i].promedio);
				}
				printf("\n");

				break;
			}
			case 4:{ // Buscar estudiante por matricula
				if(numeroEstudiantes == 0){
					printf("\nNo hay estudiantes capturados.\n\n");
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
					} else{ // Mostramos los datos del estudiante con la matricula ingresada
						printf("\nEstudiante encontrado:\n");
						printf("Matricula: %d\n", datos[posicion].matricula);
						printf("Nombre: %s\n", datos[posicion].nombre);
						printf("Edad: %d\n", datos[posicion].edad);
						printf("Promedio: %.2f\n", datos[posicion].promedio);
						printf("Materias y calificaciones:\n");
						for(int j = 0; j < MAX_MATERIAS; j++){
							printf(" %d. %s: %.2f\n",
							j + 1, datos[posicion].materias[j].nombre, datos[posicion].materias[j].calificacion);
						}
					}
				}
				printf("\n");

				break;
			}
			case 5:{ // Consultar promedios
				if(numeroEstudiantes == 0){
					printf("\nNo hay estudiantes capturados aun.\n\n");
				} else{
					int opcion2;
					printf("\n--- Consultar promedios ---\n");
					printf("1. Consultar el mejor promedio.\n");
					printf("2. Consultar el promedio general de los estudiantes capturados.\n");
					printf("Elija una opcion: ");
					scanf("%d", &opcion2);

					switch(opcion2){
						case 1:{ // Consultar el mejor promedio
							int indicador = 0;
							float mejorPromedio = datos[0].promedio;

							for(int i = 0; i < numeroEstudiantes; i++){
								if(datos[i].promedio > mejorPromedio){
									mejorPromedio = datos[i].promedio;
									indicador = i;
								}
							}

							printf("\nEstudiante con mejor promedio:\n");
							printf("Matricula: %d\n", datos[indicador].matricula);
							printf("Nombre: %s\n", datos[indicador].nombre);
							printf("Promedio: %.2f\n\n", datos[indicador].promedio);

							break;
						}
						case 2:{ // Consultar el promedio general de los estudiantes capturados
							float sumaPromedios = 0;

							for(int i = 0; i < numeroEstudiantes; i++){
								sumaPromedios += datos[i].promedio;
							}

							float promedioGeneral = sumaPromedios / numeroEstudiantes;

							printf("\nEl promedio general de los %d estudiantes capturados es %.2f\n\n", numeroEstudiantes, promedioGeneral);

							break;
						}
						default:{
							printf("\nOpcion invalida.\n");
						}
					}
				}
				break;
			}
			case 6:{
				printf("\nSaliendo del programa... Adios!\n");

				break;
			}
			default:{
				printf("\nOpcion no valida. intente de nuevo.\n\n");
			}
		}
	} while (opcion != 6);

	return 0;
}
