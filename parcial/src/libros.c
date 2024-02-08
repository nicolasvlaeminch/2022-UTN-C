/*
 * libros.c
 *
 *  Created on: 1 oct 2022
 *      Author: Nicolas
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libros.h"
#include "input.h"
#define CANTIDAD 5
#define LLENO 1
#define VACIO 0

/**
 * \fn int AltaLibro(eLibro[], int, int)
 * \brief
 *
 * \param libros
 * \param tam
 * \param legajoAutoIncremental
 * \return
 *
 * Esta funcion da de alta un libro y lo guarda en una estructura, retorna 1 si se
 * da correctamente y 0 si falla. Primero llama la funcion BuscarLibre, para verificar
 * si hay un espacio libre en el array, si lo hay guardara el numero retornado por
 * BuscarLibre en la variable indice, luego enviara los mensajes uno por uno de las
 * funciones llamadas PedirEntero y PedirCadena guardando los datos ingresados en la
 * estructura con el indice guardado anteriormente si cumple con las verificaciones.
 */
int AltaLibro(eLibro libros[], int tam, int codigoAutoIncremental) {
	int retorno;
	int indice;
	int opcion;
	int respuestaMenu;

	retorno = 0; //Si la lista está llena

	indice = BuscarLibre(libros,tam);

	if(indice > -1)
	{
		libros[indice].codigoLibro = codigoAutoIncremental;
	    PedirCadena(libros[indice].titulo, 51, "Ingrese el titulo: ");
	    libros[indice].fecha.dia=PedirEntero("Ingrese el dia de su nacimiento: ", "ERROR: Ingrese el dia de su nacimiento valido: ", 1, 31);
	    libros[indice].fecha.mes=PedirEntero("Ingrese el mes de su nacimiento: ", "ERROR: Ingrese el dia de su nacimiento valido: ", 1, 12);
	    libros[indice].fecha.anio=PedirEntero("Ingrese el año de su nacimiento: ", "ERROR: Ingrese el dia de su nacimiento valido: ", 1700, 2022);
	    libros[indice].importe=PedirEntero("Ingrese el importe del libro: ", "ERROR: Ingrese el importe del libro valido: ", 1, 100000);
	    PedirCadena(libros[indice].autor.nombre, 51, "Ingrese el autor del libro: ");
	    PedirCadena(libros[indice].autor.nacionalidad.descripcion, 51, "Ingrese la nacionalidad: ");
	    PedirCadena(libros[indice].editorial.descripcion, 51, "Ingrese la editorial del libro: ");
		respuestaMenu = utn_getNumero(&opcion,
				"\n\tMenu principal\n\n"
				"1. Narrativo\n"
				"2. Lirico\n"
				"3. Dramatico\n"
				"4. Didactico\n"
				"5. Novela"
				"\n\nIngrese una opcion: ", "\nERROR: numero invalido\n", 1, 5, 3);
		if(!respuestaMenu) {
			switch(opcion) {
			case 1:
				strcpy(libros[indice].genero.descripcion,"Narrativo");
				break;
			case 2:
				strcpy(libros[indice].genero.descripcion,"Lirico");
				break;
			case 3:
				strcpy(libros[indice].genero.descripcion,"Dramatico");
				break;
			case 4:
				strcpy(libros[indice].genero.descripcion,"Didactico");
				break;
			case 5:
				strcpy(libros[indice].genero.descripcion,"Novela");
				break;
			}
		}


	    libros[indice].estado=LLENO;
	    retorno = 1; //TODO SALIO BIEN
	}
	return retorno;
}

/**
 * \fn int BuscarLibre(eLibro[], int)
 * \brief
 *
 * \param libros
 * \param tam
 * \return
 *
 * Esta funcion reccore un for busca un espacio libre en un array.
 * Se le pasa como parametro una estructura y el tamaño.
 * retornara -1 si no hay espacio o el numero del indice encontrado.
 */
int BuscarLibre(eLibro libros[],int tam) {
	int indice;
	indice = -1;

	for(int i=0; i<tam; i++)
    {
	   if(libros[i].estado == VACIO)
	   {
		   indice = i;
		   break;
	   }
    }
	return indice;
}

