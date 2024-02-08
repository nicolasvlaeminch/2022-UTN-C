/*
 ============================================================================
 NICOLAS VLAEMINCH / DIV K / EJERCICIO 5-2
 Pedir el ingreso de 10 números enteros entre -1000 y 1000. Determinar:
	a) Cantidad de positivos y negativos.
	b) Sumatoria de los pares.
	c) El mayor de los impares.
	d) Listado de los números ingresados.
	e) Listado de los números pares.
	f) Listado de los números de las posiciones impares.
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {
	setbuf(stdout, NULL);
	int numeros[10];
	int contadorPositivos = 0;
	int contadorNegativos = 0;
	int acumuladorPares = 0;
	int banderaMayorImpares = 0;
	int MayorImpares;

	for (int i = 0; i < 10; ++i) {
		printf("Ingrese un numero: ");
		fflush(stdin);
		scanf("%d",&numeros[i]);
		Validar(numeros[i], -1000, 1000);
	}

	for (int i = 0; i < 10; ++i) {
		if (numeros[i] < 0) {
			contadorNegativos++;
		}
		else {
			contadorPositivos++;
		}

		if (numeros[i] % 2 == 0) {
			acumuladorPares = acumuladorPares + numeros[i];
		}
		else {
			if (banderaMayorImpares == 0 || MayorImpares < numeros[i]) {
				MayorImpares = numeros[i];
				banderaMayorImpares = 1;
			}
		}
	}




	printf("La cantidad de numeros negativos es de %d y la de positivos es %d",contadorNegativos, contadorPositivos);
	printf("\nLa sumatoria de los pares es de %d", acumuladorPares);
	printf("\nEl mayor impar es %d", MayorImpares);

	printf("\nLa lista de los ingresados es: ");
	for (int i = 0; i < 10; ++i) {
		printf("\n%d",numeros[i]);
	}

	printf("\nLa lista de los pares es: ");
	for (int i = 0; i < 10; ++i) {
		if (numeros[i] % 2 == 0) {
		printf("\n%d",numeros[i]);
		}
	}

	printf("\nLas posiciones de los impares es: ");
	for (int i = 0; i < 10; ++i) {
		if (numeros[i] % 2 != 0) {
		printf("\n%d",i);
		}
	}
	return EXIT_SUCCESS;
}


