/*
 * funcionesmenu.h
 *
 *  Created on: 16 abr. 2022
 *      Author: Gonzalo
 */

#ifndef FUNCIONESMENU_H_
#define FUNCIONESMENU_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * @brief La función muestra diferentes opcciones en un menu al usuario.
 *
 * @return devuelve un numero entero el cual es la opción que el usuario eligió.
 */int menu();

/**
 * @brief La función solicita al usuario una cantidad de kilometros que equivale a la distancia del vuelo.
 *
 * @return el retorno es un float el cual es la distancia del vuelo.
 */float ingresoKilometros();

/**
 * @brief La función solicita al usuario un precio del vuelo.
 *
 * @return se retorna el mismo precio que fue fijado por el usuario.
 */float ingresoPrecios();

/**
 * @brief La función muestra los resultados ya calculados.
 *
 * @param resultados Son los resultados de costos.
 * @param kilometros La distancia del vuelo.
 * @param aerolineasPrecio El precio del vuelo aerolineas.
 * @param latamPrecio El precio del vuelo latam.
 * @param flagTodoOk Es una bandera la cual si retorna 1 los calculos fueron bien hechos, en caso de que retorne 0, no.
 */void mostrarResultados(float* resultados, float kilometros, float aerolineasPrecio, float latamPrecio, int flagTodoOk);

/**
 * @brief La función se basa en la confirmación al momento de elegir la opción "salir" en el menú.
 *
 * @param p Es un puntero el cual luego es llamado en main el cual guarda el valor de "salir".
 */void confirmarSalida(char* p);

#endif /* FUNCIONESMENU_H_ */
