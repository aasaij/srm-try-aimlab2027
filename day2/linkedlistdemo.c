//Program to demonstrate linked list
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(){
//	printf("%d %d %d", sizeof(int*), sizeof(char*), sizeof(node*))	;
	node *root = NULL;
	root = addLast(root, "Anish");
	root = addFirst(root, "Saran");
	root = addFirst(root, "Seenu");
	root = addFirst(root, "Ritu");
	root = addLast(root, "Bhupender");
	printList(root);
	root = addAt(root, 3, "Zian");
	root = addAt(root, 17, "Veera");
	printList(root);
	root = deleteFirst(root);
	printList(root);
	root = deleteLast(root);
	printList(root);
	root = deleteAt(root, 3);
	printList(root);
	root = deleteAt(root, 5);
	printList(root);
	printf("\n%d", length(root));
	return 0;
}