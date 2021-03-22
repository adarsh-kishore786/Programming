/*
	bitfield.c

	This program demonstrates the 
	concept of bitfields.
*/

#include <stdio.h>
#define MALE 1;
#define FEMALE 2;
#define SINGLE 0;
#define MARRIED 1;
#define DIVORCED 2;
#define WIDOWED 3;

typedef struct employee
{
	// : 2 means that gender occupies only 2 bit
	// As 01 and 10 both occupy 2 bits max
	int gender : 2;
	int mar_status : 2;
	// There are 8 hobbies so 1000 so 4 bits
	int hobby : 4;

	// There are 15 different schemes proposed by company
	int scheme : 5;

} employee;

int main()
{
	employee emp;
	emp.gender = MALE;
	emp.mar_status = DIVORCED;
	emp.hobby = 5;
	emp.scheme = 9;

	printf("Gender = %d\n", emp.gender);
	printf("Status = %d\n", emp.mar_status);

	// printf("\nsizeof(gender) = %d\n", sizeof(emp.gender));
	// printf("sizeof(status) = %d\n", sizeof(emp.mar_status));
	// printf("sizeof(hobby) = %d\n", sizeof(emp.hobby));
	// printf("sizeof(scheme) = %d\n", sizeof(emp.scheme));
	printf("sizeof(emp) = %lu\n", sizeof(emp));

	return 0;
}