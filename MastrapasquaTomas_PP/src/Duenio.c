/*
 * Duenio.c
 *
 *  Created on: 15 oct. 2021
 *      Author: Tomas Mastra
 */

#ifndef DUENIO_C_
#define DUENIO_C_


#include "Estadia.h"
#include "Perros.h"
#include "Funciones.h"
#include "duenio.h"
#include "Nexo.h"


#define D 15


void duenio_inicializar(eDuenio duenio[], int lenDuenio)
{

	int i;

	for(i=0;i<lenDuenio;i++)
	{

		duenio[i].isEmpty = -1;

	}


}

void duenio_harcodear(eDuenio duenio[], int lenDuenio)
{
		int i;
		int ids[] = {30000, 30001, 30002};
		char nombres[][21] = {"Martina", "Sebastian", "Javier"};
		int telefonos[] = {1201001221, 1589875487, 1567983200};
		int isEmpty[] = {1,1,1};

		for(i=0; i<3; i++)
		{
			duenio[i].id = ids[i];
			strcpy(duenio[i].nombre, nombres[i]);
			duenio[i].telefono = telefonos[i];
			duenio[i].isEmpty = isEmpty[i];

		}




}

void modificarDuenio(eDuenio duenio[], int lenDuenio, int id)
{


	int index;
	//int idIngresado;

	index =  duenio_buscarId(duenio, lenDuenio, id);





	if(index>-1)
	{

	getInt(&duenio[index].telefono, "Ingrese numero de telefono (1000000000 - 1500000000)", "ERROR, Ingrese numero de telefono (1000000000 - 1500000000)", 1000000000,1500000000);

	}



}

int duenio_buscarId(eDuenio duenio[], int lenDuenio, int id)
	{

		int i = -1;
		int index = -1;

		lenDuenio = D;


		for(i=0;i<lenDuenio;i++)
			{
				if(duenio[i].id == id)
				{


					index = i;
					break;



				}



		    }

		return index;
	}

void duenio_listarUno(eDuenio duenio)
{

	printf("%-5d %-20s %-20d\n", duenio.id, duenio.nombre, duenio.telefono);


}
void duenio_listar(eDuenio duenio[], int lenDuenio)
{

	int i;


		printf("Listado de duenios:\n\n"
					   "%-5s %-20s %-20s\n", "ID", "Nombre", "telefono");

		for(i=0;i<lenDuenio;i++)
		{
			if(duenio[i].isEmpty  != -1)
			{

			 duenio_listarUno(duenio[i]);
			}


		}



	}







#endif /* DUENIO_C_ */
