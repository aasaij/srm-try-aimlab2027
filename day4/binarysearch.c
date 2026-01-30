//Program to implement linear serarch algorithm
#include <stdio.h>
int binarySearch(int a[], int n, int search){
	for (int low = 0,high=n-1; low<=high; ){
		int mid = (low + high) / 2;
		if (a[mid]==search)
			return mid;
		else if (a[mid]<search)
			low = mid+1;
		else
			high = mid -1;
	}
	return -1;
}

int main(){
	int arr[] = {1,2,3,4,5,6,7,8,10, 20, 30};
	int size = sizeof(arr)/sizeof(arr[0]);
	int element;
	scanf("%d", &element);
	int index = binarySearch(arr, size, element);
	if (index == -1)
		printf("Not found");
	else
		printf("Found at %d", index);
	return 0;
}


