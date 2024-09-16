#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int size;
	int top;
	char * arr;
}STACK;

int isEmpty(STACK *ptr) {
	if((*ptr).top==-1){
		return 1;
	}

	else return 0;
}

int isFull(STACK * ptr) {
	if((*ptr).top==(*ptr).size-1){
		return 1;
	}

	else return 0;
}

void push(STACK * ptr, char value) {
	if(isFull(ptr)){
		printf("Stack overflow, can't push\n");
	}

	else {
		//printf("Pushed element %c\n",value);
		(*ptr).top++;
		(*ptr).arr[(*ptr).top]=value;
	}
}

char pop(STACK * ptr) {
	if(isEmpty(ptr)){
		printf("Stack empty, can't pop\n");
	}

	else{
		char k=(*ptr).arr[(*ptr).top];
		//printf("Popped element %c\n",k);
		(*ptr).top--;
		return k;
	}
}

char peek(STACK * ptr, int i) {
	return (*ptr).arr[(*ptr).top-i+1];
}


int isPalindrome(char * word) {
	STACK * s=(STACK*)malloc(sizeof(STACK));
	(*s).size=100;
	(*s).top=-1;
	(*s).arr=(char*)malloc((*s).size*sizeof(char));

	int i=0;
	while(word[i]!='\0'){
		push(s,word[i]);
		i++;
	}

	for(int j=0; j<=(*s).top; j++) {
		if((*s).arr[j]!=(*s).arr[((*s).top+1)-j-1]){
			return 0;
		}

	}

	return 1;
}



int main() {

	char * word="malayalam";

	if(isPalindrome(word)){
		printf("Palindrome\n");
	}

	else printf("NOT Palindrome\n");

	return 0;
	






}