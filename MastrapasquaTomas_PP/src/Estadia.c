/*
 * Estadia.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Tomas Mastra
 */

#ifndef ESTADIA_C_
#define ESTADIA_C_

#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Estadia.h"
#include "Perros.h"
#include "Funciones.h"
#include "duenio.h"
#include "Nexo.h"



#define EMPTY -1
#define X 15

void estadia_inicializar(eEstadia estadia[], int len)
{
	int i;

	for(i=0;i<len;i++)
	{
		estadia[i].isEmpty = EMPTY;


	}


}



void estadia_pedirDatos(eEstadia estadia[], int i, int id)
{



	if(i!=EMPTY)
	{



		estadia[i].id = id;



		 estadia_pedirFecha(estadia,  i);




		 estadia_confirmar(estadia,  i);




	}
}

void estadia_pedirFecha(eEstadia estadia[], int i)
{


	 getInt(&estadia[i].fecha.dia, "Ingrese el dia (1-31):\n","Error, ingrese el dia (1-31):\n", 1, 31);
	 getInt(&estadia[i].fecha.mes, "Ingrese el mes (1-12):\n","Error, ingrese el mes (1-12):\n", 1, 12);
	 getInt(&estadia[i].fecha.anio, "Ingrese el año (2000 - 2021):\n","Error, ingrese el año (2000 - 2021):\n", 2000, 2021);







}

int estadia_buscarLibre(eEstadia estadia[], int len)
{
		int i;
		int index = EMPTY;


			for(i=0;i<len;i++)
			{




				if(estadia[i].isEmpty == EMPTY)
				{

					//estadia[i].isEmpty = 1;



					index = i;

					break;

					//list[i].isEmpty = 1;


				}



			}

			return index;
}

void estadia_confirmar(eEstadia estadia[], int i)
{
		char confirm;


		getChar(&confirm, "Ingrese S para cargar la estadia");

					 if(confirm == 's' || confirm == 'S')
						 {
								estadia[i].isEmpty = 1;

								printf("Se cargo correctamente\n");

						}



}

void estadia_cancelar(eEstadia estadia[], int len)
{//0

		int idIngresado;
		int index = EMPTY;

		int ret = -1;




		printf("Bucando estadia...\n");

	  if(validarIsEmpty(estadia, len) == 1)
	  {
			getInt(&idIngresado, "Ingrese el ID de la estadia para que sea eliminada (100000-200000): ", "ERROR, Ingrese el ID de la estadia para que sea eliminada (100000-200000): ", 100000, 200000);
			index =  estadia_buscarID(estadia, len, idIngresado);


			if(index>-1)
			{

				estadia[index].isEmpty = EMPTY;

				printf("La ID que se eliminara es %d\n\n", estadia[index].id);


					printf("La estadia se elimino correctamente\n");

					ret = 0;

			}else
				if(index == EMPTY)

			{
				printf("No se encontro el ID\n");
			}
	  }else
		  if(ret == -1)
	  {



		  printf("No cargo ninguna estadia\n");

	  }




}

	int estadia_buscarID(eEstadia estadia[], int len, int id)
	{

		int i = -1;
		int index = -1;


		for(i=0;i<len;i++)
			{
				if(estadia[i].id == id)
				{


					index = i;
					break;



				}



		    }

		return index;


	}

	int validarIsEmpty(eEstadia estadia[], int len)
	{
		int ret = -1;

		int i;


		for(i=0;i<len;i++)
			if(estadia[i].isEmpty != EMPTY)
			{


				ret=1;
				break;
			}





		return ret;
	}////////////


	void estadia_listarUno(eEstadia estadia)
	{

		printf("%-10d %-20d %d/%d/%d %-50d\n", estadia.id,  estadia.idPerro, estadia.fecha.dia, estadia.fecha.mes, estadia.fecha.anio, estadia.idDuenio);


	}



	void estadia_listarTodos(eEstadia estadia[], int len)
	{

		int i;


			printf("Listado de estadias\n\n\n"
					   "%-10s %-20s %s %-50s\n\n", "ID",  "ID perro", "Fecha", "ID duenio");



				for(i=0; i<len; i++)
				{
					if(estadia[i].isEmpty != EMPTY)
					{
						estadia_listarUno(estadia[i]);
					}
				}


	}

void estadia_ordenar(eEstadia estadia[], int len)
{

	int i;
	int j;

	eEstadia auxEstadia;

	printf("Funciona...\n");

	for(i=0; i<len-1; i++)
			{
				for(j=i+1; j<len; j++)
				{
					if(estadia[i].isEmpty != EMPTY && estadia[j].isEmpty != EMPTY)
					{
						if(estadia[i].fecha.anio < estadia[j].fecha.anio)//BIEN
						{
							auxEstadia = estadia[i];
							estadia[i] = estadia[j];
							estadia[j] = auxEstadia;
						}else
						{

							if(estadia[i].fecha.anio == estadia[j].fecha.anio)
							{
								if(estadia[i].fecha.mes < estadia[j].fecha.mes)
								{
									auxEstadia = estadia[i];
									estadia[i] = estadia[j];
									estadia[j] = auxEstadia;

								}else
								{

									if(estadia[i].fecha.mes == estadia[j].fecha.mes)
									{

										if(estadia[i].fecha.dia < estadia[j].fecha.dia)
										{

											auxEstadia = estadia[i];
											estadia[i] = estadia[j];
											estadia[j] = auxEstadia;



										}else
										{
											if(estadia[i].fecha.dia == estadia[j].fecha.dia)
											{


												{

													auxEstadia = estadia[i];
													estadia[i] = estadia[j];
													estadia[j] = auxEstadia;
												}

											}

										}


									}


								}


							}
						}
					}
				}
			}

	 estadia_listarTodos(estadia,  len);






}

void estadia_harcodear(eEstadia estadia[], int len)
{

	//Poner flag en 1;

		int i;
		int ids[] = {100000, 100001, 100002, 100003, 100004};

		int anio[] = {2000, 2000, 2003, 2000, 2021};
		int mes[] = {2, 2, 2, 1, 8};
		int dia[] = {24, 24, 24, 25, 12};

		for(i=0; i<len; i++)
		{
			estadia[i].id = ids[i];


			estadia[i].fecha.anio = anio[i];
			estadia[i].fecha.mes = mes[i];
			estadia[i].fecha.dia = dia[i];
		}




}
#endif /* ESTADIA_C_ */
