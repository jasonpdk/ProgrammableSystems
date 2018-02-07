/*
 * functions.c
 *
 *  Created on: 1 Feb 2018
 *      Author: jason
 */

/*
 * functions.c
 *
 *  Created on: 1 Feb 2018
 *      Author: Jason Keane
 */

#include <stdio.h>
#include <stdlib.h>
#include "structuresAssignment.h"

void readInData(Employee *emp)
{
	/* ID */
	printf("\nEnter the employee's ID: ");
	scanf("%d", &emp->empID);

	/* Name */
	printf("\nEnter the employee's first name: ");
	scanf("%s", emp->employeeName.firstName);

	printf("\nEnter the employee's middle name: ");
	scanf("%s", emp->employeeName.middleName);

	printf("\nEnter the employee's last name: ");
	scanf("%s", emp->employeeName.lastName);

	/* Address */
	printf("\nEnter the employee's street name: ");
	scanf("%s", emp->employeeAddress.street);

	printf("\nEnter the employee's town: ");
	scanf("%s", emp->employeeAddress.town);

	printf("\nEnter the employee's county: ");
	scanf("%s", emp->employeeAddress.county);

	/* Age */
	printf("\nEnter the employee's age: ");
	scanf("%d", &emp->age);

	/* Salary */
	printf("\nEnter the employee's salary: ");
	scanf("%f", &emp->salary);
}

void printData(Employee *emp)
{
	printf("Employee ID: %d\n", emp->empID);
	printf("Employee Name: %s %s %s\n", emp->employeeName.firstName, emp->employeeName.middleName, emp->employeeName.lastName);
	printf("Employee Address: %s %s %s\n", emp->employeeAddress.street, emp->employeeAddress.town, emp->employeeAddress.county);
	printf("Employee Age: %d\n", emp->age);
	printf("Employee Salary: %.2f\n", emp->salary);
}
