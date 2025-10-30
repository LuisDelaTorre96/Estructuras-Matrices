// Juego del gato

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

// Definimos las dimensiones del tablero
#define MAX_FILAS 3
#define MAX_COLS 3

// Prototipos de funciones
void inicializarTablero(char tablero[MAX_FILAS][MAX_COLS]);
void imprimirTablero(const char tablero[MAX_FILAS][MAX_COLS]);
int tableroLleno(const char tablero[MAX_FILAS][MAX_COLS]);
int hayGanador(const char tablero[MAX_FILAS][MAX_COLS], char *ganador);
int turnoUsuario(char tablero[MAX_FILAS][MAX_COLS]);
int turnoPC(char tablero [MAX_FILAS][MAX_COLS]);
void limpiarEntrada();

int main(){
	char tablero[MAX_FILAS][MAX_COLS];
	int puntajeUsuario = 0;
	int puntajePC = 0;
	int empates = 0;
	char jugarOtra = 'S';

	srand((unsigned)time(NULL));

	//Bucle principal mientras se continue jugando
	while (toupper((unsigned char)jugarOtra) == 'S'){

		inicializarTablero(tablero); // Limpiamos el tablero en cada partida

		printf("\n===== JUEGO DEL GATO =====\n");
		printf("Jugador 1: X	|    PC: O\n\n");

		int movimientos = 0;
		char ganador = ' ';
		int turnoEsUsuario = 1;

		// Bucle para una sola partida
		while (1){
			imprimirTablero(tablero);

			int jugadaValida = 0;

			// Turno del jugador
			if (turnoEsUsuario){
				printf("\nTu turno.\n");
				jugadaValida = turnoUsuario(tablero);
			}
			// Turno del pc
			else{
				printf("Turno de la PC...\n");
				jugadaValida = turnoPC(tablero);
			}

			// Repite el turno si la jugada es invalida
			if(!jugadaValida){
				printf("ERROR! No se peude realizar la jugada. Reintentando turno.\n");
				continue;
			}

			movimientos++;

			// Validamos ganador despues del 5to. movimiento
			if (movimientos >= 5){
				if(hayGanador(tablero, &ganador)){
					imprimirTablero(tablero); // Mostramos el tablero final

					// Determinamos quien gano
					if(ganador == 'X'){
						printf("\nGanaste!\n");
						puntajeUsuario++;
					} else if(ganador == 'O'){
						printf("\nGana la PC!\n");
						puntajePC++;
					}
					break; // Termina la partida
				}
			}

			// Empate
			if(tableroLleno(tablero)){
				imprimirTablero(tablero);
				printf("\nNo hay mas movimientos. EMPATE!\n");
				empates++;
				break;
			}

			turnoEsUsuario = !turnoEsUsuario; // Cambiamos de turno
		}

		// Mostramos el marcador acumulado
		printf("\n=== MARCADOR ===\n");
		printf("Usuario: %d | PC: %d | Empates: %d\n", puntajeUsuario, puntajePC, empates);

		// Preguntamos si queremos nueva partida
		printf("\n¿Deseas jugar de nuevo? (S/N): ");
		if(scanf(" %c", &jugarOtra) != 1){
			limpiarEntrada();
			jugarOtra = 'N';
		} else {
			limpiarEntrada();
		}
	}

	// Final del juego y mostrar marcador total
	printf("\nFin del juego. Marcador final:\n");
	printf("Usuario: %d | PC: %d | Empates: %d\n", puntajeUsuario, puntajePC, empates);

	return 0;
}

// ----------------------------------------------------------------------------
// Funciones auxiliares
void inicializarTablero(char tablero[MAX_FILAS][MAX_COLS]){
	for(int i = 0; i < MAX_FILAS; i++){
		for (int j = 0; j < MAX_COLS; j++){
			tablero[i][j] = ' '; // Espacio vacio en cada casilla
		}
	}
}

