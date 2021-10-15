/*
 * Nexo.h
 *
 *  Created on: 12 oct. 2021
 *      Author: Tomas Mastra
 */


#ifndef NEXO_H_
#define NEXO_H_

void validarIdPerro(eEstadia estadia[], ePerro perro[], int len, int index,int id);//Valida que el perro exista y no ingrese cualquier numero
void validarIdDuenio(eEstadia estadia[], eDuenio duenio[], int lenDuenio, int index);
int voidValidarPerroTieneEstadia(eEstadia estadia[], ePerro perro[], int len);
int inicializar(eEstadia estadia[], ePerro perro[],eDuenio duenio[],  int len, int flag, int id, int lenDuenio, int idDuenio, int lenPerro);//Inicializa todas las estadias y los perros si el flag es 0, si el flag es 1 solo pide los datos

int buscarEstadia(eEstadia estadia[], ePerro perro[], int len, int lenPerro);

void modificarEstadia(eEstadia estadia[], ePerro perro[], eDuenio duenio[],  int len,  int lenPerro, int lenDuenio);//Pide la ID para pasarsela a la funcion de buscarID, luego le pasa el index al sub menu
void modificarSubMenu(eEstadia estadia[], ePerro perro[], eDuenio duenio[], int len, int option, int lenPerro, int lenDuenio, int id);//El sub menu de la funcion de modificar con un switch que valida que queres modificar

void modificarIdPerro(eEstadia estadia[], ePerro perro[], int lenPerro, int index, int id);

int buscarMasEstadias(eEstadia estadia[], ePerro perro[], int lenPerro);
void mostrarMasEstadias(ePerro perro[], int lenPerro, int masEstadias);

void mostrarPerrosConEstadias(ePerro perro[], eEstadia estadia[], int lenPerro, int len);





#endif /* NEXO_H_ */

