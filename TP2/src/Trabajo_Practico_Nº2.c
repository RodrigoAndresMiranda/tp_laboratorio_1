#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"

int main()
{
	setbuf(stdout, NULL);

	int firstID = 1000;
	int id = 0;
	char continuar = 'C';
	int opcionMenu;
	int flagCarga = 0;

	eEmployee baseDeDatos[MAX_NUM_EMPLEADOS]; /*= { {2232,"Juan", "Perez", 109.00,2,1},
	 {1050,"Marcos", "Alonso", 1290.00,3,1},
	 {1001,"Horacio", "Novoa", 80.00,4,1},
	 {1002,"Maria", "Ramos", 70.00,2,1},
	 {1020,"Facundi", "Ark", 150.00,5,1},
	 {1003,"Julieta", "Martinez", 380.00,2,1}
	 };*/

	/*HARCODEO DE DATOS*/

	if (initEmployees(baseDeDatos, MAX_NUM_EMPLEADOS) == 0)
	{
		printf("Base de datos inicializada exitosamente.\n\n");
		system("pause");
		system("cls");
	}
	else
	{
		printf("Error al inicializar datos");
	}

	do
	{
		system("cls");

		opcionMenu = menu(flagCarga);
		system("cls");

		switch (opcionMenu)
		{
		case 1:
			addEmployees(baseDeDatos, MAX_NUM_EMPLEADOS, firstID);
			flagCarga = system("pause");
			break;

		case 2:
			modificarEmployee(baseDeDatos, MAX_NUM_EMPLEADOS, firstID);
			system("pause");
			break;

		case 3:
			removeEmployee(baseDeDatos, MAX_NUM_EMPLEADOS, id);
			break;

		case 4:
			sortEmployees(baseDeDatos, MAX_NUM_EMPLEADOS);
			printEmployees(baseDeDatos, MAX_NUM_EMPLEADOS);
			promedioSueldos(baseDeDatos, MAX_NUM_EMPLEADOS);
			empleadosSueldosImportantes(baseDeDatos, MAX_NUM_EMPLEADOS);
			system("pause");
			break;

		case 5:
			printf("\nPARA CONFIRMAR SALIDA PRESIONE S ....");
			continuar = toupper(continuar);
			fflush(stdin);
			scanf("%c", &continuar);
			break;

		default:
			fflush(stdin);
			printf("OPCION NO VALIDA.\n");
			system("pause");
			break;
		}

	} while (continuar != 'S');

	printf("\n[PROGRAMA FINALIZADO]\n");
	system("pause");
}

