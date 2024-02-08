/*
 * funciones.c
 *
 *  Created on: 16 sept 2022
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>

int Validar(int temperatura, int min, int max) {
	while (temperatura < min || temperatura > max) {
		printf("ERROR: Ingrese una temperatura valida: ");
		scanf("%d",&temperatura);
	}
	return temperatura;
}

void CaF(int celsius) {
	float fahrenheit;

	fahrenheit = (float)celsius * 1.8 + 32;
	printf("Los %d celsius son %f fahrenheit\n", celsius, fahrenheit);
}

void FaC(int fahrenheit) {
	float celsius;

	celsius = ((float)fahrenheit - 32) * 5 / 9;
	printf("Los %d fahrenheit son %f celsius\n", fahrenheit, celsius);
}
