#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _tree* left;
typedef struct _tree* right;

typedef struct _tree {
	int number;
	left nextLeft;
	right nextRight;
}Tree;

Tree* createTree(int number) {

	Tree* newTree = (Tree*)malloc(sizeof(Tree));
	if (!newTree) {
		printf("Allocation failed\n");
		return newTree;
	}

	newTree->nextLeft = NULL;
	newTree->nextRight = NULL;
	newTree->number = number;

	return newTree;
}

Tree* addtoTree(Tree* root, int data) {

	if (!root)
		return root;

	if (root->number <= data) {
		if (!root->nextLeft) {
			Tree* newTree = createTree(data);
			root->nextLeft = newTree;
			return newTree;
		}
		else
			addtoTree(root->nextLeft, data);
	}
	else if (root->number > data) {
		if (!root->nextRight) {
			Tree* newTree = createTree(data);
			root->nextRight = newTree;
			return newTree;
		}
		else
			addtoTree(root->nextRight, data);
	}
	

	return root;
}

int printTree(Tree* root) {
	
	if (!root)
		return 0;
	

	printTree(root->nextRight);
	printf("%d ", root->number);
	printTree(root->nextLeft);
	
	

	return 0;
}

//int replaceWithSum(Tree* root) {
//
//	if (!root)
//		return 0;
//	
//	if (!root->nextLeft && !root->nextRight) {
//		root->number = 0;
//	}
//
//	return 0;
//}

//int traverseTree(Tree* root, int *data) {
//
//	if (!root)
//		return 0;
//	traverseTree(root->nextLeft, data);
//	traverseTree(root->nextRight, data);
//
//	*data = *data + root->number;
//
//	return 0;
//}

//int traverseTree(Tree* root, int *data) {
//
//	if (!root)
//		return 0;
//	
//	traverseTree(root->nextLeft, data);
//	traverseTree(root->nextRight, data);
//	*data += root->number;
//	
//
//	
//
//	if (!root->nextLeft && !root->nextRight) {
//		root->number = 0;
//	}
//	else
//		root->number = *data - root->number;
//
//	return 0;
//}
//void increment(Tree* root, int diff)
//{
//	/* IF left child is not NULL then increment it */
//	if (root->nextLeft)
//	{
//		root->nextLeft->number = root->nextLeft->number + diff;
//
//		// Recursively call to fix the descendants of node->left
//		increment(root->nextLeft, diff);
//	}
//	else if (root->nextRight) // Else increment right child
//	{
//		root->nextRight->number = root->nextRight->number + diff;
//
//		// Recursively call to fix the descendants of node->right
//		increment(root->nextRight, diff);
//	}
//}

//int traverseTree(Tree* root){
//
//	int left_number = 0, right_number = 0, diff = 0;
//
//	if (!root ||
//		(!root->nextLeft && !root->nextRight))
//	{
//		return 0;
//	}
//	else {
//		traverseTree(root->nextLeft);
//		traverseTree(root->nextRight);
//
//		if (root->nextLeft) {
//			left_number = root->nextLeft->number;
//		}
//
//		if (root->nextRight) {
//			right_number = root->nextRight->number;
//		}
//
//		diff = left_number + right_number - root->number;
//
//		if (diff > 0)
//			root->number = root->number + diff;
//
//		if (diff < 0)
//			increment(root, -diff);
//	}
	
	

	/*if (!root->nextLeft && !root->nextRight) {
		root->number = 0;
	}
	*/

	// return root->number;
//}

int traverseTree(Tree* root) {

	if (!root)
		return 0;
	int temp = root->number;
	int sum = traverseTree(root->nextLeft) + traverseTree(root->nextRight);
	
	if (root->nextLeft || root->nextRight)
		root->number = sum;

	if (!root->nextLeft && !root->nextRight) {
		root->number = 0;
	}

	return temp + sum;
}

int printToFile(char* fileName, Tree* root) {

	FILE* fp = fopen(fileName, "a");
	if (!fp)
		return -1;


	goThroughTree(root, fp);
	
	traverseTree(root);

	goThroughTree(root, fp);
	
	fclose(fp);

	return 0;
}
int goThroughTree(Tree* root, FILE* fp) {

	if (!root)
		return 0;
	goThroughTree(root->nextRight, fp);
	fprintf(fp,"%d ", root->number);
	goThroughTree(root->nextRight, fp);

	return 0;
}


int main() {

	
	time_t t = 0;
	Tree head = { .nextLeft = NULL, .nextRight = NULL, .number = 2 };
	srand((unsigned)time(&t));

	for (int i = 0; i < 10; i++) {
		addtoTree(&head, rand() % (90 + 1 - 10) + 10);
	}

	/*addtoTree(&head, 5);
	addtoTree(&head, 7);
	addtoTree(&head, 8);
	addtoTree(&head, 11);
	addtoTree(&head, 1);
	addtoTree(&head, 4);
	addtoTree(&head, 2);
	addtoTree(&head, 3);
	addtoTree(&head, 7);*/

	printToFile("took_me_too_fucking_long_to_do_this_one_sorry.txt", &head);
	
	printTree(&head);

	return 0;
}