/*
 * ArrayPassenger.c
 *
 *  Created on: 14 may. 2022
 *      Author: Gonzalo
 */
#include "../Headers/ArrayPassenger.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buscarPasajeroLibre (Passenger pasajeros[],int tam,int* pIndex)
{
    int todoOk = -1;
    if(pasajeros != NULL && tam > 0 && pIndex)
    {
        *pIndex = -1;
        for(int i = 0 ;i < tam; i++)
        {
            if(pasajeros[i].isEmpty)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int hardcodearPasajeros(Passenger pasajeros[],int tamP,int cantidad,int* pId)
{
    int todoOk = 0;
    Passenger pasajerosHard []= {{0,"Martin","Martinez",100,"MM200",10000,1,0},
                          {1,"Martina","Castro",200,"MC300",10001,0,0},
                          {2,"Bruno","Cantisani",300,"BC400",10002,1,0},
                          {3,"David","Arizaga",400,"DA500",10000,0,0},
                          {4,"Agustin","Esperon",500,"AE600",10001,1,0}};

    if (pasajeros && tamP && pId && cantidad > 0 && cantidad <= 5)
    {
        for(int i=0;i<cantidad;i++)
        {
        	pasajeros[i] = pasajerosHard[i];
        	pasajeros[i].id = (*pId);
            (*pId)++;
        }
        todoOk = cantidad;

    }
    return todoOk;
}

void printPassengerData(Passenger p,eTipoPasajero tiposPasajeros[], int tamT)
{
	char descripcionTipoPasajero [30];
	char descripcionEstado [10] = {"CANCELADO"};
	if(tiposPasajeros && tamT>0)
	{
		if(p.statusFlight)
			strcpy(descripcionEstado,"ACTIVO");
		cargarDescripcionTipoPasajero(tiposPasajeros,tamT,p.typePassenger,descripcionTipoPasajero);
		printf("%04d\t\t%-16s%-24s$%10.2f\t\t%-30s\t%-10s\t\t%-s\n",p.id,
							p.name,p.lastName,p.price,descripcionTipoPasajero,
							p.flycode,descripcionEstado);
	}
	else
		printf("Error en los parametros de printPassengerData \n");
}

int initPassengers(Passenger* list, int len)
{
	int todoOk = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i ++)
		{
			list[i].isEmpty = 1;
		}

		todoOk = 1;
	}

	return todoOk;
}

int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, int statusFlight, char flycode[])
{
	int todoOk = 0;
	int index;
	Passenger nuevoPassenger;

		if(list != NULL && name != NULL && lastName != NULL && len > 0 && id > 0 && buscarPasajeroLibre(list, len, &index))
		{
			if(index != -1)
			{
				strcpy(nuevoPassenger.name, name);
				strcpy(nuevoPassenger.lastName, lastName);

				nuevoPassenger.price = price;
				nuevoPassenger.typePassenger = typePassenger;

				strcpy(nuevoPassenger.flycode, flycode);

				nuevoPassenger.id = id;
				nuevoPassenger.isEmpty = 0;
				nuevoPassenger.statusFlight = statusFlight;

				list[index] = nuevoPassenger;

				todoOk = 0;
			}
		}
	return todoOk;
}

int findPassengerById(Passenger* list, int len,int id)
{
	int todoOk = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(!list[i].isEmpty && id == list[i].id)
			{
				todoOk = i;
				break;
			}
		}
	}

	return todoOk;
}

int removePassenger(Passenger* list, int len, int id)
{
	int todoOk = -1;

		if(list != NULL && len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				if(id == list[i].id && !list[i].isEmpty)
				{
					list[i].isEmpty = 1;
					todoOk = i;
					break;
				}
			}
		}

		return todoOk;
}

int swapPasajeros(Passenger* pasajero1, Passenger* pasajero2)
{
	Passenger auxPassenger;
	int todoOk = -1;

	if(pasajero1 && pasajero2)
	{
		auxPassenger = *pasajero1;
		*pasajero1 = *pasajero2;
		*pasajero2 = auxPassenger;

		todoOk = 1;
	}

	return todoOk;
}

int sortPassengers(Passenger* list, int len, int order)
{
	int todoOk = -1;

		if(list != NULL && len > 0 && (order == 0 || order == 1))
		{
			for(int i = 0; i < len; i++)
			{
				for(int j = i + 1; j < len; j++)
				{
					if((order && ((0 == strcmp(list[i].lastName, list[j].lastName) && list[i].typePassenger > list[j].typePassenger) || 0 < strcmp(list[i].lastName,list[j].lastName) )) || (!order && ((0 == strcmp(list[i].lastName,list[j].lastName) && list[i].typePassenger < list[j].typePassenger) || 0 > strcmp(list[i].lastName,list[j].lastName))))
					{
						swapPasajeros(&list[i], &list[j]);
						break;
					}
				}
			}

			todoOk = 1;
		}

		return todoOk;
}

