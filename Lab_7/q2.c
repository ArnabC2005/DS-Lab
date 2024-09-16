#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 10

typedef struct{
	int f;
	int r;
	int arr[size/2];
}QUEUE;

int isEmpty_1(QUEUE * q1){
	if((*q1).f==(*q1).r){
		return 1;
	}

	else return 0;
}

int isFull_1(QUEUE * q1){
	if((((*q1).r+2)%(size/2))==(*q1).f){
		return 1;
	}

	else return 0;
}

void insertcq_1 (QUEUE * q1, int elem){
	if(isFull_1(q1)){
		printf("Queue 1 full, can't enqueue\n");
	}

	else {
		printf("Queue 1 enqueing %d\n",elem);
		(*q1).r=(((*q1).r+1)%(size/2));
		(*q1).arr[(*q1).r]=elem;
	}
}

int deletecq_1(QUEUE * q1){
	if(isEmpty_1(q1)){
		printf("Queue 1 empty, can't dequeue\n");
	}

	else {
		(*q1).f=((*q1).f+1)%(size/2);
		printf("Deleting %d\n",(*q1).arr[(*q1).f]);
		return (*q1).arr[(*q1).f];
	}
}

void displaycq(QUEUE *q){
	for (int i=(((*q).f+1)%size/2);i<=(*q).r;i=(i+1)%(size/2)){
		printf("%d\n",(*q).arr[i]);
	}
}


int isEmpty_2(QUEUE * q2){
	if((*q2).f==(*q2).r){
		return 1;
	}

	else return 0;
}

int isFull_2(QUEUE * q2){
	if((((*q2).r+2)%(size/2))==(*q2).f){
		return 1;
	}

	else return 0;
}

void insertcq_2 (QUEUE * q2, int elem){
	if(isFull_2(q2)){
		printf("Queue 2 full, can't enqueue\n");
	}

	else {
		printf("Queue 2 enqueing %d\n",elem);
		(*q2).r=(((*q2).r+1)%(size/2));
		(*q2).arr[(*q2).r]=elem;
	}
}

int deletecq_2(QUEUE * q2){
	if(isEmpty_1(q2)){
		printf("Queue 2 empty, can't dequeue\n");
	}

	else {
		(*q2).f=((*q2).f+1)%(size/2);
		printf("Deleting %d\n",(*q2).arr[(*q2).f]);
		return (*q2).arr[(*q2).f];
	}
}

int main(){
	QUEUE * q1=(QUEUE *)malloc(sizeof(QUEUE));
	(*q1).f=(*q1).r=0;
	QUEUE * q2=(QUEUE *)malloc(sizeof(QUEUE));
	(*q2).r=(*q2).f=size/2;

	insertcq_1(q1,3);
	insertcq_1(q1,5);
	insertcq_1(q1,7);
	//insertcq_1(q1,8);
	
	deletecq_1(q1);
	deletecq_1(q1);
	//printf("\n");
	displaycq(q1);
	printf("\n\n");

	insertcq_2(q2,3);
	insertcq_2(q2,5);
	insertcq_2(q2,7);

	deletecq_2(q2);
	deletecq_2(q2);
	displaycq(q2);
	printf("\n");


}