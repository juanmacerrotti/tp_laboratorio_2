/*
 ============================================================================
 Name        : tp2.c
 Author      : JUAN
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Employee.h"

#define EMPLEADOS 999
int main(void) {

	setbuf (stdout,NULL);

	Employee ArrayEmpleados [EMPLEADOS];
	int auxiliarIndice;
	int opcion;
	int idEmpleado;
	int auxiliarId;
	float acumuladorSalarios=0;
	float promedioSalarios;
	int opcionInformes;
	int EmpleadosConSueldoPromedio;
	int flagCasos=1;

	employee_initArray (ArrayEmpleados,EMPLEADOS);

	do
	{

		if (utn_getNumero (&opcion,"1.ALTAS \n2.MODIFICAR \n3.BAJAS \n4.INFORMAR \n5.SALIR \n","Error no es una opcion\n",1,5,3) ==0)
		{
			switch(opcion)
			{
			case 1: //ALTAS
				flagCasos=0;
				auxiliarIndice = employee_getEmptyIndex(ArrayEmpleados,EMPLEADOS); //busca indice vacio del array.
				if(auxiliarIndice >= 0 &&
					employee_addEmployee(ArrayEmpleados,EMPLEADOS,auxiliarIndice,&idEmpleado) ==0)  //funcion que añade un empleado nuevo y le asigna un ID automaticamente.
				{
						printf("Carga OK.\n \n");
				}
				else
				{
					printf("\nNo Hay mas lugar.\n");
				}
				break;
			case 2:  //MODIFICACION.
				if(flagCasos == 0)
				{
					employee_printEmployee(ArrayEmpleados,EMPLEADOS);  //imprimo array.

					if(utn_getNumero(&auxiliarId,"Indique el ID del empleado a modificar:\n","ID invalido\n",0,999,2) == 0)
					{
						auxiliarIndice= employee_findEmployeeById (ArrayEmpleados,EMPLEADOS,auxiliarId); //busco el empleado por su ID y doy la posicion en el Array.

						if(employee_modifEmployee (ArrayEmpleados,EMPLEADOS,auxiliarIndice,auxiliarId) == 0) //llama a la funcion de modificacion y en caso de exito imprime mensaje de OK.
						{
							printf("Modificacion realizada con exito. \n\n");
						}
						else
						{
							printf("El ID ingresado no pertenece a un empleado. \n\n");
						}
					}

				}
				else
				{
					printf("Debe dar de alta un empleado.\n");
				}
				break;


			case 3: //BAJAS
				if(flagCasos == 0)
				{
					employee_printEmployee(ArrayEmpleados,EMPLEADOS);  //imprimo array.

					if(utn_getNumero(&auxiliarId,"Indique el ID del empleado a dar de baja:\n","ID invalido\n",0,idEmpleado,0) == 0) //Se pide ingresar ID del empleado.
					{

						auxiliarIndice= employee_findEmployeeById (ArrayEmpleados,EMPLEADOS,auxiliarId); //Busco el empleado por su ID y doy la posicion en el Array.

						if(auxiliarIndice >= 0 &&
							employee_removeEmployee (ArrayEmpleados, EMPLEADOS,auxiliarId) == 0) //se llama a la funcion de remover empleado y en caso de exito da el mensaje de confirmacion.
						{
							printf ("Baja realizada con exito. \n \n"); //mensaje de confirmacion
						}
					}
				}
				else //restriccion en caso de haber dado de baja todos los ID.
				{
					printf("Debe dar de alta un empleado.\n");
				}
				if(employee_bajaTotalDeEmpleados (ArrayEmpleados,EMPLEADOS) != 0) // sirve para bloquear el menu (opcion 2,3 y 4 si dieron de baja todos los empleados)
				{
					flagCasos=1;
				}
				break;
			case 4: //INFORMES
				if(flagCasos == 0)
				{
					if (utn_getNumero (&opcionInformes,"1.LISTA DE EMPLEADOS \n2.INFORME DE SUELDOS\n","Error no es una opcion\n",1,2,2) ==0) //menu del caso 4.
					{
						switch(opcionInformes)
						{
						case 1:
							printf("Lista de empleados:\n");
							if (employee_sortEmployee (ArrayEmpleados,EMPLEADOS) == 0) //llama a la funcion de ordenamiento. en caso de existo imprime el Array.
										{
											employee_printEmployee(ArrayEmpleados,EMPLEADOS);
										}
							break;
						case 2:
							printf("Informe de sueldos:\n");
							if(employee_salarios (ArrayEmpleados,EMPLEADOS,&acumuladorSalarios,&promedioSalarios) == 0 &&   // funcion que acumula todos los salarios y da el salario promedio.
								employee_EmpleadosMasSalario (ArrayEmpleados,EMPLEADOS,promedioSalarios,&EmpleadosConSueldoPromedio) == 0)  //funcion que calcula cuantos empleados cobran mas que el promedio salarial.
								{
									printf("el total de salarios es: %.3f \nEl salario promedio es: %.3f \nLa cantidad de empleados que supera el salario promedio es: %d  \n\n",acumuladorSalarios,promedioSalarios,EmpleadosConSueldoPromedio);
								}
							break;
						}
					}
				}
				else
				{
					printf("Debe dar de alta un empleado.\n");
				}
				break;
			}
		}
	}while(opcion != 5);
	return EXIT_SUCCESS;
}
