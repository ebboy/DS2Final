#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define FLOAT_MAX 9999999.0

/*
typedef struct Dependent {
	int code;
	char name[100];
	int age;
	int employee_code;
	int status; // 1 used, 0 free
	int pointer;
} Dependent;


*/




/*
Para funcionário:
	name (1)
	age (2)
	wage(3)

Para dependente:
	employee_code (3, 4)
	name (5)
	age (6)


Extras:
	Para funcionário:
		wage - Quem ganha mais que um certo salário
		code - Nome do funcionario pelo codigo

	Para dependente:
		code = Nome do dependente pelo codigo

*/
 //


// typedef struct Employee_lk {
// 	int code;
// 	char name[100];
// 	int age;
// 	float wage;
// 	int status;
// 	int pointer;
// 	int disc_addr;
// 	int a5_pt;
// 	int a5_q;
// 	int prox_1;
// 	int prox_2;
// 	int prox_3;
// } Employee_lk;

typedef struct Dependent_lk {
	int code;
	char name[100];
	int age;
	int employee_code;
	int status; // 1 used, 0 free
	int pointer;
	int disc_addr;
	int a5_pt;
	int a5_q;
	int prox_1;
	int prox_2;
	int prox_3;
} Dependent_lk;

int dependent_lk_Size() {
	return sizeof(int)  // code
	+ sizeof(char) * 100 // name
	+ sizeof(int) // age
	+ sizeof(int) // employee_code
	+ sizeof(int) // status
	+ sizeof(int) // pointer
	+ sizeof(int) // disc_addr
	+ sizeof(int) // a5_pt
	+ sizeof(int) //a5_q
	+ sizeof(int) // prox_1
	+ sizeof(int) // prox_2
	+ sizeof(int); // prox_3
}

