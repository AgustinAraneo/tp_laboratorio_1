/*
 * ArrayPassenger.c
 *
 *  Created on: 14 may. 2022
 *      Author: Agus
 */

#include "ArrayPassenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1
#define ACTIVO 2
#define INACTIVO 1
#define CANCELADO 0
#define PRIMERACLASE 3
#define BUSINESS 2
#define TURISTA 1



void initPassenger(EPassenger pasajeros[], int tamanio)
{
    for(int i=0; i<tamanio; i++)
    {
            pasajeros[i].isEmpty=LIBRE;
    }
}

int addPassenger(EPassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[],int statusFlight)
{
    int retorno=0;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==LIBRE)
        {
        	list[i].id=id;
        	strcpy(list[i].name,name);
        	strcpy(list[i].lastname,lastName);
        	list[i].price=price;
        	list[i].typePassenger=typePassenger;
        	strcpy(list[i].flycode,flycode);
        	list[i].statusFlight=statusFlight;
            list[i].isEmpty=OCUPADO;
            retorno=1;
            break;
        }
    }
    return retorno;
}

int modifyPassenger(EPassenger pasajeros[],int tamanio)
{
    int auxPosicion;
    int auxId;
    int iteracion=0;
    int opciones;
    int retorno=0;

    printf("Ingrese el id del pasajero que quiera modificar:\n");
    printPassengers(pasajeros, tamanio);
    scanf("%d",&auxId);

    auxPosicion=findPassengerById(auxId,pasajeros,tamanio);

    if(auxPosicion==-1)
    {
        printf("\nNo se encontro ningun pasajero con ese id");
    }
    else
    {
        do
        {
            printf("Caso 1:Nombre\n");
            printf("Caso 2:Apellido\n");
            printf("Caso 3:Precio\n");
            printf("Caso 4:Codigo de Vuelo\n");
            printf("Caso 5:Tipo de Pasajero\n");
            printf("Caso 6:Estado del Vuelo\n");
            printf("Caso 7:Salir\n");
            scanf("%d",&opciones);
            switch(opciones)
            {
            case 1:
                printf("Ingrese el nuevo Nombre:\n");
                fflush(stdin);
                gets(pasajeros[auxPosicion].name);
                fflush(stdin);
                break;
            case 2:
                printf("Ingrese el nuevo Apellido:\n");
                fflush(stdin);
                gets(pasajeros[auxPosicion].lastname);
                fflush(stdin);
                break;
            case 3:
                printf("Ingrese el nuevo Precio $:\n");
                scanf("%f",&pasajeros[auxPosicion].price);
                break;
            case 4:
                printf("Ingrese el Codigo del Vuelo(Maximo 10 digitos):\n");
                fflush(stdin);
                gets(pasajeros[auxPosicion].flycode);
                fflush(stdin);
                break;
            case 5:
                printf("Ingrese el Tipo de Pasajero: (3 = Primera Clase)(2 = Business)(1 = Turista)\n");
                scanf("%d",&pasajeros[auxPosicion].typePassenger);
                break;
            case 6:
                printf("Ingrese el Estado del Vuelo (2 = ACTIVO)(1 = INACTIVO)(0 = CANCELADO):\n");
                scanf("%d",&pasajeros[auxPosicion].statusFlight);
                break;
            case 7:
                iteracion=1;
                break;
            }
            system("pause");
            system("cls");
        }
        while(iteracion==0);
        retorno =1;
    }

    return retorno;
}
int autoIncrementalId(EPassenger pasajeros[], int tamanio)
{
    int idx =1;
    for(int i =0;i<tamanio;i++)
    {
        if(idx==pasajeros[i].id && pasajeros[i].isEmpty==OCUPADO)
        {
            idx++;
        }
    }
    return idx;
}

int findPassengerById(int id, EPassenger pasajeros[], int tamanio)
{
    int retorno=-1;
    for(int i=0; i<tamanio; i++)
    {
        if(id == pasajeros[i].id && pasajeros[i].isEmpty==OCUPADO)
        {
            retorno=i;
        }
    }
    return retorno;
}

int removePassenger(EPassenger *pasajeros,int tamanio, int id)
{
    int auxPosicion;
    int retorno = 0;
    char confirmar;

    auxPosicion=findPassengerById(id,pasajeros,tamanio);

    if(auxPosicion==-1)
    {
        printf("\nNo se encontro ningun pasajero con ese id");
    }
    else
    {
        fflush(stdin);
        printf("\n¿Esta seguro que desea elminiar al pasajero(s/n)?\n");
        scanf("%c",&confirmar);
        fflush(stdin);

        if(confirmar=='s')
        {
            pasajeros[auxPosicion].isEmpty=LIBRE;
            retorno = 1;
        }

    }

    return retorno;
}

void printPassengers(EPassenger *pasajeros, int tamanio)
{
    printf("%s %10s %10s %7s %16s %3s %3s\n\n", "ID", "Nombre", "Apellido", "Precio", "Codigo de Vuelo","Tipo de Pasajero", "Estado del Vuelo");

    for(int i =0; i<tamanio; i++)
    {
        if(pasajeros[i].isEmpty==OCUPADO)
        {
        	printf("%d %10s %10s %6.2f %15s %7d %12d\n", pasajeros[i].id, pasajeros[i].name, pasajeros[i].lastname, pasajeros[i].price, pasajeros[i].flycode,pasajeros[i].typePassenger, pasajeros[i].statusFlight);
        }
    }
}