int printPassenger(Passenger* list, int length, eTipoPasajero tiposPasajeros[], int tamT)
{
		int todoOk = -1;
		int flagIngreso = 0;
		Passenger actualPasajero;

		if(list && length >0 && tiposPasajeros && tamT > 0){
			printf("\t\t\t\t\t\t\t***LISTA DE PASAJEROS***\n");
			printf("-------------------------------------------------------------------------------------------------------------------------------"
					"------------------------\n");
			printf("ID\t\tNombre\t\tApellido\t\t    Precio\t\tTipo de Pasajero\t\tCodigo de vuelo\t\tEstado de vuelo\n");
			printf("-------------------------------------------------------------------------------------------------------------------------------"
					"------------------------\n");
			for(int i = 0; i < length; i++)
			{
				actualPasajero = list[i];
				if(!actualPasajero.isEmpty)
				{
					printPassengerData(actualPasajero, tiposPasajeros, tamT);
					flagIngreso = 1;
				}
			}
			if(!flagIngreso)
			{
				printf(" No existen pasajeros");
			}
			todoOk = 1;
		}

		return todoOk;
}

int printPassengerActive(Passenger* list, int length,eTipoPasajero tiposPasajeros[],int tamT)
{
	int retorno = -1;
	Passenger pasajeroActual;
	int seEjecuto = 0;

	if(list && length >0 && tiposPasajeros && tamT)
	{
		printf("\t\t\t\t\t\t\t***LISTA DE PASAJEROS ACTIVOS***\n");
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		printf("ID\t\tNombre\t\tApellido\t\t    Precio\t\tTipo de Pasajero\t\tCodigo de vuelo\t\tEstado de vuelo\n");
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		for(int i=0;i<length;i++)
		{
			pasajeroActual = list[i];
			if(!pasajeroActual.isEmpty && pasajeroActual.statusFlight)
			{
				printPassengerData(pasajeroActual,tiposPasajeros,tamT);
				seEjecuto = 1;
			}

		}
		if(!seEjecuto)
			printf("No hay ningun pasajero para mostrar \n");

		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n\n");
		retorno = 0;
	}

	return retorno;
}

int sortPassengersByCode(Passenger* list, int len, int order)
{
	int todoOk = -1;
		if(list && len > 0 && (order==1 || order == 0))
		{
			for(int i=0;i<len-1;i++)
			{
				for(int j=i+1;j<len;j++)
				{
					if ((order && ((0 == strcmp(list[i].flycode, list[j].flycode) && list[i].statusFlight > list[j].statusFlight) || 0 < strcmp(list[i].flycode, list[j].flycode))) || (!order && ((0 == strcmp(list[i].flycode, list[j].flycode) && list[i].statusFlight < list[j].statusFlight) || 0 > strcmp(list[i].flycode, list[j].flycode))))
					{
						swapPasajeros(&list[i], &list[j]);
					}
				}
			}

		todoOk = 1;
		}

		return todoOk;
}

int modifyPassenger(Passenger* list, int len, int id, char name[],char lastName[], float price,int typePassenger, char flycode[])
{
	int todoOk = 1;
	int indice;

	if(list && len > 0 && name && lastName && flycode)
	{
		indice = findPassengerById(list, len, id);
		if(indice != -1)
		{
			strcpy(list[indice].name, name);
			strcpy(list[indice].lastName, lastName);

			list[indice].price = price;
			list[indice].typePassenger = typePassenger;

			strcpy(list[indice].flycode, flycode);

			list[indice].isEmpty = 0;

			todoOk = 1;
		}
	}
	return todoOk;
}

int calculatePricesPassengers(Passenger* list, int len)
{
	int todoOk = 0;
	int contadorPassenger = 0;
	float promedioPrecios = 0;
	float acumTotalPrecios = 0;

	if(list && len > 0 )
	{
		for(int i=0;i<len;i++)
		{
			if(!list[i].isEmpty)
			{
				acumTotalPrecios += list[i].price;
				contadorPassenger++;
			}
		}
	}

	if(contadorPassenger)
	{
		promedioPrecios = acumTotalPrecios/contadorPassenger;
	}

	todoOk = 1;

	printf("El precio total de los pasajes: $%.2f \n", acumTotalPrecios);
	printf("El promedio de los pasajes: $%.2f \n", promedioPrecios);

	return todoOk;
}

