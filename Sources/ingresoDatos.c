/*
 * ingresoDatos.c
 *
 *  Created on: 13 may. 2022
 *      Author: Gonzalo
 */

#include "../Headers/ingresoDatos.h"
#include "../Headers/ArrayPassenger.h"
#include "../Headers/tipoPasajero.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int pedirDatosMenu()
{
	int opcion;
	do{
		printf("     ***Trabajo Practico Numero 2***\n");
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		printf("1- Alta\n");
		printf("2- Modificar\n");
		printf("3- Baja\n");
		printf("4- Informar\n");
		printf("5- Carga Forzada\n");
		printf("6- Salir\n");
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");

		scanf("%d", &opcion);
		fflush(stdin);

		if(opcion < 1 || opcion > 6)
		{
			printf("Error. Ingrese una opcion correcta.\n");
		}
	}
	while(opcion <1 || opcion > 6);

	return opcion;
}

int pedirMenuModificar()
{
	int opcion;
	printf("1- Nombre\n");
	printf("2- Apellido\n");
	printf("3- Precio\n");
	printf("4- Tipo de Pasajero\n");
	printf("5- Codigo de Vuelo\n");
	printf("6- Salir\n");

	scanf("%d", &opcion);
	fflush(stdin);

	return opcion;
}

char pedirConfirmacion (Passenger pasajero, int tipo, eTipoPasajero tiposPasajeros[], int tamT)
{
	char respuesta = 'n';
	if(!pasajero.isEmpty && tiposPasajeros && tamT)
	{
		if(tipo == 2)
		{
			printf("Desea modificar el siguiente pasajero ? s-n \n\n");
		}
		else
		{
			printf("Desea borrar el siguiente pasajero ? s-n \n\n");
		}

		printf("ID\t\tNombre\t\tApellido\t\t    Precio\t\tTipo de Pasajero\t\tCodigo de vuelo\t\tEstado de vuelo\n");
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		printPassengerData(pasajero, tiposPasajeros, tamT);
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		fflush(stdin);
		scanf("%c",&respuesta);
		respuesta = tolower(respuesta);
		fflush(stdin);
	}
	return respuesta;

}

void pedirNombre(char nombre[])
{
	if(nombre)
	{
		printf("Ingrese el nombre del pasajero: ");

		gets(nombre);
		fflush(stdin);

		while(strlen(nombre) > 50)
		{
			printf("Nombre demasiado largo, vuelva a ingresar: ");
			gets(nombre);
			fflush(stdin);
		}
	}
	else
	{
		printf("Error al momento de pedir el nombre\n");
	}
}

void pedirApellido (char apellido[])
{
	if(apellido)
	{
		printf("Ingrese el apellido del pasajero: ");
		gets(apellido);
		fflush(stdin);
		while(strlen(apellido) > 50)
		{
			printf("Apellido demasiado largo, vuelva a ingresar: ");
			gets(apellido);
			fflush(stdin);
		}
	}
	else
	{
		printf("Error al momento de ingresar el apellido.");
	}
}

void pedirPrecio (float* precio)
{
	if(precio)
	{
		printf("Ingrese el precio del vuelo \n");
		scanf("%f",precio);
		fflush(stdin);
		while(*precio < 0)
		{
			printf("Error, ingrese un precio positivo: $: ");
			scanf("%f",precio);
		}
	}
	else
	{
		printf("Error al momento de ingresar el precio.");
	}
}


void pedirTipoPasajero (int* pId,eTipoPasajero tiposPasajeros[],int tamT)
{
	if(pId && tiposPasajeros && tamT)
	{
		mostrarTiposPasajeros(tiposPasajeros,tamT);
		printf("Ingrese el ID del tipo de pasajero: ");
		scanf("%d",pId);
		fflush(stdin);

		while(!validarTipoPasajero (tiposPasajeros, tamT, *pId))
		{
			printf("Error en la ID, ingrese nuevamente: ");
			scanf("%d",pId);
			fflush(stdin);
		}
	}
	else
	{
		printf("Error en los parametros de pedirTipoPasajero \n");
	}
}

void pedirCodigoVuelo(char codigoVuelo[])
{
	if(codigoVuelo)
	{
		printf("Ingrese el codigo de vuelo del pasajero: ");
		gets(codigoVuelo);
		fflush(stdin);
		while(strlen(codigoVuelo) > 9)
		{
			printf("Codigo de vuelo demasiado largo, MAX 9 caracteres, vuelva a ingresar: ");
			gets(codigoVuelo);
			fflush(stdin);
		}
	}
	else
	{
		printf("Error en parametros de pedirCodigoVuelo \n");
	}
}

void pedirEstadoVuelo(int* estadoVuelo)
{
	if(estadoVuelo)
	{
		printf("Ingrese el estado del vuelo ACTIVO (1), CANCELADO (0): ");
		scanf("%d", estadoVuelo);
		fflush(stdin);
		while((*estadoVuelo) != 1 && (*estadoVuelo) != 0){
			printf("Ingrese el estado del vuelo, debe ser ACTIVO (1), CANCELADO (0): ");
			scanf("%d",estadoVuelo);
			fflush(stdin);
		}
	}
	else
	{
		printf("Error en los parametros de pedirEstadoVuelo \n");
	}
}

int pedirDatosAlta (Passenger* pasajero, eTipoPasajero tiposPasajeros[], int tamT)
{
	int todoOk = 0;

	if(pasajero && tiposPasajeros && tamT)
	{
		pedirNombre(pasajero->name);
		pedirApellido(pasajero->lastName);
		pedirPrecio(&pasajero->price);
		pedirCodigoVuelo(pasajero->flycode);
		pedirEstadoVuelo(&pasajero->statusFlight);
		pedirTipoPasajero(&pasajero->typePassenger,tiposPasajeros,tamT);
		todoOk = 1;
	}
	return todoOk;


}

int pedirId()
{
	int id;
	printf("Ingrese el ID: ");
	fflush(stdin);
	scanf(" %d", &id);
	fflush(stdin);
	return id;
}

int pedirDatosSubMenu()
{
	int opcion;
	do
	{
		printf("1) Listado de los pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero \n");
		printf("2) Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio. \n");
		printf("3) Listado de los pasajeros por Codigo de vuelo y estados de vuelos 'ACTIVO'\n");
		printf("4) Salir \n\n");
		scanf("%d",&opcion);
		fflush(stdin);
		printf("\n");
		if(opcion <1 || opcion > 4)
		{
			printf("Error en la opcion del menu, vuelva a ingresar \n");
		}
	}
	while (opcion < 1 || opcion > 4);
	return opcion;
}
