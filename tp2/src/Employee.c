/*
 * Employee.c
 *
 *  Created on: 26 abr. 2020
 *      Author: Juan
 */

#define NAME_LEN 51
#define LASTNAME_LEN 51
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Employee.h"


/**
 * \brief Inicializa el array de empleados para que esten todos vacios.
 * \param ArrayEmpleados para ser actualizado
 * \param limite Limite del array de empleados
 * \return retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int employee_initArray(Employee* ArrayEmpleados,int len)
{
	int retorno = -1;
	int i;

	if(ArrayEmpleados != NULL && len > 0)
	{
		retorno = 0;
		for(i=0;i<len;i++)
		{
			ArrayEmpleados[i].isEmpty = 1;
		}
	}
	return retorno;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int employee_getEmptyIndex(Employee* arrayEmployee,int len)
{
	int respuesta = -1;
	int i;
	if(arrayEmployee != NULL && len > 0)
	{
		respuesta = 0;
		for(i=0;i<len;i++)
		{
			if(arrayEmployee[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief añade un nuevo empleado a la lista.
 * \param ArrayEmpleados para ser actualizado
 * param tamaño del array.
 * param indice
 * param id del empleado
 * param char[] con el nombre del empleado
 * param char [] con el apellido
 * param float salario.
 * param int de sector donde trabaja.
 * \return retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int employee_addEmployee(Employee* ArrayEmpleados, int len,int indice, int* id)
{
	int retorno= -1;

	Employee auxEmpleados;

	if(ArrayEmpleados != NULL && len>0 && indice >= 0 && id != NULL)
	{
		if(
				utn_getNombre(auxEmpleados.name, NAME_LEN,"ingrese el nombre:\n", "Error en nombre.\n", 2) == 0 &&
				utn_getNombre(auxEmpleados.lastName, LASTNAME_LEN,"ingrese el apellido:\n","Error en apellido.\n", 2) == 0 &&
				utn_getNumeroFlotante(&auxEmpleados.salary,"Ingrese el salario del empleado: \n","Salario es invalido\n",0.01,1000000,2) == 0 &&
				utn_getNumero(&auxEmpleados.sector, "ingrese el sector del empleado: \n", "Sector incorrecto", 1, 999, 2) == 0)
		{
			auxEmpleados.id = *id;
			auxEmpleados.isEmpty = 0;
			ArrayEmpleados[indice] = auxEmpleados;
			(*id)++;
			retorno = 0;
		}
	}

	return retorno;
}

int employee_modifEmployee(Employee* ArrayEmpleados, int len,int indice, int id)
{
	int retorno= -1;
	int opcion;

	Employee auxEmpleados;

	if(ArrayEmpleados != NULL && len>0 && indice >= 0 && id >=0 && ArrayEmpleados[indice].isEmpty == 0)
	{
		utn_getNumero (&opcion,"Ingrese que opcion desea modificar: \n1.Nombre\n2.Apellido\n3.Salario\n4.sector", "Error, respuesta no valida.\n",1,4,2);
		switch (opcion)
		{
						case 1:
						utn_getNombre(auxEmpleados.name, NAME_LEN,"ingrese nuevo nombre:\n", "Error en nombre.\n", 2);
						strcpy(ArrayEmpleados[indice].name,auxEmpleados.name);
						break;

						case 2:
						utn_getNombre(auxEmpleados.lastName, LASTNAME_LEN,"ingrese nuevo apellido:\n","Error en apellido.\n", 2);
						strcpy(ArrayEmpleados[indice].lastName,auxEmpleados.lastName);
						break;

						case 3:
						utn_getNumeroFlotante(&auxEmpleados.salary,"Ingrese la modificacion de salario del empleado: \n","Salario es invalido\n",0.01,1000000,2);
						ArrayEmpleados[indice].salary=auxEmpleados.salary;
						break;

						case 4:
						utn_getNumero(&auxEmpleados.sector, "ingrese el nuevo sector del empleado: \n", "Sector incorrecto\n", 1, 999, 2);
						ArrayEmpleados[indice].sector=auxEmpleados.sector;
						break;
		}
		retorno=0;
	}

	return retorno;
}

/**
 * \brief busca un empleado recibiendo como parametro su ID
 * param array de empleados
 * param tamaño del array
 * param id del empleado.
 * \return retorna 0 (EXITO) y -1 (ERROR)
 */
int employee_findEmployeeById (Employee* ArrayEmpleados, int len, int id)
{
	int i;
	int retorno = -1;

	if(ArrayEmpleados != NULL && len >0 && id >= 0)
	{
		for(i=0;i<len;i++)
		{
			if(ArrayEmpleados[i].id == id)
			{
				retorno = i;
				break;
			}
		}

	}
	return retorno;
}

/**
 * \brief remueve (logicamente) un empleado de la lista, recibiendo como parametro su ID
 * param array de empleados
 * param tamaño del array
 * param id del empleado.
 * \return retorna 0 (EXITO) y -1 (ERROR)
 */
