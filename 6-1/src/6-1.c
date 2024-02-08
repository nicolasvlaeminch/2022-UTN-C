/*
 ============================================================================
 NICOLAS VLAEMINCH / DIV K / EJERCICIO 6-1
 	Disponemos de dos variables numéricas (a y b). Realizar un algoritmo que permita el intercambio
	de valores de dichas variables.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a = 3;
	int b = 4;
	int buffer;

	buffer = a;
	a = b;
	b = buffer;

	printf("A vale %d y B vale %d", a, b);
	return EXIT_SUCCESS;
}
