#ifndef MEC_H_
#define MEC_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Diagnosticos
#define ACEITE 1
#define MOTOR 2
#define SUSPENCION 3

#define SIN_ASIGNAR -1
#define ASIGNADO 0

typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct{
	int id;
	char especialidad[25];
}eEspecialidad;

typedef struct{
	int id;
	char tipo[50];
}eDiagnosticos;

typedef struct{
	int id;
	char nombre[50];
	int idEspecialidad;
}eMecanico;

typedef struct{
	int idServicio;
	char nombreCliente[50];
	eFecha fecha;
	int idDiagnostico;
	int idMecanicoEncargado;
	float cotizacion;
	int estado;
}eServicio;

//Los parametros repetitivos como listaServicios,especialidades, Mecanicos, sizeS, sizeM...etc. Solo se explicaran 1 vez, leer de forma descendente.

/// @brief Inicializa toda la listaServicios de la estructura eServicio: idServicio, idMecanicoEncargado, idDiagnostico en 0 y el estado en -1 (SIN_ASIGNAR)
/// @param listaServicios  lista servicios es el parametro de tipo eServicio donde espera recibir la lista que alberga todos los servicios inicializados y albergaran los proximos a inicializar
/// @param sizeS tamaño totañ del array de la lista listaServicios
void InicializarServicio(eServicio listaServicios[],int sizeS);

/// @brief Harcodea un par de servicios diagnosticados y uno sin diagnosticar
/// @param listaServicios
void ServicioHardcode(eServicio listaServicios[]);

/// @brief Ordena los id de los servicios de mayor a menor
/// @param listaServicios
/// @param sizeS
void OrdenarPorIdMayor(eServicio listaServicios[], int sizeS);

/// @brief Muestra la lista de todos los Mecanicos macheada con la lista de especialidades
/// @param Mecanico parametro de tipo eMecanico donde espera recibir la lista donde albergan todos los mecanicos existentes
/// @param sizeM tamaño total del array de la lista Mecanico
/// @param especialidades parametro de tipo eEspecialidad donde espera recibir la lista de especialdiades existentes
/// @param sizeE tamaño total del array de la lista de especialidades
void MostrarListaMecanicos(eMecanico Mecanico[],int sizeM,eEspecialidad especialidades[], int sizeE);

/// @brief Muestra la lista de todos los servicios existentes, esta funcion es la que se llama desde el punto en el que se quiere ver la lista
/// es dependiente de otras dos funciones CompararFKconPK y MostrarServicio, lo que hace es un for para reccorer la lista de servicios y luego llama a CompararFKconPK;
/// @param listaServicios
/// @param sizeS
/// @param Mecanico
/// @param sizeM
/// @param Diagnostico parametro de tipo eDiagnosticos donde espera recibir la lista de todos los diagnosticos existentes
/// @param sizeD tamaño total del array de la lista de Diagnosticos
void MostrarListaServicios(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD,eEspecialidad especialidades[], int sizeE);


/// @brief Esta funcion es un printf que printea un servicio, recibe el indice exacto de cada array para poder mostrar solo el contenido correspondiente a ese indice
/// @param listaServicios
/// @param Mecanico
/// @param Diagnostico
void MostrarServicio(eServicio listaServicios,eMecanico Mecanico,eDiagnosticos Diagnostico, eEspecialidad especialidades);

/// @brief Muestra la lista de todos los servicios no diagnosticados, esta funcion es la que se llama desde el punto en el que se quiere ver la lista
/// es dependiente de otras dos funciones CompararFKconPKNoDiagnosticados y MostrarServicio, lo que hace es un for para reccorer la lista de servicios y luego llama a CompararFKconPKNoDiagnosticados;
/// @param listaServicios
/// @param sizeS
/// @param Mecanico
/// @param sizeM
/// @param Diagnostico
/// @param sizeD
void MostrarServicioNoDiagnosticado(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD,eEspecialidad especialidades[], int sizeE);

/// @brief Muestra la lista de los tipos de diagnosticos existentes
/// @param Diagnostico
/// @param sizeD

/// @brief Muestra la lista de todos los servicios solo diagnosticados, esta funcion es la que se llama desde el punto en el que se quiere ver la lista
/// es dependiente de otras dos funciones CompararFKconPKDiagnosticado y MostrarServicio, lo que hace es un for para reccorer la lista de servicios y luego llama a CompararFKconPKDiagnosticado;
/// @param listaServicios
/// @param sizeS
/// @param Mecanico
/// @param sizeM
/// @param Diagnostico
/// @param sizeD
void MostrarListaServiciosDiagnosticados(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD,eEspecialidad especialidades[], int sizeE);


