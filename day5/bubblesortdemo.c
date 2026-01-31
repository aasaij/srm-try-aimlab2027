//Program to implement bubble sort algorithm
#include <stdio.h>
#include <stdlib.h>
void swap(int *x, int *y){
	*x = *x + *y - (*y=*x);
}

void bubbleSort(int arr[], int n){
	for (int i =1;i<=n-1;i++)
		for(int j = 0;j<n-i; j++)
			if ( arr[j] > arr[j+1])
//				swap(arr+j, arr+j+1);
				arr[j] = arr[j]+arr[j+1] - (arr[j+1]=arr[j]);
}

void printArray(int arr[], int n){
	for (int i = 0; i<n; printf("%d ", arr[i++]));
}

int main(){
	int size, *arr;
	scanf("%d", &size);
	arr = calloc(size, sizeof(int));
	//reading <size> elements from the usesr
	for (int i = 0; i<size; scanf("%d", &arr[i++]));
	bubbleSort(arr, size);
	printArray(arr, size);
	return 0;	
}
