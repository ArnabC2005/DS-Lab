struct stack{
	int size;
	int top;
	int *arr;
};

int isEmpty(struct stack * ptr){
	if((*ptr).top==-1){
		return 1;
	}

	else return 0;
}

int isFull(struct stack * ptr){
	if((*ptr).top==(*ptr).size-1){
		return 1;
	}

	else return 0;
}

void push(struct stack * ptr, int value){
	if(isFull(ptr)){
		printf("Stack overflow, can't push\n");
	}

	else {
		//printf("Pushed element %d\n",value);
		(*ptr).top++;
		(*ptr).arr[(*ptr).top]=value;
	}
}

int pop(struct stack * ptr){
	if(isEmpty(ptr)){
		printf("Stack empty, can't pop\n");
		return 0;
	}

	else {
		int k=(*ptr).arr[(*ptr).top];
		//printf("Popped element %d\n",k);
		(*ptr).top--;
		return k;
	}
}