/*
 ============================================================================
 NICOLAS VLAEMINCH / DIV K / EJERCICIO 6-3
	Pedirle al usuario su nombre y apellido (en variables separadas, una para el nombre y otra para el
	apellido). Ninguna de las dos variables se puede modificar.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
	setbuf(stdout, NULL);

	char nombre[20];
	char apellido[20];
	char aux[20];
	int tamanioArray;

	printf("Ingrese su nombre: ");
	fflush(stdin);
	gets(nombre);

	printf("Ingrese su apellido: ");
	fflush(stdin);
	gets(apellido);

	strlwr(nombre);
	strlwr(apellido);

	tamanioArray = strlen(nombre);

	nombre[0] = toupper(nombre[0]);
	for (int i = 0; i < tamanioArray; ++i) {
		if (nombre[i] == ' ') {
			nombre[i + 1] = toupper(nombre[i + 1]);
		}
	}
	apellido[0] = toupper(apellido[0]);

	strcpy(aux, apellido);
	strcat(aux, ", ");
	strcat(aux, nombre);


	printf("%s", aux);
}