int employee_removeEmployee(Employee* ArrayEmpleados, int len, int id)
{
	int i;
	int retorno=-1;

	if(ArrayEmpleados != NULL && len >0 && id >=0)
	{
		retorno=0;
		for(i=0;i<len;i++)
		{
			if(ArrayEmpleados[i].id == id)
			{
				ArrayEmpleados[i].isEmpty = 1;
			}
		}
	}
	return retorno;
}

/**
 * \brief imprime el array de empleados en forma encolumnada.
 * param array de empleados
 * param tamaño del array
 * \return retorna 0 (EXITO) y -1 (ERROR)
 */
int employee_printEmployee(Employee* arrayEmployee,int len)
{
	int respuesta = -1;
	int i;
	if(arrayEmployee != NULL && len > 0)
	{
		respuesta = 0;
		for(i=0;i<len;i++)
		{
			if(arrayEmployee[i].isEmpty != 1)
			{
				printf("\nID: %d - NOMBRE: %s - APELLIDO: %s - SALARIO: %.3f - SECTOR: %d \n",arrayEmployee[i].id,arrayEmployee[i].name,arrayEmployee[i].lastName,arrayEmployee[i].salary,arrayEmployee[i].sector);

			}
		}
	}
	return respuesta;
}

/**
 * \brief da la cantidad de empleados que cobra mas que el promedio salarial.
 * param array de empleados
 * param tamaño del array
 * param la variable del main de promedio de salarios.
 * param el puntero de la cantidad de sueldos promedio.
 * \return retorna 0 (EXITO) y -1 (ERROR)
 */
int employee_EmpleadosMasSalario (Employee* arrayEmployee,int len, float promedioSalarios, int* EmpleadosConSueldoPromedio)           //arreglar esto
{
	int retorno=-1;
	int ContadorDeEmpleados=0;
	int i;

	if(arrayEmployee != NULL && len > 0 && promedioSalarios > 0)
	{
		for(i=0;i<len;i++)
		{

			if (arrayEmployee[i].salary >= promedioSalarios && arrayEmployee[i].isEmpty == 0)
			{
				ContadorDeEmpleados++;
			}
		}
		*EmpleadosConSueldoPromedio = ContadorDeEmpleados;
		retorno=0;
	}
	return retorno;
}

/**
 * \brief acumula los salarios y da el total de salarios y promedio
 * param array de empleados
 * param tamaño del array
 * param puntero del acumulador de salarios
 * param puntero de promedio de salarios.
 * \return retorna 0 (EXITO) y -1 (ERROR)
 */
int employee_salarios (Employee* arrayEmployee,int len,float *acumuladorSalarios,float *promedioSalarios)
{
	int retorno=-1;
	int i;
	int ContadorEmpleados=0;
	float acuSalarios=0;
	float promedio;

	if(arrayEmployee != NULL && len > 0 && acumuladorSalarios != NULL && promedioSalarios != NULL)
	for(i=0;i<len;i++)
			{
				if(arrayEmployee[i].isEmpty != 1)
				{
					retorno=0;
					acuSalarios= arrayEmployee[i].salary + acuSalarios;
					ContadorEmpleados=ContadorEmpleados+1;
				}

			}
	promedio=(float)acuSalarios/ContadorEmpleados;

	*acumuladorSalarios = acuSalarios;
	*promedioSalarios = promedio;

	return retorno;
}

/**
 * \brief ordena por nombre
 * param array de empleados
 * param tamaño del array
 * \return retorna 0 (EXITO) y -1 (ERROR)
 */
int employee_sortEmployee (Employee* arrayEmployee, int len)     //arreglar esto !!
{
	int retorno = -1;
	int flagSwap;
	int i;
	Employee buffer;
	int auxiliarCmp;

	if(arrayEmployee != NULL && len >0)
	{
		do
		{
			flagSwap=0;
			for(i=0;i<len-1;i++)
			{
				if(arrayEmployee[i].isEmpty  || arrayEmployee[i+1].isEmpty)
				{
					continue;
				}
				auxiliarCmp = strncmp(arrayEmployee[i].lastName,arrayEmployee[i+1].lastName,NAME_LEN);
				if(auxiliarCmp > 0 || (auxiliarCmp == 0 && arrayEmployee[i].sector > arrayEmployee[i+1].sector) )
				{
					flagSwap = 1;
					buffer = arrayEmployee[i];
					arrayEmployee[i] = arrayEmployee[i+1];
					arrayEmployee[i+1]=buffer;
				}
			}
			len--;
			retorno=0;
		}while(flagSwap);
	}
	return retorno;
}

/**
 * \brief indica si hay algun empleado cargado en el array teniendo como referencia el IsEmpty
 * param array de empleados
 * param tamaño del array
 * \return retorna 0 (MODIFICADO) y -1 (NO MODIFICADO)
 */
int employee_bajaTotalDeEmpleados (Employee* arrayEmployee, int len)
{
	int retorno=-1;
	int i;

	for(i=0;i<len-1;i++)
	{
		if(arrayEmployee[i].isEmpty == 0)
		{
			retorno=0;
		}

	}
	return retorno;
}
