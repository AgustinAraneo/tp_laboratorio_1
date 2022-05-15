/*
 * Utn.c
 *
 *  Created on: 14 may. 2022
 *      Author: Agus
 */

#include "Utn.h"
#include <ctype.h>
#include <conio.h>
#include<string.h>

int getInt(char mensaje[], char mensajeError[])
{
    char auxiliarChar[20];
    int enteroADevolver;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", auxiliarChar);
    enteroADevolver = atoi(auxiliarChar);

    while(getInti(auxiliarChar)!=1)
    {
        printf("%s", mensajeError);
        fflush(stdin);
        scanf("%s", auxiliarChar);
        enteroADevolver = atoi(auxiliarChar);
    }


    return enteroADevolver;
}
			int getInti(char str[])
			{
			    int retorno = 1;
			    for(int i =0; str[i]!='\0'; i++)
			    {
			        if(str[i]<'0' || str[i]>'9')
			        {
			            retorno = 0;
			            break;
			        }
			    }
			    return retorno;
			}

			void getnombre(char mensaje[],char mensajeError[], char input[])
			{
			    printf("%s", mensaje);
			    fflush(stdin);
			    gets(input);

			    strlwr(input);
			    input[0] = toupper(input[0]);
			    while(nombresValidos(input)!= 1)
			    {
			        printf("%s", mensajeError);
			        fflush(stdin);
			        gets(input);
			        input[0] = toupper(input[0]);
			    }

			}

			int nombresValidos(char str[])
			{
			    int retorno = 1;
			    for(int i=0; str[i]!='\0'; i++)
			    {
			        if(str[i]<'A' || (str[i]>'Z' && str[i]<'a') || str[i]>'z')
			        {
			            retorno=0;
			            break;
			        }
			    }
			    return retorno;
			}


			float getFloat(char mensaje[], char mensajeError[])
			{
			    char auxiliarChar[10];
			    float floatADevolver;

			    printf("%s", mensaje);
			    scanf("%s", auxiliarChar);
			    fflush(stdin);
			    floatADevolver = atof(auxiliarChar);

			    while(floatADevolver == 0)
			    {
			        printf("%s", mensajeError);
			        scanf("%s", auxiliarChar);
			        fflush(stdin);
			        floatADevolver = atof(auxiliarChar);
			    }


			    return floatADevolver;

			}

		float getPrecio()
		{
			float auxFloatPrecio = getFloat("Ingrese el precio $:", "Error ingrese correctamente el precio (Solo numeros)$:");

			while(auxFloatPrecio < 1000 || auxFloatPrecio > 550000)
			{
				auxFloatPrecio = getFloat("\nError ingrese un valor mayor a $1000 y menor a $550000:", "Error ingrese correctamente el precio (Solo numeros)$:");
			}
		return auxFloatPrecio;
		}

	void getFlycode(char mensaje[], char mensajeError[],char input[])
	{
		printf("%s", mensaje);
		scanf("%s", input);

		int auxCode;
		auxCode = strlen(input);

		while(auxCode < 0 || auxCode > 10)
		{
			printf("%s", mensajeError);
			scanf("%s", input);
		}
	}

	int getStatusFlight()
	{
		int auxStatusFlight = getInt("Ingrese el Estatus de Vuelo (2 = ACTIVO)(1 = INACTIVO)(0 = CANCELADO):", "Ingrese solo numeros:");

		while(auxStatusFlight < 0  || auxStatusFlight > 2)
		{
			auxStatusFlight = getInt("\nERROR. Reingrese el Estatus de Vuelo (2 = ACTIVO)(1 = INACTIVO)(0 = CANCELADO):", "Ingrese solo numeros:");
		}
	return auxStatusFlight;
	}

	int getTypePassenger()
		{
			int auxTypePassenger = getInt("Ingrese su tipo de Vuelo (3 = Primera Clase)(2 = Business)(1 = Turista):", "Ingrese solo numeros:");

			while(auxTypePassenger < 1  || auxTypePassenger > 3)
			{
				auxTypePassenger = getInt("\nERROR. Reingrese su tipo de Vuelo (3 = Primera Clase)(2 = Business)(1 = Turista):", "Ingrese solo numeros:");
			}
		return auxTypePassenger;
		}








