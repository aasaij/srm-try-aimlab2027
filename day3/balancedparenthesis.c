//Balanced parenthesis
#include <stdio.h>
#include <string.h>
int main(){
	char exp[100];
	scanf("%s",exp);
	int len = strlen(exp), top=-1, i;
	char stack[len+1];
	for ( i = 0; i<len; i++){
		char ch = exp[i];
		if (ch=='{' || ch == '(' || ch =='[')
			stack[++top] = ch;
		else if (ch=='}' && stack[top]=='{' || ch==']' && stack[top]=='[' || ch==')' && stack[top]=='(')
			top--;
		else{
			break;
		}
	}
	if (i==len && top==-1)
		printf("Valid");
	else
		printf("Invalid");
	return 0;
}