/// @brief Muestra la lista de mecanicos a los cuales no se les asigno un servicio, es decir estan LIBRES
/// @param listaServicios
/// @param sizeS
/// @param Mecanico
/// @param sizeM
/// @param especialidades
/// @param sizeE
void MostrarListaMecanicosSinServicios(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eEspecialidad especialidades[], int sizeE);

/// @brief Ordena todos los servicios por fecha, desde la fecha mas antigua a la mas reciente
/// @param listaServicios
/// @param sizeS
void ordenarPorFecha(eServicio listaServicios[], int sizeS);

/// @brief esta funcion pide una fecha a ingresar, una vez ingresada filtra todos los servicios que se les asigno como diagnostico cambio de aceite en la fecha seleccionada,
/// si existe muestra el total cotizado en cambio de aceite de dicha fecha, sino avisa su inexistencia
/// @param listaServicios
/// @param sizeS
void ColocarFechaCambioAceiteCotizacion(eServicio listaServicios[],int sizeS);

/// @brief realiza y Muestra la cotizacion promedio de cada mecanico en funcion del total cotizado por cada uno
/// @param listaServicios
/// @param sizeS
/// @param Mecanico
/// @param sizeM
void CotizacionPromedioDeMecanico(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM);

/// @brief Realiza un calculo donde obtiene la  cantidad de diagnosticos realizado por un mecanico, compara y obtiene cual es la mayor cantidad
/// en funciona esa cantidad maxima de diagnosticos muestra el mecanico con la mayor cantidad de diagnosticos, o los mecanicos en caso de poseer
/// el maximo mas de uno.
/// @param listaServicios
/// @param sizeS
/// @param Mecanico
/// @param sizeM
void MecanicosConMayorDiagnosticos(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM);

/// @brief Ordena alfabeticamente las especialidades existentes  y llama  a MostrarServiciosMasEspecilidadesOrdenadas
/// @param listaServicios
/// @param sizeS
/// @param Mecanico
/// @param sizeM
/// @param Diagnostico
/// @param sizeD
/// @param especialidades
/// @param sizeE
void listarOrdenarPorEspecialidad(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD,eEspecialidad especialidades[], int sizeE);

/// @briefen funcion a este ordenamiento de la funcion listarOrdenarPorEspecialidad  muestra todas las listas de servicios, en caso de no exisitir un servicio diagnosticado
/// es decir que no posee un mecanico asignado y esto conlleva a no poder ordenarlo con este criterio,
/// lo que hace es separar la lista en servicios diagnosticados y los muestra ordenados y no diagnosticados que los muestra ultimos y separados al resto.
/// @param listaServicios
/// @param sizeS
/// @param Mecanico
/// @param sizeM
/// @param Diagnostico
/// @param sizeD
/// @param especialidades
/// @param sizeE
void MostrarServiciosMasEspecilidadesOrdenadas(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD,eEspecialidad especialidades[], int sizeE);

/// @brief Pide seleccionar una de las especialidades existentes, en base a esta especialidad filtra todos los servicios realizados en el mes de Mrzo a Mayo de 2022
/// cuales fueron o seran realizados por la especialdiad elegida, si no existen dichos servicios lo avisara.
/// @param listaServicios
/// @param sizeS
/// @param Mecanico
/// @param sizeM
/// @param Diagnostico
/// @param sizeD
/// @param especialidades
/// @param sizeE
void ServicosMarzoMayo2022Especialidades(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD,eEspecialidad especialidades[], int sizeE);

/// @brief Calcula la cantidad total de servicios diagnosticados existentes y asi sabe el 100% de estos, en base a esto, calcula la cantida de servicios diagnosticados que posee cada mecanico
/// con este criterio calcula el porcentaje correspondiente de diagnosticos de cada mecanico en funcion del total de diagnosticos, y los muestra
/// @param listaServicios
/// @param sizeS
/// @param Mecanico
/// @param sizeM
/// @param especialidades
/// @param sizeE
void PorcentajeDiagnosticosDeCadaMecanico(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eEspecialidad especialidades[],int sizeE);

//----------------------------- FUNCIONES QUE RETORNA ----------------------------------------------------------------------------------------------------------------------------------------------------------

/// @brief Esta funcion Busca la existencia de un espacio libre dentro del array listaServicios que es recibido por el parametro llamado del mismo nombre, recorre los indices del array preguntado si el estado es
/// igual a -1
/// @param listaServicios
/// @param sizeS
/// @return retorna el primer indice del array anteriormente mencionado donde se encontro que el estado era  -1, sino devuelve -1 que (indica que no hay espacio libre)
int BuscarEspacioLibre(eServicio listaServicios[], int sizeS);

