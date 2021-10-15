/*
 * Perros.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Tomas Mastra
 */

#ifndef PERROS_C_
#define PERROS_C_

#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Estadia.h"
#include "Perros.h"
#include "Funciones.h"
#include "Nexo.h"

#define P 10
#define EMPTY -1

void perro_inicializar(ePerro perro[], int lenPerro)
{
	int i;

	for(i=0;i<lenPerro;i++)
	{


		perro[i].isEmpty = EMPTY;


	}

}






void harcodearPerros(ePerro perro[], int lenPerro)
{
	lenPerro =P;
		int i;
		int ids[] = {7000, 7001, 7002};
		char nombres[][21] = {"Lobo", "Shelia", "Reina"};
		char razas[][21] = {"Sharpei", "Golden", "Galgo"};
		int edad[] = {2, 12, 13};
		int isEmpty[] = {1,1,1};

		for(i=0; i<3; i++)
		{
			perro[i].id = ids[i];
			strcpy(perro[i].nombre, nombres[i]);
			strcpy(perro[i].raza, razas[i]);
			perro[i].edad = edad[i];
			perro[i].isEmpty = isEmpty[i];

		}




}


void perro_listar(ePerro perro[], int lenPerro)
{

	int i;

	lenPerro = P;

	printf("Listado de perros:\n\n"
				   "%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Raza", "Edad");

	for(i=0;i<lenPerro;i++)
	{
		if(perro[i].isEmpty  != EMPTY)
		{

		 perro_listarUno(perro[i]);
		}


	}



}

void perro_listarUno(ePerro perro)
{

	printf("%-5d %-20s %-20s %-20d\n", perro.id, perro.nombre, perro.raza, perro.edad);

}

void perro_calcularPromedioEdad(ePerro perro[], int lenPerro)
{

	float promedio;
	int i;
	float sumaEdades;

	int cantidadPerros = 0;

	sumaEdades = 0;
	promedio = 0;


	for(i=0;i<lenPerro;i++)
	{
		if(perro[i].isEmpty != EMPTY)
		{

		sumaEdades = sumaEdades + perro[i].edad;
		cantidadPerros++;

		}

	}


	promedio = sumaEdades/cantidadPerros;

	printf("Promedio de edades de los perros: %f\n", promedio);

}





#endif /* PERROS_C_ */
