/*
 * funciones.c
 *
 *  Created on: 16 sept 2022
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>

int Validar(int numero) {
	while (numero == 0) {
		printf("ERROR: Ingrese un numero que no sea 0: ");
		scanf("%d",&numero);
	}
	return numero;
}

float PromedioPositivos(int numeros, int cantidadNumeros) {
	float promedio;

	promedio = (float)numeros / cantidadNumeros;

	return promedio;
}

int SumaAntecesores(int numero) {
	int sumatoria = 0;

	for (int i = numero; i < 0; ++i) {
		sumatoria = sumatoria + i;
	}
	sumatoria = sumatoria - numero;

	return sumatoria;
}