/// @brief Busca espacios ocupados dentro del array de listaServicios, es similar a BuscarEspacioLibre, solo que cambia la condicion, en vez de preguntar si el estado es igual a -1, pregunta si el estado es igual a 0
/// esto indica que dicho indice del array esta ocupado.
/// @param listaServicios
/// @param sizeS
/// @return devuelve el indice del primer espacio ocupado que se encontro dentro del array anteriormente mencionado, sino devuelve -1
int BuscarEspacioOcupado(eServicio listaServicios[], int sizeS);

/// @brief Esta funcion que se llama desde el main se encarga de, junto a otras funciones cargar un nuevo servicio
/// @param listaServicios
/// @param sizeS
/// @return devuelve si existe la posibilidad de realizar dicha operacion, es decir devuelve -1 si no es posible, y si lo es devuelve un indice de memoria de listaServicios (Esto lo hace llanando a BuscarEspacioLibre)
int AltaServicio(eServicio listaServicios[],int sizeS);

/// @brief Genera un id nuevo en base al id mayor existente, es decir si existe el id 1, 3, 4, 100 toma el id 100 le suma 1 y genera el id 101
/// @param listaServicios
/// @param sizeS
/// @return devuelve un nuevo id
int GeneradorId(eServicio listaServicios[], int sizeS);

/// @brief Esta funcion imprime la lista de los mecanicos existentes, pide ingresar el id de uno de ellos y valida su coincidencia
///
/// @param Mecanico
/// @param sizeM
/// @param especialidades
/// @param sizeE
/// @return devuelve el id del mecanico seleccionado
int DefinirMecanico(eMecanico Mecanico[],int sizeM,eEspecialidad especialidades[], int sizeE);

/// @brief Verifica la existencia de un servicio existente y Diagnosticado con la funcion BuscarEspacioOcupadoMasServicioDiagnosticado, en base a la respuesta
/// realiza las operaciones para modificar los servicios, despliega la lista de servicios que cumplen con la caracteristica de estar diagnosticados, pide el id de uno de ellos
/// valida su coincidencia y luego despliega un menu donde da las opciones de cambiar nombre del cliente, fecha del servicio,  mecanico asignado y salir al menu principal.
/// en base a lo seleccionado se realiza la operacion correspondiente
/// @param listaServicios
/// @param sizeS
/// @param Mecanico
/// @param sizeM
/// @param Diagnostico
/// @param sizeD
/// @param especialidades
/// @param sizeE
/// @return retorna -1 si no es posible realizar la operacion y si se puede retorna un numero correspondiente al indice del array listaServicios devuelto por BuscarEspacioOcupadoMasServicioDiagnosticado
int ModificarServicio(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD,eEspecialidad especialidades[], int sizeE);

/// @brief pide selecionar un servicio segun su id y verifica su coincidencia
/// @param listaServicios
/// @param sizeS
/// @return devuelve el id del servicio selecionado
int BuscarServicioPorId(eServicio listaServicios[], int sizeS);

/// @brief  pide selecionar un servicio segun su id y verifica su coincidencia
///
/// @param listaServicios
/// @param sizeS
/// @returndevuelve el id del servicio selecionado
int BuscarServicioPorIdSinDiagnosticar(eServicio listaServicios[], int sizeS);

/// @brief Verifica si existe la posibilidad de dar de baja un servicio llamando a BuscarServicioOpcupado, si es distinto a -1 lo que devuelve la anterior funcion realiza la operacion,
/// esta operacion se realiza pidiendo primero en base a una lista de servicios el id de uno de ellos, una vez obtenido da de baja el servicio de forma logica solo cambiandole el estado de 0 a -1
/// @param listaServicios
/// @param sizeS
/// @param Mecanico
/// @param sizeM
/// @param Diagnostico
/// @param sizeD
/// @return devuelve -1 si no se puede realizar la operacion, en caso de poder devuelve un idice del array listaServicios devuelto por BuscarEspacioOcupado
int BajaDeServicio(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD,eEspecialidad especialidades[], int sizeE);

