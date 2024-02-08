/*
 ============================================================================
 Nicolas Vlaeminch Div K
 Parcial 1 - Parte 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libros.h"
#include "input.h"
#include "utn.h"
#include "validaciones.h"
#define CANTIDAD 5
#define LLENO 1
#define VACIO 0

int main(void) {
	setbuf(stdout, NULL);

	eLibro libros[CANTIDAD];
	int respuestaMenu;
	int opcion;

	//1
	int codigoIncremental = 0;

	//2
	int respuestaModificar;
	int opcionModificar;

	//4
	int totalImporte;
	float promedio;
	int superiorPromedio;
	int librosViejos;





	for(int i=0; i<CANTIDAD; i++)
	{
		libros[i].estado = VACIO;
		libros[i].importe = VACIO;
		libros[i].fecha.anio = VACIO;
	}

	for (;;) {
		respuestaMenu = utn_getNumero(&opcion,
				"\n\tMenu principal\n\n"
				"1. ALTAS\n"
				"2. MODIFICAR\n"
				"3. BAJA\n"
				"4. INFORMAR\n"
				"5. LISTAR"
				"\n\nIngrese una opcion: ", "\nERROR: numero invalido\n", 1, 5, 3);
		if(!respuestaMenu) {
			switch(opcion) {
			case 1:
				if(AltaLibro(libros, CANTIDAD, codigoIncremental) == 1) {
					printf("\nSe dio de alta correctamente\n\n");
					codigoIncremental++;
					system("pause");
				}
				else {
					printf("Lo siento la lista está llena\n");
					system("pause");
				}
				break;
			case 2:
				if (VerificarLleno(libros,CANTIDAD) == 1) {
					respuestaModificar = utn_getNumero(&opcionModificar,
									"\nQue desea modificar?\n\n"
									"1. Titulo\n"
									"2. Fecha de publicacion\n"
									"3. Importe\n"
									"4. Autor\n"
									"5. Editorial\n"
									"6. Genero"
									"\n\nIngrese una opcion: ", "\nERROR: numero invalido\n", 1, 6, 3);
					if(!respuestaModificar) {
						if (ModificarLibro(libros, CANTIDAD, opcionModificar) == 1) {
							printf("Modoficacion realizada con exito\n");
							system("pause");
						}
						else {
							printf("No se pudo modificar\n");
							system("pause");
						}
					}
				}
				else {
					printf("Primero debe dar de Alta un libro\n");
					system("pause");
				}
				break;
			case 3:
				if (VerificarLleno(libros,CANTIDAD) == 1) {
					if (BajaLibro(libros, CANTIDAD) == 1) {
						printf("\nDatos cargados con exito\n");
						system("pause");
					}
					else {
						printf("No se pudo dar de baja\n");
						system("pause");
					}
				}
				else {
					printf("Primero debe dar de Alta un libro\n");
					system("pause");
				}
				break;
			case 4:
				if (VerificarLleno(libros,CANTIDAD) == 1) {
					totalImporte = Sumatoria(libros, CANTIDAD);
					if (Sumatoria(libros, CANTIDAD) > 0) {
						promedio = Promedio(libros, CANTIDAD);
						superiorPromedio = SuperiorPromedio(libros, CANTIDAD);
						librosViejos = ContadorLibrosViejos(libros, CANTIDAD);
						printf("\nDatos cargados con exito: "
								"\n\nEl importe total es %d"
								" y el promedio es %.2f\n"
								"%d libros superan el promedio\n",
								totalImporte, promedio, superiorPromedio);
						printf("La cantidad de libros con una fecha anterior al 2000 son : %d\n\n", librosViejos);
						system("pause");
					}
					else {
						printf("ERROR\n");
						system("pause");
					}
				}
				else {
					printf("Primero debe dar de Alta un libro\n");
					system("pause");
				}
				break;
			case 5:
				if (VerificarLleno(libros,CANTIDAD) == 1) {
					MostrarEditorial(libros, CANTIDAD);
					MostrarPaises(libros, CANTIDAD);
					MostrarAutores(libros, CANTIDAD);
					MostrarGeneros(libros, CANTIDAD);
					MostrarLibros(libros, CANTIDAD);
					OrdenarImporteYTitulo(libros, CANTIDAD);
					MostrarLibros(libros, CANTIDAD);
					MostrarLibrosSinNovela(libros, CANTIDAD);
					MostrarLibrosArgentinos(libros, CANTIDAD);
					system("pause");
				}
				else {
					printf("Primero debe dar de Alta un libro\n");
					system("pause");
				}
				break;
			}
		}
	}
	return EXIT_SUCCESS;
}
