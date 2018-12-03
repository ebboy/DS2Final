#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hash_employee.c"
#include "hash_dependent.c"
#include "lefkowitz_employee.c"
#include "lefkowitz_dependent.c"

void createLefkowitzDep(FILE * depHash){
	FILE * table_a11 = fopen("table_a11.dat", "w+b");
	FILE * table_a12 = fopen("table_a12.dat", "w+b");
	FILE * table_a13_name = fopen("table_a13_name.dat", "w+b");
	FILE * table_a13_age = fopen("table_a13_age.dat", "w+b");
	FILE * table_a13_employee_code = fopen("table_a13_employee_code.dat", "w+b");
	FILE * table_a14_name = fopen("table_a14_name.dat", "w+b");
	FILE * table_a14_age = fopen("table_a14_age.dat", "w+b");
	FILE * table_a14_employee_code = fopen("table_a14_employee_code.dat", "w+b");
	FILE * table_a15_name = fopen("table_a15_name.dat", "w+b");
	FILE * table_a15_age = fopen("table_a15_age.dat", "w+b");
	FILE * table_a15_employee_code = fopen("table_a15_employee_code.dat", "w+b");
	FILE * table_a16_name = fopen("table_a16_name.dat", "w+b");
	FILE * table_a16_age = fopen("table_a16_age.dat", "w+b");
	FILE * table_a16_employee_code = fopen("table_a16_employee_code.dat", "w+b");
	FILE * table_a17_name = fopen("table_a17_name.dat", "w+b");
	FILE * table_a17_age = fopen("table_a17_age.dat", "w+b");
	FILE * table_a17_employee_code = fopen("table_a17_employee_code.dat", "w+b");
	FILE * table_a18 = fopen("table_a18.dat", "w+b");
	system("cp depTabHash.dat copiaDepHash.dat");
	FILE * copiaDepHash = fopen("copiaDepHash.dat", "r+b");

	rewind(copiaDepHash);
	dep_sortA1File(copiaDepHash, table_a11);
	dep_createA2File(table_a11, table_a12);
	dep_createA3File(table_a12, table_a13_name, table_a13_age, table_a13_employee_code);
	dep_createA4File(table_a13_name, table_a13_age, table_a13_employee_code, table_a14_name, table_a14_age, table_a14_employee_code);
	rewind(table_a14_name);
	rewind(table_a14_age);
	rewind(table_a14_employee_code);
	system("cp table_a14_name.dat copyNameA14_dep.dat");
	system("cp table_a14_age.dat copyAgeA14_dep.dat");
	system("cp table_a14_employee_code.dat copyEmployeeCodeA14.dat");
	FILE * copy_a14_name = fopen("copyNameA14_dep.dat", "r+b");
	FILE * copy_a14_age = fopen("copyAgeA14_dep.dat", "r+b");
	FILE * copy_a14_employee_code = fopen("copyEmployeeCodeA14.dat", "r+b");
 	dep_createA5File(copy_a14_name, copy_a14_age, copy_a14_employee_code, table_a15_name, table_a15_age, table_a15_employee_code);
	dep_createA6File(table_a14_name, table_a14_age, table_a14_employee_code, table_a16_name, table_a16_age, table_a16_employee_code);
	dep_createA7File(table_a16_name, table_a17_name,1);
	dep_createA7File(table_a16_age, table_a17_age,2);
	dep_createA7File(table_a16_employee_code, table_a17_employee_code,3);

	rewind(table_a11);
	dep_createA8File(table_a11, table_a17_name, table_a17_age, table_a17_employee_code, table_a18);

	printf("\nDEP A5 NAME ------------------------------\n" );
	dep_printTableA5(table_a15_name, 1);
	printf("\nDEP A5 AGE ------------------------------\n" );
	dep_printTableA5(table_a15_age, 2);
	printf("\nDEP A5 EMPLOYEECODE ------------------------------\n" );
	dep_printTableA5(table_a15_employee_code,3);

	printf("\nA8 -----------------------------------\n" );
	dep_printTableA8(table_a18);


	fclose(table_a12);
	fclose(table_a13_name);
	fclose(table_a13_age);
	fclose(table_a13_employee_code);
	fclose(table_a14_name);
	fclose(table_a14_age);
	fclose(table_a14_employee_code);
	fclose(table_a15_name);
	fclose(table_a15_age);
	fclose(table_a15_employee_code);
}

