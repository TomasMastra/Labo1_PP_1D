/*
 * Nexo.h
 *
 *  Created on: 12 oct. 2021
 *      Author: Tomas Mastra
 */

#ifndef NEXO_H_
#define NEXO_H_

void validarIdPerro(eEstadia estadia[], ePerro perro[], int len, int index);//Valida que el perro exista y no ingrese cualquier numero
int voidValidarPerroTieneEstadia(eEstadia estadia[], ePerro perro[], int len);
int inicializar(eEstadia estadia[], ePerro perro[], int len, int flag, int id);//Inicializa todas las estadias y los perros si el flag es 0, si el flag es 1 solo pide los datos


void modificarEstadia(eEstadia estadia[], ePerro perro[], int len);//Pide la ID para pasarsela a la funcion de buscarID, luego le pasa el index al sub menu
void modificarSubMenu(eEstadia estadia[], ePerro perro[], int len, int i);//El sub menu de la funcion de modificar con un switch que valida que queres modificar

#endif /* NEXO_H_ */

