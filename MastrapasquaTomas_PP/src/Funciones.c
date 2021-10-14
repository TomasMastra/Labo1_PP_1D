/*
 * Funciones.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Tomas Mastra
 */

#include <stdio.h>   //MASTRAPASQUA TOMAS D
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define OCCUPED 1
#define EMPTY -1

#include "Estadia.h"
#include "Perros.h"
#include "Funciones.h"
#include "Nexo.h"




int validateLetters(char *string)
{

	//int i;
	int ret = -1;
	int len;
	char validateCaps[256];

	len = strlen(string);

	//tolower(string);


	for(int i=0;i<len;i++)
	{

		validateCaps[i] = tolower(string[i]);

		if(validateCaps[i] < 97 || validateCaps[i] > 122)
		{
			ret = 0;

		}

	}





	return ret;

}


int getInt(int* integer, char* message, char* messageError, int min, int max)
{
	int ret = -1;
	int number;

	if(integer != NULL && message != NULL && messageError != NULL && min < max)
	{
		printf("%s", message);
		fflush(stdin);
		scanf("%d", &number);

		while(number < min || number > max)
		{
			printf("%s", messageError);
			fflush(stdin);
			scanf("%d", &number);
		}

		*integer = number;
		ret = 0;
	}

	return ret;
}

int getFloat(float* floating, char* message, char* messageError, float min, float max)
{

	int ret = -1;
	float number;

		if(floating != NULL && message != NULL && messageError != NULL && min < max)
		{
			printf("%s", message);
			fflush(stdin);
			scanf("%f", &number);

			while(number < min || number > max)
			{
				printf("%s", messageError);
				fflush(stdin);
				scanf("%f", &number);
			}

			*floating = number;
			ret = 0;
		}

		return ret;

}

int getString(char* string, char* message, char* messageError, int max)
{
	int ret = -1;
	char buffer[256];
	int len;

	int i;

	if(string != NULL && message != NULL && messageError != NULL && max > 0)
	{
		printf("%s", message);
		fflush(stdin);
		scanf("%[^\n]", buffer);
		len = strlen(buffer);



		for(i=0;i<len;i++)
		{



			while(len>max || validateLetters(buffer)==0)
			{



						{
							printf("%s", messageError);
							fflush(stdin);
							scanf("%[^\n]", buffer);
							len = strlen(buffer);

						}

			}
		}

		 PonerMayusculas(buffer);

		strcpy(string, buffer);



		ret = 0;
	}

	while(len>max)
	{

	}

	return ret;
}

int getChar(char* character, char* message)
{
	int ret = -1;

	if(character != NULL && message != NULL)
	{
		printf("%s", message);
		fflush(stdin);
		//__fpurge(stdin);

		*character = getchar();
		ret = 0;
	}

	return ret;
}

int PonerMayusculas(char* string)
{

	int ret = -1;
	int i;
	char buffer[21];

	strcpy(buffer, string);


	for(i=0; buffer[i]!='\0' ; i++)
{
   // if(buffer[i-1]==' ')
  //  {

  //  }
   // else
   // {
        buffer[i] = tolower(buffer[i]);
   // }
}
	buffer[0] = toupper(buffer[0]);

	strcpy(string, buffer);






	return ret;
}
