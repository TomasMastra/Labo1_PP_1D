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



void harcodearPerros(ePerro perro[], int len)
{

		int i;
		int ids[] = {7000, 7001, 7002};
		char nombres[][21] = {"Lobo", "Shelia", "Reina"};
		char razas[][21] = {"Sharpei", "Golden", "Galgo"};
		int edad[] = {2, 12, 13};

		for(i=0; i<len; i++)
		{
			perro[i].id = ids[i];
			strcpy(perro[i].nombre, nombres[i]);
			strcpy(perro[i].raza, razas[i]);
			perro[i].edad = edad[i];
		}




}

void perro_listar(ePerro perro[], int lenPerro)
{

	int i;

	printf("Listado de perros:\n\n"
				   "%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Raza", "Edad");

	for(i=0;i<lenPerro;i++)
	{

		printf("%-5d %-20s %-20s %-20d\n", perro[i].id, perro[i].nombre, perro[i].raza, perro[i].edad);

	}



}

void perro_calcularPromedioEdad(ePerro perro[], int lenPerro)
{

	float promedio;
	int i;
	int sumaEdades;

	sumaEdades = 0;
	promedio = 0;


	for(i=0;i<lenPerro;i++)
	{
		if(perro[i].edad<20)
		{

		sumaEdades = sumaEdades + perro[i].edad;

		}

	}


	promedio = sumaEdades/lenPerro;

	printf("Promedio de edades de los perros: %f\n", promedio);

}





#endif /* PERROS_C_ */
