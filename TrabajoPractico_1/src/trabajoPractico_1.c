/*
 ============================================================================
 Name        : trabajoPractico_1.c
 Author      : Agustín Ezequiel Ramón Araneo
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo practico para la UTN. Este programa tiene el fin de calcular los precios y
 kilometros para unas aerolineas.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "utnBiblioteca.h"
#define PRECIOBITCOIN 4606954.55
#define AEROLINEASPRECIO 162965.00
#define LATAMPRECIO 159339.00
#define KILOMETROS 7090

int main(void) {
	setbuf(stdout, NULL);

	int retorno;
	int opcionMenu;
	int kmTotales;
	float precioAerolineas;
	float precioLatam;
	int validacionRetorno;
	float debitoAerolineas;
	float debitoLatam;
	float creditoAerolineas;
	float creditoLatam;
	float bitcoinAerolineas;
	float bitcoinLatam;
	float unitarioAerolineas;
	float unitarioLatam;
	float debitoAerolineasAux;
	float debitoLatamAux;
	float creditoAerolineasAux;
	float creditoLatamAux;
	float bitcoinAerolineasAux;
	float bitcoinLatamAux;
	float unitarioAerolineasAux;
	float unitarioLatamAux;
	float diferenciaPrecios;
	float diferenciaPreciosAux;

	retorno = -1;
	kmTotales = 0;
	precioAerolineas = 0;
	precioLatam = 0;

	do {
		printf("1) Ingresar Kilometros (%d):\n", kmTotales);
		printf("2) Ingresar precios de vuelos: (Latam: $%2.f)(Aerolineas: $%2.f)\n",precioLatam, precioAerolineas);
		printf("3) Calcular todos los costos:\n");
		printf("4) Informar resultados:\n");
		printf("5) Carga forzada de datos:\n");
		printf("6) Salir\n");

		validacionRetorno = getInt(&opcionMenu, "Ingrese una opción:",
				"Error. Ingresaste una opción inválida", 1, 6);

		if (validacionRetorno == 0) {
			switch (opcionMenu) {
			case 1:
				validacionRetorno = getInt(&kmTotales, "Ingrese los km:",
						"Error. Ingresaste kms inválidos", 1, 15000);
				if (validacionRetorno == 0) {
					printf("Los km se cargaron\n");
				} else {
					printf("Error función getInt");
				}
				system("pause");
				break;
			case 2:
				do {
					printf("1) Precio vuelo Aerolineas:\n");
					printf("2) Precio vuelo Latam:\n");
					printf("3) Volver al menu:\n");

					validacionRetorno = getInt(&opcionMenu,
							"Ingrese una opción:",
							"Error. Ingresaste una opción inválida", 1, 3);
					if (validacionRetorno == 0) {
						switch (opcionMenu) {
						case 1:
							validacionRetorno = getFloat(&precioAerolineas,
									"Ingrese el precio de Aerolineas:",
									"Error. Ingresaste un precio inválido",
									0.01, 2147483647);
							if (validacionRetorno == 0) {
								printf("El precio ingresado se cargó\n");
							} else {
								printf("Error función getFloat\n");
							}

							system("pause");
							break;
						case 2:
							validacionRetorno = getFloat(&precioLatam,
									"Ingrese el precio de Latam:",
									"Error. Ingresaste un precio inválido",
									0.01, 2147483647);
							if (validacionRetorno == 0) {
								printf("El precio ingresado se cargó\n");
							} else {
								printf("Error función getFloat\n");
							}
							system("pause");
							break;
						case 3:
							printf("Volvio al Menu\n");
							system("pause");
							break;
						}
					}
				} while (opcionMenu != 3);
				break;
			case 3:
				debitoAerolineas = calcDebit(precioAerolineas, 10);
				debitoLatam = calcDebit(precioLatam, 10);
				creditoAerolineas = calcCredit(precioAerolineas, 1.25);
				creditoLatam = calcCredit(precioLatam, 1.25);
				bitcoinAerolineas = calcBit(precioAerolineas, PRECIOBITCOIN);
				bitcoinLatam = calcBit(precioLatam, PRECIOBITCOIN);
				unitarioAerolineas = calcKm(precioAerolineas, kmTotales);
				unitarioLatam = calcKm(precioLatam, kmTotales);
				diferenciaPrecios = calcDiferencia(precioLatam,
						precioAerolineas);
				printf("Calculos realizados\n");
				system("pause");
				break;
			case 4:
				printf("Los kilometros ingresados son: %d \n", kmTotales);
				printf("Latam: $ %2.f \n", precioLatam);
				printf("Precio con tarjeta de debito: $ %.2f \n", debitoLatam);
				printf("Precio con tarjeta de credito: $ %.2f \n",
						creditoLatam);
				printf("Precio pagando con Bitcoin es: $ %.8f BTC\n",
						bitcoinLatam);
				printf("Precio unitario por Km es: $ %.2f \n", unitarioLatam);
				printf("\n");
				printf("Aerolineas: $ %.2f \n", precioAerolineas);
				printf("Precio con tarjeta de debito: $ %.2f \n",
						debitoAerolineas);
				printf("Precio con tarjeta de credito: $ %.2f \n",
						creditoAerolineas);
				printf("Precio pagando con Bitcoin es: $ %.8f BTC\n",
						bitcoinAerolineas);
				printf("Precio unitario por Km es: $ %.2f \n",
						unitarioAerolineas);
				printf("\n");
				printf("La diferencias es precio es $ %.2f: \n",
						diferenciaPrecios);
				system("pause");
				break;
			case 5:
				debitoAerolineasAux = calcDebit(AEROLINEASPRECIO, 10);
				debitoLatamAux = calcDebit(LATAMPRECIO, 10);
				creditoAerolineasAux = calcCredit(AEROLINEASPRECIO, 1.25);
				creditoLatamAux = calcCredit(LATAMPRECIO, 1.25);
				bitcoinAerolineasAux = calcBit(AEROLINEASPRECIO, PRECIOBITCOIN);
				bitcoinLatamAux = calcBit(LATAMPRECIO, PRECIOBITCOIN);
				unitarioAerolineasAux = calcKm(AEROLINEASPRECIO, KILOMETROS);
				unitarioLatamAux = calcKm(LATAMPRECIO, KILOMETROS);
				diferenciaPreciosAux = calcDiferencia(LATAMPRECIO,
						AEROLINEASPRECIO);
				printf("Los kilometros ingresados son: %d \n", KILOMETROS);
				printf("Latam: $ %.2f \n", LATAMPRECIO);
				printf("Precio con tarjeta de debito: $ %.2f \n",
						debitoLatamAux);
				printf("Precio con tarjeta de credito: $ %.2f \n",
						creditoLatamAux);
				printf("Precio pagando con Bitcoin es: %.8f BTC\n",
						bitcoinLatamAux);
				printf("Precio unitario por Km es: $ %.2f \n",
						unitarioLatamAux);
				printf("\n");
				printf("Aerolineas: $ %.2f \n", AEROLINEASPRECIO);
				printf("Precio con tarjeta de debito: $ %.2f \n",
						debitoAerolineasAux);
				printf("Precio con tarjeta de credito: $ %.2f\n",
						creditoAerolineasAux);
				printf("Precio pagando con Bitcoin es: %.8f btc \n",
						bitcoinAerolineasAux);
				printf("Precio unitario por Km es: $ %.2f \n",
						unitarioAerolineasAux);
				printf("\n");
				printf(
						"La diferencias es precio es: $ %.2f (Aerolineas es el de mayor precio) \n",
						diferenciaPreciosAux);
				system("pause");
				break;

			case 6:
				retorno = 0;
				printf("Usted ha salido correctamente.\n");
				system("pause");
				break;
			}
		}
	} while (opcionMenu != 6);

	return retorno;
}