int dep_readLine(Dependent_lk * row, FILE *fileName, int table_id){

	switch (table_id) {
		case 1:
			return (	fread(&row->code, sizeof(int), 1, fileName) &&
						fread(row->name, sizeof(char), sizeof(row->name), fileName) &&
						fread(&row->age, sizeof(int), 1, fileName) &&
						fread(&row->employee_code, sizeof(int), 1, fileName) &&
						fread(&row->status, sizeof(int), 1, fileName) &&
						fread(&row->pointer, sizeof(int), 1, fileName));
		case 2:
			return (	fread(&row->disc_addr, sizeof(int), 1, fileName) &&
						fread(&row->code, sizeof(int), 1, fileName) &&
						fread(row->name, sizeof(char), sizeof(row->name), fileName) &&
						fread(&row->age, sizeof(int), 1, fileName) &&
						fread(&row->employee_code, sizeof(int), 1, fileName));
		case 31:
			return (	fread(&row->disc_addr, sizeof(int), 1, fileName) &&
						fread(&row->code, sizeof(int), 1, fileName) &&
						fread(row->name, sizeof(char), sizeof(row->name), fileName));
		case 32:
			return (	fread(&row->disc_addr, sizeof(int), 1, fileName) &&
						fread(&row->code, sizeof(int), 1, fileName) &&
						fread(&row->age, sizeof(int), 1, fileName));
		case 33:
			return (	fread(&row->disc_addr, sizeof(int), 1, fileName) &&
						fread(&row->code, sizeof(int), 1, fileName) &&
						fread(&row->employee_code, sizeof(int), 1, fileName));
		case 41:
			return (	fread(&row->disc_addr, sizeof(int), 1, fileName) &&
						fread(&row->code, sizeof(int), 1, fileName) &&
						fread(row->name, sizeof(char), sizeof(row->name), fileName));
		case 42:
			return (	fread(&row->disc_addr, sizeof(int), 1, fileName) &&
						fread(&row->code, sizeof(int), 1, fileName) &&
						fread(&row->age, sizeof(int), 1, fileName));
		case 43:
			return (	fread(&row->disc_addr, sizeof(int), 1, fileName) &&
						fread(&row->code, sizeof(int), 1, fileName) &&
						fread(&row->employee_code, sizeof(int), 1, fileName));
		case 51:
			return (	fread(row->name, sizeof(char), sizeof(row->name), fileName) &&
						fread(&row->a5_pt, sizeof(int), 1, fileName) &&
						fread(&row->a5_q, sizeof(int), 1, fileName));
		case 52:
			return (	fread(&row->age, sizeof(int), 1, fileName) &&
						fread(&row->a5_pt, sizeof(int), 1, fileName) &&
						fread(&row->a5_q, sizeof(int), 1, fileName));
		case 53:
			return (	fread(&row->employee_code, sizeof(int), 1, fileName) &&
						fread(&row->a5_pt, sizeof(int), 1, fileName) &&
						fread(&row->a5_q, sizeof(int), 1, fileName));
		case 61:
			return (	fread(&row->disc_addr, sizeof(int), 1, fileName) &&
						fread(&row->code, sizeof(int), 1, fileName) &&
						fread(row->name, sizeof(char), sizeof(row->name), fileName) &&
						fread(&row->prox_1, sizeof(int), 1, fileName));
		case 62:
			return (	fread(&row->disc_addr, sizeof(int), 1, fileName) &&
						fread(&row->code, sizeof(int), 1, fileName) &&
						fread(&row->age, sizeof(int), 1, fileName) &&
						fread(&row->prox_2, sizeof(int), 1, fileName));
		case 63:
			return (	fread(&row->disc_addr, sizeof(int), 1, fileName) &&
						fread(&row->code, sizeof(int), 1, fileName) &&
						fread(&row->employee_code, sizeof(int), 1, fileName) &&
						fread(&row->prox_3, sizeof(int), 1, fileName));
		case 71:
			return (	fread(&row->disc_addr, sizeof(int), 1, fileName) &&
						fread(&row->code, sizeof(int), 1, fileName) &&
						fread(row->name, sizeof(char), sizeof(row->name), fileName) &&
						fread(&row->prox_1, sizeof(int), 1, fileName));
		case 72:
			return (	fread(&row->disc_addr, sizeof(int), 1, fileName) &&
						fread(&row->code, sizeof(int), 1, fileName) &&
						fread(&row->age, sizeof(int), 1, fileName) &&
						fread(&row->prox_2, sizeof(int), 1, fileName));
		case 73:
			return (	fread(&row->disc_addr, sizeof(int), 1, fileName) &&
						fread(&row->code, sizeof(int), 1, fileName) &&
						fread(&row->employee_code, sizeof(int), 1, fileName) &&
						fread(&row->prox_3, sizeof(int), 1, fileName));
		case 8:
			return (	fread(&row->code, sizeof(int), 1, fileName) &&
						fread(row->name, sizeof(char), sizeof(row->name), fileName) &&
						fread(&row->age, sizeof(int), 1, fileName) &&
						fread(&row->employee_code, sizeof(int), 1, fileName) &&
						fread(&row->prox_1, sizeof(int),1, fileName) &&
						fread(&row->prox_2, sizeof(int),1, fileName) &&
						fread(&row->prox_3, sizeof(int),1, fileName));

		default:
			break;
	}
}

