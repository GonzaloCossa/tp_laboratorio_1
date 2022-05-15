/*
 * inicioPrograma.c
 *
 *  Created on: 13 may. 2022
 *      Author: Gonzalo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Headers/inicioPrograma.h"
#include "../Headers/tipoPasajero.h"
#include "../Headers/ingresoDatos.h"
#include "../Headers/ArrayPassenger.h"

void iniciarPrograma()
{
	int opcion;
	int id = VIAJES_ID;
	int flagCarga = 0;
	int contadorPasajeros = 0;
	Passenger arrayPassengers [PASAJEROS] = {};
	eTipoPasajero tiposPasajeros[TIPOS_PASAJEROS] = {{10000,"Clase Economica"},
										   {10001,"Clase VIP"},
										   {10002,"Clase Empresarial"}};

	if(0 == initPassengers(arrayPassengers, PASAJEROS))
	{
		do{
			opcion = pedirDatosMenu();
				if(opcion >=2 && opcion<=4 && !contadorPasajeros)
				{
					printf("Para continuar se debe dar un alta por lo menos\n");
				}
				else
				{
					switch(opcion)
					{
						case 1:
							alta(arrayPassengers, &id, tiposPasajeros, TIPOS_PASAJEROS);
							contadorPasajeros++;
						break;
						case 2:
							modificar(arrayPassengers, tiposPasajeros, TIPOS_PASAJEROS);
						break;
						case 3:
							baja(arrayPassengers, tiposPasajeros, TIPOS_PASAJEROS);
							contadorPasajeros--;
						break;
						case 4:
							listar(arrayPassengers, tiposPasajeros, TIPOS_PASAJEROS);
						break;
						case 5:
							if(!flagCarga && (contadorPasajeros = hardcodearPasajeros(arrayPassengers, PASAJEROS, 5, &id)))
							{
								printf("Carga forzada realizada de manera exitosa \n");
								flagCarga = 1;
							}else
								printf("Error en la carga forzada o ya se realizo una \n");
						break;
						case 6:
							printf("Saliendo \n");
						break;
					}
				}
				system("pause");
				system("cls");
		}
		while(opcion != 6);
	}
	else printf("Hubo un error en el ingreso del programa.\n");
}

void alta(Passenger* list,int* id,eTipoPasajero tiposPasajeros[],int tamT)
{
	Passenger nuevoPassenger;
	int index;

	if(list && id && tiposPasajeros && tamT>0 ){
		buscarPasajeroLibre(list,PASAJEROS,&index);
		if(index == -1){
			printf("Limite de pasajeros alcanzado (MAX: %d) \n",PASAJEROS);
		}else{
			pedirDatosAlta(&nuevoPassenger,tiposPasajeros,tamT);
			if(!addPassenger(list, PASAJEROS, *id, nuevoPassenger.name, nuevoPassenger.lastName, nuevoPassenger.price, nuevoPassenger.typePassenger, nuevoPassenger.statusFlight, nuevoPassenger.flycode))
			{
				printf("Pasajero dado de ALTA exitosamente \n");
				(*id)++;
			}
			else
			{
				printf("Error en la ALTA del pasajero \n");
			}
		}
	}else
		printf("Error en los parametros del alta \n");
}


void modificar(Passenger* list, eTipoPasajero tiposPasajeros[], int tam)
{
	Passenger actualPasajero;
	int respuesta = 0;
	int idBusqueda;
	int index;

	if(list && tiposPasajeros && tam >0)
	{
		printPassenger(list,PASAJEROS,tiposPasajeros,tam);
		idBusqueda = pedirId();
		index = findPassengerById(list,PASAJEROS,idBusqueda);

		if(-1 == index)
		{
			printf("Error en la ID ingresada \n");
		}
		else if ('s'== pedirConfirmacion(list[index], 2, tiposPasajeros, tam))
		{
			actualPasajero = list[index];
			do
			{
				switch(respuesta = pedirMenuModificar())
				{
					case 1:
						pedirNombre(actualPasajero.name);
						printf("Nombre modificado de manera correcta \n");
						break;
					case 2:
						pedirApellido(actualPasajero.lastName);
						printf("Apellido modificado de manera correcta \n");
						break;
					case 3:
						pedirPrecio(&actualPasajero.price);
						printf("Precio modificado de manera correcta \n");
						break;
					case 4:
						pedirTipoPasajero(&actualPasajero.typePassenger,tiposPasajeros,tam);
						printf("Tipo de pasajero modificado de manera correcta \n");
						break;
					case 5:
						pedirCodigoVuelo(actualPasajero.flycode);
						printf("Codigo de vuelo modificado de manera correcta \n");
						break;
				}
			}
			while(respuesta != 6);

			if(!modifyPassenger(list, PASAJEROS, idBusqueda, actualPasajero.name, actualPasajero.lastName, actualPasajero.price, actualPasajero.typePassenger, actualPasajero.flycode))
			{
				printf("Pasajero MODIFICADO exitosamente \n");
			}
			else
			{
				printf("Error en la MODIFICACION del pasajero \n");
			}
		}
			else
			{
			printf("MODIFICACION cancelada \n");
			}
	}
	else
	{
		printf("Error en los parametros de modificar \n");
	}

}


void baja(Passenger* list, eTipoPasajero tiposPasajeros[], int tamT)
{
	if(list && tiposPasajeros && tamT > 0)
	{
		printPassenger(list, PASAJEROS, tiposPasajeros, tamT);
		int idBusqueda = pedirId();
		int index = findPassengerById(list, PASAJEROS, idBusqueda);

		if(-1 == index)
		{
			printf("Error en la ID ingresada \n");
		}
		else if ('s'== pedirConfirmacion(list[index], 3, tiposPasajeros, TIPOS_PASAJEROS))
			{
				if(!removePassenger(list, PASAJEROS, idBusqueda))
				{
					printf("Pasajero dado de BAJA de manera exitosa \n");

				}
				else
				{
					printf("Error en la BAJA del pasajero \n");
				}
			}
		else
		{
			printf("BAJA cancelada \n");
		}
	}
	else
	{
		printf("Error en los parametros de baja \n");
	}
}

void listar(Passenger* list, eTipoPasajero tiposPasajeros[], int tamT)
{
	int opcion;
	Passenger auxArrayPassengers[PASAJEROS];

	if(list && tiposPasajeros && tamT >0)
	{
		for(int i = 0; i < PASAJEROS; i++)
		{
			auxArrayPassengers[i] = list[i];
		}
		do
		{
			switch(opcion = pedirDatosSubMenu())
			{
				case 1:
					sortPassengers(auxArrayPassengers, PASAJEROS, 1);
					printPassenger(auxArrayPassengers, PASAJEROS, tiposPasajeros, tamT);
				break;
				case 2:
					calculatePricesPassengers(auxArrayPassengers, PASAJEROS);
				break;
				case 3:
					sortPassengersByCode(auxArrayPassengers, PASAJEROS, 1);
					printPassengerActive(auxArrayPassengers, PASAJEROS, tiposPasajeros, tamT);
				break;
			}
		}
		while(opcion != 4);
	}
	else
	{
		printf("Ocurrio un error con la opcion ingresada\n");
	}
}
