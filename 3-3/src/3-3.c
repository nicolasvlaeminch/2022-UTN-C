/* NICOLAS VLAEMINCH / DIV K / EJERCICIO 3-3

Crear una función que pida el ingreso de un entero y lo retorne.*/

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

	return numero;
}