void dep_writeLine(Dependent_lk *row, FILE *fileName_1, FILE *fileName_2, FILE *fileName_3, int table_id){
	switch (table_id) {
		case 2:
			fwrite(&row->disc_addr, sizeof(int), 1, fileName_1);
			fwrite(&row->code, sizeof(int), 1, fileName_1);
			fwrite(row->name, sizeof(char), sizeof(row->name), fileName_1);
			fwrite(&row->age, sizeof(int), 1, fileName_1);
			fwrite(&row->employee_code, sizeof(int), 1, fileName_1);
			break;

		case 3:
			fwrite(&row->disc_addr, sizeof(int), 1, fileName_1);
			fwrite(&row->disc_addr, sizeof(int), 1, fileName_2);
			fwrite(&row->disc_addr, sizeof(int), 1, fileName_3);

			fwrite(&row->code, sizeof(int), 1, fileName_1);
			fwrite(&row->code, sizeof(int), 1, fileName_2);
			fwrite(&row->code, sizeof(int), 1, fileName_3);

			fwrite(row->name, sizeof(char), sizeof(row->name), fileName_1);
			fwrite(&row->age, sizeof(int), 1, fileName_2);
			fwrite(&row->employee_code, sizeof(int), 1, fileName_3);
			break;

		case 41:
			fwrite(&row->disc_addr, sizeof(int), 1, fileName_1);
			fwrite(&row->code, sizeof(int), 1, fileName_1);
			fwrite(row->name, sizeof(char), sizeof(row->name), fileName_1);
			break;

		case 42:
			fwrite(&row->disc_addr, sizeof(int), 1, fileName_1);
			fwrite(&row->code, sizeof(int), 1, fileName_1);
			fwrite(&row->age, sizeof(int), 1, fileName_1);
			break;

		case 43:
			fwrite(&row->disc_addr, sizeof(int), 1, fileName_1);
			fwrite(&row->code, sizeof(int), 1, fileName_1);
			fwrite(&row->employee_code, sizeof(int), 1, fileName_1);
			break;

		case 71:
			fwrite(&row->disc_addr, sizeof(int), 1, fileName_1);
			fwrite(&row->code, sizeof(int), 1, fileName_1);
			fwrite(row->name, sizeof(char), sizeof(row->name), fileName_1);
			fwrite(&row->prox_1, sizeof(int), 1, fileName_1);
			break;

		case 72:
			fwrite(&row->disc_addr, sizeof(int), 1, fileName_1);
			fwrite(&row->code, sizeof(int), 1, fileName_1);
			fwrite(&row->age, sizeof(int), 1, fileName_1);
			fwrite(&row->prox_2, sizeof(int), 1, fileName_1);
			break;

		case 73:
			fwrite(&row->disc_addr, sizeof(int), 1, fileName_1);
			fwrite(&row->code, sizeof(int), 1, fileName_1);
			fwrite(&row->employee_code, sizeof(int), 1, fileName_1);
			fwrite(&row->prox_3, sizeof(int), 1, fileName_1);
			break;

		case 8:
			fwrite(&row->code, sizeof(int), 1, fileName_1);
			fwrite(row->name, sizeof(char), sizeof(row->name), fileName_1);
			fwrite(&row->age, sizeof(int), 1, fileName_1);
			fwrite(&row->employee_code, sizeof(int), 1, fileName_1);
			fwrite(&row->prox_1, sizeof(int), 1, fileName_1);
			fwrite(&row->prox_2, sizeof(int), 1, fileName_1);
			fwrite(&row->prox_3, sizeof(int), 1, fileName_1);
			break;

		default:
			break;
	}
}



void dep_createA2File(FILE* input, FILE *output){
	Dependent_lk * row = (Dependent_lk*) malloc(sizeof(Dependent_lk));
	rewind(input);

	int discAddress = 0;
	while(dep_readLine(row, input, 1)){
		// fwrite(&fileAddress, sizeof(int),1,output);
		row->disc_addr = discAddress;
		//printRow(row);
		dep_writeLine(row, output, NULL, NULL, 2);
		discAddress++;
	}
	free(row);
}

void dep_createA3File(FILE* input, FILE *output_name, FILE *output_age, FILE *output_employee_code){
	Dependent_lk * row = (Dependent_lk*) malloc(sizeof(Dependent_lk));

	rewind(input);
	while (dep_readLine(row, input, 2)) {
		dep_writeLine(row, output_name, output_age, output_employee_code, 3);
	}
}