void createLefkowitzEmp(FILE * hash){
	rewind(hash);
	FILE * table_a1 = fopen("table_a1.dat", "w+b");
	FILE * table_a2 = fopen("table_a2.dat", "w+b");

	FILE * table_a3_name = fopen("table_a3_name.dat", "w+b");
	FILE * table_a3_age = fopen("table_a3_age.dat", "w+b");
	FILE * table_a3_wage = fopen("table_a3_wage.dat", "w+b");

	FILE * table_a4_name = fopen("table_a4_name.dat", "w+b");
	FILE * table_a4_age = fopen("table_a4_age.dat", "w+b");
	FILE * table_a4_wage = fopen("table_a4_wage.dat", "w+b");

	FILE * table_a5_name = fopen("table_a5_name.dat", "w+b");
	FILE * table_a5_age = fopen("table_a5_age.dat", "w+b");
	FILE * table_a5_wage = fopen("table_a5_wage.dat", "w+b");

	FILE * table_a6_name = fopen("table_a6_name.dat", "w+b");
	FILE * table_a6_age = fopen("table_a6_age.dat", "w+b");
	FILE * table_a6_wage = fopen("table_a6_wage.dat", "w+b");

	FILE * table_a7_name = fopen("table_a7_name.dat", "w+b");
	FILE * table_a7_age = fopen("table_a7_age.dat", "w+b");
	FILE * table_a7_wage = fopen("table_a7_wage.dat", "w+b");
	FILE * table_a8 = fopen("table_a8.dat", "w+b");
	system("cp tabHash.dat copiaHash.dat");

	FILE * copiaHash = fopen("copiaHash.dat", "r+b");

	emp_sortA1File(copiaHash, table_a1);
	emp_createA2File(table_a1, table_a2);
	emp_createA3File(table_a2, table_a3_name, table_a3_age, table_a3_wage);
	emp_createA4File(table_a3_name, table_a3_age, table_a3_wage, table_a4_name, table_a4_age, table_a4_wage);
	rewind(table_a4_name);
	rewind(table_a4_age);
	rewind(table_a4_wage);
	system("cp table_a4_name.dat copyNameA4.dat");
	system("cp table_a4_age.dat copyAgeA4.dat");
	system("cp table_a4_wage.dat copyWageA4.dat");
	FILE * copy_a4_name = fopen("copyNameA4.dat", "r+b");
	FILE * copy_a4_age = fopen("copyAgeA4.dat", "r+b");
	FILE * copy_a4_wage = fopen("copyWageA4.dat", "r+b");
	emp_createA5File(copy_a4_name, copy_a4_age, copy_a4_wage, table_a5_name, table_a5_age, table_a5_wage);
	emp_createA6File(table_a4_name, table_a4_age, table_a4_wage, table_a6_name, table_a6_age, table_a6_wage);
	emp_createA7File(table_a6_name, table_a7_name,1);
	emp_createA7File(table_a6_age, table_a7_age,2);
	emp_createA7File(table_a6_wage, table_a7_wage,3);
	emp_createA8File(table_a1, table_a7_name, table_a7_age, table_a7_wage, table_a8);
	emp_printTableA8(table_a8);

	printf("\nA5 NAME ------------------------------\n" );
	emp_printTableA5(table_a5_name, 1);
	printf("\nA5 AGE ------------------------------\n" );
	emp_printTableA5(table_a5_age, 2);
	printf("\nA5 WAGE ------------------------------\n" );
	emp_printTableA5(table_a5_wage,3);

	printf("\nA8 -----------------------------------\n" );
	emp_printTableA8(table_a8);

	fclose(table_a2);
	fclose(table_a3_name);
	fclose(table_a3_age);
	fclose(table_a3_wage);
	fclose(table_a4_name);
	fclose(table_a4_age);
	fclose(table_a4_wage);
	fclose(table_a5_name);
	fclose(table_a5_age);
	fclose(table_a5_wage);
	fclose(table_a6_name);
	fclose(table_a6_age);
	fclose(table_a6_wage);
	fclose(table_a7_name);
	fclose(table_a7_age);
	fclose(table_a7_wage);
	fclose(table_a8);
	fclose(copy_a4_name);
	fclose(copy_a4_age);
	fclose(copy_a4_wage);
}

