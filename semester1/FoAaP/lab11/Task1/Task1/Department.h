struct Employee {
	char FirstName[15];
	char LastName[15];
	char MiddleName[15];
	char Gender;
	char Speciality[50];
	char WorkExperience[255];
	char Age[255];
	char YearOfBirth[255];
};

#define MAX_EMPLOYEES 30
struct HumanResourcesDepartment {
	char Name[10];
	char Amount[255];
	Employee Employees[MAX_EMPLOYEES];
};


Employee inputEmployee();
void outputEmployee(Employee Employee);
void inputDepartment(HumanResourcesDepartment* Department);
void outputDepartment(HumanResourcesDepartment Department);
void outputListOfPensioners(HumanResourcesDepartment Department);
void insSort_descending(Employee* arrayPtr, double array_size);
