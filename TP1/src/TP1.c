#include <stdio.h>
#include <stdlib.h>

#include "utn.h"
int menu();
int main()
{
	setbuf(stdout, NULL);
	int num1;
	int num2;
	int opcion;
	int rtoSuma;
	int rtoResta;
	int rtoMultiplicacion;
	float rtoDivision;
	int rtoFactorialN1;
	int rtoFactorialN2;
	char salir = 'n';
	int flagNum1 = 0;
	int flagNum2 = 0;
	int flagCalculo = 0;

	do
	{
		system("cls");
		opcion = menu(num1, num2, flagNum1, flagNum2);
		fflush(stdin);
		switch (opcion)
		{
		case 1:
			printf("\nIngresar 1er operando A = ");
			scanf("%d", &num1);
			flagNum1 = 1;
			break;
		case 2:
			if (flagNum1 == 0)
			{
				printf("\nPrimero debe ingresarse el operando A!\n");
			}
			else
			{
				printf("\nIngresar 2do operando B = ");
				scanf("%d", &num2);
				flagNum2 = 1;
			}
			break;
		case 3:
			if (flagNum2 == 0)
			{
				printf("\nPrimero debe ingresarse el operando B!\n");
			}
			else
			{
				rtoSuma = suma(num1, num2);
				rtoResta = resta(num1, num2);
				rtoMultiplicacion = producto(num1, num2);
				rtoDivision = division(num1, num2);
				rtoFactorialN1 = factorial(num1);
				rtoFactorialN2 = factorial(num2);
				printf("\nSe han calculado todas las opeaciones\n");
				flagCalculo = 1;
			}
			break;
		case 4:
			if (flagCalculo == 0)
			{
				printf("\nPrimero debe calcularse las operaciones!\n");
			}
			else
			{
				printf(
						"a) El resultado de A+B es: %d\nb) El resultado de A-B es: %d\n",
						rtoSuma, rtoResta);
				if (num2 == 0)
				{
					printf("c) No se puede dividir por cero\n");
				}
				else
				{
					printf("c) El resultado de A/B es: %.2f\n", rtoDivision);
				}
				printf(
						"d) El resultado de A*B es: %d\ne) El factorial de A es: %d y El factorial de B es: %d\n",
						rtoMultiplicacion, rtoFactorialN1, rtoFactorialN2);
				if (rtoFactorialN1 == -1 || rtoFactorialN2 == -1)
				{
					printf(
							"Error -1. No se puede calcular el factorial de un numero negativo\n");
				}
			}
			break;
		case 5:
			printf("\nSalir del programa? s / n \n");
			scanf("%c", &salir);
			break;
		default:
			printf("\nopcion erronea");
			break;
		} //Cierre switch
		system("pause");
	} while (salir == 'n');
} //llave de cierre main

int menu(int num1, int num2, int flagNum1, int flagNum2)
{
	int opcion;
	if (flagNum1 == 1)
	{
		if (flagNum2)
		{
			printf(
					"========= MENU DE OPCIONES ==========\n\n1. Ingresar 1er operando (A=%d)\n"
							"2. Ingresar 2do operando (B=%d)\n"
							"3. Calcular todas las operaciones\n"
							"4. Informar resultados\n"
							"5. Salir\n\n", num1, num2);
		}
		else
		{
			printf(
					"========= MENU DE OPCIONES ==========\n\n1. Ingresar 1er operando (A=%d)\n"
							"2. Ingresar 2do operando (B=y)\n"
							"3. Calcular todas las operaciones\n"
							"4. Informar resultados\n"
							"5. Salir\n\n", num1);
		}
	}
	else
	{
		printf(
				"========= MENU DE OPCIONES ==========\n\n1. Ingresar 1er operando (A=x)\n"
						"2. Ingresar 2do operando (B=y)\n"
						"3. Calcular todas las operaciones\n"
						"4. Informar resultados\n"
						"5. Salir\n\n");
	}
	printf("Ingrese la opcion deseada: ");
	scanf("%d", &opcion);
	return opcion;
}

