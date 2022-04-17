/*
 * funcionescalculos.c
 *
 *  Created on: 16 abr. 2022
 *      Author: Gonzalo
 */

#include "../Hearders/funcionescalculos.h"

#include <stdio.h>
#include <stdlib.h>

#define btc 4606954.55
#define kmCargaForzada 7090
#define aerolineasCargaForzada 162965
#define latamCargaForzada 159339

int calcularCostos(float aerolineasPrecio, float latamPrecio, float kilometros, float* costosCalculados)
{
	int retorno = 0; // 0 Si hubo un error, 1 si no lo hubo

	if(aerolineasPrecio && latamPrecio && kilometros)
		{
			// Calculos Aerolineas
			costosCalculados [0] = aerolineasPrecio * (0.9); // Tarjeta de débito (descuento 10%)
			costosCalculados [1] = aerolineasPrecio * (1.25); // Tarjeta de crédito (interés 25%)
			costosCalculados [2] = pasajeBtc(aerolineasPrecio); // Bitcoin
			costosCalculados [3] = precioUnitario(aerolineasPrecio, kilometros); // Mostrar precio por km

			// Calculos Latam
			costosCalculados [4] = latamPrecio * (0.9); // Tarjeta de débito (descuento 10%)
			costosCalculados [5] = latamPrecio * (1.25); // Tarjeta de crédito (interés 25%)
			costosCalculados [6] = pasajeBtc(latamPrecio); // Bitcoin
			costosCalculados [7] = precioUnitario(latamPrecio, kilometros); // Mostrar precio por km

			// ostrar diferencia de precio ingresada
			if(aerolineasPrecio > latamPrecio)
			{
				costosCalculados [8] = aerolineasPrecio - latamPrecio;
			}

			else
			{
				costosCalculados [8] = latamPrecio - aerolineasPrecio;
			}

			if(kilometros != kmCargaForzada)
			{
				printf("Los calculos fueron correctos \n\n");
			}

			retorno = 1;
		}

	// En caso de que haya faltado ingresar algun valor
	else
		{
			if(!aerolineasPrecio)
			{
				printf("Error, no ha sido ingresado el precio de Aerolineas \n");
			}
			if(!latamPrecio)
			{
				printf("Error, no ha sido ingresado el precio de Latam \n");
			}

			if(!kilometros){
				printf("Error, no ha sido ingresado los kilometros \n");
			}
			printf("\n");
			retorno = 0;
		}

	return 0;
}

float pasajeBtc(float precio)
{
	return precio / btc;
}

float precioUnitario(float precio, float kilometros)
{
	return precio / kilometros;
}

void cargaForzada(float* aerolineasPrecio, float* latamPrecio, float* kilometros)
{
	*aerolineasPrecio = aerolineasCargaForzada;
	*latamPrecio = latamCargaForzada;
	*kilometros = kmCargaForzada;
}
