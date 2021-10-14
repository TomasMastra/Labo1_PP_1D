/*
 ============================================================================
 Name        : MastrapasquaTomas_PP.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#include "Estadia.h"
#include "Perros.h"
#include "Funciones.h"
#include "Nexo.h"



#define X 5
#define P 3

int main(void) {

	setbuf(stdout, NULL);


	 int flag = 0;
	 int option;
	 int len = X;
	 int lenPerro = P;

	 eEstadia estadia[X];
	 ePerro perro[X];

	 int id = 100000;







		 do{
			 getInt(&option, "-------------------------------------\n"
		 							 "1. ALTA estadia\n"
		 							 "2. BAJA estadia\n"
		 							 "3. MODIFICACION estadia\n"
		 							 "4. LISTADO ordenado por fecha\n"
		 							 "5. LISTADO perros\n"
		 							 "6. PROMEDIO edad perros\n"
		 							 "10. SALIR\n"
		 							 "-------------------------------------\n",
		 							 "Ingrese una opcion: "
		 							 "-------------------------------------\n"
		 							 "1. ALTA estadia\n"
		 							 "2. BAJA estadia\n"
		 							 "3. MODIFICACION estadia\n"
		 							 "4. LISTADO ordenado por fecha\n"
		 							 "5. LISTADO perros\n"
		 							 "6. PROMEDIO edad perros\n"
		 							 "10. SALIR\n"
		 							 "-------------------------------------\n"
		 							 "Opcion invalida, reingrese: ", 1, 10);

		 		switch(option)
		 		{
		 			case 1:



		 					 flag = inicializar(estadia, perro, len, flag, id);

		 					 id++;
		 					//flag = 1;



		 				break;



		 			case 2:

		 				if(flag ==1)
		 				{

		 				 estadia_cancelar(estadia, len);
		 				}else
		 				{

				 			printf("Ingrese una estadia\n");

		 				}








					break;

		 			case 3:


		 				if(flag == 1)
		 				{
		 					 modificarEstadia(estadia, perro, len);
		 				}else
		 				{

				 			printf("Ingrese una estadia\n");


		 				}





		 				break;


		 			case 4:

		 					if(flag == 1)
		 					{
		 					estadia_ordenar(estadia,  len);
		 					}else
		 					{

					 			printf("Ingrese una estadia\n");


		 					}



		 				break;


		 		case 5:

		 			if(flag == 1)
		 			{
		 			harcodearPerros(perro,  len);
		 			 perro_listar(perro, lenPerro);
		 			}else
		 			{

			 			printf("Ingrese una estadia\n");


		 			}








		 			break;


		 		case 6:

		 			if(flag == 1)
		 			{
		 				harcodearPerros(perro,  len);
		 				perro_calcularPromedioEdad(perro, lenPerro);
		 			}else
		 			{

			 			printf("Ingrese una estadia\n");

		 			}



		 			break;



		 		}





		 	}while(option !=10);

	return EXIT_SUCCESS;
}
