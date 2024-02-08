/* NICOLAS VLAEMINCH / DIV K / EJERCICIO 3-5

Realizar un programa en donde se puedan utilizar los prototipos de la función Sumar en sus 4 combinaciones.

int Sumar1(int, int);
int Sumar2(void);
void Sumar3(int, int);
void Sumar4(void); */

#include <stdio.h>
#include <stdlib.h>

int Sumar1(int, int);
int Sumar2(void);
void Sumar3(int, int);
void Sumar4(void);

int main(void) {
	setbuf(stdout, NULL);

	int tipoCuenta;
	int numeroUno;
	int numeroDos;
	int resultado;

	printf("Ingrese que tipo de cuenta quiere hacer 1, 2, 3 o 4: ");
	scanf("%d",&tipoCuenta);
	while (tipoCuenta < 1 || tipoCuenta > 4) {
		printf("ERROR: Ingrese que tipo de cuenta quiere hacer 1, 2, 3 o 4: ");
		scanf("%d",&tipoCuenta);
	}

	switch (tipoCuenta) {
		case 1:
			printf("Ingrese numero uno: ");
			scanf("%d",&numeroUno);
			printf("Ingrese numero dos: ");
			scanf("%d",&numeroDos);
			resultado = Sumar1(numeroUno, numeroDos);
			printf("%d", resultado);
			break;

		case 2:
			resultado = Sumar2();
			printf("%d", resultado);
			break;

		case 3:
			printf("Ingrese numero uno: ");
			scanf("%d",&numeroUno);
			printf("Ingrese numero dos: ");
			scanf("%d",&numeroDos);
			Sumar3(numeroUno, numeroDos);
			break;

		default:
			Sumar4();
			break;
	}


	return EXIT_SUCCESS;
}

int Sumar1(int numeroUno, int numeroDos) {
	int sumaUno;

	sumaUno = numeroUno + numeroDos;

	return sumaUno;
}

int Sumar2(void) {
	int sumaDos;
	int numeroUno_1;
	int numeroDos_2;

	printf("Ingrese numero uno: ");
	scanf("%d",&numeroUno_1);
	printf("Ingrese numero dos: ");
	scanf("%d",&numeroDos_2);

	sumaDos = numeroUno_1 + numeroDos_2;

	return sumaDos;
}

void Sumar3(int numeroUno_3, int numeroDos_3) {
	int sumaTres;

	sumaTres = numeroUno_3 + numeroDos_3;

	printf("%d", sumaTres);
}

void Sumar4(void) {
	int sumaCuatro;
	int numeroUno_4;
	int numeroDos_4;

	printf("Ingrese numero uno: ");
	scanf("%d",&numeroUno_4);
	printf("Ingrese numero dos: ");
	scanf("%d",&numeroDos_4);

	sumaCuatro = numeroUno_4 + numeroDos_4;

	printf("%d", sumaCuatro);
}
