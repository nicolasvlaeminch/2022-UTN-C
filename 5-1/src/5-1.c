/*
 ============================================================================
 NICOLAS VLAEMINCH / DIV K / EJERCICIO 5-1
 Pedir el ingreso de 5 números. Mostrarlos y calcular la sumatoria de los mismos.
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int numeros[5];
	int sumatoria = 0;

	for (int i = 0; i < 5; ++i) {
		setbuf(stdout, NULL);
		printf("Ingrese un numero: ");
		scanf("%d",&numeros[i]);
	}

	for (int i = 0; i < 5; ++i) {
		printf("%d ",numeros[i]);
		sumatoria = sumatoria + numeros[i];
	}

	printf("\nLa sumatoria de todos los numeros es %d",sumatoria);

	return EXIT_SUCCESS;
}