int dep_createA4File(FILE* input_name, FILE* input_age, FILE* input_employee_code, FILE *output_name, FILE *output_age, FILE *output_employee_code){
	Dependent_lk * row = (Dependent_lk*) malloc(sizeof(Dependent_lk));
	rewind(input_name);
	rewind(input_age);
	rewind(input_employee_code);

	int sizeofRow;
	Dependent_lk minDependent;

	int maxAge = INT_MAX;
	//int minAge;

	char maxName[100] = {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255};
	//char minName[100];

	int maxEmployeeCode = INT_MAX;
	//float minWage;

	strcpy(minDependent.name, maxName);
	minDependent.age = maxAge;
	minDependent.employee_code = maxEmployeeCode;
	// AGE
	sizeofRow = sizeof(int) * 2 + sizeof(int);
	while(1) {
		rewind(input_age);
		minDependent.age = maxAge;
		while (dep_readLine(row, input_age, 32)) {
			if(row->age < minDependent.age) {
				minDependent = *row;
			}
		}

		if(minDependent.age == maxAge)
			break;
		fseek(input_age, (minDependent.disc_addr * sizeofRow + (sizeof(int) * 2)), SEEK_SET);
		fwrite(&maxAge, sizeof(int), 1, input_age);
		dep_writeLine(&minDependent, output_age, NULL, NULL, 42);
	}
	// NAME
	sizeofRow = sizeof(int) * 2 + sizeof(char) * sizeof(row->name);
	while(1) {
		rewind(input_name);
		strcpy(minDependent.name, maxName);
		while (dep_readLine(row, input_name, 31)) {
			if(strcmp(row->name, minDependent.name) < 0) {
				minDependent = *row;
			}
		}

		if(strcmp(minDependent.name, maxName) == 0)
			break;

		fseek(input_name, (minDependent.disc_addr * sizeofRow + (sizeof(int) * 2)), SEEK_SET);
		fwrite(&maxName, sizeof(char), sizeof(row->name), input_name);
		dep_writeLine(&minDependent, output_name, NULL, NULL, 41);
	}
	// EMPLOYEE_CODE
	sizeofRow = sizeof(int) * 2 + sizeof(int);
	while(1) {
		rewind(input_employee_code);
		minDependent.employee_code = maxEmployeeCode;
		while (dep_readLine(row, input_employee_code, 33)) {
			if(row->employee_code < minDependent.employee_code) {
				minDependent = *row;
			}
		}

		if(minDependent.employee_code == maxEmployeeCode)
			break;

		fseek(input_employee_code, (minDependent.disc_addr * sizeofRow + (sizeof(int) * 2)), SEEK_SET);
		fwrite(&maxEmployeeCode, sizeof(int), 1, input_employee_code);
		dep_writeLine(&minDependent, output_employee_code, NULL, NULL, 43);
	}

}

int dep_createA5File(FILE* input_1, FILE* input_2, FILE* input_3, FILE *output_1, FILE *output_2, FILE *output_3){
	Dependent_lk * row = (Dependent_lk*) malloc(sizeof(Dependent_lk));
	int fileAddress, code, age, usedAddress = -1;
	int chosenAddress, chosenCode, chosenAge;
	int employee_code, chosenEmployeeCode;
	char name[100];
	char chosenName[100];
	int i = 1, j = 0;
	int count = 1;

	rewind(input_1);
	rewind(input_2);
	rewind(input_3);

	while(dep_readLine(row,input_1,41)){
		chosenAddress = row->disc_addr;
		chosenCode = row->code;
		strcpy(chosenName, row->name);
		while(dep_readLine(row,input_1,41))
		{
			fileAddress = row->disc_addr;
			code = row->code;
			strcpy(name, row->name);
			if(chosenAddress == -1)
				break;

			//i++;
			if(strcmp(chosenName, name) == 0){
				printf("Entro no if---------------------------\n" );
				fseek(input_1, - ((sizeof(int) *2) + (sizeof(char) * 100)), SEEK_CUR);
				fwrite(&usedAddress, sizeof(int), 1, input_1);
				fseek(input_1, sizeof(int) + (sizeof(char) * 100), SEEK_CUR);
				count++;
			}
		}
		if(chosenAddress != -1){
			fwrite(chosenName, sizeof(char), sizeof(chosenName), output_1);
			fwrite(&chosenAddress, sizeof(int), 1, output_1);
			fwrite(&count, sizeof(int), 1, output_1);
		}
		count = 1;
		j++;
		fseek(input_1, j * (sizeof(int) *2  + sizeof(char) * sizeof(row->name)), SEEK_SET);
		if(row) memset(row,0,sizeof(Dependent_lk));
	}

	i = 1; j = 0;
	count = 1;
	while(dep_readLine(row, input_2, 42))
	{
		chosenAddress = row->disc_addr;
		chosenCode = row->code;
		chosenAge = row->age;
		while(dep_readLine(row, input_2, 42))
		{
			fileAddress = row->disc_addr;
			code = row->code;
			age = row->age;
			if(chosenAddress == -1)
				break;

			i++;
			if(chosenAge == age){
				fseek(input_2, - sizeof(int) * 3, SEEK_CUR);
				fwrite(&usedAddress, sizeof(int), 1, input_2);
				fseek(input_2, sizeof(int)*2, SEEK_CUR);
				count++;
			}
		}
		if(chosenAddress != -1){
			fwrite(&chosenAge, sizeof(int), 1, output_2);
			fwrite(&chosenAddress, sizeof(int), 1, output_2);
			fwrite(&count, sizeof(int), 1, output_2);
		}
		count = 1;
		j++;
		fseek(input_2, j * sizeof(int) *3, SEEK_SET);
	}

	i = 1; j = 0;
	count = 1;
	while(dep_readLine(row, input_3, 43))
	{
		chosenAddress = row->disc_addr;
		chosenCode = row->code;
		chosenEmployeeCode = row->employee_code;
		printf("chosenEmployeeCode = %d\n", chosenEmployeeCode);
		while(dep_readLine(row, input_3, 43))
		{
			fileAddress = row->disc_addr;
			code = row->code;
			employee_code = row->employee_code;
			if(chosenAddress == -1)
				break;

			i++;
			if(employee_code == chosenEmployeeCode){
				fseek(input_3, - sizeof(int) * 2 - sizeof(int), SEEK_CUR);
				fwrite(&usedAddress, sizeof(int), 1, input_3);
				fseek(input_3, sizeof(int) + sizeof(int), SEEK_CUR);
				count++;
			}
		}
		if(chosenAddress != -1){
			fwrite(&chosenEmployeeCode, sizeof(int), 1, output_3);
			fwrite(&chosenAddress, sizeof(int), 1, output_3);
			fwrite(&count, sizeof(int), 1, output_3);
		}
		count = 1;
		j++;
		fseek(input_3, j * (sizeof(int) *2 + sizeof(int)), SEEK_SET);
	}

}

