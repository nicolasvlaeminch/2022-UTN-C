/* NICOLAS VLAEMINCH / DIV K / EJERCICIO 3-2

Crear una función que permita determinar si un número es par o no. La función retorna 1 en caso
afirmativo y 0 en caso contrario. Probar en el main. */

#include <stdio.h>
#include <stdlib.h>

int MostrarParImpar();

int main(void)
{

	setbuf(stdout, NULL);

	int numero;


	printf("Ingrese un numero ");
	scanf("%d", &numero);

	MostrarParImpar(numero);

	return 0;
}

int MostrarParImpar(int numero)
{
	if((numero % 2 == 0))
	{
		printf("Es par");
	}
	else
	{
		printf("Es impar");
	}

	return numero;
}
