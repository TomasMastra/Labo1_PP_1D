/*
 * Nexo.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Tomas Mastra
 */

#ifndef NEXO_C_
#define NEXO_C_

#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Estadia.h"
#include "Perros.h"
#include "Funciones.h"
#include "duenio.h"
#include "Nexo.h"

#include "Nexo.h"

#define EMPTY -1
#define X 15
#define P 10


int inicializar(eEstadia estadia[], ePerro perro[], eDuenio duenio[], int len, int flag, int id, int lenDuenio, int idDuenio, int lenPerro)
{


	int index;











		index = estadia_buscarLibre(estadia, len);

		if(index != -1)
		{






				printf("Cargo correctamente el programa..\n\n");

				flag = 1;


				validarIdPerro(estadia, perro,  lenPerro,  index, id);

				 validarIdDuenio(estadia, duenio, lenDuenio, index);

				estadia_pedirDatos(estadia,  index,  id);
				//id++;




		}else
		{


			printf("No hay espacio, elimine una estadia\n");
		}











	return flag;
}






void validarIdPerro(eEstadia estadia[], ePerro perro[], int len, int index, int id)
{

	int number;
	int i;
	len = X;



	 perro_listar(perro, P);




	if(index!=EMPTY)
		{
	getInt(&number, "Ingrese una ID de perro: ", "Error, ingrese una ID de perro correcta: ", 7000, 7100);



	for(i=0;i<len;i++)
	{


			if(number == perro[i].id)
			{

					estadia[index].idPerro = number;
					perro[i].estadia = id;
					perro[i].cantidadEstadias++;
					//printf("%d\n", perro[i].estadia);


				break;
			}
			if(number!= perro[i].id)
			{
				if(i == len -1)
				{

				printf("No cargaste nada, Puedes modificarla despues!!\n");


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

void mostrarPerrosConEstadias(ePerro perro[], eEstadia estadia[], int lenPerro, int len)
{

	int i;

	printf("Listado de perros con sus estadias:\n\n"
					   "%-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Raza", "estadia", "Estadia");

	for(i=0;i<lenPerro;i++)
	{


		if(estadia[i].isEmpty == 1 && perro[i].estadia >99999)
		{

			printf("%-5d %-20s %-20s %-20d %-20d %-20d\n", perro[i].id, perro[i].nombre, perro[i].raza, perro[i].edad, perro[i].estadia, perro[i].isEmpty);


		}

	}


}

void modificarEstadia(eEstadia estadia[], ePerro perro[], eDuenio duenio[], int len, int lenPerro, int lenDuenio)
{

	/*int idIngresado;
	int index = EMPTY;*/
	int option = 0;







			if(validarIsEmpty(estadia, len) == 1)
			  {


						modificarSubMenu(estadia, perro, duenio, len, option, lenPerro, lenDuenio, P);


			}else
			{

				printf("No cargo ninguna estadia ");
			}


}


void modificarSubMenu(eEstadia estadia[], ePerro perro[], eDuenio duenio[],  int len, int option, int lenPerro, int lenDuenio, int id)
{

	/////////

	int i = 0;


	getInt(&option, "Ingrese la opcion a modificar (1.duenio 2.perro): ", "ERROR, Ingrese la opcion para modificar (1.duenio 2.perro): ", 1, 2);


		switch(option)
		{

		case 1:

			 getInt(&id, "Ingrese el id del duenio modificar el telefono :\n","Error, ingrese el id del duenio para modificar el telefono:\n", 30000, 31000);
			 modificarDuenio(duenio,  lenDuenio, id);



			break;



		case 2:

			 getInt(&id, "Ingrese el id de la estadia para modificar el perro asociado:\n","Error, ingrese el id de la estadia para modificar el perro asociado:\n", 100000, 110000);


			modificarIdPerro(estadia,  perro, lenPerro,  i, id);



			break;


		}


}

void modificarIdPerro(eEstadia estadia[], ePerro perro[], int lenPerro, int index, int id)
{



	index = estadia_buscarID( estadia,  lenPerro,  id);//Esta funcion busca un ID

	//index =  perro_buscarID(perro, lenPerro, id);



	printf("%d\n", index);




		if(index >-1)
		{

			 validarIdPerro( estadia,  perro,  lenPerro, index, id);//Valida que el perro exista y no ingrese cualquier numero



		}


}

int buscarMasEstadias(eEstadia estadia[], ePerro perro[], int lenPerro)
{

	int i;
	int cantidadEstadias[P];
	int masEstadias = 0;
	int flagEstadias = 0;
	int perroMasEstadias;



	for(i=0;i<lenPerro;i++)
		{


			if(flagEstadias ==0)
			{
				if(perro[i].isEmpty == 1)
				{
					printf("sa");

					masEstadias = perro[i].cantidadEstadias;
					flagEstadias = 1;
				}


				}else
				if(perro[i].cantidadEstadias > masEstadias)
				{

					if(perro[i].isEmpty == 1)
					{

					printf("asa");
					masEstadias = perro[i].cantidadEstadias;
					}



				}
		}









	printf("%d\n", masEstadias);

	 mostrarMasEstadias(perro, lenPerro, masEstadias);


	return perroMasEstadias;


}

void mostrarMasEstadias(ePerro perro[], int lenPerro, int masEstadias)
{



	int i;

	printf("Listado de perros con mas estadias:\n\n"
					   "%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Raza", "Edad");

	for(i=0;i<lenPerro;i++)
	{
		if(perro[i].cantidadEstadias == masEstadias && perro[i].isEmpty == 1)
		{


			 perro_listarUno(perro[i]);




		}


	}





}

void validarIdDuenio(eEstadia estadia[], eDuenio duenio[], int lenDuenio, int index)
{


	int number;
		int i;
		lenDuenio = 15;



		 //perro_listar(perro, P);




		if(index!=EMPTY)
			{
		getInt(&number, "Ingrese una ID de duenio: ", "Error, ingrese una ID de perro correcta: ", 30000, 31000);



		for(i=0;i<lenDuenio;i++)
		{


				if(number == duenio[i].id)
				{

						estadia[index].idDuenio = number;


					break;
				}
				if(number!= duenio[i].id)
				{
					if(i == lenDuenio -1)
					{

					printf("No cargaste nada, Puedes modificarla despues!!\n");
					estadia[index].idDuenio = 0;
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








#endif /* NEXO_C_ */
