/*
 * funciones.c
 *
 *  Created on: 16 sept 2022
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>

int Validar(int numero, int min, int max) {
	while (numero < min || numero > max) {
		printf("ERROR: Ingrese un numero valido: ");
		scanf("%d",&numero);
	}
	return numero;
}
