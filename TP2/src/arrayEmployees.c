#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"
#include "Validaciones.h"

void mostrarPersona(eEmployee unaPersona)
{
	printf("\n %4d %10s %10s %10.2f %5d\n", unaPersona.id, unaPersona.name,
			unaPersona.lastName, unaPersona.salary, unaPersona.sector);
}

int printEmployees(eEmployee baseDeDatos[], int length)
{
	int error = 1;
	int flag;
	system("cls");
	printf("================BASE DE DATOS=================\n\n"
			"ID       Nombre     Apellido   Salario  Sector\n"
			"----------------------------------------------\n");

	if (baseDeDatos != NULL && length > 0)
	{
		for (int i = 0; i < length; i++)
		{
			if (baseDeDatos[i].isEmpty == 1)
			{
				mostrarPersona(baseDeDatos[i]);
				flag = 1;
			}
		}

		if (flag == 0)
		{
			printf("No hay empleados en la nomina.");
		}

		printf("\n\n");
		error = 0;
	}
	return error;
}

int sortEmployees(eEmployee baseDeDatos[], int length)
{

	int respuesta = -1;

	printf("======== Seleccionar tipo de ordenamiento =========== "
			"\n\n1. Ascendente\n2. descendente"
			"\n\nElija la opcion segun el numero correpondiente:");

	scanf("%d", &respuesta);

	if (respuesta == 1)
	{
		ordenAscendente(baseDeDatos, length);
		respuesta = 1;
	}
	else
	{
		if (respuesta == 2)
		{
			ordenDescendente(baseDeDatos, length);
			respuesta = 1;
		}
		else
		{

			printf("[ERROR] Opción ingresada invalida. ");
		}
	}

	return respuesta;

}

void ordenAscendente(eEmployee baseDeDatos[], int length)
{
	eEmployee auxiliarBaseDeDatos;

	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if ((strcmp(baseDeDatos[i].lastName, baseDeDatos[j].lastName)) > 0)
			{
				auxiliarBaseDeDatos = baseDeDatos[i];
				baseDeDatos[i] = baseDeDatos[j];
				baseDeDatos[j] = auxiliarBaseDeDatos;
			}
			else
			{
				if ((strcmp(baseDeDatos[i].lastName, baseDeDatos[j].lastName))
						== 0)
				{
					if (baseDeDatos[i].sector > baseDeDatos[j].sector)
					{
						auxiliarBaseDeDatos = baseDeDatos[i];
						baseDeDatos[i] = baseDeDatos[j];
						baseDeDatos[j] = auxiliarBaseDeDatos;
					}
				}
			}
		}
	}

}

void ordenDescendente(eEmployee baseDeDatos[], int length)
{
	eEmployee auxiliarBaseDeDatos;

	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if ((strcmp(baseDeDatos[i].lastName, baseDeDatos[j].lastName)) < 0)
			{
				auxiliarBaseDeDatos = baseDeDatos[i];
				baseDeDatos[i] = baseDeDatos[j];
				baseDeDatos[j] = auxiliarBaseDeDatos;
			}
			else
			{
				if ((strcmp(baseDeDatos[i].lastName, baseDeDatos[j].lastName))
						== 0)
				{
					if (baseDeDatos[i].sector < baseDeDatos[j].sector)
					{
						auxiliarBaseDeDatos = baseDeDatos[i];
						baseDeDatos[i] = baseDeDatos[j];
						baseDeDatos[j] = auxiliarBaseDeDatos;
					}
				}
			}
		}
	}
}

int initEmployees(eEmployee baseDeDatos[], int lenght)
{

	int error = -1;
	if (baseDeDatos != NULL && lenght > 0)
	{
		for (int i = 0; i < lenght; i++)
		{
			baseDeDatos[i].isEmpty = 0;
		}
		error = 0;
	}
	return error;
}

int buscarLibre(eEmployee baseDeDatos[], int length)
{
	int indice = -1;

	for (int i = 0; i < length; i++)
	{
		if (baseDeDatos[i].isEmpty == 0)
		{
			indice = i;
			break;
		}
	}
	return indice;
}