/**
 * \fn int BuscarLibro(eLibro[], int, int)
 * \brief
 *
 * \param libros
 * \param tam
 * \param codigoABuscar
 * \return
 *
 * Esta funcion busca un libro por su codigo.
 *
 * Recorre la sentencia for verificiando si el codigo pasado
 * por parametro existe, si existe retornara el indice de lo
 * contrario retornara -1.
 */
int BuscarLibro(eLibro libros[],int tam,int codigoABuscar) {
	int indice;

	indice = -1;

	for(int i=0; i<tam; i++)
    {
	   if(libros[i].estado == LLENO && libros[i].codigoLibro == codigoABuscar)
	   {
		   indice = i;
		   break;
	   }
    }

	return indice;
}


/**
 * \fn int ModificarLibro(eLibro[], int, int)
 * \brief
 *
 * \param libros
 * \param tam
 * \param opcion
 * \return
 *
 * Esta funcion permite modificar un lugar en concreto de un libro.
 * Primero la funcion pide que ingrese el codigo del libro mediante
 * la funcion PedirEntero, busca el libro mediante la funcion
 * BuscarLibro, luego dependiendo del dato pasado por la variable
 * opcion ingresara al switch eligiendo el tipo de dato a cambiar,
 * una vez terminado el cambio pedira verificar si estas seguro en
 * realizar los cambios ingresando 1 si la respuesta es si, y 0
 * si la respuesta es no.
 * Retorna -1 no encuentra el libro y 1 si lo encuentra.
 *
 */
int ModificarLibro(eLibro libros[], int tam, int opcion) {
	int codigoAModificar;
	char nombreModificado[51];
	int indiceAModificar;
	int confirmacion;
	int retorno;
	int dia;
	int mes;
	int anio;
	int nuevoImporte;
	char nacionalidadModificar[51];
	int respuestaMenu;
	int opcionMenu;
	retorno = -1;//Si no encontro el libro

	codigoAModificar = PedirEntero("Ingrese el codigo del libro a modificar: ", "Error: Ingrese el codigo del libro a modificar: ", 0, 4);
	indiceAModificar = BuscarLibro(libros, tam, codigoAModificar);

	if(indiceAModificar > -1)
	{
		switch (opcion) {
			case 1:
				PedirCadena(nombreModificado,51,"Ingrese el nuevo Titulo : ");
				retorno = 0;//Si cancelo la operación
				confirmacion = PedirEntero("Titulo listo para ser cargado ¿Desea guardar los cambios? 1 si 0 no: ",
						"ERROR: Titulo listo para ser cargado ¿Desea guardar los cambios? 1 si 0 no: ", 0, 1);
				if(confirmacion == 1)
				{
					strcpy(libros[indiceAModificar].titulo,nombreModificado);
					retorno = 1;//Salió todo bien
				}
				break;
			case 2:
			    dia=PedirEntero("Ingrese el dia de su nacimiento: ", "ERROR: Ingrese el dia de su nacimiento valido: ", 1, 31);
			    mes=PedirEntero("Ingrese el mes de su nacimiento: ", "ERROR: Ingrese el dia de su nacimiento valido: ", 1, 12);
			    anio=PedirEntero("Ingrese el año de su nacimiento: ", "ERROR: Ingrese el dia de su nacimiento valido: ", 1700, 2022);
				retorno = 0;//Si cancelo la operación
				confirmacion = PedirEntero("Fecha de publicacion lista para ser cargada ¿Desea guardar los cambios? 1 si 0 no: ",
						"ERROR: Fecha de publicacion lista para ser cargada ¿Desea guardar los cambios? 1 si 0 no: ", 0, 1);
				if(confirmacion == 1)
				{
				    libros[indiceAModificar].fecha.dia= dia;
				    libros[indiceAModificar].fecha.mes= mes;
				    libros[indiceAModificar].fecha.anio= anio;
					retorno = 1;//Salió todo bien
				}
				break;
			case 3:
				nuevoImporte = PedirEntero("Ingrese el nuevo importe: ", "ERROR: Ingrese un importe valido: ", 1, 100000);
				retorno = 0;//Si cancelo la operación
				confirmacion = PedirEntero("Nuevo importe listo para ser cargado ¿Desea guardar los cambios? 1 si 0 no: ",
						"ERROR: Nuevo importe listo para ser cargado ¿Desea guardar los cambios? 1 si 0 no: ", 0, 1);
				if(confirmacion == 1)
				{
				    libros[indiceAModificar].importe = nuevoImporte;
					retorno = 1;//Salió todo bien
				}
				break;
			case 4:
				PedirCadena(nombreModificado,51,"Ingrese el nuevo nombre del autor: ");
				PedirCadena(nacionalidadModificar,51,"Ingrese la nacionalidad: ");
				retorno = 0;//Si cancelo la operación
				confirmacion = PedirEntero("Nuevo autor listo para ser cargado ¿Desea guardar los cambios? 1 si 0 no: ",
						"ERROR: Nuevo autor listo para ser cargado ¿Desea guardar los cambios? 1 si 0 no: ", 0, 1);
				if(confirmacion == 1)
				{
					strcpy(libros[indiceAModificar].autor.nombre,nombreModificado);
					strcpy(libros[indiceAModificar].autor.nacionalidad.descripcion,nacionalidadModificar);
					retorno = 1;//Salió todo bien
				}
				break;
			case 5:
				PedirCadena(nombreModificado,51,"Ingrese el nuevo nombre de la editorial: ");
				retorno = 0;//Si cancelo la operación
				confirmacion = PedirEntero("Nuevo editorial listo para ser cargado ¿Desea guardar los cambios? 1 si 0 no: ",
						"ERROR: Nuevo editorial listo para ser cargado ¿Desea guardar los cambios? 1 si 0 no: ", 0, 1);
				if(confirmacion == 1)
				{
					strcpy(libros[indiceAModificar].editorial.descripcion,nombreModificado);
					retorno = 1;//Salió todo bien
				}
				break;
			case 6:
				respuestaMenu = utn_getNumero(&opcionMenu,
						"\n\tMenu principal\n\n"
						"1. Narrativo\n"
						"2. Lirico\n"
						"3. Dramatico\n"
						"4. Didactico\n"
						"5. Novela"
						"\n\nIngrese una opcion: ", "\nERROR: numero invalido\n", 1, 5, 3);
				if(!respuestaMenu) {
					switch(opcionMenu) {
					case 1:
						strcpy(libros[indiceAModificar].genero.descripcion,"Narrativo");
						retorno = 1;
						break;
					case 2:
						strcpy(libros[indiceAModificar].genero.descripcion,"Lirico");
						retorno = 1;
						break;
					case 3:
						strcpy(libros[indiceAModificar].genero.descripcion,"Dramatico");
						retorno = 1;
						break;
					case 4:
						strcpy(libros[indiceAModificar].genero.descripcion,"Didactico");
						retorno = 1;
						break;
					case 5:
						strcpy(libros[indiceAModificar].genero.descripcion,"Novela");
						retorno = 1;
						break;
					}
				}
				break;
		}
	}

	return retorno;
}

