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
	int choice = -1;
	int element,pos, size;

	Node *first = NULL;

	void addElement(Node **p, int v);
	void displayElements(Node *p);
	void displayElementsInReverse(Node *p);
	int deleteElement(Node **p, int v);

	setbuf(stdout, NULL);
	printf("Enter the choice : \n1 to add\n2 to print\n3 for display elements in reverse\n4 for delete an element\n");

	do{
		printf("Enter choice : ");
		scanf("%d",&choice);

		switch (choice) {
			case 1:{
				//Add an element

				printf("Enter the element\n");
				scanf("%d",&element);

				addElement(&first, element);
				break;
			}
			case 2:{
				//Print the list

				displayElements(first);
				break;
			}
			case 3:{
				//Print list in reverse

				displayElementsInReverse(first);
				break;
			}
			case 4:{
				//Delete an element

				printf("Enter the element\n");
				scanf("%d",&element);

				if(deleteElement(&first, element) == 1){
					printf("Deleted\n");
				}
				else{
					printf("Not deleted\n");
				}

				break;
			}

			default:{
				choice = -1;
			}
		}


	}while(choice != -1);


	printf("End");

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

int deleteElement(Node **p, int v){

	Node *temp,*previous;
	temp = *p;

	while(temp != NULL){

		if(temp->data == v){
			break;
		}

		previous = temp;
		temp = temp->next;

	}

	if(temp  == NULL){
		return 0;
	}
	else{

		if(temp == *p){
			*p = temp->next;
			(*p)->previous = NULL;
			free(temp);
		}
		else{
			previous->next = temp->next;
			temp->next->previous = temp->previous;
			free(temp);
		}

		return 1;
	}

}
