/*
 * structuresAssignment.h
 *
 *  Created on: 1 Feb 2018
 *      Author: Jason Keane
 */

#ifndef STRUCTURESASSIGNMENT_H_
#define STRUCTURESASSIGNMENT_H_

/* STRUCTURES */
typedef struct name
{
	char firstName[20];
	char middleName[20];
	char lastName[20];
} Name;

typedef struct address
{
	char street[20];
	char town[20];
	char county[20];
} Address;

typedef struct employee
{
	int empID;
	Name employeeName;
	Address employeeAddress;
	int age;
	float salary;
} Employee;

/* PROTOTYPES */
void readInData(Employee *);
void printData(Employee *);

#endif /* STRUCTURESASSIGNMENT_H_ */
