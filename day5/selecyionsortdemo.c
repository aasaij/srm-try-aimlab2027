//Program to implement bubble sort algorithm
#include <stdio.h>
#include <stdlib.h>
void swap(int *x, int *y){
	*x = *x + *y - (*y=*x);
}

void selectionSort(int arr[], int n){
	for(int i = 0; i<n;i++ ){
		int minIndex = i;
		//checking whether the minimum value is found rest of the list
		for (int j = i+1; j<n; j++){
			if (arr[minIndex]>arr[j])
				minIndex = j;
		}
		if (i!=minIndex)
			swap(arr+i, arr+minIndex);
	}
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
	selectionSort(arr, size);
	printArray(arr, size);
	return 0;	
}
