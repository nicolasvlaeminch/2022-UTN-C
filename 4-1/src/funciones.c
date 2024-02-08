/*
 * funciones.c
 *
 *  Created on: 12 sept 2022
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int MostrarEntero(int numero)
{
	printf("Ingrese un numero entero: ");
	scanf("%d", &numero);

	while (numero < 0 || numero > 100) {
		printf("ERROR: Ingrese un numero entero: ");
		scanf("%d", &numero);
	}

	return numero;
}