int dep_createA6File(FILE* input_1, FILE* input_2, FILE* input_3, FILE *output_1, FILE *output_2, FILE *output_3){
	Dependent_lk * row = (Dependent_lk*) malloc(sizeof(Dependent_lk));
	int fileAddress, code, age, usedAddress = -1;
	int chosenAddress, chosenCode, chosenAge;
	int chosenEmployeeCode, employee_code;
	char name[100], chosenName[100];
	int j = 0;
  int equal = 0;

	rewind(input_1);
	rewind(input_2);
	rewind(input_3);

	while(dep_readLine(row, input_1, 41))
	{
		chosenAddress = row->disc_addr;
		chosenCode = row->code;
		strcpy(chosenName, row->name);
		/*
		printf("Address %d\n",chosenAddress );
		printf("Code %d\n",chosenCode );
		printf("%s\n",chosenName );
		printf("While---------------\n");
		*/

		while(dep_readLine(row, input_1, 41))
		{
			if(strcmp(chosenName, row->name) == 0){
		        fwrite(&chosenAddress, sizeof(int), 1, output_1);
		        fwrite(&chosenCode, sizeof(int), 1, output_1);
		        fwrite(chosenName, sizeof(char), sizeof(chosenName), output_1);
		        fwrite(&row->disc_addr, sizeof(int), 1, output_1);
		        equal = 1;
		        break;
	        }
		}
		if(equal != 1){
			fwrite(&chosenAddress, sizeof(int), 1, output_1);
			fwrite(&chosenCode, sizeof(int), 1, output_1);
			fwrite(chosenName, sizeof(char), sizeof(chosenName), output_1);
			fwrite(&usedAddress, sizeof(int), 1, output_1);
		}
		j++;
		fseek(input_1, j * (sizeof(int) * 2 + sizeof(char) * 100), SEEK_SET);
		equal = 0;
	}
	j = 0;
	equal = 0;

	while(dep_readLine(row, input_2, 42))
	{
		chosenAddress = row->disc_addr;
		chosenCode = row->code;
		chosenAge = row->age;
		while(dep_readLine(row, input_2, 42))
		{
			if(chosenAge == row->age){
				fwrite(&chosenAddress, sizeof(int), 1, output_2);
				fwrite(&chosenCode, sizeof(int), 1, output_2);
				fwrite(&chosenAge, sizeof(int), 1, output_2);
				fwrite(&row->disc_addr, sizeof(int), 1, output_2);
				equal = 1;
				break;
			}
		}
		if(equal != 1){
			fwrite(&chosenAddress, sizeof(int), 1, output_2);
			fwrite(&chosenCode, sizeof(int), 1, output_2);
			fwrite(&chosenAge, sizeof(int), 1, output_2);
			fwrite(&usedAddress, sizeof(int), 1, output_2);
		}
		j++;
		fseek(input_2, j * sizeof(int) * 3, SEEK_SET);
		equal = 0;
	}
	j = 0;
	equal = 0;

	while(dep_readLine(row, input_3, 43))
	{
		chosenAddress = row->disc_addr;
		chosenCode = row->code;
		chosenEmployeeCode = row->employee_code;
		while(dep_readLine(row, input_3, 43))
		{
			if(chosenEmployeeCode == row->employee_code){
				fwrite(&chosenAddress, sizeof(int), 1, output_3);
				fwrite(&chosenCode, sizeof(int), 1, output_3);
				fwrite(&chosenEmployeeCode, sizeof(int), 1, output_3);
				fwrite(&row->disc_addr, sizeof(int), 1, output_3);
				equal = 1;
				break;
			}
		}
		if(equal != 1){
			fwrite(&chosenAddress, sizeof(int), 1, output_3);
			fwrite(&chosenCode, sizeof(int), 1, output_3);
			fwrite(&chosenEmployeeCode, sizeof(int), 1, output_3);
			fwrite(&usedAddress, sizeof(int), 1, output_3);
		}
		j++;
		fseek(input_3, j * (sizeof(int) * 2 + sizeof(int)), SEEK_SET);
		equal = 0;
	}

}

