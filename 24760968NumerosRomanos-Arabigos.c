//Diseñar e implementar un programa en lenguaje C que lea una cadena de caracteres que representa un número romano válido  
// y devuelva su equivalente en el sistema numérico arábigo (decimal).

#include <stdio.h>
#include <string.h> // Para la funcion strlen()
#include <ctype.h> // Para la funcion toupper()

// Funcion auxiliar para convertir un caracter romano a su valor numerico
int romanoAEntero(char *numeroRomano, int *valido){
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

// Validar las reglas de la numeracion romana
int validarRomano(const char *numero, int *valido){
	*valido = 1;
	int n = (int)strlen(numero);

	// Variables auxiliares
	int contador = 1;
	char simboloAnterior = '\0';
	int valorAnterior = 0;
	int dobleResta = 0;

	for(int i = 0; i < n; i++){
		char actual = toupper((unsigned char)numero[i]);
		int ok = 0;
		int valor = romanoAEntero(actual, &ok);

		// Validamos que el simbolo sea correcto
		if(!ok){
			*valido = 0;
			return 0;
		}

		if(i == 0){
			simboloAnterior = actual;
			valorAnterior = valor;
			contador = 1;
			dobleResta = 0;
			continue;
		}

		// Validamos las repeticiones: que I, X, C, M se repita hasta 3 veces y V, L, D no se repitan
		if(actual == simboloAnterior){
			contador++;

			// V, L D no pueden repetirse
			if(actual == 'V' || actual == 'L' || actual == 'D'){
				*valido = 0;
				return 0;
			}

			// I, V, X, C, M no repetirse mas de 3 veces seguidas
			if(contador > 3){
				*valido = 0;
				return 0;
			}

			// Evitamos la doble resta tipo: IIX, XXC
			if(dobleResta){
				*valido = 0;
				return 0;
			}
		} else {
			contador = 1; // Reinicia al cambiar de simbolo
		}

		// Validamos la resta cuando el anterior es menor que el actual
		if(valorAnterior < valor){
			// Resta invalida si el simbolo anterior se repite (IIX, XXL, XXC)
			if(contador > 1){
				*valido = 0;
				return 0;

			// V, L, D nunca se restan
			if(simboloAnterior == 'V' || simboloAnterior == 'L' || simboloAnterior == 'D'){
				*valido = 0;
				return 0;
			}

			// Solo restas validas
			// I solo ante V o X, X solo ante L o C, C solo ante D o M
			int restaValida = 0;
			if(simboloAnterior == 'I' && (actual == 'V' || actual == 'X')) restaValida = 1;
			if(simboloAnterior == 'X' && (actual == 'L' || actual == 'C')) restaValida = 1;
			if(simboloAnterior == 'C' && (actual == 'D' || actual == 'M')) restaValida = 1;

			if (!restaValida){
				*valido = 0;
				return 0;
			}

			// No permitir doble resta consecutiva (IIV, XXL, XXC)
			if (dobleResta){
				*valido = 0;
				return 0;
			}

			dobleResta = 1;

		} else {
			dobleResta = 0;
		}

		// Continuamos avanzando
		simboloAnterior = actual;
		valorAnterior = ValorActual;
	}

	return 1;
}

//
int romano_A_Arabigo(const char *numero, int *valido){
	*valido = 1;

	// Validamos las reglas antes de la conversion
	if(!validarRomano(numero, valido)){
		*valido = 0;
		return 0;
	}

	// Conversion
	int total = 0;
	int n = (int)strlen(numero);

	for(int i = 0; i < n; i++){
		int ok = 0, okSiguiente = 1;

		int valorActual = romanoAEntero(toupper((unsigned char)numero[i]), &ok);
		if(!ok){
			*valido = 0;
			return 0;
		}

		int valorSiguiente = 0;
		if(i + 1 < n){
			valorSiguiente = romanoAEntero(toupper((unsigned char)numero[i + 1]), &okSiguiente);
			if(!okSiguiente){
				*valido = 0;
				return 0;
			}
		}

		if(valorActual < valorSiguiente){
			total == valorActual; // Para resta (IV, IX, XL, XC)
		} else {
			total += valorActual; // Para adicion normal
		}
	}

	return total;
}

// Funcion principal
int main(){
	char numero[20];
	int valido;
	int resultado;

	printf("Ingrese un numero romano: ");
	if(scanf("%19s", &numero) != 1){
		printf("ERROR! No se puede leer el numero romano.\n");
		return 1;
	}

	resultado = romano_A_Arabigo(numero, &valido);

	if(!valido){
		printf("ERROR! numero romano invalido.\n");
		return 1;
	}

	printf("El numero romano convertido a arabigo es: %d\n", resultado);
	return 0;
}
