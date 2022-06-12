/*
 ============================================================================
 Author      : Jeronimo Granadillo
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "mec.h"
#include "input.h"
#define LS 100 //longitud servicios
#define LM 8  //longitud mecanicos
#define LD 7   //longitud diagnosticos
#define LE 5  //longitud especialidades
#define SALIR 7
int main(void) {
	setbuf(stdout, NULL);
	eServicio listaServicios[LS];
	eMecanico listaMecanicos[LM]={{1,"Juan",2},{2,"Toti",4},
	    {3,"Pedro",1},{4,"Marquitos",2},{5,"Maria",3},{6,"Melisa",3},{7,"Paco",2},{0,"Sin Asignar",0}};
	eDiagnosticos tiposDiagnosticos[LD]={{ACEITE,"Cambio de aceite"},{MOTOR,"Averia en motor"},{SUSPENCION,"Averia en suspecion",},
		{0,"No diagnosticado"},{5,"Cambio de ruedas"},{6,"Alineacion y Balanceo"},{7,"Cambio de carroceria"}};
	eEspecialidad especialidades[LE]={{1,"Ayudante"},{2,"Tecnico Automotriz"},{3,"Electro mecanica"},{4,"Alineacion y Balanceo"},{0,"Sin especialidad"}};

	InicializarServicio(listaServicios,LS);
	int retorno;
	int menuOpciones;
	int banderaForzada = 0;
	do{

		menuOpciones = getIntMasIntentos("\n|--------MENU OPCIONES--------|\n"
										   "|1.Dar alta servicio-\n"
										   "|2.Modificar sevicio-\n"
										   "|3.Cancelar servicio-\n"
										   "|4.Diagnosticar-\n"
										   "|5.Listar-\n"
										   "|6.Carga forzada-\n"
										   "|7.Salir-\n"
										   "|----->Elija una opcion: \n",1,SALIR,3,0);
		switch(menuOpciones)
		{
		case 1:
			retorno = AltaServicio(listaServicios,LS);
			if(retorno == -1)
			{
              printf("No hay esapcio para cargar un nuevo servicio\n");
			}
		break;
		case 2:
			retorno = ModificarServicio(listaServicios,LS,listaMecanicos,LM,tiposDiagnosticos,LD,especialidades,LE);
			if(retorno == -1)
			{
			  printf("No hay servicios dados de alta o Servicios diagnosticados para modificar\n");
			}
		break;
		case 3:
			retorno = BajaDeServicio(listaServicios,LS,listaMecanicos,LM,tiposDiagnosticos,LD,especialidades,LE);
			if(retorno == -1)
			{
			  printf("No hay servicios dados de alta para dar de baja\n");
			}
		break;
		case 4:
			retorno = Diagnosticar(listaServicios,LS,listaMecanicos,LM,tiposDiagnosticos,LD,especialidades,LE);
			if(retorno == -1)
			{
			  printf("No hay servicios dados de alta o sin diagnosticar para realizar esta operacion\n");
			}
		break;
		case 5:
			retorno = SubMenu(listaServicios,LS,listaMecanicos,LM,tiposDiagnosticos,LD,especialidades,LE);
			if(retorno == -1)
			{
			  printf("No hay servicios dados de alta para accder a esta opcion\n");
			}
		break;
		case 6:
			if(banderaForzada == 0 && BuscarEspacioOcupado(listaServicios,LS) == -1)
			{
				ServicioHardcode(listaServicios);
				banderaForzada = 1;
				printf("Carga forzada realizada\n");
			}
			else
			{
				if(banderaForzada == 1)
				{
                   printf("Solo se puede hacer una carga forzada de datos\n");
				}
				else
				{
					printf("Si existen datos cargados no se puede realizar una carga forzada\n");
				}
			}
		break;
		case 7:
			printf("Hasta luego!\n");
		break;
			}
		}while(menuOpciones != SALIR);
	return EXIT_SUCCESS;
}
