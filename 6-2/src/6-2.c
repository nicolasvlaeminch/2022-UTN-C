/*
 ============================================================================
 NICOLAS VLAEMINCH / DIV K / EJERCICIO 6-2
 	Realizar un programa que permita el ingreso de 10 números enteros (positivos y negativos).
	Necesito generar un listado de los números positivos de manera creciente y negativos de manera
	decreciente. (Como máximo 5 estructuras repetitivas)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Ordenamiento.h"

int main(void) {
	setbuf(stdout, NULL);
	int numeros[10];
	int iteraciones;

	for (int i = 0; i < 10; ++i) {
		printf("Ingrese un numero entero: ");
		fflush(stdin);
		scanf("%d",&numeros[i]);
	}
	iteraciones = OrdenarArray(numeros, 10);
	printf("Iteraciones %d\n",iteraciones);

	printf("Los positivos son: ");
	for (int j = 10; j > 0; --j) {
		if (numeros[j] > 0) {
			printf("%d ",numeros[j]);
		}
	}

	printf("\nLos negativos son: ");
	for (int k = 0; k < 10; ++k) {
		if (numeros[k] < 0) {
			printf("%d ",numeros[k]);
		}
	}

	return EXIT_SUCCESS;
}
