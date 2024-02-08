/*
 ============================================================================
 NICOLAS VLAEMINCH / DIV K / EJERCICIO 5-3
	 Realizar un programa que permita el ingreso de 10 números enteros distintos de cero. La carga
	 deberá ser aleatoria (todos los elementos se inicializan en cero por default). Determinar el
	 promedio de los positivos, y del menor de los negativos la suma de los antecesores (Según la recta
 	 numérica de los reales, hasta llegar a cero).
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {
	setbuf(stdout, NULL);
	int numeros[10];
	int acumulador = 0;
	float promedio;
	int banderaMenorNegativo = 0;
	int menorNegativos;
	int sumaAntecesores;

	for (int i = 0; i < 10; ++i) {
		printf("Ingrese un numero entero: ");
		fflush(stdin);
		scanf("%d",&numeros[i]);
		Validar(numeros[i]);

		if (numeros[i] > 0) {
			acumulador = acumulador + numeros[i];
		}
		else {
			if (banderaMenorNegativo == 0 || menorNegativos > numeros[i]) {
				menorNegativos = numeros[i];
				banderaMenorNegativo = 1;
			}
		}
	}

		promedio = PromedioPositivos(acumulador, 10);
		sumaAntecesores = SumaAntecesores(menorNegativos);

	printf("El promedio de los positivos es de %f",promedio);
	printf("\nLa suma de los antecesores de los negativos es de %d",sumaAntecesores);

	return EXIT_SUCCESS;
}
