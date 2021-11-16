#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE (128)

typedef struct _polynom {
	int _coefficient;
	int _exponent;
	struct _polynom* next;
}Polynom;

Polynom* createOne(int storeCoeff, int storeExp);
int loadFromFile(char* fileName, Polynom* head);
int printList(Polynom* head);
int sortedEntry(Polynom* head, Polynom* element);


int main() {

	Polynom head = { .next = NULL, ._coefficient = 0, ._exponent = 0 };

	loadFromFile("Mi_Dispiace.txt", &head);

	printList(head.next);

	return 0;
}

Polynom* createOne(int storeCoeff, int storeExp) {

	Polynom* newElement = (Polynom*)malloc(sizeof(Polynom));

	newElement->_coefficient = storeCoeff;
	newElement->_exponent = storeExp;

	newElement->next = NULL;

	return newElement;
}

int loadFromFile(char* fileName, Polynom* head) {

	FILE* fp = fopen(fileName, "r");
	if (!fp) {
		printf("Non possible aprire questo file\n");
		return -1;
	}


	int counter = 2, number = 0, temp = 0;
	int coeff = 0, exp = 0;

	char buffName[MAX_SIZE] = { '\0' };

	fgets(buffName, MAX_SIZE, fp);
	while (counter == 2) {
		
		counter = sscanf(buffName + temp, " %d %d %n", &coeff, &exp, &number);
		temp += number;
		if (counter != 2) {
			printf("Mangio i gatto\n");
			break;
		}
		Polynom* newOne = createOne(coeff, exp);
		sortedEntry(head, newOne);

	}
	return 0;
}

int sortedEntry(Polynom* head, Polynom* element) {

	Polynom* p = head;
	Polynom* q = p;


	if (!q->next) {
		element->next = q->next;
		q->next = element;
		return 0;
	}
	while (q && element->_exponent > q->_exponent) {
		p = q;
		q = q->next;
	}

	element->next = p->next;
	p->next = element;

	return 0;
}

int printList(Polynom* head) {

	Polynom* temp = head;

	int resultExp = 0, resultCoeff = 1;
	printf("Added: ");
	while (temp) {
		resultCoeff *= temp->_coefficient;
		resultExp += temp->_exponent;
		printf("%dx^%d ", temp->_coefficient, temp->_exponent);
		temp = temp->next;
		if (temp)
			printf("+ ");
	}

	printf("\nMultiplied: %dx^%d", resultCoeff, resultExp);

	return 0;
}