void dep_createA7File(FILE* input, FILE *output, int col){
	Dependent_lk * row = (Dependent_lk*) malloc(sizeof(Dependent_lk));
		// col = 1 p/ name
		// col = 2 p/ age
		// col = 3 p/ wage
		rewind(input);
	Dependent_lk minDependent;
	int i, pos_min, sizeofRow;

	int maxCode = INT_MAX;
	minDependent.code = maxCode;

	switch (col) {
		case 1:
			sizeofRow = sizeof(int) * 3 + sizeof(char) * sizeof(row->name);
			break;
		case 2:
			sizeofRow = sizeof(int) * 3 + sizeof(int);
			break;
		case 3:
			sizeofRow = sizeof(int) * 3 + sizeof(int);
			break;
		default:
			return ;
	}

	while (1) {
		rewind(input);
		minDependent.code = maxCode;
		i = 0;
		while (dep_readLine(row, input, (60 + col))) {
			if(row->code < minDependent.code){
				minDependent = *row;

				pos_min = i;
			}
			i++;
		}
		if(minDependent.code == maxCode)
			break;
		fseek(input, (pos_min * sizeofRow + (sizeof(int))), SEEK_SET);
		fwrite(&maxCode, sizeof(int), 1, input);

		dep_writeLine(&minDependent, output, NULL, NULL, (70 + col));

	}
}

void dep_createA8File(FILE* a1, FILE* a7_name, FILE* a7_age, FILE* a7_employee_code, FILE *output){
	Dependent_lk row_a8;
	Dependent_lk row_a1, row_a7_name, row_a7_age,  row_a7_employee_code;
	rewind(a1);
	rewind(a7_name);
	rewind(a7_age);
	rewind(a7_employee_code);

	while(dep_readLine(&row_a1, a1, 1) && dep_readLine(&row_a7_name, a7_name, 71) && dep_readLine(&row_a7_age, a7_age, 72) && dep_readLine(&row_a7_employee_code, a7_employee_code, 73)){
		printf("Entrei no a8\n" );
		row_a8 = row_a1;
		row_a8.prox_1 = row_a7_name.prox_1;
		row_a8.prox_2 = row_a7_age.prox_2;
		row_a8.prox_3 = row_a7_employee_code.prox_3;

		dep_writeLine(&row_a8, output, NULL, NULL, 8);

		// fwrite(&row_a1->code, sizeof(int), 1, output);
		// fwrite(row_a1->name, sizeof(char), sizeof(row->name), output);
		// fwrite(&row_a1->age, sizeof(int), 1,output);
		// fwrite(&row_a1->wage, sizeof(float), 1,output);
		// fwrite(&row_a7_name->prox_1, sizeof(int), 1, output);
		// fwrite(&row_a7_age->prox_2, sizeof(int), 1, output);
		// fwrite(&row_a7_wage->prox_3, sizeof(int), 1, output);
	}

}

