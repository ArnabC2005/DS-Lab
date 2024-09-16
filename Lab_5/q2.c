#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int size;
	int top;
	int * arr;
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

void push(STACK * ptr, int value) {
	if(isFull(ptr)){
		printf("Stack overflow, can't push\n");
	}

	else {
		printf("Pushed element %d\n",value);
		(*ptr).top++;
		(*ptr).arr[(*ptr).top]=value;
	}
}

int pop(STACK * ptr) {
	if(isEmpty(ptr)){
		printf("Stack empty, can't pop\n");
	}

	else{
		int k=(*ptr).arr[(*ptr).top];
		printf("Popped element %d\n",k);
		(*ptr).top--;
		return k;
	}
}

int peek(STACK * ptr, int i) {
	return (*ptr).arr[(*ptr).top-i+1];
}

void DecimalToBinary(int Decimal){
	STACK * s=(STACK*)malloc(sizeof(STACK));
	(*s).size=100;
	(*s).top=-1;
	(*s).arr=(int*)malloc((*s).size*sizeof(int));

	int i=0;

	while(Decimal!=0){
		push(s,(Decimal%2));
		Decimal=Decimal/2;
		i++;
	}

	printf("The Binary Equivalent is: ");
	for(int j=1; j<=i;j++) {
		printf("%d\t",peek(s,j));
	}

	printf("\n");


}

int main() {
	
	int Decimal = 150;

	DecimalToBinary(Decimal);









}