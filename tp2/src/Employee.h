/*
 * Employee.h
 *
 *  Created on: 26 abr. 2020
 *      Author: Juan
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include "utn.h"
#define NAME_LEN 51
#define LASTNAME_LEN 51

typedef struct
{
	int id;
	char name [NAME_LEN];
	char lastName [LASTNAME_LEN];
	float salary;
	int sector;
	int isEmpty;
}Employee;

int employee_initArray(Employee* ArrayEmpleados,int len);
int employee_addEmployee(Employee* ArrayEmpleados, int len,int indice, int* id);
int employee_modifEmployee(Employee* ArrayEmpleados, int len,int indice, int id);
int employee_findEmployeeById (Employee* ArrayEmpleados, int len, int id);
int employee_removeEmployee(Employee* ArrayEmpleados, int len, int id);
int employee_printEmployee(Employee* arrayEmployee,int len);
int employee_getEmptyIndex(Employee* arrayEmployee,int len);
int employee_salarios (Employee* arrayEmployee,int len,float *acumuladorSalarios,float *promedioSalarios);
int employee_sortEmployee (Employee* arrayEmployee, int len);
int employee_EmpleadosMasSalario (Employee* arrayEmployee,int len, float promedioSalarios, int* cantidadSueldosPromedio);
int employee_bajaTotalDeEmpleados (Employee* arrayEmployee, int len);

#endif /* EMPLOYEE_H_ */
