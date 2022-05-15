/*
 * Utn.h
 *
 *  Created on: 14 may. 2022
 *      Author: Agus
 */

#ifndef UTN_H_
#define UTN_H_
#include <stdio.h>
#include <stdlib.h>


/// @brief
/// Esta funcion tiene como fin pedir un entero.
/// @param mensaje
/// @param mensajeError
/// @return Retorna un entero (Indica un Error si el numero no es valido)
int getInt(char mensaje[], char mensajeError[]);
/// @brief
/// Esta funcion tiene como fin pedir un flotante
/// @param mensaje
/// @param mensajeError
/// @return Retorna un flotante (Indica un Error si el numero no es valido)
float getFloat(char mensaje[], char mensajeError[]);
/// @brief
/// Esta funcion tiene como fin imprimir una "String"
/// @param mensaje
/// @param mensajeError
/// @param input
void getnombre(char mensaje[],char mensajeError[], char input[]);
/// @brief
/// Esta funcion tiene como fin devolver un entero para la funcion getInt
/// @param str[]
/// @return Retorna un entero para getInt
int getInti(char str[]);
/// @brief
/// Esta funcion tiene como fin devolver un Int para la funcion getNombres
/// @param str[]
/// @return Retorna un entero para la funcion getNombres
int nombresValidos(char str[]);
/// @brief
/// Esta funcion tiene como fin conseguir un flotante que representa un precio
/// @return Retorna un flotante
float getPrecio();
/// @brief
/// Esta funcion tiene como fin devolver un mensaje
/// @param mensaje
/// @param mensajeError
/// @param input
void getFlycode(char mensaje[], char mensajeError[],char input[]);
/// @brief
/// Esta funcion tiene como fin realizar una validacion para validar un estado de vuelo.
/// @return Retorna una variable que tiene un valor de entero
int getStatusFlight();
/// @brief
/// Esta funcion tiene como fin realizar una validacion para validar un tipo de pasajero.
/// @return Retorna una variable que tiene un valor de entero.
int getTypePassenger();



#endif /* UTN_H_ */
