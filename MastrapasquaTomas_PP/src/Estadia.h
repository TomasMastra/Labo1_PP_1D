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

	int idDuenio;
	int idPerro;
	eFecha fecha;

	int isEmpty;

}eEstadia;

void estadia_harcodear(eEstadia estadia[], int len);
void estadia_inicializar(eEstadia estadia[], int len);//Esta funcion inicializa el array de isEmpty en -1 (EMPTY)

int validarIsEmpty(eEstadia estadia[], int len);//Esta funcion la uso en caso de que se haya ingresado la opcion 1 y se eliminen todos las estadias


void estadia_pedirDatos(eEstadia estadia[], int i, int id);//Esta funcion pide los datos, el index lo busca la funcion de inicializar en el nexo.c
int estadia_buscarLibre(eEstadia estadia[], int len);

void estadia_confirmar(eEstadia estadia[], int i);//Esta funcion pide que introduzcas s si queres que se guarde lo que ingresaste, en caso de que lo hagas en isEmpty se cambia a 1;
int estadia_buscarID(eEstadia estadia[], int len, int id);//Esta funcion busca un ID



void estadia_cancelar(eEstadia estadia[], int len);//Esta funcio elimina una estadia

void estadia_listarTodos(eEstadia estadia[], int len);//Esta funcion muestra todas las estadias, llama a la de listarUno
void estadia_listarUno(eEstadia estadia);//Esta funcion muestra 1 estadia
void estadia_ordenar(eEstadia estadia[], int len);/*Esta funcion ordena por fecha, primero comparo el año y si son iguales estadia de i es igual a la de j, en caso de que sean iguales se compara el mes y despues el dia.
 * En caso de que sean todas las fechas igual, se compara el nombreDuenio
 *
 *
 */

void estadia_pedirFecha(eEstadia estadia[], int i);//Esta funcion pide las fechas, dia, mes y año



#endif /* ESTADIA_H_ */
