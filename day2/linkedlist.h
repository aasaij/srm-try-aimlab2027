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
node* addAt(node* list, int loc, char data[]){
	if (loc == 0 || loc ==1)
		return addFirst(list, data);
	//checking the following conditions
	//1 The location should be > 1
	//2. List should not be empty
	//3. list should contain atleast two elements
	if (loc > 1 && list && list->nxt)  {
		node* newNode = createNode(data);
		node* temp= list;
		for (int i = 2;temp->nxt && i<loc; i++)
			temp = temp->nxt;
		newNode->nxt = temp->nxt;
		temp->nxt = newNode;
	}	
	return list;
}
node* deleteFirst(node *list){
	if (list){
		node* temp = list;
		list = list->nxt;
		free(temp);		
	}
	return list;
}

node* deleteLast(node* list){
	if (list){
		//checking whether the list is having only one node
		if (!list->nxt){	
			free(list);
			return NULL;
		}
		node* temp;
		for (temp = list; temp->nxt->nxt; temp=temp->nxt);
		free(temp->nxt);
		temp->nxt = NULL;	
	}
	return list;
}
node* deleteAt(node* list, int loc){
	if (loc== 0|| loc == 1)
		return deleteFirst(list);
	if (loc > 1 && list && list->nxt){
		node* temp = list;
		for (int i = 2; temp->nxt && i<loc; i++)
			temp = temp->nxt;
		if (temp->nxt){
			node* temp1 = temp->nxt;
			temp->nxt = temp1->nxt;
			free(temp1);
		}		
	}
	return list;
}
int length(node* list){
	int cnt = 0;
	for (node* temp = list; temp; cnt++,temp=temp->nxt);
	return cnt;
}
//list traversal
void printList(node* list){
	printf("\n[");
	node* temp;
	for (temp = list; temp->nxt; temp=temp->nxt)
		printf("'%s',", temp->name);		
	printf("'%s']", temp->name);
}
