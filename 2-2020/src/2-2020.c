/*
 ============================================================================
 Name        : 2-2020.c
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
	int numeroUno;
	int numeroDos;
	int numeroTres;
	int cuenta;
	float promedio;


	printf("Ingrese numero1: ");
	scanf("%d", &numeroUno);
	printf("Ingrese numero2: ");
	scanf("%d", &numeroDos);
	printf("Ingrese numero3: ");
	scanf("%d", &numeroTres);

	cuenta = numeroUno + numeroDos + numeroTres;
	promedio = cuenta / 3;

	printf("El promedio es %f", promedio);

	return 0;
}
