/*
 * Ordenamiento.c
 *
 *  Created on: 29 sept 2022
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>

int OrdenarArray(int numeros[], int limite) {
	int buffer;
	int flagSwap;
	int contador = 0;
	int retorno = -1;
	int nuevoLimite;

	if (numeros != NULL && limite >= 0) {
		nuevoLimite = limite - 1;
		do {
			flagSwap = 0;
			for (int i = 0; i < limite-1;i++) {
				contador++;
				if(numeros[i] < numeros[i + 1]) {
					flagSwap = 1;
					buffer = numeros[i];
					numeros[i] = numeros[i + 1];
					numeros[i + 1] = buffer;
				}
			}
			nuevoLimite--;
		} while (flagSwap);
		retorno = contador;
	}
	return retorno;
}