void hardcodePassenger(EPassenger pasajeros[], int tamanio)
{
    int auxID[]={1,2,3,4,5};
    char auxName[][51]={{"Agustin"},{"Luciano"},{"Matias"},{"Javier"},{"Melina"}};
    char auxLastname[][51]={{"Araneo"},{"Kaffler"},{"Shofer"},{"Braaunx"},{"Zalamanca"}};
    float auxPrice[]={34600,22000.21,56711.87,2960,15789};
    char auxFlycode[][10]={{"324567845"},{"34252"},{"567565"},{"67986778"},{"134"}};


    for(int i=0;i<tamanio;i++)
    {
        pasajeros[i].id=auxID[i];

        strcpy(pasajeros[i].name,auxName[i]);
        strcpy(pasajeros[i].lastname,auxLastname[i]);
        strcpy(pasajeros[i].flycode,auxFlycode[i]);

        pasajeros[i].price=auxPrice[i];
        pasajeros[i].isEmpty=OCUPADO;
        pasajeros[i].statusFlight=ACTIVO;
        pasajeros[i].typePassenger=TURISTA;
    }
}

int sortPassengers(EPassenger* list, int len, int order)
{
	int retorno = -1;
	EPassenger auxPassenger;
	if(order == 1){
	  for(int i=0; i<len-1; i++){
	        {
	            for(int j=i+1; j<len; j++)
	            {
	            	if(strcmp(list[i].lastname,list[j].lastname)>0)
	            	{
	            		 auxPassenger=list[i];
	            		 list[i]= list[j];
	            		 list[j]=auxPassenger;
	            	}else if((strcmp(list[i].lastname, list[j].lastname)==0)&& list[i].typePassenger > list[j].typePassenger)
	            	{
	            		auxPassenger=list[i];
	            		list[i]= list[j];
	            		list[j]=auxPassenger;
	            		retorno = 1;
	            	}
	            	}
	            }
	            }
	}else
	{
		for(int i=0; i<len-1; i++){
			        {
			            for(int j=i+1; j<len; j++)
			            {
			            	if(strcmp(list[i].lastname,list[j].lastname)<0)
			            	{
			            		 auxPassenger=list[i];
			            		 list[i]= list[j];
			            		 list[j]=auxPassenger;
			            	}else if((strcmp(list[i].lastname, list[j].lastname)==0)&& list[i].typePassenger < list[j].typePassenger)
			            	{
			            		auxPassenger=list[i];
			            		list[i]= list[j];
			            		list[j]=auxPassenger;
			            		retorno = 1;
			            	}
			            	}
			            }
			            }
	}
	return retorno;
}

int sortPassengersByCode(EPassenger* list, int len, int order)
{
	int retorno = -1;
	EPassenger auxPassenger;
		if(order == 1){
		  for(int i=0; i<len-1; i++){
		        {
		            for(int j=i+1; j<len; j++)
		            {
		            	if(strcmp(list[i].flycode,list[j].flycode)>0)
		            	{
		            		 auxPassenger=list[i];
		            		 list[i]= list[j];
		            		 list[j]=auxPassenger;
		            	}else if((strcmp(list[i].flycode, list[j].flycode)==0)&& list[i].statusFlight > list[j].statusFlight)
		            	{
		            		auxPassenger=list[i];
		            		list[i]= list[j];
		            		list[j]=auxPassenger;
		            		retorno = 1;
		            	}
		            	}
		            }
		            }
		}else
		{
			for(int i=0; i<len-1; i++){
				        {
				            for(int j=i+1; j<len; j++)
				            {
				            	if(strcmp(list[i].flycode,list[j].flycode)<0)
				            	{
				            		 auxPassenger=list[i];
				            		 list[i]= list[j];
				            		 list[j]=auxPassenger;
				            	}else if((strcmp(list[i].flycode, list[j].flycode)==0)&& list[i].statusFlight < list[j].statusFlight)
				            	{
				            		auxPassenger=list[i];
				            		list[i]= list[j];
				            		list[j]=auxPassenger;
				            		retorno = 1;
				            	}
				            	}
				            }
				            }
		}
		return retorno;
}


void printTotalAndAveragesPriceFlights(EPassenger* list, int len)
{
	float totalPrice;
	float averagePrice;
	int contador = 0;

	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			totalPrice += list[i].price;
			contador ++;
		}
	}
	averagePrice = totalPrice / contador;
	printf("El total de los precios es: $%f", totalPrice);
	printf("\nEl promedio de los precios es: $%f", averagePrice);
	printf("\n");
	printf("-----------------------------------------------------");
	printf("\n");

	for(int i = 0; i < len; i++)
	{
		if(list[i].price == averagePrice && list[i].isEmpty == OCUPADO)
		{
			printPassengers(list, len);
		}
	}
}