/// @brief Verifica la existencia de servicios y servicios sin diagnosticar llamando a BuscarEspacioOcupadoSinDiagnosticar, si existen servicios, pide el id de un mecanico luego filtra la lista de servicios sin diagnosticar,
/// y pide el id de uno de los servicios, una vez teniendo el id del mecanico y el servicio despliega una lista de diagnosticos, pide seleccionar el id de uno de los diagnosticos y lo carga en la listaServicios.idDiagnostico, tambien
/// pide la cotizacion del mismo y carga la cotizacion y el id del mecanico en la listaServicios.cotizacion y listaServicios.idMecanicoEncargado del servicio seleccionado anteriormente por el id
/// @param listaServicios
/// @param sizeS
/// @param Mecanico
/// @param sizeM
/// @param Diagnostico
/// @param sizeD
/// @param especialidades
/// @param sizeE
/// @return retorna -1 si no se puede realizar la operacion, en caso de poder devuelve un idice del array listaServicios devuelto por BuscarEspacioOcupadoSinDiagnosticar
int Diagnosticar(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD,eEspecialidad especialidades[], int sizeE);
/// @brief  Al igual que BuscarEspacioOcupado busca un espacio ocupado dentro del array listaServicios solo que en este caso agrega como condicion que el servicio
/// no este diagnosticado es decir listaServicios.idDiagnostico sea menor a 1
/// @param listaServicios
/// @param sizeS
/// @return devuelve -1 si no se encontro ningun servicio que cumpla la condicion, sino devuelve el indice del primer servicio que cumple dicha condicion.
int BuscarEspacioOcupadoSinDiagnosticar (eServicio listaServicios[], int sizeS);

/// @brief muestra una lista de servicios sin diagnosticar, pide el id de uno de los servicios y verifica su coincidencia
/// @param listaServicios
/// @param sizeS
/// @param Mecanico
/// @param sizeM
/// @param Diagnostico
/// @param sizeD
/// @return retorna el id seleccionado
int BuscarServicioSinDiagnosticarPorId(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD,eEspecialidad especialidades[], int sizeE);

/// @brief esta funcion despliega una lista de diagnosticos disponibles, pide seleccioanr uno y verefica su coincidencia
///
/// @param Diagnostico
/// @param sizeD
/// @return devuelve el id del diagnostico seleccionado
int CargarDiagnostico(eDiagnosticos Diagnostico[],int sizeD);

/// @brief hace los mismo que BuscarEspacioOcupado solo que añade la condicion de que el servicio este diagnosticado
/// @param listaServicios
/// @param sizeS
/// @return devuelve -1 si no se encontro ningun servicio que cumpla la condicion, sino devuelve el indice del primer servicio que cumple dicha condicion.
int BuscarEspacioOcupadoMasServicioDiagnosticado(eServicio listaServicios[], int sizeS);

/// @brief Un submenu correspondiente a la opcion LISTAR del menu principal, esta funcion antes de  desplegar el menu verifica la existencia de servicios dados de alta
/// llamando a BuscarEspacioOcupado, si existe se ejecuta por completo un menu parecido al principal donde hay llamado a funciones
/// @param listaServicios
/// @param sizeS
/// @param Mecanico
/// @param sizeM
/// @param Diagnostico
/// @param sizeD
/// @param especialidades
/// @param sizeE
/// @return retorna -1 si es imposible ingresar a esta opcion, sino retorna el indice devuelto por BuscarEspacioOcupado
int SubMenu(eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD,eEspecialidad especialidades[], int sizeE);

/// @brief Muestra la lista de especialdiades existentes, pide seleccioanr un id de dicha lista, y verifica que el id seleccioando coincida con los existentes
/// @param especialidades
/// @param sizeE
/// @return retoena el id de la especialidad seleccionada
int DefinirEspecialidad(eEspecialidad especialidades[], int sizeE);


/// @brief esta funcion de tipo eServicio se encarga de crear en su interior una variable de tipo eServicio donde lo que hara sera pedir y cargar todos los campos de
/// dicha variable segun la estructura
///
/// @param listaServicios
/// @param sizeS
/// @return devuelve un parametro o tipod e dato eServicio para ser almacenado en un indice en espesifico de un variable de similar tipo
eServicio CargarServicio(eServicio listaServicios[],int sizeS);

/// @brief hace el calculo de cual es la especialidad mas estudiada segun las especialidades de los mecanicos existentes, para luego mostrar un top 3
/// @param Mecanico
/// @param sizeM
/// @param especialidades
/// @param sizeE
void EspecialidadesMasEstudidadas(eMecanico Mecanico[],int sizeM,eEspecialidad especialidades[], int sizeE);

/// @brief Compara el id del mecanico asignado a la lista (fK) con el id de un mecanico existente(PK)
/// @param listaServicios
/// @param Mecanico
/// @param sizeM
/// @return devuleve el indice del mecanico que coincidio con el mecanico asigando a la lista
int CompararServicioConMecanico(eServicio listaServicios,eMecanico Mecanico[],int sizeM);

