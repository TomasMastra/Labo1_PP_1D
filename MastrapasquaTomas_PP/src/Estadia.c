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
#include "Nexo.h"


#define EMPTY -1
#define X 5

void estadia_inicializar(eEstadia estadia[], int len)
{
	int i;

	for(i=0;i<len;i++)
	{
		estadia[i].isEmpty = EMPTY;
		//printf("%d \n", estadia[i].isEmpty);


	}


}

int estadia_reservar(eEstadia estadia[], int len, int id)
{

	int index;

	index = estadia_buscarLibre(estadia, len);

	//estadia_pedirDatos(estadia, index, id);







	//printf("index vale %d\n", index);
	if(index != -1)
	{

		id++;

		id = id+index;
		estadia_pedirDatos(estadia, index, id);

		//break;



	}else
	{

		printf("No hay espacio!!\n");
	}


 return index;
}

void estadia_pedirDatos(eEstadia estadia[], int i, int id)
{



	if(i!=EMPTY)
	{

		printf("i vale %d\n", i);


		estadia[i].id = id;
		printf("el id es %d\n", id);
		 getString(estadia[i].nombreDuenio, "Ingrese el nombre del duenio: ", "ERROR, solo letras y menos de 20 caracteres, reingrese: ", 21);
		 getInt(&estadia[i].telefonoContacto, "Ingrese su numero:\n","Error, ingrese su numero:\n", 1000000000, 1500000000);
		 //   validateIdPerro(ePerro perro[], int* integer, char* message, char* messageError, int len)


		 estadia_pedirFecha(estadia,  i);




		 estadia_confirmar(estadia,  i);




	}
}

void estadia_pedirFecha(eEstadia estadia[], int i)
{

	//eFecha fecha;

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
					//printf("estadia %d", estadia[i].isEmpty);

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

		printf("antes de confirmar i es %d\n", i);

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
		int i = EMPTY;

		int ret = -1;




		printf("Bucando estadia...\n");

	  if(validarIsEmpty(estadia, len) == 1)
	  {// 1
			getInt(&idIngresado, "Ingrese el ID de la estadia para que sea eliminada (100000-200000): ", "ERROR, Ingrese el ID de la estadia para que sea eliminada (100000-200000): ", 100000, 200000);
			i =  estadia_buscarID(estadia, len, idIngresado);


			if(i!= EMPTY)
			{//2

					estadia[i].isEmpty = EMPTY;
					printf("%d\n", estadia[i].isEmpty);


					printf("La estadia se elimino correctamente\n");

					ret = 0;

			}else///2
			{//3
				printf("No se encontro el ID\n");
			}//3
	  }else //1
		  if(ret == -1)
	  {//4



		  printf("No cargo ninguna estadia\n");

	  }//4




}//0

	int estadia_buscarID(eEstadia estadia[], int len, int id)
	{//0

		int i;
		int index = -1;


		for(i=0;i<len;i++)
			{
				if(estadia[i].isEmpty != EMPTY && estadia[i].id == id)
				{


					index = i;



				}



		    }

		return index;


	}//0

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

		printf("%-10d %-20s %-20d %-20d %d/%d/%d\n", estadia.id, estadia.nombreDuenio, estadia.telefonoContacto, estadia.idPerro, estadia.fecha.dia, estadia.fecha.mes, estadia.fecha.anio);


	}



	void estadia_listarTodos(eEstadia estadia[], int len)
	{

		int i;


			printf("\n\n\n"
					   "%-10s %-20s %-20s %-20s %-20s\n", "ID", "Nombre duenio", "Telefono", "ID perro", "Fecha");



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
					if(estadia[i].isEmpty == 1 && estadia[j].fecha.anio == 1)
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

												if(strcmp(estadia[i].nombreDuenio, estadia[j].nombreDuenio) == 0)
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






}

void estadia_harcodear(eEstadia estadia[], int len)
{

		int i;
		int ids[] = {7000, 7001, 7002};
		char nombres[][21] = {"Joaquin", "Walter", "Gonzalo"};
		int telefono[] = {1000000000, 1200000000, 1300000000};
		int anio[] = {2000, 2020, 2005};
		int mes[] = {2, 9, 1};
		int dia[] = {4, 24, 5};

		for(i=0; i<len; i++)
		{
			estadia[i].id = ids[i];
			strcpy(estadia[i].nombreDuenio, nombres[i]);
			estadia[i].telefonoContacto = telefono[i];

			estadia[i].fecha.anio = anio[i];
			estadia[i].fecha.mes = mes[i];
			estadia[i].fecha.dia = dia[i];
		}




}
#endif /* ESTADIA_C_ */
