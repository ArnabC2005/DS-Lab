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
		//printf("Pushed element %d\n",value);
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
		//printf("Popped element %d\n",k);
		(*ptr).top--;
		return k;
	}
}

int peek(STACK * ptr, int i) {
	return (*ptr).arr[(*ptr).top-i+1];
}

void cutshort(int * arr, int n, int k){
	STACK *s=(STACK*)malloc(sizeof(STACK));
	(*s).size=100;
	(*s).top=-1;
	(*s).arr=(int*)malloc((*s).size*sizeof(int));

	while(k!=0){
		int i=n-1;

		while(arr[i]>=arr[i+1]){
			i--;
		}

		while(i!=n-2){
			arr[i]=arr[i+1];
			i++;
		}
		n--;
		k--;
	}



}

int main() {
	int arr[]={20,10,25,30,40};
	int n=5;

	cutshort(arr,n,2);

	for(int i=0;i<sizeof(arr)/sizeof(int);i++) {
		printf("%d\t",arr[i]);
	}

	

}