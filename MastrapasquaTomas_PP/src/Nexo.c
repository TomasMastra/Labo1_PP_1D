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
#define X 5


int inicializar(eEstadia estadia[], ePerro perro[], int len, int flag)
{


	int index;
	int id = 0;;




	if(flag ==0)
	{
		estadia_inicializar(estadia, len);
		harcodearPerros(perro,  len);

		index = estadia_buscarLibre(estadia, len);

		if(index != -1)
		{


				id = 100000;


				printf("Cargo correctamente el programa...\n\n");

				flag = 1;


				validarIdPerro(estadia, perro,  len,  index);
				estadia_pedirDatos(estadia,  index,  id);




		}else
		{


			printf("No hay espacio, elimine una estadia\n");
		}
	}else
		if(flag==1)
	{

		index = estadia_buscarLibre(estadia, len);



		id = 100000 + index;

		validarIdPerro(estadia, perro,  len,  index);
		estadia_pedirDatos(estadia,  index,  id);


	}










	return flag;
}






void validarIdPerro(eEstadia estadia[], ePerro perro[], int len, int index)
{

	int number;
	int i;





	getInt(&number, "Ingrese una ID de perro", "Error, ingrese una ID de perro correcta", 7000, 7100);


	printf("len vale %d\n", len);
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




			//estadia[index].idPerro = number;
			estadia[index].idPerro = number;








	}







}



void modificarEstadia(eEstadia estadia[], ePerro perro[], int len)
{

	int idIngresado;
	int index = EMPTY;

	int ret = -1;


	 	 //ret = validarIsEmpty(estadia, len);


			//index =  estadia_buscarID(estadia, len, idIngresado);


			if(validarIsEmpty(estadia, len) == 1)
			  {

				getInt(&idIngresado, "Ingrese el ID de la estadia para que sea modificada (1.Telefono 2.IdPerro): ", "ERROR, Ingrese el ID de la estadia para que sea modificada (1.telefono 2.IdPerro): ", 1, 2);
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
