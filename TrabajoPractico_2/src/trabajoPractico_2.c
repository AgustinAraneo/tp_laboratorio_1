/*
 ============================================================================
 Name        : trabajoPractico_2.c
 Author      : Agustín Ezequiel Ramón Araneo
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo practico para la UTN. Este programa tiene el fin de listar, dar de alta, dar de baja, o
 modificar a los pasajeros de una aerolinea.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "Utn.h"
#include <string.h>
#define TAMPASSENGER 2000
#define TAMPASSENGERHARDCODE 5

int main(void)
{
	setbuf(stdout, NULL);
    int opcion;
    int iterador=0;
    int todoFunciona;

    EPassenger pasajeros[TAMPASSENGER];

    initPassenger(pasajeros,TAMPASSENGER);

    hardcodePassenger(pasajeros,TAMPASSENGERHARDCODE);

    int id;
    char name[51];
    char lastName[51];
    float price;
    int typePassenger;
    char flycode[10];
    int statusFlight;
    int iterador2 = 0;
    int subMenuMostrar;

    do
    {
        opcion = getInt("Caso 1: Alta\nCaso 2: Baja\nCaso 3: Modificacion\nCaso 4: Informar\nCaso 5: Cerrar\n:", "ERROR. Ingrese una opcion valida (Solo numeros):");

        switch(opcion)
        {
        case 1:
        	id = autoIncrementalId(pasajeros, TAMPASSENGER);
			getnombre("Ingrese un Nombre:", "Error ingrese un Nombre valido (Solo palabras):", name);
			getnombre("Ingrese el Apellido:","Ingrese un Apellido valido (Solo palabras):", lastName);
			typePassenger = getTypePassenger();
			price = getPrecio();
			getFlycode("Ingrese el Codigo de Vuelo:", "Ingrese nuevamente el Codigo de Vuelo (No puede tener mas 10 digitos):", flycode);
			statusFlight = getStatusFlight();

           todoFunciona = addPassenger(pasajeros, TAMPASSENGER, id, name,lastName,price,typePassenger, flycode, statusFlight);
           if(todoFunciona==1)
           {
               printf("Alta completa\n");
           }else
           {
               printf("\nNo se pudo realizar el alta\n");
           }
            break;

        case 2:
            printPassengers(pasajeros, TAMPASSENGER);
            id = getInt("Ingrese el id del pasajero que desea dar de baja:\n", "ERROR. Ingrese solo numeros");
            todoFunciona = removePassenger(pasajeros,TAMPASSENGER, id);
            if(todoFunciona == 1)
            {
                printf("Se ha dado de baja al pasajero correctamente");
            }else
            {
                printf("No se dio pudo dar de baja al pasajero");
            }
            break;
        case 3:
        todoFunciona=modifyPassenger(pasajeros,TAMPASSENGER);
        if(todoFunciona==1)
        {
            printf("Modifacion exitosa");
        }else
        {
            printf("No se pudo realizar la modificacion");
        }
            break;

        case 4:
        	do
        	{
        		subMenuMostrar = getInt("Case 1: Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero\nCase 2: Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\nCase 3:Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’.\nCase 4: Salir.\n:", "ERROR. Ingrese solo numeros:\n");
        		switch(subMenuMostrar)
        		{
        		case 1:
        			todoFunciona = sortPassengers(pasajeros, TAMPASSENGER, 1);
        			if(todoFunciona	== 1)
        			{
        				printPassengers(pasajeros, TAMPASSENGER);
        			}
        			break;
        		case 2:
        			printTotalAndAveragesPriceFlights(pasajeros, TAMPASSENGER);
        			break;
        		case 3:
          			todoFunciona = sortPassengersByCode(pasajeros, TAMPASSENGER, 1);
            			if(todoFunciona	== 1)
            			{
            				printPassengers(pasajeros, TAMPASSENGER);
            			}
        			break;
        		case 4:
        			iterador2=1;
        			break;
        		}

        		system("pause");
        	}while(iterador2 == 0);
            break;

        default:
            iterador=1;
            break;
        }
    system("pause");
    }
    while(iterador==0);
    return 0;
}
