//Program to demonstrate linked list
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//node declaration
typedef struct Node{
	char name[30]; //30
	struct Node *nxt; //8
}node;
//
node *createNode(char str[]){
	node *temp = (node *)malloc(sizeof(node));
	strcpy(temp->name, str);
	temp->nxt = NULL;
	return temp;
}
node* addFirst(node* list, char str[]){
	node *newNode = createNode(str);
	newNode->nxt = list;
	list = newNode;
	return list;
}
node* addLast(node* list, char str[]){
	node* newNode = createNode(str);
	//checking whether the list is having node or not
	if (list){
		node* temp;
		for (temp = list; temp->nxt; temp= temp->nxt);
		temp->nxt = newNode;
		return list;
	}
	return newNode;
		
}

//list traversal
void printList(node* list){
	printf("\n[");
	node* temp;
	for (temp = list; temp->nxt; temp=temp->nxt)
		printf("'%s',", temp->name);		
	printf("'%s']", temp->name);
}

int main(){
//	printf("%d %d %d", sizeof(int*), sizeof(char*), sizeof(node*))	;
	node *root = NULL;
	root = addLast(root, "Anish");
	root = addFirst(root, "Saran");
	root = addFirst(root, "Seenu");
	root = addFirst(root, "Ritu");
	root = addLast(root, "Bhupender");
	printList(root);
	return 0;
}