int findEmployeeByName(FILE * a5_name, FILE * a8, char * name){
	Employee_lk * row = (Employee_lk*) malloc(sizeof(Employee_lk));
	int pointer = -1;
	while(emp_readLine(row, a5_name, 51)){
		if(strcmp(row->name, name) == 0){
			pointer = row->a5_pt;
			break;
		}
	}
	if(pointer == -1){
		printf("Employee not found!\n" );
		return -1;
	}
	else{
		fseek(a8, pointer * emp_sizeofA8(), SEEK_SET);
		emp_readLine(row, a8, 8);
		return row->code;
	}
}

char * findEmployeeByAge(FILE * a5_age, FILE * a8, int age){
	Employee_lk * row = (Employee_lk*) malloc(sizeof(Employee_lk));
	int pointer = -1;
	while(emp_readLine(row, a5_age, 52)){
		if(row->age > age){
			pointer = row->a5_pt;
			break;
		}
	}
	if(pointer == -1){
		char * msg = (char*) malloc(sizeof(char) * 100);
		strcpy(msg, "Employee not found");
		return msg;
	}
	else{
		fseek(a8, pointer * emp_sizeofA8(), SEEK_SET);
		emp_readLine(row, a8, 8);
		return row->name;
	}
}

char * findEmployeeByNumDependent(FILE * a5_dep_employee, FILE * a8_dep, FILE * hashEmp, int count){
	rewind(hashEmp);
	Dependent_lk * rowDep = (Dependent_lk*) malloc(sizeof(Dependent_lk));
	Employee * emp = (Employee*) malloc(sizeof(Employee));

	int pointer = -1;
	while(dep_readLine(rowDep, a5_dep_employee, 53)){
		if(rowDep->a5_q > count){
			pointer = rowDep->a5_pt;
			break;
		}
	}
	if(pointer == -1){
		char * msg = (char*) malloc(sizeof(char) * 100);
		strcpy(msg, "Employee not found");
		return msg;
	}
	else{
		fseek(a8_dep, pointer * dep_sizeofA8(), SEEK_SET);
		dep_readLine(rowDep, a8_dep, 8);
		int position = emp_findEmployee(hashEmp, rowDep->employee_code);
		if(position == -1){
			char * msg = (char*) malloc(sizeof(char) * 100);
			strcpy(msg, "Employee not found");
			return msg;
		}
		else{
			fseek(hashEmp, position * emp_sizeofEmployee(), SEEK_SET);
			emp_readEmployee(emp, hashEmp);
			return emp->name;
		}

	}
}

void showMenu(FILE * hash){
	char input = 'z', inputMenu = 'z';
	char name[100];
	Employee * emp = (Employee*) malloc(sizeof(Employee));
	while(input != '0'){
		printf("0 - Exit\n");
		printf("1 - Insert Menu\n" );
		printf("2 - Create Dependent\n" );
		printf("3 - Search Employee - Name\n");
		printf("4 - Show Employee Hash\n");
		scanf("%c",&input);
		switch (input){
			case '0':
				exit(0);
			break;
			case '1':
				printf("\nINSERT MENU\n");
				printf("1 - Insert Employee\n" );
				printf("2 - Insert Dependent\n");
				printf("0 - Return");
				while(inputMenu != '0'){
					scanf("%c",&inputMenu);
					switch (inputMenu) {
						case '1':
							printf("Insert Employee code:\n");
							scanf("%d", &emp->code);
							printf("Insert Employee name:\n");
							scanf(" %[^\t\n]s",name);
							strcpy(emp->name, name);
							printf("Insert Employee age:\n");
							scanf("%d", &emp->age);
							printf("Insert Employee wage:\n");
							scanf("%f", &emp->wage);
							inputMenu = 'z';
							break;
						break;
						case '0':
						break;
					}
				}
			break;
			case '4':
				emp_printEmployees(hash);
			break;
		}
	}
}

