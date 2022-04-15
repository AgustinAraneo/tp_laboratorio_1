/*
 * utnBiblioteca.h
 *
 *  Created on: 15 abr. 2022
 *      Author: Agus
 */

#ifndef UTNBIBLIOTECA_H_
#define UTNBIBLIOTECA_H_
#include <stdio.h>
#include <stdlib.h>
/// @brief
/// Esta funcion tiene como fin pedir un entero.
/// @param enteroIngresado
/// @param mensaje
/// @param mensajeError
/// @param enteroMinimo
/// @param enteroMaximo
/// @return Retorna un -1 si es FALSO o 0 si es VERDADERO.
int getInt(int *enteroIngresado, char *mensaje, char *mensajeError,
		int enteroMinimo, int enteroMaximo);
/// @brief
/// Esta funcion tiene como fin pedir un flotante
/// @param flotanteIngresado
/// @param mensaje
/// @param mensajeError
/// @param flotanteMinimo
/// @param flotanteMaximo
/// @return Retorna un -1 si es FALSO o 0 si es VERDADERO.
int getFloat(float *flotanteIngresado, char *mensaje, char *mensajeError,
		float flotanteMinimo, float flotanteMaximo);
/// @brief
/// Esta funcion tiene como fin calcular un descuento
/// @param precioVuelo
/// @param descuento
/// @return Retorna el resultado del calculo.
float calcDebit(float precioVuelo, int descuento);
/// @brief
/// Esta funcion tiene como fin calcular un credito.
/// @param precioVuelo
/// @param credito
/// @return Retorna el resultado del calculo.
float calcCredit(float precioVuelo, float credito);
/// @brief
/// Esta funcion tiene como fin realizar una conversion.
/// @param precioVuelo
/// @param btcCambio
/// @return Retorna el resultado del calculo.
float calcBit(float precioVuelo, float btcCambio);
/// @brief
/// Esta funcion tiene como fin realizar una division para conseguir un valor unitario entre 2 variables.
/// @param precioVuelo
/// @param unitarioKm
/// @return Retorna el resultado del calculo.
float calcKm(float precioVuelo, int unitarioKm);
/// @brief
/// Esta funcion tiene como fin realizar una comparacion entre 2 variables.
/// @param precioVueloLatam
/// @param precioVueloAerolineas
/// @return Retorna el resultado del calculo.
float calcDiferencia(float precioVueloLatam, float precioVueloAerolineas);

#endif /* UTNBIBLIOTECA_H_ */
