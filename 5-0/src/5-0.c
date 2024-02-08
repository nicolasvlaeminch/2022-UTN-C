/*
 NICOLAS VLAEMINCH / DIV K / EJERCICIO 5-0
	Pedir cinco números y mostrarlos desde el último que pedi hasta el primero
	Por ejemplo:
	Pedí: 3-5-2-4-7
	Tengo que devolver: 7-4-2-5-3
	Haganlo con todo lo que saben hasta ahora.
*/


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int numeros[5];

	for (int i = 0; i < 5; i++) {
		setbuf(stdout, NULL);
		fflush(stdin);
		printf("Ingrese un numero: ");
		scanf("%d",&numeros[i]);
	}

		printf("%d - %d - %d - %d - %d",numeros[4],numeros[3],numeros[2],numeros[1],numeros[0]);
	return 0;
}


