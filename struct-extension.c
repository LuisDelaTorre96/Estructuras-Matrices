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
	struct Estudiante datos[MAX_ESTUDIANTES];
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
			case 1:
				int cantidad;

				printf("\nIngrese el numero de estudiantes a capturar (maximo 100 estudiantes): ");
				scanf("%d", &cantidad);

				int total = numeroEstudiantes + cantidad;

				if(total > MAX_ESTUDIANTES){
					printf("\nError: excede el maximo de estudiantes a capturar (%d)", MAX_ESTUDIANTES);
				}else{
					printf("\nIngrese los datos de los estudiantes.\n");
					for(int i = numeroEstudiantes; i < total; i++){
						float suma = 0.0f;

						printf("\nEstudiante %d.\n", i + 1);

						printf("Matricula: ");
						scanf("%d", &datos[i].matricula);

						getchar();

						printf("Nombre: ");
						fgets(datos[i].nombre, 50, stdin);

						datos[i].nombre[strcspn(datos[i].nombre, "\n")] = '\0'; // Elimina el \n de fgets().

						printf("Edad: ");
						scanf("%d", &datos[i].edad);

						for(int j = 0; j < MAX_MATERIAS; j++){
							printf("\nMateria %d\n", j + 1);

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
				break;
			case 2:
				printf("\n");

				break;
			case 3:
				if(numeroEstudiantes == 0){
					printf("\nNo hay estudiantes capturados.\n");
				} else{
					printf("\n--- Lista de estudiantes capturados ---\n");
					for(int i = 0; i < numeroEstudiantes; i ++){
						printf("\nEstudiante %d\n", i + 1);
						printf("Matricula: %d\n", datos[i].matricula);
						printf("Nombre: %s\n", datos[i].nombre);
						printf("Edad: %d\n", datos[i].edad);
						printf("Materias:\n");
						for(int j = 0; j < MAX_MATERIAS; j++){
							printf(" %d. %s - Calificacion: %.2f\n", j + 1, datos[i].materias[j].nombre, datos[i].materias[j].calificacion);
						}
						printf("Promedio: %.2f", datos[i].promedio);
					}
				}
				break;
			case 4:
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
			case 5:
				printf("\n");

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
