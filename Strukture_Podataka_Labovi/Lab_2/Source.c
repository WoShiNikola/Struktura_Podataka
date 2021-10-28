#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 128

typedef struct _person {
	int ID_number;
	/*char name[MAX_SIZE];
	char surname[MAX_SIZE];
	int _year_birth;*/
	struct _person* next;
}Person;




int addToListBegin(Person** p);
int printList(Person* first);
int addToListEnd(Person** first);
int printElement(Person* first, int element);
int eraseElement(Person** first, int element);



int main() {

	Person* head = NULL;

	int i = 1, del = 0;



	while (i) {
		printf("Enter wanted action:\n");
		printf("*1) Enter a new element on the beginning of the list\n"
			   "*2) Enter a new element at the end of the list\n"
			   "*3) Print the list\n"
			   "*4) Find and print Element by ID\n"
			   "*5) Erase an element\n"
			   "*0) Exit the program\n"
		       "-----------------------------   ");
		scanf(" %d", &i);
		if (i == 1)
			addToListBegin(&head);
		else if (i == 2)
			addToListEnd(&head);
		else if (i == 3)
			printList(head);
		else if (i == 4)
			printElement(head, 4);
		else if (i == 5) {
			printf("Enter which one you want to erase: \n");
			scanf(" %d", &del);
			eraseElement(&head, del);
		}
		else if (!i)
			break;

	}
	return 0;
}

int addToListBegin(Person** p) {

	Person* newOne = (Person*)malloc(sizeof(Person));


	if (!(*p)) {
		newOne->next = NULL;
		*p = newOne;
		newOne->ID_number = 0;
		return 0;
	}
	int x = 0;
	scanf(" %d", &x);
	newOne->ID_number = x;
	newOne->next = *p;
	*p = newOne;

	return 0;

}



int printList(Person* first) {

	Person* current = first;
	if (!current)
		return 0;

	while (current) {
		printf(" - %d", current->ID_number);
		current = current->next;
	}
	printf("\n");
	return 0;
}

int addToListEnd(Person** first) {

	Person* current = *first;
	Person* getNewOne = (Person*)malloc(sizeof(Person));


	while (current->next)
		current = current->next;


	getNewOne->ID_number = 25;
	getNewOne->next = current->next;
	current->next = getNewOne;

	return 0;

}

int printElement(Person* first, int element) {

	Person* current = first;
	if (!current)
		return 0;

	while (current ) {
		if (current->ID_number == element) {
			printf(" - %d", current->ID_number);
			break;
		}
		current = current->next;
	}
	printf("\n");
	return 0;
}

int eraseElement(Person** first, int element) {

	Person* p = *first, * q = *first;

    if(!p)
        return -1;

	while (q != NULL && q->ID_number != element) {
		p = q;
		q = q->next;
	}

	if (q == NULL)
	{
		printf("\nNo such number\n");
		return 0;
	}

	p->next = q->next;

	free(q);

	printf("\nDeleted: %d\n", element);

	return 0;
}