// Imprimimos el tablero 3 x 3 cons separaciones
void imprimirTablero(const char tablero[MAX_FILAS][MAX_COLS]){
	printf("\n");
	for(int i = 0; i < MAX_FILAS; i++){
		for(int j = 0; j < MAX_COLS; j++){
			printf(" %c ", tablero[i][j]); // Imprime la casilla X, O o espacio
			if(j < MAX_COLS - 1)
				printf("|"); // Separador de columnas
		}
		if(i < MAX_FILAS - 1)
			printf("\n---+---+---\n");
	}
	printf("\n");
}

// Verifica los espacios vacios en el tablero
int tableroLleno(const char tablero[MAX_FILAS][MAX_COLS]){
	for(int i = 0; i < MAX_FILAS; i++){
		for(int j = 0; j < MAX_COLS; j++){
			if(tablero[i][j] == ' ')
				return 0; // Aun hay espacio
		}
	}
	return 1; // Tablero lleno
}

// Verifica las combinaciones ganadoras
int hayGanador(const char tablero[MAX_FILAS][MAX_COLS], char *ganador){
	//Verificamos las filas
	for(int i = 0; i < MAX_FILAS; i++){
		if(tablero[i][0] != ' ' && tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]){
			*ganador = tablero[i][0];
			return 1;
		}
	}

	// Verificamos las columnas
	for(int j = 0; j < MAX_COLS; j++){
		if(tablero[0][j] != ' ' && tablero [0][j] == tablero[1][j] && tablero[1][j] == tablero[2][j]){
			*ganador = tablero[0][j];
			return 1;
		}
	}

	// Verificar la diagonal principal
	if(tablero[0][0] != ' ' && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]){
		*ganador = tablero[0][0];
		return 1;
	}

	// Verificar la diagonal secundaria
	if(tablero[0][2] != ' ' && tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]){
		*ganador = tablero[0][2];
		return 1;
	}

	*ganador = ' '; // En caso de que nadie gane
	return 0;
}

// Permite al usuario elegir una casilla libre
int turnoUsuario(char tablero[MAX_FILAS][MAX_COLS]){
	int fila, col;
	while (1){
		printf("Ingresa la fila y columna, separados por espacio (Ej. 1 2): ");
		if(scanf("%d %d", &fila, &col) != 2){
			printf("Entrada Invalida. Intenta de nuevo.\n");
			limpiarEntrada(); // Limpia el buffer
			continue;
		}
		limpiarEntrada();

		// Verificar que este dentro del rango permitido
		if(fila < 1 || fila > MAX_FILAS || col < 1 || col > MAX_COLS){
			printf("Fuera de rango. Debe ser entre 1 y 3.\n");
			continue;
		}

		fila--; col--; // Convertimos a indices 0..2

		// Si la casilla ya esta ocupada, pide otra al jugador
		if(tablero[fila][col] != ' '){
			printf("La casilla ya esta ocupada. Elige otra.\n");
			continue;
		}

		tablero[fila][col] = 'X'; // Colocamos la marca del usuario
		return 1;
	}
}

// Turno del PC de elegir una casilla aleatoria libre
int turnoPC(char tablero[MAX_FILAS][MAX_COLS]){
	int libres[9][2]; // guarda maximo 9 coordenadas libres
	int xLibres = 0; // Cuenta las casillas disponibles

	// Recorre el tablero para encontrar espacios vacios
	for(int i = 0; i < MAX_FILAS; i++){
		for(int j = 0; j < MAX_COLS; j++){
			if(tablero[i][j] == ' '){
				libres[xLibres][0] = i; // Guarda la fila
				libres[xLibres][1] = j; // Guarda la columna
				xLibres++;
			}
		}
	}

	if(xLibres == 0) return 0; // Si no hay casillas disponibles, se acaba el juego

	// Escoge una posicion aleatoria entre las disponibles
	int k = rand() % xLibres;
	int f = libres[k][0];
	int c = libres[k][1];

	tablero[f][c] = 'O';
	printf("PC juega en: %d, %d\n", f + 1, c + 1);
	return 1;
}

void limpiarEntrada(){
	int limpiar;
	while ((limpiar = getchar()) != '\n' && limpiar != EOF){}
}
