/*
 * funcionescalculos.h
 *
 *  Created on: 16 abr. 2022
 *      Author: Gonzalo
 */

#ifndef FUNCIONESCALCULOS_H_
#define FUNCIONESCALCULOS_H_

#include <stdio.h>
#include <stdlib.h>


/**
 * @brief La funcion calcula los costos de los vuelos solicitados.
 *
 * @param aerolineasPrecio es el precio del vuelo de aerolineas seleccionado por el usuario.
 * @param latamPrecio es el precio del vuelo de latam seleccionado por el usuario.
 * @param kilometros es la distancia del vuelo que seleccionó el usuario.
 * @param costosCalculados este es el vector con los datos de los diferentes costos ya calculados.
 * @return
 */int calcularCostos(float aerolineasPrecio, float latamPrecio, float kilometros, float* costosCalculados);

/**
 * @brief La función convierte el precio del vuelo al formato bitcoin.
 *
 * @param precio Es el precio del vuelo elegido por el usuario.
 * @return la función devuelve el precio del vuelo en bitcoin.
 */float pasajeBtc(float precio);

/**
 * @brief La función calcula el precio de un kilometro del viaje.
 *
 * @param precio es el precio del vuelo seleccionado por el usuario.
 * @param kilometros es la distancia del vuelo seleccioando por el usuario.
 * @return devuelve el valor de un kilometro.
 */float precioUnitario(float precio, float kilometros);

/**
 * @brief La función carga forzadamente diferentes valores a las varibles.
 *
 * @param aerolineasPrecio es el precio del vuelo de aerolineas.
 * @param latamPrecio es el precio del vuelo de latam.
 * @param kilometros es la distancia del vuelo seleccioando por el usuario.
 */void cargaForzada(float* aerolineasPrecio, float* latamPrecio, float* kilometros);

#endif /* FUNCIONESCALCULOS_H_ */