/**
 * \fn int BajaLibro(eLibro[], int)
 * \brief
 *
 * \param libros
 * \param tam
 * \return
 *
 * Esta funcion da de baja un libro.
 * Primero pide que ingreses el codigo del libro que deseas borrar mediante
 * la funcion PedirEntero, luego busca el libro por la funcion BuscarLibro
 * si lo encuentra deja un espacio vacio y retorna 1 de lo contrario retorna 0.
 *
 *
 */
int BajaLibro(eLibro libros[],int tam) {
	int libroABorrar;
	int retorno;
	int indiceDelLibro;

	libroABorrar = PedirEntero("Ingrese el codigo del libro a borrar: ", "ERROR: Ingrese el codigo del libro a borrar: ", 0, 4);
	indiceDelLibro = BuscarLibro(libros,tam,libroABorrar);

	retorno = 0;//Si no encontro al libro a borrar

	if(indiceDelLibro > -1)
	{
		libros[indiceDelLibro].estado=VACIO;
		retorno = 1;//Encontro al libro y lo borro
	}
    return retorno;
}

/**
 * \fn int Sumatoria(eLibro[], int)
 * \brief
 *
 * \param libros
 * \param tam
 * \return
 *
 * Esta funcion recorre la sentencia for guardando en la
 * variable total el importe total de libros.
 */
int Sumatoria(eLibro libros[], int tam) {
	int total = 0;

	for (int i = 0; i < tam; ++i) {
		total = libros[i].importe + total;
	}

	return total;
}

/**
 * \fn float Promedio(eLibro[], int)
 * \brief
 *
 * \param libros
 * \param tam
 * \return
 *
 * Esta funcion recorre la sentencia for si el importe es mayor a 0
 * sumara 1 al contador, luego sacara el promedio pasando a float
 * el retorno de la funcion Sumatoria y dividiendo por la variable
 * cantidadLibros para luego retornar el promedio.
 */
