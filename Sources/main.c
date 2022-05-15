/*
 ============================================================================
 Name        : main.c
 Author      : Gonzalo Agustin Cossa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "../Headers/inicioPrograma.h"

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);

	iniciarPrograma();

	return 0;
}
