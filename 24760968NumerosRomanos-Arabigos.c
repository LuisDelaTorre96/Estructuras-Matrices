//Diseñar e implementar un programa en lenguaje C que lea una cadena de caracteres que representa un número romano válido  
// y devuelva su equivalente en el sistema numérico arábigo (decimal).

#include <stdio.h>
#include <string.h> // Para la funcion strlen()
#include <ctype.h> // Para la funcion toupper()

// Funcion auxiliar para convertir un caracter romano a su valor numerico
int romanoAEntero(char numeroRomano, int *valido){
	*valido = 1; // Utilizamos para decir que es valido el caracter
	numeroRomano = toupper((unsigned char)numeroRomano);

	switch (numeroRomano) {
		case 'I': return 1;
		break;

		case 'V': return 5;
		break;

		case 'X': return 10;
		break;

		case 'L': return 50;
		break;

		case 'C': return 100;
		break;

		case 'D': return 500;
		break;

		case 'M': return 1000;

		default:
			*valido = 0; // No es un simbolo romano valido
			return 0;
	}
}

int main(){
	char simbolo;
	int valido;
	int valor;

	printf("Ingrese un simbolo romano (I, V, X, L, C, D, M): ");
	if(scanf(" %c", &simbolo) != 1){
		printf("ERROR! No se puede leer el caracter.\n");
		return 1;
	}

	valor = romanoAEntero(simbolo, &valido);

	if(!valido){
		printf("ERROR! %c no es un simbolo romano valido.\n", simbolo);
		return 1;
	}

	printf("El valor del simbolo romano %c es: %d\n", simbolo, valor);

	return 0;
}