int main(int argc, char const *argv[]) {

	FILE * hash = fopen("tabHash.dat", "w+b");
	FILE * depHash = fopen("depTabHash.dat", "w+b");

	dep_createHash(HASH_SIZE, depHash);
	emp_createHash(HASH_SIZE, hash);

	Employee * teste1 = (Employee*) malloc(sizeof(Employee));
	Employee * teste2 = (Employee*) malloc(sizeof(Employee));
	Employee * teste3 = (Employee*) malloc(sizeof(Employee));
	Employee * teste4 = (Employee*) malloc(sizeof(Employee));
	Employee * teste5 = (Employee*) malloc(sizeof(Employee));
	Employee * teste6 = (Employee*) malloc(sizeof(Employee));
	Employee * teste7 = (Employee*) malloc(sizeof(Employee));

	// Dependent * teste1 = (Dependent*) malloc(sizeof(Dependent));
	// Dependent * teste2 = (Dependent*) malloc(sizeofFILE * hashEmp(Dependent));
	// Dependent * teste3 = (Dependent*) malloc(sizeof(Dependent));
	// Dependent * teste4 = (Dependent*) malloc(sizeof(Dependent));
	// Dependent * teste5 = (Dependent*) malloc(sizeof(Dependent));
	// Dependent * teste6 = (Dependent*) malloc(sizeof(Dependent));
	// Dependent * teste7 = (Dependent*) malloc(sizeof(Dependent));


	teste1->code = 2;
	strcpy(teste1->name, "Joao zao");
	teste1->age = 27;
	teste1->wage = 2000.5;
	// teste1->employee_code = 12;
	teste1->pointer = -1;
	teste1->status = 1;

	teste2->code = 9;
	strcpy(teste2->name, "Armando jorge");
	teste2->age = 200;
	teste2->wage = 5000.0;
	// teste2->employee_code = 0;
	teste2->pointer = -1;
	teste2->status = 1;

	teste3->code = 20;
	strcpy(teste3->name, "okokoko a");
	teste3->age = 29;
	teste3->wage = 800.9;
	// teste3->employee_code = 21;
	teste3->pointer = -1;
	teste3->status = 1;

	teste4->code = 14;
	strcpy(teste4->name, "oloco moco");
	teste4->age = 20;
	teste4->wage = 6700.9;
	// teste4->employee_code = 21;
	teste4->pointer = -1;
	teste4->status = 1;

	teste5->code = 40;
	strcpy(teste5->name, "Joao zao");
	teste5->age = 32;
	teste5->wage = 4300.9;
	// teste5->employee_code = 0;
	teste5->pointer = -1;
	teste5->status = 1;

	teste6->code = 25;
	strcpy(teste6->name, "manga banga");
	teste6->age = 27;
	teste6->wage = 4200.2;
	// teste6->employee_code = 0;
	teste6->pointer = -1;
	teste6->status = 1;

	teste7->code = 34;
	strcpy(teste7->name, "Joao zao");
	teste7->age = 27;
	teste7->wage = 2000.5;
	// teste7->employee_code = 0;
	teste7->pointer = -1;
	teste7->status = 1;


	emp_insertEmployee(teste1, hash);
	emp_insertEmployee(teste2, hash);

	emp_insertEmployee(teste3, hash);

	emp_insertEmployee(teste4, hash);

	emp_insertEmployee(teste5, hash);

	emp_insertEmployee(teste6, hash);



	printf("\n>>>>>>>>>>>>>>>>FICOU ASSIM<<<<<<<<<<<<<<<<<<<\n");
	emp_printEmployees(hash);


	createLefkowitzDep(depHash);

	createLefkowitzEmp(hash);

	int employeecode;
	FILE * a5 = fopen("table_a5_name.dat","r+b");
	FILE * a5_age = fopen("table_a5_age.dat","r+b");
	FILE * a8 = fopen("table_a8.dat","r+b");
	FILE * a8Dep = fopen("table_a18.dat","r+b");
	FILE * a5_emp_code = fopen("table_a15_employee_code.dat","r+b");

	char nome[100];
	strcpy(nome, "Joao zao");
	employeecode = findEmployeeByName(a5, a8, nome);
	printf("EmployeeCode = %d\n", employeecode);
	rewind(a8);
	printf("empregado %s", findEmployeeByAge(a5_age, a8, 27));

	Dependent * teste10 = (Dependent*) malloc(sizeof(Dependent));
	Dependent * teste11 = (Dependent*) malloc(sizeof(Dependent));

	teste10->code = 3;
	strcpy(teste10->name, "Joaoqweqwe zaoDEP1");
	teste10->age = 27;
	// teste11->wage = 2000.5;
	teste10->employee_code = 25;
	teste10->pointer = -1;
	teste10->status = 1;

	teste11->code = 2;
	strcpy(teste11->name, "Joao zaoDEP1");
	teste11->age = 27;
	// teste11->wage = 2000.5;
	teste11->employee_code = 25;
	teste11->pointer = -1;
	teste11->status = 1;

	dep_insertDependent(teste10, depHash);
	dep_insertDependent(teste11, depHash);
	rewind(depHash);
	createLefkowitzDep(depHash);
	//showMenu(hash);

	printf("\n\nEMPREGADAO %s", findEmployeeByNumDependent(a5_emp_code, a8Dep, hash, 1));

	return 0;
}


