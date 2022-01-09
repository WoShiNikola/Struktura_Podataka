#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX_SIZE (128)

typedef struct _tree* left;
typedef struct _tree* right;

typedef struct _tree {

	int citizenAmount;
	char cityName[MAX_SIZE];
	left leftLeaf;
	right rightLeaf;

}Tree;

typedef struct _list* pointer;

typedef struct _list {
	char* countryName[MAX_SIZE];
	Tree* Cities;
	pointer next;
}List;



int addToList(char* fileName, List* head);
int printList(List* headElement);
List* createNode(char* countryName, char* Cities);

Tree* createLeaf(char* cityName, int population_number);
Tree* createTreeLeaves(char* cityFilename);
int addLeafBySize(Tree* root, char* city, int size);

int main() {

	List head = { .countryName = {'\0'}, .next = NULL };

	printf("%d\n", addToList("Countries.txt", &head));

	printList(head.next);

	return 0;
}

int addToList(char* fileName, List* head) {

	FILE* fp = fopen(fileName, "r");
	if (!fp)
		return -1;
	char names[MAX_SIZE] = { '\0' };
	char names_2[MAX_SIZE] = { '\0' };
	List* temp = head;

	while (!feof(fp)) {

		fscanf(fp, "%s %s", names, names_2);
		List* newOne = createNode(names, names_2);
		
		while (temp) {
			
			if (temp->next && strcmp(temp->next->countryName, newOne->countryName) < 0 ){
				temp = temp->next;
			}
			else {
				newOne->next = temp->next;
				temp->next = newOne;
				break;
			}
		}
		temp = head;
	}
	fclose(fp);
	return 0;
}

List* createNode(char* countryName, char* cityFilename) {

	
	List* newNode = (List*)malloc(sizeof(List));
	if (!newNode) {
		printf("Allocazione della memoria non riuscita \n");
		return newNode;
	}



	newNode->Cities = createTreeLeaves(cityFilename);

	printTree(newNode->Cities);

	strcpy(newNode->countryName, countryName);
	newNode->next = NULL;

	return newNode;
}
Tree* createLeaf(char* cityName, int population_number) {

	Tree* newLeaf = (Tree*)malloc(sizeof(Tree));
	if (!newLeaf) {
		printf("Allocazione della memoria non riuscita \n");
		return newLeaf;
	}
	newLeaf->citizenAmount = population_number;
	strcpy(newLeaf->cityName, cityName);
	newLeaf->leftLeaf = NULL;
	newLeaf->rightLeaf = NULL;

	return newLeaf;

}

Tree* createTreeLeaves(char* cityFilename) {

	FILE* fp_2 = fopen(cityFilename, "r");
	if (!fp_2) {
		printf("Didn't open mate\n");
		return NULL;
	}
	char cityName[MAX_SIZE] = { '\0' };
	int population = 0;

	Tree* newTree = createLeaf(cityName, population);

	while (!feof(fp_2)) {
		fscanf(fp_2, "%s %d", cityName, &population);

		
		addLeafBySize(newTree, cityName, population);
	}

	fclose(fp_2);
	return newTree;
}

int addLeafBySize(Tree* root, char* city, int size) {

	if (!root->citizenAmount) {
		root->citizenAmount = size;
		strcpy(root->cityName, city);
		return 0;
	}
	if (size > root->citizenAmount && root->rightLeaf)
		addLeafBySize(root->rightLeaf, city, size);
	else {
		Tree* newLeaf = createLeaf(city, size);
		root->rightLeaf = newLeaf;
	}
	if (size < root->citizenAmount && root->leftLeaf)
		addLeafBySize(root->leftLeaf, city, size);
	else {
		Tree* newLeaf_2 = createLeaf(city, size);
		root->leftLeaf = newLeaf_2;
	}

	return 0;

}

int printTree(Tree* root) {
	if (!root)
		return 0;

	printf("\tName: %s Size: %d\n", root->cityName, root->citizenAmount);
	printTree(root->rightLeaf);
	printTree(root->leftLeaf);

	return 0;
}

int printList(List* headElement) {

	List* temp = headElement;
	while (temp) {
		printf("%s ", temp->countryName);
		temp = temp->next;
	}
	return 0;
}