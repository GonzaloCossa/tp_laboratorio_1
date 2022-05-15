/*
 * ArrayPassenger.h
 *
 *  Created on: 13 may. 2022
 *      Author: Gonzalo
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include "../Headers/tipoPasajero.h"

		struct
		{
			int id;
			char name[51];
			char lastName[51];
			float price;
			char flycode[10];
			int typePassenger;
			int statusFlight;
			int isEmpty;
		}typedef Passenger;

#endif /* ARRAYPASSENGER_H_ */

	/** \brief To indicate that all position in the array are empty,
	* this function put the flag (isEmpty) in TRUE in all
	* position of the array
	* \param list Passenger* Pointer to array of passenger
	* \param len int Array length
	* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
	*
	*/
	int initPassengers(Passenger* list, int len);

	/** \brief add in a existing list of passengers the values received as parameters
	* in the first empty position
	* \param list passenger*
	* \param len int
	* \param id int
	* \param name[] char
	* \param lastName[] char
	* \param price float
	* \param typePassenger int
	* \param flycode[] char
	* \return int Return (-1) if Error [Invalid length or NULL pointer or without
	free space] - (0) if Ok
	*/
	int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger,int statusFlight, char flycode[]);


	/** \brief find a Passenger by Id en returns the index position in array.
	*
	* \param list Passenger*
	* \param len int
	* \param id int
	* \return Return passenger index position or (-1) if [Invalid length or
	NULL pointer received or passenger not found]
	*
	*/
	int findPassengerById(Passenger* list, int len,int id);


	/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
	*
	* \param list Passenger*
	* \param len int
	* \param id int
	* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
	find a passenger] - (0) if Ok
	*
	*/
	int removePassenger(Passenger* list, int len, int id);


	/** \brief Sort the elements in the array of passengers, the argument order
	indicate UP or DOWN order
	*
	* \param list Passenger*
	* \param len int
	* \param order int [1] indicate UP - [0] indicate DOWN
	* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
	*
	*/
	int sortPassengers(Passenger* list, int len, int order);

	/** \brief print the content of passengers array
	*
	* \param list Passenger*
	* \param length int
	* \return int
	*
	*/
	int printPassenger(Passenger* list, int length,eTipoPasajero tiposPasajeros[], int tamT);


	/** \brief Sort the elements in the array of passengers, the argument order
	indicate UP or DOWN order
	*
	* \param list Passenger*
	* \param len int
	* \param order int [1] indicate UP - [0] indicate DOWN
	* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
	*
	*/
	int sortPassengersByCode(Passenger* list, int len, int order);

	/**
		* @brief modifica los campos necesarios del pasajero
	 *
	 * @param list puntero a la lista de pasajeros
	 * @param len capacidad de la lista
	 * @param id entero identificador del pasajero
	 * @param name nombre del pasajero
	 * @param lastName apellido del pasajero
	 * @param price precio del vuelo
	 * @param typePassenger tipo de pasajero
	 * @param flycode codigo del vuelo
	 * @return devuelve un entero para verificar si salio bien 1 para si 0 para no
	 */
	int modifyPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[]);

	/// @brief muestra del vector de pasajeros aquellas posiciones que no estan vacias y el tipo de pasajero
	/// es ACTIVO = 1
	///
	/// @param list Passenger*, puntero a vector de pasajeros
	/// @param length int, tamanio del vector
	/// @param eTipoPasajero tiposPasajeros[], vector de tipos de pasajeros
	/// @param int tamT, tamanio del vector de tipos de pasajeros
	/// @return int, retorna un valor de -1 en caso de ERROR o un valor de 0 en caso de que se pudo hacer la muestra de datos
	int printPassengerActive(Passenger* list, int length,eTipoPasajero tiposPasajeros[],int tamT);

	/**
		 * @brief La funcion calcula los promedios de los precios de los pasajeros
	 *
	 * @param list lista de los pasajeros
	 * @param len capacidad de la lista de los suplentes
	 * @return devuelve un entero para verificar si salio bien 1 para si 0 para no
	 */
	int calculatePricesPassengers(Passenger* list, int len);

	/// @brief realiza una muestra de datos de un pasajero en particular, funcion usada en printPassengerActive() y
	///  printPassenger()
	///
	///
	/// @param p Passenger, tipo de dato Pasenger , donde los campos contiene la informacion a mostrar
	/// @param eTipoPasajero tiposPasajeros[], vector de tipos de pasajeros
	/// @param int tamT, tamanio del vector de tipos de pasajeros
	void printPassengerData (Passenger p,eTipoPasajero tiposPasajeros[], int tamT);

	/// @brief carga en el vector de pasajeros informacion cargada previamente para probar el codigo
	///
	/// @param Passenger pasajeros[],vector de pasajeros
	/// @param int tamP, tamanio del vector de pasajeros
	/// @param int cantidad, cantidad de pasajeros con informacion falsa a cargar (MAX = 5)
	/// @param int* pId, puntero a entero que apunta a la variable que lleva el control de la id de pasajeros
	/// @return si los parametros son correctos retorna 1, si los parametros son incorrectos retorna 0
	int hardcodearPasajeros (Passenger pasajeros[],int tamP,int cantidad,int* pId);

	/**
		 * @brief busca en el array de pasajeros los puestos vacios
	 *
	 * @param pasajeros lista de los pasajeros
	 * @param tam capacidad de la lista de los pasajeros
	 * @param pIndex punto al indice
	 * @return devuelve un entero para verificar si salio bien 1 para si 0 para no
	 */
	int buscarPasajeroLibre(Passenger pasajeros[], int tam, int* pIndex);

	/**
		 * @brief se encarga de hacer swap entre pasajeros segun sea necesario
	 *
	 * @param pasajero1 puntero a un pasajero
	 * @param pasajero2 puntero a otro pasajero
	 * @return devuelve un entero para verificar si salio bien 1 para si 0 para no
	 */
	int swapPasajeros(Passenger* pasajero1, Passenger* pasajero2);

