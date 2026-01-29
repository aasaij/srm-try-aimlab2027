#include <stdio.h>

int main(){
	char ch;
	if (sizeof(ch)>-1)
		printf("true");
	else
		printf("false");
	return 0;
}
