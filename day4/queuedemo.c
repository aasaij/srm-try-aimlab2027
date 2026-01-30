//Program to demonstrate queue data structure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Employee{
	int id;
	char name[30];
	double salary;
}employee;
typedef struct Queue {
	int capacity;
	int rear;
	int front;
	int cnt;
	employee *employees;
}queue;
queue *createQueue(int max){
	queue *temp = (queue*)malloc(sizeof(queue));
	temp->capacity = max;
	temp->rear = -1;
	temp->front = -1;
	temp->cnt = 0;
	temp->employees = (employee*)malloc(max * sizeof(employee));
	return temp;
}
bool isEmpty(queue* q){
	return q->rear == -1 && q->front == -1;
}
//circular queue
bool isFull(queue *q){
	return q->rear+1 == q->capacity && q->front == 0 || q->rear+1 == q->front;
}
bool enqueue(queue *q, employee e){
	if (isFull(q))
		return false;
	if (q->front == -1)
		q->front = 0;
	q->rear= (q->rear+1)% q->capacity;
	q->employees[q->rear] = e;
	q->cnt++;
	return true;
}
employee *dequeue(queue *q){
	if (isEmpty(q))
		return NULL;
	int index = q->front;		
	if (q->front == q->rear)	
		q->rear = q->front = -1;		
	else
		q->front = (q->front+1)%q->capacity;		
	q->cnt--;
	return &q->employees[index];	
}
employee *front(queue *q){
	if (isEmpty(q))
		return NULL;
	return &q->employees[q->front];	
}

int queueSize(queue *q){
	return q->cnt;
}
employee getEmployee(){
	employee e;
	printf("Employee Id     : ");
	scanf("%d", &e.id);
	printf("Emoployee Name  : ");
	scanf("\n%29[^\n]s", e.name);
	printf("Employee Salary :");
	scanf("%lf", &e.salary);
	return e;
}

void printEmployee(employee e){
	printf("\nEmployee Id     : %d\n", e.id);
	printf("Emoployee Name  : %-30s\n", e.name);
	printf("Employee Salary : %.2lf\n", e.salary);
	
}
void printMenu(){
	printf("Queue operations demo\n");
	printf("*********************\n");
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Display front\n");
	printf("4. Queue size\n");
	printf("5. Exit\n");
	printf("Enter your choice : ");
}

int main(){
	queue *myQueue = NULL;
	int size;
	scanf("%d", &size);
	myQueue = createQueue(size);
	while(true){
		int choice;
		printMenu();
		scanf("%d", &choice);
		switch(choice){
			case 1:
				if (enqueue(myQueue, getEmployee()))
					printf("\nEnqueued..");
				else
					printf("\nQueue is full..");
				break;
			case 2:{
				employee *e = dequeue(myQueue);
				if (e == NULL)
					printf("\nQueue is empty!");
				else
					printEmployee(*e);
				break;
			}
			case 3:{
				employee *e = front(myQueue);
				if (e == NULL)
					printf("\nQueue is empty!");
				else
					printEmployee(*e);
				break;
			}
		    case 4:
		   		printf("\nQueue Size : %d", queueSize(myQueue))				;
		   		break;
		   	default:
		   		printf("Thank you so much for being very silent in the class!");
		   		return 0;			
		}
	}
//	printEmployee(getEmployee());
	return 0;
}