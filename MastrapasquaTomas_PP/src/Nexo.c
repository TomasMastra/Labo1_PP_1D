/*
 * Nexo.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Tomas Mastra
 */

#ifndef NEXO_C_
#define NEXO_C_

#include "Estadia.h"
#include "Perros.h"
#include "Funciones.h"
#include "Nexo.h"

#define EMPTY -1
#define X 15
#define P 10


int inicializar(eEstadia estadia[], ePerro perro[], int len, int flag, int id)
{


	int index;











		index = estadia_buscarLibre(estadia, len);

		if(index != -1)
		{




			 //harcodearPerros(perro, P);

				printf("Cargo correctamente el programa..\n\n");

				flag = 1;


				validarIdPerro(estadia, perro,  len,  index);
				estadia_pedirDatos(estadia,  index,  id);
				//id++;




		}else
		{


			printf("No hay espacio, elimine una estadia\n");
		}











	return flag;
}






void validarIdPerro(eEstadia estadia[], ePerro perro[], int len, int index)
{

	int number;
	int i;



	 perro_listar(perro, P);




	if(index!=EMPTY)
		{
	getInt(&number, "Ingrese una ID de perro: ", "Error, ingrese una ID de perro correcta: ", 7000, 7100);



	for(i=0;i<len;i++)
	{


			if(number == perro[i].id)
			{

					estadia[index].idPerro = number;


				break;
			}
			if(number!= perro[i].id)
			{
				if(i == len -1)
				{

				printf("No cargaste nada, Puedes modificarla despues!!\n");
				estadia[index].idPerro = 0;
				break;
				}


			}
	}
		}else
		if(index==EMPTY)
	{

			printf("\nNo hay espacio!!\n");

	}








}



void modificarEstadia(eEstadia estadia[], ePerro perro[], int len)
{

	int idIngresado;
	int index = EMPTY;







			if(validarIsEmpty(estadia, len) == 1)
			  {

				getInt(&idIngresado, "Ingrese el ID de la estadia para que sea modificada: ", "ERROR, Ingrese el ID de la estadia para que sea modificada: ", 100000, 150000);
				index =  estadia_buscarID(estadia, len, idIngresado);
					if(index!=EMPTY)
					{

						modificarSubMenu(estadia, perro, len, index);

					}else
						{

							printf("No se encontro el id\n");
						}
			}else
			{

				printf("No cargo ninguna estadia ");
			}


}


void modificarSubMenu(eEstadia estadia[], ePerro perro[], int len, int i)
{


	int option;

		getInt(&option, "Ingrese opcion para modificar (1.Telefono de contacto 2.Perro)", "ERROR, Ingrese opcion para modificar (1.Telefono de contacto 2.Perro)", 1,2);


		switch(option)
		{

		case 1:

			getInt(&estadia[i].telefonoContacto, "Ingrese telefono", "ERROR, ingrese telefono", 1000000000,1500000000);


			break;



		case 2:
			 validarIdPerro(estadia, perro,  len,  i);


			break;


		}


}






#endif /* NEXO_C_ */
