#include<stdio.h>
#include<stdlib.h>

#define MAX 6

typedef struct{
	char arr[MAX];
	int f;
	int r;
}DEqueue;

int isEmpty(DEqueue * q){
	return (q->f==q->r);
}

int isFull(DEqueue *q){
	return (((q->r)+1)%MAX==q->f);                                                           
}

void enqueueR(DEqueue * q, char ch){
	if(isFull(q)){
		printf("Queue full, can't enqueue\n");
	}
	else {
		printf("Enqueued %c to rear end\n",ch);
		q->r=((q->r+1)%MAX);
		q->arr[q->r]=ch;
	}
}

void enqueueF(DEqueue * q, char ch){
	if(isFull(q)){
		printf("Queue full, can't enqueue\n");
	}
	else {
		printf("Enqueued %c to front end\n",ch);
		q->arr[q->f]=ch;
		q->f=((q->f-1+MAX)%MAX);
	}
}

void display(DEqueue *q){
	for(int i=(q->f+1)%MAX; i!=(q->r+1)%MAX;i=(i+1)%MAX){
		printf("Element: %s\n",q->arr[i]);

	}
}

char dequeueF(DEqueue *q){
	if(isEmpty(q)){
		printf("Queue empty, can't dequeue\n");
	}

	else{
		q->f=((q->f)+1)%MAX;
		return q->arr[q->f];
	}
}

char dequeueR(DEqueue *q){
	if(isEmpty(q)){
		printf("Queue empty, can't dequeue\n");
	}

	else{
		char k=q->arr[q->r];
		q->r=((q->r)-1+MAX)%MAX;
		return k;
	}
}

int isPalindrome(DEqueue *q){
	while(q->f!=q->r){
		if(dequeueF(q)!=dequeueR(q)){
			return 0;
		}
	}

	return 1;
}

int main(){
	DEqueue *q=(DEqueue*)malloc(sizeof(DEqueue));

	enqueueR(q,'a');
	enqueueR(q,'c');
	enqueueR(q,'c');
	enqueueR(q,'a');

	if(isPalindrome(q)){
		printf("Palindrome\n");
	}

	else printf("Not palindrome\n");
}