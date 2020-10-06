#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"
#include "Validaciones.h"

void pedirCadena(char *nombre, int TAM, char *MSJ)
{
	char buffer[1000];
	int maximosCharParaVerificar = TAM;

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while (strlen(buffer) > maximosCharParaVerificar || strlen(buffer) < 1)
	{
		printf("\n[ERROR] [%d CARACTERES MAX] RE%s: ",
				maximosCharParaVerificar - 1, MSJ);
		fflush(stdin);
		gets(buffer);
	}
	strlwr(buffer);
	buffer[0] = toupper(buffer[0]);
	strcpy(nombre, buffer);
}

int validarCadena(char *nombreParaValidar)
{
	int i = 0;
	int retornoValidacion = 0;
	int j;

	j = strlen(nombreParaValidar);

	while (i < j && retornoValidacion == 0)
	{
		if (isalpha(nombreParaValidar[i]) != 0)
		{
			i++;
		}
		else
		{
			printf("\n[ERROR SOLO CARACTERES ALFABETICOS] RE");
			retornoValidacion = 1;
		}
	}
	return retornoValidacion;
}

void pedirValidarCadena(char *nombre, int tamc, char *MSJ)
{
	int validar = 0;
	do
	{
		pedirCadena(nombre, tamc, MSJ);
		validar = validarCadena(nombre);

	} while (validar != 0);

}

float pedirFloatPositivo(const char *MSJ)
{
	float valorFlotante;
	char buffer[30];

	do
	{
		printf("%s: ", MSJ);
		fflush(stdin);
		gets(buffer);

		while (validarNumeroExcluyeSignos(buffer) == 1)
		{
			printf("[ERROR] REINGRESE NUMERO: ");
			fflush(stdin);
			gets(buffer);
		}
		valorFlotante = atof(buffer);

		if (valorFlotante < 0)
		{
			puts("[ERROR] VALOR SOLO POSITIVO\n");
			system("pause");

		}

	} while (valorFlotante < 0);

	return valorFlotante;
}

int validarNumeroExcluyeSignos(char *numero)
{
	int i = 0;
	int retornoValidacion = 0;
	int j = strlen(numero);

	while (i < j && retornoValidacion == 0)
	{
		if (isdigit(numero[i]) != 0 || numero[i] == '.' || numero[i] == ','
				|| numero[i] == '-')
		{
			i++;
		}
		else
		{
			retornoValidacion = 1;
		}
	}
	return retornoValidacion;
}

int validarNumero(char *numero)
{
	int i = 0;
	int retornoValidacion = 0;
	int j = strlen(numero);

	while (i < j && retornoValidacion == 0)
	{
		if (isdigit(numero[i]) != 0)
		{
			i++;
		}
		else
		{
			retornoValidacion = 1;
		}
	}
	return retornoValidacion;
}

int pedirIntPositivo(const char *MSJ)
{
	int valorInt;
	char buffer[30];

	printf("%s: ", MSJ);
	fflush(stdin);
	gets(buffer);

	while (validarNumero(buffer) == 1)
	{
		printf("[ERROR] REINGRESE NUMERO: ");
		fflush(stdin);
		gets(buffer);
	}

	if (buffer < 0)
	{
		puts("[ERROR] VALOR SOLO POSITIVO. REINGRESE NUMERO:\n");
		system("pause");
		pedirIntPositivo(MSJ);
	}

	valorInt = atoi(buffer);

	return valorInt;
}

