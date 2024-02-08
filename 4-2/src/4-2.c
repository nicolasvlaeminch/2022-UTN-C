/// NICOLAS VLAEMINCH / DIV K / EJERCICIO 4-2
//
//Realizar un programa que permita la carga de temperaturas en celsius y fahrenheit , validando que
//las temperaturas ingresadas estén entre el punto de congelación y ebullición del agua para cada
//tipo de escala.
//Las validaciones se hacen en una biblioteca.
//Las funciones de transformación de fahrenheit a celsius y de celsius a fahrenheit se hacen en otra biblioteca.

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void)
{
	setbuf(stdout, NULL);
	char tipoTemperatura;
	int celsius;
	int fahrenheit;


	printf("Ingrese c si quiere ingresar celsius o f si quiere fahrenheit: ");
	scanf("%c",&tipoTemperatura);

	while (tipoTemperatura != 'c' && tipoTemperatura != 'f') {
		fflush(stdin);
		printf("ERROR: Ingrese c si quiere ingresar celsius o f si quiere fahrenheit: ");
		scanf("%c",&tipoTemperatura);
	}

	if (tipoTemperatura == 'c') {
		printf("Ingrese grados celsius: ");
		scanf("%d",&celsius);
		Validar(celsius, 0, 100);
		CaF(celsius);
	}
	else {
		printf("Ingrese grados fahrenheit: ");
		scanf("%d",&fahrenheit);
		Validar(fahrenheit, 32, 212);
		FaC(fahrenheit);
	}
	return 0;
}