int addEmployees(eEmployee baseDeDatos[], int length, int firstId)
{
	int error = -1;
	int indice;
	eEmployee newEmployee;
	char continuar;

	system("cls");

	do
	{
		if (baseDeDatos != NULL && length > 0 && firstId > 0)
		{
			indice = buscarLibre(baseDeDatos, length);
			if (indice == -1)
			{
				printf("El sistema esta completo.\n");
			}
			else
			{
				system("cls");
				printf("======== INGRESO DE DATOS ===========\n\n");
				newEmployee.id = indice + firstId;
				newEmployee.isEmpty = 1;
				printf("%d", indice);

				pedirValidarCadena(newEmployee.name, TAMC, "INGRESE NOMBRE: ");
				pedirValidarCadena(newEmployee.lastName, TAMC,
						"INGRESE APELLIDO: ");
				newEmployee.salary = pedirFloatPositivo("INGRESE SALARIO: ");
				newEmployee.sector = pedirIntPositivo("INGRESE SECTOR: ");

				baseDeDatos[indice] = newEmployee;
				error = 0;
			}

			printf("\n\nContinuar cargando datos? S / N \n");
			fflush(stdin);
			scanf("%c", &continuar);
			continuar = toupper(continuar);
		}
	} while (continuar == 'S');

	if (error == 0)
	{
		printf("\n[CARGA DE DATOS EXITOSA]\n");
	}
	else
	{
		printf("\n[ERROR: Problemas en la carga de datos.]\n");
	}

	return error;
}

int findEmployeeById(eEmployee baseDeDatos[], int length, int id)
{
	int indice = -1;

	printf("Ingrese legajo buscado: ");
	scanf("%d", &id);
	for (int i = 0; i < length; i++)
	{
		if (baseDeDatos[i].id == id && baseDeDatos[i].isEmpty == 1)
		{
			indice = i;
			break;
		}
	}

	return indice;
}

int removeEmployee(eEmployee baseDeDatos[], int length, int id)
{
	int error = 1;
	int indice;
	char confirma;
	char reintetar;

	do
	{
		if (baseDeDatos != NULL && length > 0)
		{
			system("cls");
			printf("*************** BAJA DE PERSONA ***************\n\n");
			printEmployees(baseDeDatos, length);
			indice = findEmployeeById(baseDeDatos, length, id);

			if (indice == -1)
			{
				printf("No existe una persona con ese legajo\n\n");
			}
			else
			{
				system("cls");
				printf("======== DATOS DE LA PERSONA A ELIMINAR =====\n\n"
						" ID       Nombre     Apellido   Salario  Sector\n"
						"----------------------------------------------");
				mostrarPersona(baseDeDatos[indice]);
				printf("\nConfirmar baja: S / N\n");
				fflush(stdin);
				confirma = getchar();
				confirma = toupper(confirma);
				if (confirma == 'S')
				{
					baseDeDatos[indice].isEmpty = 2;
					error = 0;
				}
				else
				{
					printf("\n\n La baja se ha cancelado por el usuario...");
					error = 2;
				}
			}
		}
		printf("\nDar de baja con otro ID? S / N\n");
		fflush(stdin);
		reintetar = getchar();
		reintetar = toupper(reintetar);
	} while (reintetar == 'S');

	return error;
}

int menu(int flag)
{
	int opcion = 0;
	printf("========= MENU DE OPCIONES ==========\n\n1. ALTAS\n"
			"2. MODIFICAR \n"
			"3. BAJA\n"
			"4. INFORMAR\n"
			"5. SALIR\n"
			"\nINGRESE LA OPCION DESEADA: ");

	scanf("%d", &opcion);

	if (flag == 0)
	{
		if (opcion == 1 || opcion == 5)
		{
			return opcion;
		}
		else
		{

			if (opcion == 2 || opcion == 3 || opcion == 4)
			{
				printf(
						"\nPrimero deben darse datos de alta de los empleados.\n\n");
			}
			else
			{

				printf("\n[OPCION NO VALIDA.]\n\n");
				fflush(stdin);
			}

			system("pause");
			system("cls");
			return menu(flag);
		}
	}
	else
	{
		return opcion;
	}

	return opcion;

}

