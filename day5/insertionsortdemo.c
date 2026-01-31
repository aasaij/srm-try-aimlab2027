//Program to implement bubble sort algorithm
#include <stdio.h>
#include <stdlib.h>
void insertionSort(int arr[], int n){
	for (int i = 1; i<n; i++){
		int key = arr[i], j;
		for ( j= i-1;j>=0 && key <arr[j]; j--){
			arr[j+1] = arr[j];
		}
		arr[j+1] = key;	
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
	insertionSort(arr, size);
	printArray(arr, size);
	return 0;	
}
