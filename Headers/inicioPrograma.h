/*
 * inicioPrograma.h
 *
 *  Created on: 13 may. 2022
 *      Author: Gonzalo
 */

#include "../Headers/ArrayPassenger.h"
#include "../Headers/ingresoDatos.h"

#define PASAJEROS 2000 // Cantidad max de pasajeros
#define TIPOS_PASAJEROS 3 // Cantidad de tipos de pasajeros
#define VIAJES_ID 0 // Comienzo de los ID de los pasajeros

#ifndef INICIOPROGRAMA_H_
#define INICIOPROGRAMA_H_


#endif /* INICIOPROGRAMA_H_ */

/**@brief funcion principal del programa, opera todas las opciones y la logica del menu
 */
void iniciarPrograma();

/**
 * @brief se le incluye las opciones listar del menu
 *
 * @param list puntero a vector de los pasajeros
 * @param tiposPasajeros vector con los tipos de pasajeros
 * @param tam capacidad del vector de tipos de pasajeros
 */
void listar(Passenger* list, eTipoPasajero tiposPasajeros[], int tam);

/**
 * @brief su funcion es dar de alta a los pasajeros solicitados
 *
 * @param list puntero de vector de pasajeros
 * @param id puntero a la cantidad de ids posibles de los pasajeros
 * @param tiposPasajeros vector de los tipos de pasajeros
 * @param tam capacidad del vector de tipos de pasajeros
 */
void alta(Passenger* list, int* id, eTipoPasajero tiposPasajeros[], int tam);

/**
 * @brief tiene la capacidad de modificar los diferentes campos necesarios del menu acerca de los pasajeros
 *
 * @param list puntero a vector de los pasajeros
 * @param tiposPasajeros vector de los diferentes tipos de pasajeros
 * @param tam capacidad del vector de tipos de pasajeros
 */
void modificar(Passenger* list, eTipoPasajero tiposPasajeros[], int tam);

/**
 * @brief
 *
 * @param list puntero a vector de los pasajeros
 * @param tiposPasajeros vector de los diferentes tipos de pasajeros
 * @param tam capacidad del vector de tipos de pasajeros
 */
void baja(Passenger* list, eTipoPasajero tiposPasajeros[], int tam);

