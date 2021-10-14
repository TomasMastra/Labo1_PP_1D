/*
 * Nexo.h
 *
 *  Created on: 12 oct. 2021
 *      Author: Tomas Mastra
 */

#ifndef NEXO_H_
#define NEXO_H_

void validarIdPerro(eEstadia estadia[], ePerro perro[], int len, int index);

int inicializar(eEstadia estadia[], ePerro perro[], int len, int flag);


void modificarEstadia(eEstadia estadia[], ePerro perro[], int len);


void modificarSubMenu(eEstadia estadia[], ePerro perro[], int len, int i);

#endif /* NEXO_H_ */
