#include<stdio.h>
#include<stdlib.h>

#define MAX 5

typedef struct{
	char *arr[MAX];
	int f;
	int r;
}DEqueue;

int isEmpty(DEqueue * q){
	return (q->f==q->r);
}

int isFull(DEqueue *q){
	return (((q->r)+1)%MAX==q->f);                                                           
}

void enqueueR(DEqueue * q, char * str){
	if(isFull(q)){
		printf("Queue full, can't enqueue\n");
	}
	else {
		printf("Enqueued %s to rear end\n",str);
		q->r=((q->r+1)%MAX);
		q->arr[q->r]=str;
	}
}

void enqueueF(DEqueue * q, char * str){
	if(isFull(q)){
		printf("Queue full, can't enqueue\n");
	}
	else {
		printf("Enqueued %s to front end\n",str);
		q->arr[q->f]=str;
		q->f=((q->f-1+MAX)%MAX);
	}
}

void display(DEqueue *q){
	for(int i=(q->f+1)%MAX; i!=(q->r+1)%MAX;i=(i+1)%MAX){
		printf("Element: %s\n",q->arr[i]);

	}
}

char * dequeueF(DEqueue *q){
	if(isEmpty(q)){
		printf("Queue empty, can't dequeue\n");
	}

	else{
		q->f=((q->f)+1)%MAX;
		return q->arr[q->f];
	}
}

int main() {
	DEqueue *q=(DEqueue*)malloc(sizeof(DEqueue));
	q->f=q->r=0;

	enqueueR(q,"Ball");
	enqueueR(q,"Cat");
	enqueueF(q,"Apple");

	display(q);
	printf("\n");

	printf("Dequeued %s\n",dequeueF(q));
	display(q);

	free(q);


}