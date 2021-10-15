/*
 * Perros.h
 *
 *  Created on: 12 oct. 2021
 *      Author: Tomas Mastra
 */

#ifndef PERROS_H_
#define PERROS_H_

#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define P 10

typedef struct
{

	int id;
	char nombre[21];
	char raza[21];
	int edad;

	int isEmpty;


}ePerro;

void harcodearPerros(ePerro perro[], int lenPerro);//Esta funcion harcodea los perros en la posicion de i
void perro_inicializar(ePerro perro[], int lenPerro);




void perro_listar(ePerro perro[], int len);//Esta funcion llama a la funcion de listarUno con un for para que se muestren todos los perros
void perro_listarUno(ePerro perro);//esta funcion muestra un perro, se usa para la funcion de mostar todos



void perro_calcularPromedioEdad(ePerro perro[], int lenPerro);//Esta funcion suma las edades para buscar el promedio de sus edades






#endif /* PERROS_H_ */
