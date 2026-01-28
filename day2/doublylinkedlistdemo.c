//Program to demonstrate doubly linked list
#include <stdio.h>
#include <stdlib.h>
//delclaration of node
typedef struct Node{
	struct Node *prev;
	char data;
	struct Node *next;
}node;

node* createNode(char element){
	node* temp = (node*)calloc(1,sizeof(node));
	temp->data = element;	
	return temp;
}
node* addFirst(node* list, char element){
	node* newNode = createNode(element);
	//checking whether the list is empty
	if (!list)	return newNode;
	newNode->next = list;
	list->prev = newNode;
	list = newNode;
	return list;	
}
node* addLast(node* list, char element){
	node* newNode = createNode(element);
	if (!list) return newNode;
	node* temp;
	for (temp=list; temp->next; temp=temp->next);
	newNode->prev = temp;
	temp->next = newNode;
	return list;
}
node* deleteFirst(node* list){
	if (list){
		//list contains only one node
		if (!list->next){
			free(list);
			return NULL;
		}
		node* temp = list;
		list = list->next;
		list->prev=NULL;
		free(temp);
	}
	return list;
}
node* deleteLast(node* list){
	if (list){
		if (!list->next){
			free(list);
			return NULL;
		}
		node* temp;
		for (temp = list; temp->next->next; temp=temp->next);
		free(temp->next);
		temp->next=NULL;			
	}
	return list;
}
void printList(node* list){
	if (list){
		printf("\nForward Traversal\n[");
		node* temp;
		for (temp = list; temp->next; temp=temp->next)
			printf("\'%c\',", temp->data);
		printf("\'%c\']", temp->data);			
		printf("\nReverse Traversal\n[");
		for(;temp->prev; temp=temp->prev)
			printf("\'%c\',", temp->data);
		printf("\'%c\']", temp->data);			
	}
	else
		printf("\n[]");
}

int main(){
	node* root = NULL;
	root = addFirst(root, 'A');
	root = addFirst(root, 'B');
	printList(root);
	root = addLast(root, 'C');
	printList(root);
	root = deleteFirst(root);
	printList(root);
	root = deleteLast(root);
	printList(root);
	root = deleteLast(root);
	printList(root);
	return 0;
}