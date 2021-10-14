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

typedef struct
{

	int id;
	char nombre[21];
	char raza[21];
	int edad;
	//int isEmpty;


}ePerro;

void harcodearPerros(ePerro perro[], int len);

void perro_inicializar();

void perro_listar(ePerro perro[], int len);

void perro_calcularPromedioEdad(ePerro perro[], int lenPerro);






#endif /* PERROS_H_ */
