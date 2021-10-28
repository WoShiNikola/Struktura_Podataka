#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 128
#define MAX_LINE 1024

typedef struct _students {
	char name[MAX_SIZE];
	char surname[MAX_SIZE];
	int points;
} Students;

int _countStudents(char* fileName);
Students* allocateMemoryAndReadFromFile(int studentCount, char* fileName);
int printStructure(Students* pointer, int studentCount);


int main() {

	int x = 0;

	x = _countStudents("Students.txt");
	printf("The number of students is: %d\n", x);
	
	printStructure(allocateMemoryAndReadFromFile(x, "Students.txt"), x);

	return 0;
}


int _countStudents(char* fileName) {

	int count = 0;
	FILE* fp = NULL;
	char buffer[MAX_LINE] = { 0 };

	if (!(fp = fopen(fileName, "r+"))) {
		printf("Couldn't open the file, sorry\n");
		return -1;
	}

	while (!feof(fp)){
		fgets(buffer, MAX_LINE, fp);
		count++;
	}

	fclose(fp);

	return count;
}

Students* allocateMemoryAndReadFromFile(int studentCount, char* fileName)
{
	FILE* fp = NULL;
	Students* p = NULL;
	int count = 0;
	

	if (!(fp = fopen(fileName, "r"))) {
		printf("Couldn't open the file man, sorry\n");
		return NULL;
	}

	if (!(p = (Students*)malloc(sizeof(Students) * studentCount))) {
		printf("Well, seems to be a problem with allocating memory for your structure my friend\n");
		return NULL;
	}

	while (!feof(fp) && count < studentCount) {
		fscanf(fp, " %s %s %d", p[count].name, p[count].surname, &p[count].points);
		count++;
	}
	fclose(fp);
	return p;
}

int printStructure(Students* pointer, int studentCount) {
	int count = 0;
	while (count < studentCount){
		printf(" %s %s %d\n", pointer[count].name, pointer[count].surname, pointer[count].points);
		count++;
	}
	return 0;
}