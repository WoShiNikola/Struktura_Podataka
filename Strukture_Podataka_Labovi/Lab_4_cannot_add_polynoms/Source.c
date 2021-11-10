#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE (128)

// Gli structure sono importante, qui il definiamo

typedef struct _polynom{
	int coefficient;
	int exponent;
	struct _polynom* next;
}Polynom;

Polynom* AddPolynomsToList(char* fileName, Polynom* first);
int printList(Polynom* head);
int multiplyPolynoms(Polynom* first);
int addPolynoms(Polynom* first, char* fileName);

int main() {

	Polynom head = { .coefficient = 0, .exponent = 0, .next = NULL };

	head.next = AddPolynomsToList("Linkin_Park.txt", head.next);

	printList(head.next);
	multiplyPolynoms(head.next);
	
	return 0;
} 

Polynom* AddPolynomsToList(char* fileName, Polynom* first) {
	
	char buffName[MAX_SIZE] = { '\0' };
	int counter = 2, begin = 0, temp = 0;
	int i = 1;

	FILE* fp = fopen(fileName, "r");
	if (!fp) {
		printf("Non e possibile aprire questo file");
			return NULL;
	}

	fgets(buffName, MAX_SIZE, fp);

	
	
	while (counter != EOF && counter == 2) {

		Polynom* newOne = (Polynom*)malloc(sizeof(Polynom));
		

		counter = sscanf(buffName + temp, " %d %d %n", &newOne->coefficient, &newOne->exponent, &begin);
		temp += begin;
		if (counter == EOF)
			break;
		printf("x1: %d x2: %d n: %d savedVar: %d\n", newOne->coefficient, newOne->exponent, begin, counter);

		newOne->next = first;
		first = newOne;

	}


	return first;
}

int printList(Polynom* head) {

	Polynom* temp = head;

	while (temp) {
		printf("%dx^%d", temp->coefficient, temp->exponent);
		
		temp = temp->next;
		if(temp)
			printf(" + ");
	}
	
	free(temp);

	return 0;
}

int multiplyPolynoms(Polynom* first) {

	int x = 1, y = 0;

	Polynom* temp = first;

	while (temp) {
		x *= temp->coefficient;
		y += temp->exponent;
		temp = temp->next;
	}

	printf("\n%dx^%d", x, y);

	free(temp);


	return 0;
}

int addPolynoms(Polynom* first, char* fileName) {

	char buffName[MAX_SIZE] = { '\0' };
	int counter = 2, begin = 0, temp = 0;
	int i = 1;

	FILE* fp = fopen(fileName, "r");
	if (!fp) {
		printf("Non e possibile aprire questo file");
		return -1;
	}

	fgets(buffName, MAX_SIZE, fp);



	while (counter != EOF && counter == 2) {

		Polynom* newOne = (Polynom*)malloc(sizeof(Polynom));

		counter = sscanf(buffName + temp, " %d %d %n", &newOne->coefficient, &newOne->exponent, &begin);
		temp += begin;
		if (counter == EOF)
			break;
		printf("x1: %d x2: %d n: %d savedVar: %d\n", newOne->coefficient, newOne->exponent, begin, counter);

		newOne->next = first;
		first = newOne;

	}


	return 0;
}