float Promedio(eLibro libros[], int tam) {
	float promedio;
	int cantidadLibros = 0;

	for (int i = 0; i < tam; ++i) {
		if (libros[i].importe > 0) {
			cantidadLibros++;
		}
	}

	promedio = (float)Sumatoria(libros, CANTIDAD) / cantidadLibros;

	return promedio;
}

/**
 * \fn int SuperiorPromedio(eLibro[], int)
 * \brief
 *
 * \param libros
 * \param tam
 * \return
 *
 * Esta funcion sirve para saber que libro supera el promedio de importe.
 * La funcion recorre el for verificiando si el libro es mayor al promedio,
 * si es asi suma uno a la variable contadorLibros y luego la retorna.
 *
 */
int SuperiorPromedio(eLibro libros[], int tam) {
	int contadorLibros = 0; //Cuenta la cantidad de libros que superan el promedio

	for (int i = 0; i < tam; ++i) {
		if (libros[i].importe > Promedio(libros, tam)) {
			contadorLibros++;
		}
	}

	return contadorLibros;
}

/**
 * \fn int ContadorLibrosViejos(eLibro[], int)
 * \brief
 *
 * \param libros
 * \param tam
 * \return
 *
 * Esta funcion cuenta cuentos libros su año es menor al 2000.
 * La funcion recorre el for verificando si el año del libro es menor
 * al 2000, si es asi sumara uno a la variable contadorLibros para
 * luego retornarlo.
 */
int ContadorLibrosViejos(eLibro libros[], int tam) {
	int contadorLibros;

	for (int i = 0; i < tam; ++i) {
		if (libros[i].fecha.anio < 2000 && libros[i].fecha.anio > 0) {
			contadorLibros++;
		}
	}

	return contadorLibros;
}

/**
 * \fn int VerificarLleno(eLibro[], int)
 * \brief
 *
 * \param libros
 * \param tam
 * \return
 *
 * Esta funcion sirve para saber si hay un espacio libre.
 * La funcion recorre el for verificando si el estado del
 * libro esta lleno si lo esta retornara 1, de lo contrario
 * retornara 0.
 */
int VerificarLleno(eLibro libros[],int tam) {
	int retorno;
	retorno = 0;

	for(int i=0; i<tam; i++)
    {
	   if(libros[i].estado == LLENO)
	   {
		   retorno = 1;
		   break;
	   }
    }
	return retorno;
}


/**
 * \fn void MostrarEditorial(eLibro[], int)
 * \brief
 *
 * \param libros
 * \param tam
 *
 * Esta funcion imprime todas las editoriales siempre
 * y cuando existan, esto lo verifica con la funcion
 * VerificarLleno, la funcion no retornada nada.
 */
void MostrarEditorial(eLibro libros[],int tam) {
   if(VerificarLleno(libros,tam) == 1)
   {
	   printf("\nEditoriales:\n\n");
	   for(int i=0; i<tam; i++)
	   {
		   if(libros[i].estado == LLENO)
		   {
			   printf("ID %d: %s\n", i, libros[i].editorial.descripcion);
		   }
	   }
   }
}

/**
 * \fn void MostrarPaises(eLibro[], int)
 * \brief
 *
 * \param libros
 * \param tam
 *
 * Esta funcion imprime todos los paises siempre
 * y cuando existan, esto lo verifica con la funcion
 * VerificarLleno, la funcion no retornada nada.
 */
void MostrarPaises(eLibro libros[],int tam) {
   if(VerificarLleno(libros,tam) == 1)
   {
	   printf("\nPaises:\n\n");
	   for(int i=0; i<tam; i++)
	   {
		   if(libros[i].estado == LLENO)
		   {
			   printf("ID %d: %s\n", i, libros[i].autor.nacionalidad.descripcion);
		   }
	   }
   }
}

/**
 * \fn void MostrarAutores(eLibro[], int)
 * \brief
 *
 * \param libros
 * \param tam
 *
 * Esta funcion imprime todos los autores siempre
 * y cuando existan, esto lo verifica con la funcion
 * VerificarLleno, la funcion no retornada nada.
 */
