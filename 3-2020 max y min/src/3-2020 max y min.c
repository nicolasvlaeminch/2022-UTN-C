/*
 ============================================================================
 Name        : 3-2020.c
 Author      : Nicolas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int numeroIngresado;
	int i;
	int minimo;
	int maximo;
	int bandera;

	bandera = 0;

	for(i = 0; i < 5; i++) {
	printf("Ingrese un numero: ");
	scanf("%d", &numeroIngresado);

	if (bandera == 0) {
		minimo = numeroIngresado;
		maximo = numeroIngresado;
		bandera = 1;
	}
	else {
		if (minimo > numeroIngresado) {
			minimo = numeroIngresado;
		}
		if (maximo < numeroIngresado) {
			maximo = numeroIngresado;
		}
	}
}

	printf("El minimo es %d y el maximo es %d",minimo, maximo);

	return 0;
}
