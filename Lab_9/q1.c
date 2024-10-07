#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node * next;
};

int isEmpty(struct Node *r, struct Node * f){
	return (f==r);
}

int isFull(struct Node *f){
	struct Node * n=(struct Node*)malloc(sizeof(struct Node));
	if(n==NULL){
		return 1;
	}

	else return 0;
}
struct Node * enqueue(struct Node **f, struct Node **r, int value){
	if(isFull(*f)){
		printf("Queue full, can't enqueue\n");
	}

	else {
		struct Node * n=(struct Node*)malloc(sizeof(struct Node));
		if((*f)==NULL){
			(*f)=n;
		}
		(*r)=n;
		(*n).data=value;
		(*n).next=NULL;

	return n;
	}

}

int dequeue(struct Node **f, struct Node **r){
	if(isEmpty((*r),(*f))){
		printf("Queue empty, can't dequeue\n");
	}

	else{
		struct Node * ptr=(*f);
		(*f)=(*(*f)).next;
		return (*ptr).data;
	}

}

void display(struct Node *f){
	struct Node * ptr=f;

	while(ptr!=NULL){
		printf("Element: %d\n",(*ptr).data);
		ptr=(*ptr).next;
	}

}

int main() {
	struct Node *f=NULL;
	struct Node *r=NULL;

	printf("Empty:%d\n",isEmpty(r,f));
	printf("Full: %d\n",isFull(f));

	struct Node * n1=enqueue(&f,&r,5);
	struct Node * n2=enqueue(&f,&r,7);
	(*n1).next=n2;

	dequeue(&f,&r);

	display(f);

	//printf("%d\n",(*r).data);



}