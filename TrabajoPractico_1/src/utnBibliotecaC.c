/*
 * utnBibliotecaC.c
 *
 *  Created on: 15 abr. 2022
 *      Author: Agus
 */

#include "utnBiblioteca.h"

int getInt(int *enteroIngresado, char *mensaje, char *mensajeError,
					int enteroMinimo, int enteroMaximo) {
				int retorno;
				int auxEnteroIngresado;

				retorno = -1;

				if (enteroIngresado != NULL && mensaje != NULL && mensajeError != NULL && enteroMinimo <= enteroMaximo) {
					do {
						printf("%s", mensaje);
						scanf("%d", &auxEnteroIngresado);
						if (auxEnteroIngresado >= enteroMinimo
								&& auxEnteroIngresado <= enteroMaximo) {
							*enteroIngresado = auxEnteroIngresado;
							retorno = 0;
						} else {
							printf("%s", mensajeError);
						}
					} while (auxEnteroIngresado < enteroMinimo
							|| auxEnteroIngresado > enteroMaximo);
				}

				return retorno;
			}

			int getFloat(float *flotanteIngresado, char *mensaje,
					char *mensajeError, float flotanteMinimo,
					float flotanteMaximo) {
				int retorno;
				float auxFlotanteIngresado;

				retorno = -1;

				if (flotanteIngresado != NULL && mensaje != NULL
						&& mensajeError != NULL
						&& flotanteMinimo <= flotanteMaximo) {
					do {
						printf("%s", mensaje);
						scanf("%f", &auxFlotanteIngresado);
						if (auxFlotanteIngresado >= flotanteMinimo
								&& auxFlotanteIngresado <= flotanteMaximo) {
							*flotanteIngresado = auxFlotanteIngresado;
							retorno = 0;
						} else {
							printf("%s", mensajeError);
						}
					} while (auxFlotanteIngresado < flotanteMinimo
							|| auxFlotanteIngresado > flotanteMaximo);
				}

				return retorno;
			}

			float calcDebit(float precioVuelo, int descuento) {
				float precioDebito;

				precioDebito = precioVuelo - ((precioVuelo * descuento) / (float) 100 );

				return precioDebito;
			}

			float calcCredit(float precioVuelo, int credito) {
				float precioCredito;

				precioCredito = precioVuelo + (precioVuelo * credito);

				return precioCredito;
			}

			float calcBit(float precioVuelo, int btcCambio) {
				float precioBit;

				precioBit = btcCambio / (float) precioVuelo;

				return precioBit;
			}

			float calcKm(float precioVuelo, int unitarioKm) {
				float precioUnitario;

				precioUnitario = precioVuelo / (float) unitarioKm;

				return precioUnitario;

			}

			float calcDiferencia(float precioVueloLatam, float precioVueloAerolineas) {
				float resto;

				if(precioVueloLatam < precioVueloAerolineas){
					resto = precioVueloAerolineas - precioVueloLatam;
				} else{
					resto = precioVueloLatam - precioVueloAerolineas;
				}

				return resto;
			}



