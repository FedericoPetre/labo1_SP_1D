/*
 * funcion_Menu.c
 *
 *  Created on: 13 nov. 2021
 *      Author: Federico Petre
 */

#include "funcion_Menu.h"

void funcionMenu(void)
{
	setbuf(stdout, NULL);
    int option = 0;

    LinkedList* listaPerritos = ll_newLinkedList();
    int flagCargoDatos = 0;
    int (*funcionQueCompara)(void* this1, void* this2);


    do{
    	funciones_imput_pedirYValidarEntero("Bienvenidx!\nIngrese una opción:\n1-Cargar los datos desde el archivo perrito\n2-Listar los perritos por nombre ascendente\n3-Calcular la cantidad de comida racion para cada perrito\n4-Listar perritos con sus raciones de comida\n5-Generar listado con perritos de raza Galgo, con mas de 10 anios y menos de 200 gramos de comida diaria\n6-Guardar listado de perritos galgo modo texto\n7-Salir","Error, opcion no valida, reingrese opcion:\nIngrese una opción:\n1-Cargar los datos desde el archivo perrito\n2-Listar los perritos por nombre ascendente\n3-Calcular la cantidad de comida racion para cada perrito\n4-Listar perritos con sus raciones de comida\n5-Generar listado con perritos de raza Galgo, con mas de 10 anios y menos de 200 gramos de comida diaria\n6-Guardar listado de perritos galgo modo texto\n7-Salir",1,7,&option);

    	switch(option)
        {
			case 1:
				printf("Elejiste la opcion 1-Cargar los datos desde el archivo perrito\nCargando datos....\n");
				if(controller_loadFromText("perritos.csv", listaPerritos) ==0)
				{
					flagCargoDatos = 1;
				}
				break;
			case 2:
				if(flagCargoDatos == 0)
				{
					printf("Error al listar los perritos por nombre, los datos no fueron cargados\n");
				}
				else
				{
					printf("Elejiste la opcion 2-Elejiste la opcion listar los perritos por nombre ascendente\nListando perritos...\n(Este proceso puede demorar algunos segundos...)\n");
					funcionQueCompara = perrito_comparateByNombre;
					ll_sort(listaPerritos, funcionQueCompara, 0);
					controller_ListPerrito(listaPerritos);
				}

				break;
			case 3:

				break;
			case 4:

				break;
			case 5:

				break;
			case 6:

				break;
			case 7:

				break;
			default:
				printf("Error en el sistema\n\n");
        }

        if(option!=7)
        {
        	system("pause");
        }

    }while(option != 7);

}

