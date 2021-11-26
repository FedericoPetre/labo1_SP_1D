/*
 * perrito.h
 *
 *  Created on: 25 nov. 2021
 *      Author: Federico Petre
 */

#ifndef PERRITO_H_
#define PERRITO_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funciones_imput.h"

typedef struct{
	int id;
	char nombre[21];
	float peso;
	int edad;
	char raza[21];
} perrito;

perrito* nuevo_perrito();
perrito* perrito_nuevoParametros(char* id,char* nombre,char* peso,char* edad, char* raza);
void perrito_eliminarPerrito(perrito* this);

int perrito_setId(perrito* this,int id);
int perrito_getId(perrito* this,int* id);

int perrito_setNombre(perrito* this,char* nombre);
int perrito_getNombre(perrito* this,char* nombre);

int perrito_setEdad(perrito* this,int edad);
int perrito_getEdad(perrito* this,int* edad);

int perrito_setRaza(perrito* this,char* raza);
int perrito_getRaza(perrito* this,char* raza);

int perrito_setPeso(perrito* this, float peso);
int perrito_getPeso(perrito* this, float* peso);

int perrito_mostrarPerrito(perrito* this);

int perrito_comparateByID(void* this1, void* this2);
int perrito_comparateByNombre(void* this1, void* this2);
int perrito_comparateByEdad(void* this1, void* this2);
int perrito_comparateByRaza(void* this1, void* this2);





#endif /* PERRITO_H_ */
