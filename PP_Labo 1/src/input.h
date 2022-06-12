#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// @brief recibe un mensaje del cual extrae un entero validad y ademas limita la cantidad de errores
/// @param mensaje mensaje que recibe de donde extraera el entero
/// @param minimo recibe un minimo para validar
/// @param maximo recibe un maximo para validar
/// @param intentos recibe cantidad de intentos que el usuario tendra
/// @param defaultInt recibe un valor default que devolvera en caso de superar el numero de intentos
/// @return devuelve el entero validado
int getIntMasIntentos(char mensaje[], int minimo, int maximo, int intentos,int defaultInt);

/// @brief recibe un mensaje del cual extrae un entero validado
/// @param mensaje mensaje que recibe de donde extraera el entero
/// @param minimo recibe un minimo para validar
/// @param maximo recibe un maximo para validar
/// @return devuelve el entero validado
int getInt(char mensaje[], int minimo, int maximo);

/// @brief Valida una cadena de caracteres
/// @param mensajeRecibido la cadena de caracteres a validar
/// @param maximo maximo de longitud que puede poseer dicha cadena
/// @return devuelve la cadena validada
int ValidacionString(char mensajeRecibido[], int maximo);

/// @brief Se encarga de pasarle un maximo de largo a una cadena de caracteres, esat cadena de caracteres recibira un maximo espesifico relacionado
/// a la cantidad de digitos que puede tener un entero, es principalmente una funcion echa para pasarle un maximo de largo a la funcion de validar cadena
/// asi la cadena que se valida luego se puede pasar a un entero
/// @param maximoNumero
/// @return devuelve el maximo de caracteres que pueden poseer la cadena
int MaximoStringInt(int maximoNumero);

/// @brief recibe un mensaje del cual extrae un dato decimal o flotante validado
/// @param mensaje mensaje de donde extrae le floatnte
/// @param minimo minimo valor a validar para el flotante
/// @param maximo maximo valor a valdiar para el flotante
/// @return devuelve el flotante validado
float getFloat(char mensaje[], int minimo, int maximo);

/// @brief Obtiene de un mensaje una cadena de caracteres
/// @param mensajeCargado variable de tipo array que se pasa por parametro donde se guardara la cadena de caracteres
/// @param mensaje mensaje de donde se extrae dicha cadena
/// @param maximo maximo de longitud que puede poseer la cadena
void getString(char mensajeCargado[], char mensaje[], int maximo);

/// @brief Obtiene un nombre y valida que solo entren caracteres de (a - z) o (A- Z)
/// @param mensajeCargado variable de tipo array que se pasa por parametro donde se guardara la cadena de caracteres
/// @param mensaje mensaje de donde se extrae dicha cadena
/// @param maximo maximo de longitud que puede poseer la cadena
void getName(char* mensajeCargado, char* mensaje, int maximo);

/// @brief recibe un array donde en teoria alberga un nombre o apellido, convierte  todas las letas de ese array en letras minusculas
/// convierte la letra del indice 0 del array en una letra mayuscula
/// verifica si ubo saltos de linea para apenas encontrar uno pasar a letra mayuscula la proxima letra, esto sirve si se ingresan un doble nombre ej 'PEPE FERNANDO'
/// esta funcion toma el nombre y lo combierte en 'Pepe Fernando'
/// @param modificar es el array de caracteres a modificar
void TrasnsformarNombres(char modificar[]);

/// @brief Valida que le dia perteneciente al mes seleccionado previamente exista en el calendario convencional
/// @param mes se le pasa el mes (anteriormete pedido y validado)
/// @return devuelve el dia validado segun el mes
int ValidarDiaFecha(int mes);

/// @brief analiza todos los caracteres de un array y pasa a mayuscula todos los caracteres correspondientes al abecedario en minuscula
/// @param codigo array de caracteres
void Set_CodigosMayus(char* codigo);

/// @brief Valida si un string donde se espera albergar una array de numeros, alberga numeros del 0 al 9
/// @param num array a validar
/// @return isOk si retorna -1 es que hay un caracter que no es un numero si devuleve 0 es que son todos numeros
int EsNumerica(char* num);

/// @brief  valida los nombres, reccorre el array donde alberga un "nombre o apellido" y valida que todos los caracteres pertenezcan al abecedario
/// tanto en minuscula como en mayuscula, tambien valida que la posicion 0 del array no sea un espacio
/// @param nombre array a validar
/// @return isOk si retorna -1 es que hay un caracter que no cumplen con la condicion si devuleve 0 es que si cumplen la condicion
int esUnNombre(char* nombre);
#endif /* FUNCIONESINPUTVALIDACIONES_H_ */

