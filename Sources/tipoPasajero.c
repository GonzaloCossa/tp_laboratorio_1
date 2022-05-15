/*
 * tipoPasajero.c
 *
 *  Created on: 13 may. 2022
 *      Author: Gonzalo
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../Headers/tipoPasajero.h"

int mostrarTiposPasajeros (eTipoPasajero tiposPasajeros[],int tamT)
{
    int todoOk = 0;

    if(tiposPasajeros && tamT>0)
    {
        printf("***LISTADO DE TIPOS DE PASAJEROS***\n");
        printf("-------------------------------\n");
        printf("ID\tTipo de pasajero\n");
        printf("-------------------------------\n");
        for(int i=0;i<tamT;i++){
            printf("%d\t%-10s\n",tiposPasajeros[i].id,tiposPasajeros[i].descripcion);
        }
        printf("-------------------------------\n\n");
        todoOk= 1;
    }

    return todoOk;
}


int buscarTipoPasajero (eTipoPasajero tiposPasajeros[],int tamT,int id,int* pIndice)
{
    int todoOk = 0;
    if(tiposPasajeros && tamT >0 && pIndice)
    {
        *pIndice = -1;
        for(int i=0;i<tamT;i++)
        {
            if(tiposPasajeros[i].id == id)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int validarTipoPasajero (eTipoPasajero tiposPasajeros[],int tamT,int id)
{
    int todoOk = 0;
    int indice;
    if(tiposPasajeros && tamT > 0)
    {
        buscarTipoPasajero(tiposPasajeros,tamT,id,&indice);
        if(indice != -1)
            todoOk = 1;
    }
    return todoOk;
}


int cargarDescripcionTipoPasajero (eTipoPasajero tiposPasajeros[],int tamT,int id,char descripcion[])
{
    int todoOk = 0;
    int indice;
    if(tiposPasajeros && tamT >0 && descripcion && buscarTipoPasajero(tiposPasajeros,tamT,id,&indice))
    {
        strcpy(descripcion,tiposPasajeros[indice].descripcion);
        todoOk = 1;
    }
    return todoOk;
}