/*
//fclose(hashfile);

//hash = fopen("tabHash.dat", "r+b");

//Employee ** added_employees = (Employee**) malloc(sizeof(Employee) * 2);

Employee * teste1 = (Employee*) malloc(sizeof(Employee));
Employee * teste2 = (Employee*) malloc(sizeof(Employee));
Employee * teste3 = (Employee*) malloc(sizeof(Employee));
Employee * teste4 = (Employee*) malloc(sizeof(Employee));
Employee * teste5 = (Employee*) malloc(sizeof(Employee));
Employee * teste6 = (Employee*) malloc(sizeof(Employee));
Employee * teste7 = (Employee*) malloc(sizeof(Employee));

// Dependent * teste1 = (Dependent*) malloc(sizeof(Dependent));
// Dependent * teste2 = (Dependent*) malloc(sizeof(Dependent));
// Dependent * teste3 = (Dependent*) malloc(sizeof(Dependent));
// Dependent * teste4 = (Dependent*) malloc(sizeof(Dependent));
// Dependent * teste5 = (Dependent*) malloc(sizeof(Dependent));
// Dependent * teste6 = (Dependent*) malloc(sizeof(Dependent));
// Dependent * teste7 = (Dependent*) malloc(sizeof(Dependent));

/*
added_employees[0]->code = 0;
strcpy(added_employees[0]->name, "joaoalbino");
added_employees[0]->age = 27;
added_employees[0]->wage = 2000.5;
added_employees[0]->pointer = -1;
added_employees[0]->status = 1;

added_employees[1]->code = 21;
strcpy(added_employees[1]->name, "joaoalbi no2");
added_employees[1]->age = 200;
added_employees[1]->wage = 5000.0;
added_employees[1]->pointer = -1;
added_employees[1]->status = 1;
*/
/*
teste1->code = 2;
strcpy(teste1->name, "Joao zao");
teste1->age = 27;
teste1->wage = 2000.5;
// teste1->employee_code = 12;
teste1->pointer = -1;
teste1->status = 1;

teste2->code = 9;
strcpy(teste2->name, "Armando jorge");
teste2->age = 200;
teste2->wage = 5000.0;
// teste2->employee_code = 0;
teste2->pointer = -1;
teste2->status = 1;

teste3->code = 20;
strcpy(teste3->name, "okokoko a");
teste3->age = 29;
teste3->wage = 800.9;
// teste3->employee_code = 21;
teste3->pointer = -1;
teste3->status = 1;

teste4->code = 14;
strcpy(teste4->name, "oloco moco");
teste4->age = 20;
teste4->wage = 6700.9;
// teste4->employee_code = 21;
teste4->pointer = -1;
teste4->status = 1;

teste5->code = 40;
strcpy(teste5->name, "Joao zao");
teste5->age = 32;
teste5->wage = 4300.9;
// teste5->employee_code = 0;
teste5->pointer = -1;
teste5->status = 1;

teste6->code = 25;
strcpy(teste6->name, "manga banga");
teste6->age = 27;
teste6->wage = 4200.2;
// teste6->employee_code = 0;
teste6->pointer = -1;
teste6->status = 1;

teste7->code = 34;
strcpy(teste7->name, "Joao zao");
teste7->age = 27;
teste7->wage = 2000.5;
// teste7->employee_code = 0;
teste7->pointer = -1;
teste7->status = 1;

// insertEmployee(teste1, hash);

// insertEmployee(teste2, hash);
// printf("\n>>>>>>>>>>>>>>>>FICOU ASSIM<<<<<<<<<<<<<<<<<<<\n");
// printEmployees(hash);

// insertEmployee(teste3, hash);
// printf("\n>>>>>>>>>>>>>>>>FICOU ASSIM<<<<<<<<<<<<<<<<<<<\n");
// printEmployees(hash);


emp_insertEmployee(teste1, hash);

emp_insertEmployee(teste2, hash);

emp_insertEmployee(teste3, hash);

emp_insertEmployee(teste4, hash);

emp_insertEmployee(teste5, hash);

emp_insertEmployee(teste6, hash);

//emp_insertEmployee(teste7, hash);


printf("\n>>>>>>>>>>>>>>>>FICOU ASSIM<<<<<<<<<<<<<<<<<<<\n");
emp_printEmployees(hash);

Dependent * teste11 = (Dependent*) malloc(sizeof(Dependent));
Dependent * teste12 = (Dependent*) malloc(sizeof(Dependent));
Dependent * teste13 = (Dependent*) malloc(sizeof(Dependent));
Dependent * teste14 = (Dependent*) malloc(sizeof(Dependent));
Dependent * teste15 = (Dependent*) malloc(sizeof(Dependent));
Dependent * teste16 = (Dependent*) malloc(sizeof(Dependent));
Dependent * teste17 = (Dependent*) malloc(sizeof(Dependent));

teste11->code = 2;
strcpy(teste11->name, "Joao zaoDEP1");
teste11->age = 27;
// teste11->wage = 2000.5;
teste11->employee_code = 2;
teste11->pointer = -1;
teste11->status = 1;

teste12->code = 9;
strcpy(teste12->name, "Armando jorgeDEP2");
teste12->age = 200;
// teste12->wage = 5000.0;
teste12->employee_code = 9;
teste12->pointer = -1;
teste12->status = 1;

teste13->code = 20;
strcpy(teste13->name, "okokoko aDEP3");
teste13->age = 29;
// teste13->wage = 800.9;
teste13->employee_code = 20;
teste13->pointer = -1;
teste13->status = 1;

teste14->code = 14;
strcpy(teste14->name, "oloco mocoDEP4");
teste14->age = 20;
// teste14->wage = 6700.9;
teste14->employee_code = 14;
teste14->pointer = -1;
teste14->status = 1;

teste15->code = 40;
strcpy(teste15->name, "Joao zaoDEP5");
teste15->age = 20;
// teste15->wage = 4300.9;
teste15->employee_code = 40;
teste15->pointer = -1;
teste15->status = 1;

teste16->code = 25;
strcpy(teste16->name, "manga bangaDEP6");
teste16->age = 27;
// teste16->wage = 4200.2;
teste16->employee_code = 25;
teste16->pointer = -1;
teste16->status = 1;

teste17->code = 34;
strcpy(teste17->name, "oloco mocoDEP4");
teste17->age = 27;
// teste17->wage = 2000.5;
teste17->employee_code = 14;
teste17->pointer = -1;
teste17->status = 1;


dep_insertDependent(teste11, depHash);
dep_insertDependent(teste12, depHash);
dep_insertDependent(teste13, depHash);
dep_insertDependent(teste14, depHash);
dep_insertDependent(teste15, depHash);
dep_insertDependent(teste16, depHash);
dep_insertDependent(teste17, depHash);
*/
