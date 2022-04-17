/*
 ============================================================================
 Name        : TP1.c
 Author      : Gonzalo Agustin Cossa 1°A
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "../Hearders/funcionescalculos.h"
#include "../Hearders/funcionesmenu.h"

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);

	int flagKilometros = 0;
	int flagPreciosVuelos = 0;
	int flagCalcularCostos = 0;
	int flagTodoOk = 0;
	float aerolineasPrecio = 0;
	float latamPrecio = 0;
	float kilometros = 0;
	float costosCalculados[9];
	char salir = 'n';

	// Switch de la funcion menu
	do
	{
		switch(menu())
		{
			case 1: ingresoKilometros();
					flagKilometros = 1;
					break;

			case 2: if(flagKilometros == 1)
					{
						ingresoPrecios();
						flagPreciosVuelos = 1;
					}
					else
					{
						system("cls");
						printf("Ingrese primero los kilometros.\n\n");
						system("pause");
					}
					break;
			case 3: if(flagPreciosVuelos == 1)
					{
						calcularCostos(aerolineasPrecio, latamPrecio, kilometros, costosCalculados);
						flagCalcularCostos = 1;
					}
					else
					{
						system("cls");
						printf("Ingrese primero los precios.\n\n");
						system("pause");
					}
					break;
			case 4:	if(flagCalcularCostos == 1)
			{
					mostrarResultados(costosCalculados, kilometros, aerolineasPrecio, latamPrecio, flagTodoOk);
					}
					break;
			case 5:	cargaForzada(&aerolineasPrecio, &latamPrecio, &kilometros);
					calcularCostos(aerolineasPrecio, latamPrecio, kilometros, costosCalculados);
					mostrarResultados(costosCalculados, kilometros, aerolineasPrecio, latamPrecio, flagTodoOk);
					break;
			case 6: confirmarSalida(&salir);
					break;
			default:
					printf("Error, ingrese una opcion correcta.\n\n");
					break;
		}
	}
	while(salir != 's');

	return EXIT_SUCCESS;
}
