/*
EJERCICIO: HACER UNA FUNCION QUE CALCULE EL PROMEDIO DE VALORES
DEL ARRAY QUE RECIBE Y ME DEVUELVA EL PROMEDIO
 */

#include <stdio.h>
#include <stdlib.h>

float CalcularPromedio(int array[], int numeros);

int main(void) {
	setbuf(stdout, NULL);
	int numeros[5];
	float promedio;

	for (int i = 0; i < 5; ++i) {
		printf("Ingrese un numero: ");
		fflush(stdin);
		scanf("%d",&numeros[i]);
	}

	promedio = CalcularPromedio(numeros, 5);

	printf("El promedio es %f", promedio);

	return EXIT_SUCCESS;
}

float CalcularPromedio(int array[], int numeros) {
	float promedio;
	int acumulador = 0;

	for (int i = 0; i < numeros; ++i) {
		acumulador = acumulador + array[i];
	}

	promedio = (float)acumulador / numeros;

	return promedio;
}
