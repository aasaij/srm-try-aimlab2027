//Program to demonstrate stack operations
#include <stdio.h>
#include <stdlib.h>
typedef enum Boolean {true=1, false=0} boolean;
typedef struct Book{
	int id;
	char title[30];
	double price;
}book;

typedef struct Stack {
	//used to maintain the capacity of the stack
	int capacity;
	//used to main the actual number of elements present in the stack
	int size;
	//used to store the address where the elements are stored
	book *books;
}stack;

stack* createStack(int max){
	stack *temp = (stack*)malloc(sizeof(stack));
	temp->capacity = max;
	temp->size = -1;
	temp->books = (book*)malloc(sizeof(book)*max);
	return temp;
}
boolean isEmpty(stack* st){
//	if (st->size==-1)
//		return true;
//	return false;
	return st->size == -1;
}
boolean isFull(stack* st){
	return st->size+1 == st->capacity;
}
boolean push(stack* st, book b){
	if (isFull(st))
		return false;
	st->books[++st->size] = b;
	return true;
}
book* pop(stack* st){
	if (isEmpty(st))
		return NULL;
	return &st->books[(st->size)--];
}
book* peek(stack* st){
	if (isEmpty(st))
		return NULL;
	return &st->books[(st->size)];
}
book getBook(){
	book b;
	printf("Book Id     : ");
	scanf("%d",&b.id );
	printf("Book Title  : ");
	scanf("\n%[%\n]s", b.title);
	printf("Book Price : ");
	scanf("%lf", &b.price);
	return b;
}
void printBook(book b){
	printf("Book Id     : %d\n",b.id );
	printf("Book Title  : %s\n", b.title);
	printf("Book Price : %.2lf\n", b.price);	
}
void printMenu(){
	printf("\nStack application demo\n");
	printf("**********************\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Display top\n");
	printf("4. Stack size\n");
	printf("5. Exit\n");
	printf("Enter your choice : ");
}
int stackSize(stack *st){
	return st->size+1;
}

int main(){
	stack *myStack = NULL;
	int size;
	scanf("%d", &size);
	myStack = createStack(size);
	while(true){
		printMenu();
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 1:
				if (push(myStack, getBook()))
					printf("\nPushed...");
				else
					printf("\nStack overflow");
				break;
			case 2:
				{
					book *b = pop(myStack);
					if (b)
						printBook(*b);
					else
						printf("\nStack is empty");
				}
				break;
			case 3:
				{
					book *b = peek(myStack);
					if (b)
						printBook(*b);
					else
						printf("\nStack is empty");
				}
				break;
			case 4:				
				printf("\nStack size : %d", stackSize(myStack));
				break;
			default:
				printf("Thank you so much for being very interactive!");
				return 0; //exit(0)
		}		
	}
	return 0;
}