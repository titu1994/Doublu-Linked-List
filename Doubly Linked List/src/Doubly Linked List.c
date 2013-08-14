/*
 ============================================================================
 Name        : Doubly.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next, *previous;
}Node;


int main(void) {




	return EXIT_SUCCESS;
}


void addElement(Node **p, int v){
	Node *newNode = NULL;

	newNode = (Node*) calloc(1, sizeof(Node));
	newNode->data = v;
	newNode->next = NULL;
	newNode->previous = NULL;

	if(*p == NULL){
		*p = newNode;
		(*p)->previous = NULL;
	}
	else{
		Node *temp = *p;

		while(temp->next != NULL){
			temp = temp->next;
		}

		temp->next = newNode;
		newNode->previous = temp;
	}


}

void displayElements(Node *p){

	while(p != NULL){
		printf("%d\t",p->data);
		p = p->next;
	}
	printf("\n");

}

void displayElementsInReverse(Node *p){

	while(p->next != NULL){
		p = p->next;
	}

	while(p != NULL){
		printf("%d\t",p->data);
		p = p->previous;
	}

	printf("\n");

}