void dep_sortA1File(FILE* input, FILE *output){
	Dependent_lk * row = (Dependent_lk*) malloc(sizeof(Dependent_lk));
	rewind(input);
		// col = 1 p/ name
		// col = 2 p/ age
		// col = 3 p/ wage
	int iMin = -1;
	Dependent_lk minDependent;
	int i, pos_min,j=0;

	int minCode = INT_MAX,ultimoCodigoInserido = 0;
	minDependent.code = minCode;

	while (j < HASH_SIZE) {
		rewind(input);
		// minDependent.code = minCode;
		minCode = INT_MAX;
		i = 0;
		while (dep_readLine(row, input,1)) {
			if(row->code < minCode && row->code > ultimoCodigoInserido){
				minCode = row->code;

				pos_min = i;
				minDependent.code = row->code;
				strcpy(minDependent.name,row->name);
				minDependent.age = row->age;
				minDependent.employee_code = row->employee_code;
				minDependent.status = row->status;
				minDependent.pointer = row->pointer;
			}
			i++;
		}
		// if(minDependent.code == minCode)
		// 	break;
		// fseek(input, (pos_min * sizeofRow + (sizeof(int))), SEEK_SET);
		// fwrite(&minCode, sizeof(int), 1, input);
		fseek(input,(pos_min * dep_sizeofDependent()), SEEK_SET);
		fwrite(&minDependent.code, sizeof(int), 1, output);
		fwrite(minDependent.name, sizeof(char), sizeof(minDependent.name), output);
		fwrite(&minDependent.age, sizeof(int), 1, output);
		fwrite(&minDependent.employee_code, sizeof(int), 1, output);
		fwrite(&minDependent.status, sizeof(int), 1, output);
		fwrite(&minDependent.pointer, sizeof(int), 1, output);
		ultimoCodigoInserido = minDependent.code;
		j++;

	}
}

void dep_printTableA2(FILE *tableFile){
	Dependent_lk *dep = (Dependent_lk *) malloc(sizeof(Dependent_lk));
	rewind(tableFile);
	while(dep_readLine(dep, tableFile, 2)){
		printf("\n-----------------\n");
		printf("disc_addr: %d\n",dep->disc_addr);
		printf("code: %d\n", dep->code);
		printf("name: %s\n", dep->name);
		printf("age: %d\n", dep->age );
		printf("employee_code: %d\n", dep->employee_code );

	}
	free(dep);
}

void dep_printTableA3(FILE *tableFile, int col) {
	Dependent_lk *dep = (Dependent_lk *) malloc(sizeof(Dependent_lk));
	rewind(tableFile);
	switch (col) {
		case 1:
			while(dep_readLine(dep, tableFile, 31)){
				printf("\n-----------------\n");
				printf("disc_addr: %d\n",dep->disc_addr);
				printf("code: %d\n", dep->code);
				printf("name: %s\n", dep->name);
			}
		break;
		case 2:
			while(dep_readLine(dep, tableFile, 32)){
				printf("\n-----------------\n");
				printf("disc_addr: %d\n",dep->disc_addr);
				printf("code: %d\n", dep->code);
				printf("age: %d\n", dep->age );
			}
			break;
		case 3:
			while(dep_readLine(dep, tableFile, 33)){
				printf("\n-----------------\n");
				printf("disc_addr: %d\n",dep->disc_addr);
				printf("code: %d\n", dep->code);
				printf("employee_code: %d\n", dep->employee_code );
			}
			break;

	}
	free(dep);
}

void dep_printTableA4(FILE *tableFile, int col) {
	Dependent_lk *dep = (Dependent_lk *) malloc(sizeof(Dependent_lk));
	rewind(tableFile);
	switch (col) {
		case 1:
			while(dep_readLine(dep, tableFile, 41)){
				printf("\n-----------------\n");
				printf("disc_addr: %d\n",dep->disc_addr);
				printf("code: %d\n", dep->code);
				printf("name: %s\n", dep->name);
			}
		break;
		case 2:
			while(dep_readLine(dep, tableFile, 42)){
				printf("\n-----------------\n");
				printf("disc_addr: %d\n",dep->disc_addr);
				printf("code: %d\n", dep->code);
				printf("age: %d\n", dep->age );
			}
			break;
		case 3:
			while(dep_readLine(dep, tableFile, 43)){
				printf("\n-----------------\n");
				printf("disc_addr: %d\n",dep->disc_addr);
				printf("code: %d\n", dep->code);
				printf("employee_code: %d\n", dep->employee_code );
			}
			break;

	}
	free(dep);
}

