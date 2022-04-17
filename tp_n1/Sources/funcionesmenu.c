/*
 * funcionesmenu.c
 *
 *  Created on: 16 abr. 2022
 *      Author: Gonzalo
 */

#include <stdio.h>
#include <stdlib.h>

#include "../Hearders/funcionescalculos.h"

int menu()
{
	int opcion;

	// Menu que aparece al principio del programa
	printf("  *** Menu de Opciones ***\n");
	printf("1. Ingresar Kilometros (km=x)\n");
	printf("2. Ingresar Precios de Vuelos (Aerolineas=y, Latam=z)\n");
	printf("3. Calcular Todos los Costos\n");
	printf("4. Informar Resultados\n");
	printf("5. Carga Forzada de Datos\n");
	printf("6. Salir\n");

	printf("Ingrese una opcion: ");
	fflush(stdin);
	scanf("%d", &opcion);

	system("cls");

	return opcion;
}

float ingresoKilometros()
{
	float kilometros;

	// Funcion del ingreso de los kilometros del vuelo
	do
	{
		printf("Ingrese la cantidad de kilometros: ");
		scanf("%f", &kilometros);
		fflush(stdin);

	}

	while(kilometros < 1);
	{
		system("cls");
		printf("Ingreso realizado con exito.");
	}
	return kilometros;
}

float ingresoPrecios()
{
	float precioVuelo;

	do
	{
		printf("Ingrese el precio del vuelo Aerolineas: ");
		scanf("%f", &precioVuelo);
	}

	while(precioVuelo < 1);
	{
		printf("Error, ingrese un precio valido.\n");
	}

	return precioVuelo;
}

void mostrarResultados(float* resultados, float kilometros, float aerolineasPrecio, float latamPrecio, int flagTodoOk)
{
	if(flagTodoOk)
	{
		printf("KMs Ingresados: %.2f km \n", kilometros);
		printf(" \n");
		printf("Precio Aerolineas: $%.2f \n", aerolineasPrecio);
		printf("a) Precio con tarjeta de debito: $%.2f \n", resultados[0]);
		printf("b) Precio con tarjeta de credito: $%.2f \n", resultados[1]);
		printf("c) Precio pagando con bitcoin : $%f \n", resultados[2]);
		printf("d) Precio unitario: $%.2f \n", resultados[3]);
		printf(" \n");
		printf("Precio Latam: $%.2f \n", latamPrecio);
		printf("a) Precio con tarjeta de debito: $%.2f \n", resultados[4]);
		printf("b) Precio con tarjeta de credito: $%.2f \n", resultados[5]);
		printf("c) Precio pagando con bitcoin : $%f \n", resultados[6]);
		printf("d) Precio unitario: $%.2f \n", resultados[7]);
		printf(" \n");
		printf("La diferencia de precio es : $%.2f \n", resultados[8]);
		printf(" \n");
	}

	else
	{
		printf("Hubo un error con los calculos. \n\n");
	}
}

void confirmarSalida(char* p)
{
    char confirma;
    printf("Confirma salida?: ");
    fflush(stdin);
    scanf("%c", &confirma);

    // Asigno el valor de la variable "confirma" a la variable "salir" de main a traves de p que recibe la direccion de salir
    *p = confirma;

}