int modificarEmployee(eEmployee baseDeDatos[], int length, int id)
{
	int error = -1;
	int indice;
	char reintetar;
	eEmployee newEmployee;
	int opcionModificar;

	do
	{
		if (baseDeDatos != NULL && length > 0)
		{
			system("cls");
			printf("*************** MODIFICAR DATOS ***************\n\n");
			printEmployees(baseDeDatos, length);
			indice = findEmployeeById(baseDeDatos, length, id);

			if (indice == -1)
			{
				printf("No existe una persona con ese legajo\n\n");
			}
			else
			{
				system("cls");
				printf(
						"=========== DATOS ACTUALES DE LA PERSONA ===========\n\n"
								" ID       Nombre     Apellido   Salario  Sector\n"
								"----------------------------------------------");
				mostrarPersona(baseDeDatos[indice]);

				printf("\n\n======== INGRESO DE NUEVOS DATOS ===========\n\n");
				printf("Legajo: %d\n", baseDeDatos[indice].id);
				newEmployee = baseDeDatos[indice];
				printf(
						"\n\n1. Nombre\n2. Apellido\n3. Salario\n4. Sector\nIngrese opcion a modificar:");
				scanf("%d", &opcionModificar);
				switch (opcionModificar)
				{
				case 1:
					pedirValidarCadena(newEmployee.name, TAMC,
							"INGRESE NOMBRE: ");
					break;
				case 2:
					pedirValidarCadena(newEmployee.lastName, TAMC,
							"INGRESE APELLIDO: ");
					break;
				case 3:
					newEmployee.salary = pedirFloatPositivo(
							"INGRESE SALARIO: ");
					break;
				case 4:
					newEmployee.sector = pedirIntPositivo("INGRESE SECTOR: ");
					break;
				default:
					printf("Opcion ingresada no valida.");
					break;
				}
				newEmployee.isEmpty = 1;
				baseDeDatos[indice] = newEmployee;
				error = 0;
			}
		}
		printf("\nModificar otro ID? S / N \n");
		fflush(stdin);
		reintetar = getchar();
		reintetar = toupper(reintetar);

	} while (reintetar == 'S');

	return error;
}

void promedioSueldos(eEmployee baseDeDatos[], int length)
{
	float cantidadDeEmpleados = 0;
	float sueldoAcumulado;
	float promedio = -1;

	for (int i = 0; i < length; i++)
	{
		if (baseDeDatos[i].isEmpty == 1)
		{
			sueldoAcumulado = sueldoAcumulado + baseDeDatos[i].salary;
			cantidadDeEmpleados++;

		}
	}
	promedio = sueldoAcumulado / cantidadDeEmpleados;

	printf("\nEl total de los salarios equivale a : %6.2f\n", sueldoAcumulado);
	printf("\nEl promedio de los salarios equivale a : %6.2f\n", promedio);

}

float salary(eEmployee baseDeDatos[], int length)
{
	float sueldoAcumulado = 0;

	for (int i = 0; i < length; i++)
	{
		if (baseDeDatos[i].isEmpty == 1)
		{
			sueldoAcumulado = sueldoAcumulado + baseDeDatos[i].salary;
		}
	}

	return sueldoAcumulado;
}

void empleadosSueldosImportantes(eEmployee baseDeDatos[], int length)
{
	int contador = 0;
	float cantidadDeEmpleados = 0;
	float sueldoAcumulado;
	float promedio;

	for (int i = 0; i < length; i++)
	{
		if (baseDeDatos[i].isEmpty == 1)
		{
			sueldoAcumulado = sueldoAcumulado + baseDeDatos[i].salary;
			cantidadDeEmpleados++;

		}
	}

	promedio = (sueldoAcumulado / cantidadDeEmpleados);

	for (int i = 0; i < length; i++)
	{
		if (baseDeDatos[i].isEmpty == 1)
		{
			if (baseDeDatos[i].salary > promedio)
			{
				contador++;
			}
		}
	}

	printf("\nEl promedio de los salarios es superado por %4d empleados\n",
			contador);
}

