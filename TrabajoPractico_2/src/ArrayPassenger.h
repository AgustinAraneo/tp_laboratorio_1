/*
 * ArrayPassenger.h
 *
 *  Created on: 14 may. 2022
 *      Author: Agus
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct{
	  int id;
	  char name[51];
	  char lastname[51];
	  float price;
	  char flycode[10];
	  int typePassenger;
	  int statusFlight;
	  int isEmpty;
}EPassenger;

/// @brief
/// Esta funcion tiene como fin iniciar a un pasajero.
/// @param pasajeros
/// @param len
void initPassenger(EPassenger pasajeros[],int len);
/// @brief
/// Esta funcion tiene como fin agregar a un numero pasajero.
/// @param list
/// @param len
/// @param id
/// @param name
/// @param lastname
/// @param price
/// @param typaPassenger
/// @param flycode
/// @param statusFlight
/// @return Retorna un entero
int addPassenger(EPassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight);
/// @brief
/// Esta funcion tiene como fin modificar un pasajero.
/// @param pasajeros
/// @param len
/// @return Retorna un entero
int modifyPassenger(EPassenger pasajeros[],int len);
/// @brief
/// Esta funcion tiene como fin buscar a un pasajero por id.
/// @param pasajeros
/// @param len
/// @return Retorna un entero
int findPassengerById(int id,EPassenger pasajeros[],int len);
/// @brief
/// Esta funcion tiene como fin dar de baja a un pasajero.
/// @param pasajeros
/// @param len
/// @param id
/// @return Retorna un entero
int removePassenger(EPassenger *pasajeros,int len, int id);
/// @brief
/// Esta funcion tiene como fin autoincrementar la id.
/// @param pasajeros
/// @param len
/// @return Retorna un entero.
int autoIncrementalId(EPassenger pasajeros[],int len);
/// @brief
/// Esta funcion tiene como fin imprimir el listado de pasajeros.
/// @param pasajeros
/// @param len
void printPassengers(EPassenger *pasajeros, int len);
/// @brief
/// Esta funcion tiene como fin Hardcodear pasajeros (Para facilitar al profesor al testear el programa)
/// @param pasajeros
/// @param len
void hardcodePassenger(EPassenger pasajeros[], int len);
/// @brief
/// Esta funcion tiene como fin ordenar los pasajeros
/// @param list
/// @param len
/// @param order
/// @return Retorna un entero.
int sortPassengers(EPassenger* list, int len, int order);
/// @brief
/// Esta funcion tiene como fin ordenar los pasajeros por flycode
/// @param list
/// @param len
/// @param order
/// @return Retorna un entero.
int sortPassengersByCode(EPassenger* list, int len, int order);
/// @brief
/// Esta funcion tiene como fin ordenar los pasajeros por total y promedio de precio
/// @param list
/// @param len
void printTotalAndAveragesPriceFlights(EPassenger* list, int len);

#endif /* ARRAYPASSENGER_H_ */
