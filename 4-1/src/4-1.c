/* NICOLAS VLAEMINCH / DIV K / EJERCICIO 4-1

Realizar un programa EN EL MAINque permita calcular y mostrar el factorial de un
número. Utilizar la función PedirNumero de la ejercitación 3-4. */

#include <stdio.h>
#include <stdlib.h>
//#include "funciones.h"
#include "../../miBiblioteca/utn.h"

int main(void)
{
	setbuf(stdout, NULL);

	int numeroIngresado;
	int resultado = 1;

	numeroIngresado = MostrarEntero();

	for (int contador = 1; contador <= numeroIngresado; contador++) {
		resultado = resultado * contador;
	}

	printf("%d",resultado);

	return 0;
}