void dep_printTableA5(FILE *tableFile, int col) {
	Dependent_lk *dep = (Dependent_lk *) malloc(sizeof(Dependent_lk));
	rewind(tableFile);
	switch (col) {
		case 1:
			while(dep_readLine(dep, tableFile, 51)){
				printf("\n-----------------\n");
				printf("name: %s\n", dep->name);
				printf("a5_pt: %d\n", dep->a5_pt);
				printf("a5_q: %d\n", dep->a5_q);
			}
		break;
		case 2:
			while(dep_readLine(dep, tableFile, 52)){
				printf("\n-----------------\n");
				printf("age: %d\n", dep->age );
				printf("a5_pt: %d\n", dep->a5_pt);
				printf("a5_q: %d\n", dep->a5_q);
			}
			break;
		case 3:
			while(dep_readLine(dep, tableFile, 53)){
				printf("\n-----------------\n");
				printf("employee_code: %d\n", dep->employee_code );
				printf("a5_pt: %d\n", dep->a5_pt);
				printf("a5_q: %d\n", dep->a5_q);
			}
			break;

	}
	free(dep);
}

void dep_printTableA6(FILE *tableFile, int col) {
	Dependent_lk *dep = (Dependent_lk *) malloc(sizeof(Dependent_lk));
	rewind(tableFile);
	switch (col) {
		case 1:
			while(dep_readLine(dep, tableFile, 61)){
				printf("\n-----------------\n");
				printf("Address: %d\n",dep->disc_addr);
				printf("code: %d\n", dep->code);
				printf("name: %s\n", dep->name);
				printf("pointer: %d\n", dep->prox_1);
			}
		break;
		case 2:
			while(dep_readLine(dep, tableFile, 62)){
				printf("\n-----------------\n");
				printf("Address: %d\n",dep->disc_addr);
				printf("code: %d\n", dep->code);
				printf("Age: %d\n", dep->age);
				printf("pointer: %d\n", dep->prox_2);
			}
			break;
		case 3:
			while(dep_readLine(dep, tableFile, 63)){
				printf("\n-----------------\n");
				printf("Address: %d\n",dep->disc_addr);
				printf("code: %d\n", dep->code);
				printf("employee_code: %d\n", dep->employee_code);
				printf("pointer: %d\n", dep->prox_3);
			}
			break;

	}
	free(dep);
}

void dep_printTableA7(FILE *tableFile, int col) {
	Dependent_lk *dep = (Dependent_lk *) malloc(sizeof(Dependent_lk));
	rewind(tableFile);
	switch (col) {
		case 1:
			while(dep_readLine(dep, tableFile, 71)){
				printf("\n-----------------\n");
				printf("Address: %d\n",dep->disc_addr);
				printf("code: %d\n", dep->code);
				printf("name: %s\n", dep->name);
				printf("pointer: %d\n", dep->prox_1);
			}
		break;
		case 2:
			while(dep_readLine(dep, tableFile, 72)){
				printf("\n-----------------\n");
				printf("Address: %d\n",dep->disc_addr);
				printf("code: %d\n", dep->code);
				printf("Age: %d\n", dep->age);
				printf("pointer: %d\n", dep->prox_2);
			}
			break;
		case 3:
			while(dep_readLine(dep, tableFile, 73)){
				printf("\n-----------------\n");
				printf("Address: %d\n",dep->disc_addr);
				printf("code: %d\n", dep->code);
				printf("employee_code: %d\n", dep->employee_code);
				printf("pointer: %d\n", dep->prox_3);
			}
			break;

	}
	free(dep);
}

void dep_printTableA8(FILE *tableFile) {
	Dependent_lk *dep = (Dependent_lk *) malloc(sizeof(Dependent_lk));
	rewind(tableFile);
	while(dep_readLine(dep, tableFile, 8)){
		printf("\n-----------------\n");
		printf("Code: %d\n",dep->code);
		printf("Name: %s\n", dep->name);
		printf("Age: %d\n", dep->age);
		printf("employee_code: %d\n", dep->employee_code);
		printf("prox1: %d\n", dep->prox_1);
		printf("prox2: %d\n", dep->prox_2);
		printf("prox3: %d\n", dep->prox_3);
	}
	free(dep);
}
