#include <stdio.h>

int main(int argc, char *argv[])
{
	int distance = 100;
	float power = 2.349f;
	double super_power = 56789.4532;
	char initial = 'A';
	char first_name[] = "Zed";
	char last_name[] = "Shaw";

	printf("You are %d miles away.\n", distance);
	printf("You have %f level of power.\n", power);
	printf("You have %f awesome super level of power.\n", super_power);
	printf("I have an initial %c.\n", initial);
	printf("I have first name %s.\n", first_name);
	printf("I have last name %s.\n", last_name);
	printf("My full name is %s. %c. %s.\n", first_name, initial, last_name);	

	int bugs = 100;
	double bug_rate = 1.2;

	printf("You have %d bugs at the rate of %f.\n", bugs, bug_rate);

	unsigned long universe_of_defects = 1L * 1024L * 1024L * 1024L;
	printf("The universe has %ld bugs.\n", universe_of_defects);

	double expected_bugs = bugs * bug_rate;
	printf("You are expected to have %f bugs.\n", expected_bugs);

	double part_of_universe = expected_bugs/universe_of_defects;
	printf("That is only %e part of the universe.\n", part_of_universe);

	char nul_byte = '\0';
	int care_percentage = bugs * nul_byte;
	printf("Which means you should care %d%%\n", care_percentage);
	printf("This is the null byte character: %s", nul_byte);

	return 0;
}