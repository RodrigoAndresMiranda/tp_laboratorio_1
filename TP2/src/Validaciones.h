#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

/** \brief PIDE UNA CADENA Y LA VALIDA
 *
 * \param variable solicitada
 * \param tamaño maximo cadena
 * \param msj con solicitud
 * \return cadena validada
 *
 */
void pedirValidarCadena(char *nombre, int tamc, char *MSJ);

/** \brief VALIDAR CADENA SOLO CARACTERES
 * \param variable solicitada
 * \return int 0 = VALIDACION OK , 1 = ERROR
 *
 */
int validarCadena(char *nombreParaValidar);

/** \brief PIDE UNA CADENA Y LA VALIDA
 *
 * \param variable solicitada
 * \param tamaño maximo cadena
 * \param msj con solicitud
 *
 */
void pedirCadena(char *nombre, int TAM, char *MSJ);

/** \brief VALIDA NUMEROS CON SIGNOS 
 *
 * \param numero char* NUMERO INGRESADO
 * \return int 0 = VALIDACION OK / 1 = ERROR
 *
 */
int validarNumeroExcluyeSignos(char *numero);

/** \brief PIDE UN NUMERO POSITIVO Y LO VALIDA
 *
 * \param MSJ const char* NUMERO INGRESADO
 * \return float NUMERO VALIDADO
 *
 */

float pedirFloatPositivo(const char *MSJ);

/** \brief PIDE UN NUMERO POSITIVO Y LO VALIDA
 *
 * \param MSJ const char* NUMERO INGRESADO
 * \return int NUMERO VALIDADO
 *
 */
int pedirIntPositivo(const char *MSJ);

#endif // VALIDACIONES_H_INCLUDED
