/*
 * utn.c
 *
 *  Created on: 13 sept 2022
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>

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
