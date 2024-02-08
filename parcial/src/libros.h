/*
 * libros.h
 *
 *  Created on: 1 oct 2022
 *      Author: Nicolas
 */

#ifndef LIBROS_H_

typedef struct{
	int dia;
	int mes;
	int	anio;
}eFecha;

typedef struct
{
	int codigoEditorial;
	char descripcion[51];
}eEditorial;


typedef struct
{
	int codigoPais;
	char descripcion[51];
}ePais;

typedef struct
{
	int codigoAutor;
	char nombre[51];
	ePais nacionalidad;
}eAutor;

typedef struct
{
	int codigoGenero;
	char descripcion[51];
}eGenero;

typedef struct
{
	int codigoLibro;
	char titulo[51];
	eFecha fecha;
	int importe;
	eAutor autor;
	eEditorial editorial;
	int estado;
	eGenero genero;
}eLibro;

int BuscarLibre(eLibro libros[],int tam);
int AltaLibro(eLibro libros[], int tam, int codigoAutoIncremental);
int ModificarLibro(eLibro libros[], int tam, int opcion);
int BuscarLibro(eLibro libros[],int tam,int codigoABuscar);
int BajaLibro(eLibro libros[],int tam);
int Sumatoria(eLibro libros[], int tam);
float Promedio(eLibro libros[],int tam);
int SuperiorPromedio(eLibro libros[], int tam);
int ContadorLibrosViejos(eLibro libros[], int tam);
int VerificarLleno(eLibro libros[],int tam);
void MostrarEditorial(eLibro libros[],int tam);
void MostrarPaises(eLibro libros[],int tam);
void MostrarAutores(eLibro libros[],int tam);
void MostrarLibros(eLibro libros[],int tam);
void OrdenarImporteYTitulo(eLibro libros[],int tam);
void MostrarGeneros(eLibro libros[],int tam);
void MostrarLibrosSinNovela(eLibro libros[],int tam);
void MostrarLibrosArgentinos(eLibro libros[],int tam);

#define LIBROS_H_



#endif /* LIBROS_H_ */
