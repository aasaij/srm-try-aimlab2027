//Program to implement linear serarch algorithm
#include <stdio.h>
#include <string.h>
int linearSearch(int size, char nameList[size][20], char searchElement[]){
	//implementing linear search algorithm
	for (int i = 0; i<size; i++){
		if (strcmp(nameList[i], searchElement)==0)
			return i;
	}
	return -1;	
}
int main(){
	char nameList[][20] = {"Shalini", "Kiruthika", "Nithya", "Deepa", "Anamika"};
	char searchElement[20];
	int size = sizeof(nameList)/sizeof(nameList[0]);
	scanf("%s", searchElement);
	int index = linearSearch(size, nameList, searchElement);
	printf("%s %d", index==-1?"Not found":"Found", index);
	return 0;
}