/* NICOLAS VLAEMINCH / DIV K / EJERCICIO 3-4

Especializar la función anterior para que permita validar el entero ingresado en un rango
determinado.*/

#include <stdio.h>
#include <stdlib.h>

int MostrarEntero();

int main(void)
{
	setbuf(stdout, NULL);

	int resultado;

	resultado = MostrarEntero();

	printf("El numero es: %d",resultado);

	return 0;
}

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
