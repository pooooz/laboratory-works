#pragma once
#include "constants.h"

struct Date {
	int day;
	int month;
	int year;
};

struct Employee {
	char last_name[MAX_STRING_SIZE];
	char first_name[MAX_STRING_SIZE];
	char middle_name[MAX_STRING_SIZE];
	char gender[MAX_STRING_SIZE];
	Date birthdate;
	int age;
	int work_experience;

	char speciality[MAX_STRING_SIZE];
};