void MostrarAutores(eLibro libros[],int tam) {
   if(VerificarLleno(libros,tam) == 1)
   {
	   printf("\nAutores:\n\n");
	   for(int i=0; i<tam; i++)
	   {
		   if(libros[i].estado == LLENO)
		   {
			   printf("ID %d: %s\n", i, libros[i].autor.nombre);
		   }
	   }
   }
}

/**
 * \fn void MostrarLibros(eLibro[], int)
 * \brief
 *
 * \param libros
 * \param tam
 *
 * Esta funcion imprime todos los libros con sus datos
 * siempre y cuando existan, esto lo verifica con la funcion
 * VerificarLleno, la funcion no retornada nada.
 */
void MostrarLibros(eLibro libros[],int tam) {
   if(VerificarLleno(libros,tam) == 1) {

	   printf("\nCodigo\t\tTitulo\t\tFecha de publicacion\t\tImporte\t\tAutor\t\tEditorial\n\n");

	   for(int i=0; i<tam; i++) {
		   if(libros[i].estado == LLENO) {
			   printf("%d\t\t%s\t\t%d/%d/%d\t\t\t%d\t\t%s\t\t%s\n",
					   libros[i].codigoLibro,
					   libros[i].titulo,
					   libros[i].fecha.dia, libros[i].fecha.mes, libros[i].fecha.anio,
					   libros[i].importe,
					   libros[i].autor.nombre,
					   libros[i].editorial.descripcion);
		   }
	   }
   }
}

/**
 * \fn void OrdenarImporteYTitulo(eLibro[], int)
 * \brief
 *
 * \param libros
 * \param tam
 *
 * Esta funcion ordena los libros primero por Importe de manera
 * descendente y luego por Titulo de manera ascendente.
 */
void OrdenarImporteYTitulo(eLibro libros[],int tam) {
	eLibro aux;

	for (int i = 0; i < tam - 1; ++i) {
		for (int j = 0 + 1; j < tam; ++j) {
			if(libros[i].importe < libros[j].importe) {
				aux = libros[i];
				libros[i] = libros[j];
				libros[j] = aux;
			}
			else {
				if(libros[i].importe == libros[j].importe) {
					if (stricmp(libros[i].titulo, libros[j].titulo) > 0) {
						aux = libros[i];
						libros[i] = libros[j];
						libros[j] = aux;
					}
				}
			}
		}
	}
}

void MostrarGeneros(eLibro libros[],int tam) {
   if(VerificarLleno(libros,tam) == 1)
   {
	   printf("\nGeneros:\n\n");
	   for(int i=0; i<tam; i++)
	   {
		   if(libros[i].estado == LLENO)
		   {
			   printf("ID %d: %s\n", i, libros[i].genero.descripcion);
		   }
	   }
   }
}

void MostrarLibrosSinNovela(eLibro libros[],int tam) {

   if(VerificarLleno(libros,tam) == 1) {

	   printf("\nCodigo\t\tTitulo\t\tFecha de publicacion\t\tImporte\t\tAutor\t\tEditorial\t\tGenero\n\n");

	   for(int i=0; i<tam; i++) {
		   if(libros[i].estado == LLENO && strcmp(libros[i].genero.descripcion,"Narrativo")) {
			   printf("%d\t\t%s\t\t%d/%d/%d\t\t\t%d\t\t%s\t\t%s\t\t%s\n",
					   libros[i].codigoLibro,
					   libros[i].titulo,
					   libros[i].fecha.dia, libros[i].fecha.mes, libros[i].fecha.anio,
					   libros[i].importe,
					   libros[i].autor.nombre,
					   libros[i].editorial.descripcion,
					   libros[i].genero.descripcion);
		   }
	   }
   }
}

void MostrarLibrosArgentinos(eLibro libros[],int tam) {

   if(VerificarLleno(libros,tam) == 1) {

	   printf("\nCodigo\t\tTitulo\t\tAutor\t\tEditorial\t\tNacionalidad\n\n");

	   for(int i=0; i<tam; i++) {
		   if(libros[i].estado == LLENO && !strcmp(libros[i].autor.nacionalidad.descripcion, "argentina")) {
			   printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\n",
					   libros[i].codigoLibro,
					   libros[i].titulo,
					   libros[i].autor.nombre,
					   libros[i].editorial.descripcion,
					   libros[i].autor.nacionalidad.descripcion);
		   }
	   }
   }
}



