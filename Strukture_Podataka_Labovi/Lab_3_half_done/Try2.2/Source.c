#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE (128)

typedef struct _person {
	int ID_num;
	struct _person* next;
}Person;


Person* AddList(Person* firstOne);
int printList(Person* first);
Person* LastItem(Person* first);
Person* EraseItem(Person* head, int ID);
Person* AddAfter(int one, int add, Person * head);
Person* sortList(Person* head);
int printToFile(Person* head);
int ReadFromFile(char* fileName);



int main() {

	Person* head = (Person*)malloc(sizeof(Person));

	head->ID_num = 0;
	head->next = NULL;

	head = AddList(head);
	head = AddList(head);
	head = LastItem(head);
	head = AddList(head);
	
	head = LastItem(head);
	head = AddAfter(100, 2, head);

	head = AddList(head);

	head = EraseItem(head, 100);

	head = sortList(head);
	



	

	printList(head->next);

	return 0;
}

Person* AddList(Person* firstOne) {

	Person* nP = NULL;

	if (!(nP = (Person*)malloc(sizeof(Person)))) {
		printf("Couldn't allocate memory\n");
		return NULL;
	}
	nP->ID_num = 1;

	nP->next = firstOne;
	firstOne = nP;
	
	return firstOne;
}

int printList(Person* first) {

	Person* temp = first;

	if (!temp) {
		printf("List is empty\n");
		return -1;
	}

	while (temp) {
		printf("ID: %d ", temp->ID_num);
		temp = temp->next;
	}
	return 0;
}

Person* LastItem(Person* first) {

	Person* p = first;
	Person* n = (Person*)malloc(sizeof(Person));

	while (p->next) {
		p = p->next;
	}
	n->ID_num = 100;
	n->next = p->next;
	p->next = n;
		return first;
	}

Person* EraseItem(Person* head, int ID) {
	Person* p, *q;

	q = p = head;
	

	while (q && ID != q->ID_num) {
		p = q;
		q = q->next;
	}
	if (!q)
		return NULL;
	p->next = q->next;
	

	return head;
}

Person* AddAfter(int one, int add, Person* head) {

	Person* temp = head;

	while (temp && temp->ID_num != one) {
		temp = temp->next;
	}
	if (!temp) {
		printf("Couldn't add\n");
		return NULL;
	}
	if (temp->ID_num == one)
	{
		Person* newOne = (Person*)malloc(sizeof(Person));
		newOne->ID_num = add;
		newOne->next = temp->next;
		temp->next = newOne;
	}
	return head;
}

Person* sortList(Person* head) {
	
	Person* temp1 = head;
	Person* temp2 = temp1;

	while (temp1) {

		if (temp1->ID_num > temp2->ID_num) {
			int cont = temp1->ID_num;
			temp2->ID_num = temp1->ID_num;
			temp1->ID_num = cont;
		}
		temp2 = temp1;
		temp1 = temp1->next;
		
	}

	return head;
}

int printToFile(Person* head) {

	return 0;
}

int ReadFromFile(char* fileName) {

	return 0;
}