/// @brief Compara el id del diagnostico asignado a la lista (fK) con el id de un diagnostico existente(PK)
/// @param listaServicios
/// @param Diagnostico
/// @param sizeD
/// @return devuleve el indice del diagnostico que conicidio con el diagnostico asignado a la lista
int CompararServicioConDiagnosticos(eServicio listaServicios,eDiagnosticos Diagnostico[],int sizeD);

/// @brief Compara el id de la especialidad asignada a un Mecanico (fK) con el id de una especialidad existente(PK)
/// @param Mecanico
/// @param especialidades
/// @param sizeE
/// @return devuleve el indice de la especialidad que concidio con la especialidad asiganda al mecanico
int CompararMecanicoConEspecialidad(eMecanico Mecanico,eEspecialidad especialidades[], int sizeE);

/// @brief Compara el id de Mecanico (Pk) con el id del mecanico asignado a una lista existente(Fk)
/// @param Mecanico
/// @param listaServicios
/// @param sizeS
/// @return devuelve el indice del servicio cual coincidio que el mecanico asignado a dicho servicio es igual a un mecanico existente
int CompararMecanicoConServicios(eMecanico Mecanico,eServicio listaServicios[],int sizeS);

/// @brief Compara el id de una Especialidad (Pk) con el id de una especialidad asignada a un Mecanico existente(Fk)
/// @param especialidades
/// @param Mecanico
/// @param sizeM
/// @return devuelve el indice del mecanico cual coincidio que la especilidad asignado a dicho mecanico es igual a una especialidad existente
int CompararEspecialidadConMecanico(eEspecialidad especialidades, eMecanico Mecanico[], int sizeM);

/// @brief Confirma si existe un diagnostico de cambio de aceite en una fecha dada por el usuario, si existe devuelve el valor de una bandera que hace referencia a dicha existencia
/// sino devuleve un valor que hace referencia a la inexistencia de dicho servicio en la fecha dada
/// @param listaServicios
/// @param sizeS
/// @param anio anio seleccionado por el usuario
/// @param mes mes seleccionado por el usuario
/// @param dia dia seleccionado por el ususario
/// @return devuelve el valor de la bandera
int ConfirmarFechaDeCambioAceite(eServicio listaServicios[], int sizeS, int anio, int mes, int dia);

/// @brief Realiza el calculo del promedio cotizado por cada mecanico para luego mostrarlo
/// @param Mecanico
/// @param listaServicios
/// @param sizeS
void PromedioCotizacionMecanicosCalculo(eMecanico Mecanico, eServicio listaServicios[],int sizeS);

/// @brief  Recorre la lista de servicios existentes segun el indice de una especialidad cual es recibida por la funcion, para asi luego mostrarlos
/// @param especialidades
/// @param listaServicios
/// @param sizeS
/// @param Mecanico
/// @param sizeM
/// @param Diagnostico
/// @param sizeD
void RecorrerServiciosSegunEspecialidad(eEspecialidad especialidades,eServicio listaServicios[],int sizeS,eMecanico Mecanico[],int sizeM,eDiagnosticos Diagnostico[],int sizeD);

/// @brief Calcula la cantidad total de diagnosticos echos por un mecanico con un contador
/// @param Mecanico
/// @param listaServicios
/// @param sizeS
/// @return devuelve el valor del contador
int CantidadDiagnosticosDeUnMecanico(eMecanico Mecanico,eServicio listaServicios[],int sizeS);

/// @brief calcula cuantas veces una especialidad enviada a la funcion se repite en la lista de mecanicos, con un contador
/// @param especialidades
/// @param Mecanico
/// @param sizeM
/// @return devuleve el valor del contador
int ContadorEspecialidadesMecanicos(eEspecialidad especialidades,eMecanico Mecanico[],int sizeM);

/// @brief Imprime la especialidad con mayor cantidad de mecanicos relacionados, la mayor cantidad es pasada por el parametro mayorE
/// @param especialidades
/// @param sizeE
/// @param Mecanico
/// @param sizeM
/// @param mayorE Es la mayor cantidad de especialidades estudiadas anteriormente calculada
void ImprimirEspecialidadesSegunCantidad(eEspecialidad especialidades[],int sizeE,eMecanico Mecanico[],int sizeM,int mayorE);

///PRINT DE HEADER Y FOOTER DE LA LISTA PASAJEROS///
void HeaderPrintLista();
void footerPrintLista();

#endif /* SERVICIOSYMECANICOS_H_ */
