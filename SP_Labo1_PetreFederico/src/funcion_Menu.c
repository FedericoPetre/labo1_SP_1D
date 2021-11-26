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
    int (*punteroAFuncion)(void* this1, void* this2);
    int (*pFunc)(void* this);
    int flagCalculoRaciones = 0;
    LinkedList* listaFiltro;
    int banderaPasoFiltro = 0;


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
					punteroAFuncion = perrito_comparateByNombre;
					ll_sort(listaPerritos, punteroAFuncion, 0);
					controller_ListPerrito(listaPerritos);
				}

				break;
			case 3:
				if(flagCargoDatos == 0)
				{
					printf("Error al elegir calcular racion comida de los perritos...Los datos de los perritos no fueron cargados\n");
				}
				else
				{
					printf("Elejiste la opcion 3-Calcular la racion comida para cada perrito\nCalculando raciones (puede demorar algunos segundos)...\n");
					pFunc = perrito_laQueMapea;
					ll_map(listaPerritos, pFunc);
					printf("Se han calculado las raciones de comida para cada perrito\n");
					flagCalculoRaciones = 1;
				}
				break;
			case 4:
				if(flagCalculoRaciones == 0)
				{
					printf("Error al mostrar listado de perritos con raciones de comida, las raciones no fueron calculadas\n");
				}
				else
				{
					printf("Mostrando perritos con raciones de comida...\n");
					controller_listarPerritosConRacion(listaPerritos);
				}

				break;
			case 5:
				if(flagCalculoRaciones == 0)
				{
					printf("Error al generar el listado. No se calcularon las raciones de comida para cada perrito\n");
				}
				else
				{
					pFunc = perrito_laQueFiltra;
					listaFiltro = ll_filter(listaPerritos, pFunc);
					printf("Se ha generado el listado de galgo con mas de 10 años y menos de 200 gramos de comida\n");
					banderaPasoFiltro = 1;
				}

				break;
			case 6:
				if(banderaPasoFiltro == 0)
				{
					printf("Error al guardar modo texto, no se genero el listado con perritos raza 'GALGO', con mas de 10 años y menos de 200 gramos de racion\n");
				}
				else
				{
					controller_saveAsText("galgosFlaquitos.csv", listaFiltro);
				}
				break;
			case 7:
				printf("Has elejido la opcion 7-Salir\nSaliendo del sistema....\nHas salido del sistema\n");
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

