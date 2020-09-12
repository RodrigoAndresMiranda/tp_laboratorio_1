#include<stdio.h>
#include<stdlib.h>

int suma(int num1, int num2)
{
	int resultado;
	resultado = num1 + num2;
	return resultado;
}

int resta(int num1, int num2)
{
	int resultado;
	resultado = num1 - num2;
	return resultado;
}

int producto(int num1, int num2)
{
	int resultado;
	resultado = num1 * num2;
	return resultado;
}

float division(int num1, int num2)
{
	float resultado;
	if (num2 == 0)
	{
		resultado = -1;
	}
	else
	{
		resultado = (float) num1 / num2;
	}

	return resultado;
}

int factorial(int n)
{
	int respuesta;
	if (n <= 0)
	{
		respuesta = -1;
		return respuesta;
	}
	if (n == 1)
	{
		return 1;
	}
	else
	{
		respuesta = n * factorial(n - 1);
		return respuesta;
	}
}

