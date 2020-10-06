#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
#define MAX_NUM_EMPLEADOS 1000
#define TAMC 51

typedef struct
{
	int id;
	char name[TAMC];
	char lastName[TAMC];
	float salary;
	int sector;
	int isEmpty; // 1 esta vacia 0 esta llena

} eEmployee;

/** \brief AGREGA UN NUEVO EMPLEADO A LA NOMINA
 * \param  Estructura del array
 * \param  Tamaño de la base de datos
 * \param  Primer legajo a asignar
 * \return -1 = ERROR , 0 = carga exitosa.
 */
int addEmployees(eEmployee baseDeDatos[], int length, int firstId);

/**\brief MUESTRA LA NOMINA DE EMPLEADOS
 * \param  Estructura del array
 * \param  Tamaño de la base de datos
 * \param  Bandera carga de datos
 * \return -1 = ERROR , 0 = carga exitosa.
 *
 */
int printEmployees(eEmployee baseDeDatos[], int length);

/** \brief MUESTRA UNA PERSONA
 * \param  Vector buscado del array
 *
 */
void mostrarPersona(eEmployee unaPersona);

/** \brief ORDENA LA NOMINA SEGUN APELLIDO Y SECTOR, EN ORDEN ASCENDENTE O DESCENDENTE
 * \param  Estructura del array
 * \param  Tamaño de la base de datos
 * \return 0
 *
 */
int sortEmployees(eEmployee baseDeDatos[], int length);

/** \brief ORDENA LA NOMINA SEGUN APELLIDO Y SECTOR, EN ORDEN ASCENDENTE
 * \param  Estructura del array
 * \param  Tamaño de la base de datos
 *
 */
void ordenAscendente(eEmployee baseDeDatos[], int length);

/** \brief ORDENA LA NOMINA SEGUN APELLIDO Y SECTOR, EN ORDEN DESCENDENTE
 * \param  Estructura del array
 * \param  Tamaño de la base de datos

 */
void ordenDescendente(eEmployee baseDeDatos[], int length);

/** \brief INICIALIZAR BASE DE DATOS
 * \param  Estructura del array
 * \param  Tamaño de la base de datos
 * \return -1 = ERROR , 0 = carga exitosa.

 */
int initEmployees(eEmployee baseDeDatos[], int lenght);

/** \brief BUSCA EL PRIMER ESPACIO LIBRE DENTRO DEL ARRAY
 * \param  Estructura del array
 * \param  Tamaño de la base de datos
 * \return -1 = ERROR , 0 = carga exitosa.
 *
 */
int buscarLibre(eEmployee baseDeDatos[], int length);

/** \brief BUSCA UN EMPLEADO POR ID
 * \param  Estructura del array
 * \param  Tamaño de la base de datos
 * \param  id de la persona buscada
 * \return indice dentro del la persona buscada por id
 *
 */
int findEmployeeById(eEmployee baseDeDatos[], int length, int id);

/** \brief ELIMINA A UN EMPLEADO DE LA NOMINA
 * \param  Estructura del array
 * \param  Tamaño de la base de datos
 * \param  id de la persona buscada
 * \return indice dentro del la persona buscada por id
 *
 */
int removeEmployee(eEmployee baseDeDatos[], int leghth, int id);

/** \brief MENU DE INICIO
 * \param Bandera de carga de datos inicial.
 * \return Opcion seleccionada.
 *
 */
int menu(int flag);

/** \brief MODIFICA DATOS DE UN EMPLEADO
 * \param  Estructura del array
 * \param  Tamaño de la base de datos
 * \param ID de la persona buscada
 * \return -1 = ERROR , 0 = carga exitosa.
 *
 */
int modificarEmployee(eEmployee baseDeDatos[], int length, int id);

/** \brief CALCULA EL PROMEDIO DE LOS SUELDOS
 *
 * \param  Estructura del array
 * \param  Tamaño de la base de datos
 * \return Promedio final de sueldos dentro de la nomina
 *
 */
void promedioSueldos(eEmployee baseDeDatos[], int length);

/** \brief SUMATORIA DE SUELDOS
 * \param  Estructura del array
 * \param  Tamaño de la base de datos

 *
 */
float salary(eEmployee baseDeDatos[], int length);

/** \brief CALCULO DE SUELDOS QUE SUPERAN EL PROMEDIO
 * \param  Estructura del array
 * \param  Tamaño de la base de datos
 *
 */
void empleadosSueldosImportantes(eEmployee baseDeDatos[], int length);

#endif // ARRAYEMPLOYEES_H_INCLUDED

