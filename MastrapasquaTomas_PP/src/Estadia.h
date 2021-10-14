/*
 * Estadia.h
 *
 *  Created on: 12 oct. 2021
 *      Author: Tomas Mastra
 */

#ifndef ESTADIA_H_
#define ESTADIA_H_

#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{

	int dia;
	int mes;
	int anio;

}eFecha;
typedef struct
{

	int id;
	char nombreDuenio[21];
	int telefonoContacto;
	int idPerro;
	eFecha fecha;

	int isEmpty;

}eEstadia;

void estadia_harcodear(eEstadia estadia[], int len);
void estadia_inicializar(eEstadia estadia[], int len);

int validarIsEmpty(eEstadia estadia[], int len);

int estadia_reservar(eEstadia estadia[], int len, int id);

void estadia_pedirDatos(eEstadia estadia[], int i, int id);
int estadia_buscarLibre(eEstadia estadia[], int len);

void estadia_confirmar(eEstadia estadia[], int i);
int estadia_buscarID(eEstadia estadia[], int len, int id);

void estadia_modificar(eEstadia estadia[], int len);
void estadia_modificarSubMenu(eEstadia estadia[], int len, int i);

void estadia_cancelar(eEstadia estadia[], int len);

void estadia_listarTodos(eEstadia estadia[], int len);
void estadia_listarUno(eEstadia estadia);
void estadia_ordenar(eEstadia estadia[], int len);

void estadia_pedirFecha(eEstadia estadia[], int i);



#endif /* ESTADIA_H_ */
