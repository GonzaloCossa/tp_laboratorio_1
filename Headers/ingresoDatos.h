/*
 * ingresoDatos.h
 *
 *  Created on: 13 may. 2022
 *      Author: Gonzalo
 */

#include "../Headers/tipoPasajero.h"
#include "../Headers/ArrayPassenger.h"

#ifndef INGRESODATOS_H_
#define INGRESODATOS_H_


#endif /* INGRESODATOS_H_ */

/**
 * @brief se encarga de pedir el ingreso del nuevo ID al usuario
 *
 * @return devuelve el mismo ID ingresado como un entero
 */
int pedirId();

/**
 * @brief antes de dar de baja a un pasajero pide nuevamente los datos de alta
 *
 * @param pasajero puntero de los datos anteriormente ingresados en el alta del pasajero seleccionado
 * @param tiposPasajeros vector de los distintos tipos de pasajeros
 * @param tam capacidad
 * @return
 */
int pedirDatosAlta(Passenger* pasajero, eTipoPasajero tiposPasajeros[], int tam);

/**
 * @brief brinda las distintas opciones del menu al usuario
 *
 * @return devuelve el entero que eligio el usuario
 */
int pedirDatosMenu();

/**
 * @brief brinda las opciones del submenu al momento de informar
 *
 * @return
 */
int pedirDatosSubMenu();

/**
 * @brief da la info de un pasajero ademas solicita confirmacion para la alta o modificacion
 *
 * @param pasajero, de quien se quiere mostrar la info
 * @param tipo, de que tipo es el pasajero
 * @param tiposPasajeros, lista de los tipos de pasajero
 * @param tamT, capacidad de los tipos de pasajero
 * @return
 */
char pedirConfirmacion (Passenger pasajero, int tipo, eTipoPasajero tiposPasajeros[], int tamT);

/**
 * @brief solicita el estado en el que se encuentra el vuelo actual
 *
 * @param estadoVuelo puntero donde se guarda el valor que refiere al tipo de estado de vuelo
 */
void pedirEstadoVuelo(int* estadoVuelo);

/**
 * @brief solicita el codigo del vuelo actual
 *
 * @param codigoVuelo vector de caracteres donde se almacena el valor ingresado por el usuario
 */
void pedirCodigoVuelo(char codigoVuelo[]);

/**
 * @brief pide al usuario que ingrese el tipo de pasajero validando los valores
 *
 * @param pId puntero donde se guarda el valor de id que ingreso el usuario
 * @param tiposPasajeros lista de los tipos de pasajero
 * @param tamT capacidad de los tipos de pasajero
 */
void pedirTipoPasajero (int* pId, eTipoPasajero tiposPasajeros[], int tamT);

/**
 * @brief pide el precio del vuelo
 *
 * @param precio puntero flotante donde se almacena el precio ingresado por el usuario
 */
void pedirPrecio (float* precio);

/**
 * @brief pide el apellido del pasajero a ingresar
 *
 * @param apellido vector donde se almacena el apellido del pasajero
 */
void pedirApellido (char apellido[]);

/**
 * @brief pide el nombre del pasajero a ingresar
 *
 * @param nombre vector donde se almacena el nombre del pasajero
 */
void pedirNombre(char nombre[]);

/**
 * @brief muestra el menu de opciones con los distintos campos que permite la funcion modificar
 *
 * @return retorna la respuesta del tipo entera ingresada por el usuario
 */
int pedirMenuModificar();
