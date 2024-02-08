/*
 ============================================================================
 Name        : 4-2020.c
 Author      : Nicolas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int dividir (float* pResultado, int operador1, int operador2);

int main(void) {
	int numeroUno;
	int numeroDos;
	int respuesta;
	float resultado = 11111111;

	setbuf(stdout, NULL);
	printf("Ingrese numero1: ");
	scanf("%d",&numeroUno);
	printf("Ingrese numero2: ");
	scanf("%d",&numeroDos);

	respuesta = dividir (&resultado,numeroUno,numeroDos);
	if(respuesta == 0){
		printf("El resultado es: %f\n",resultado);
	}
	else {
		printf("No es posible dividir por cero\n");
	}



	return EXIT_SUCCESS;
}

int dividir (float *pResultado, int operador1, int operador2) {
	float resultado;

	if(pResultado != NULL && operador2 != 0)
	{
		resultado = (float) operador1 / operador2;
		*pResultado = resultado;
		return 0;
	}

	return -1;
}
