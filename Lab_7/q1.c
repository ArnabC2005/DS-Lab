#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 5

typedef struct{
	int f;
	int r;
	char * arr[size];
}QUEUE;

int isEmpty(QUEUE * q){
	if((*q).f==(*q).r){
		return 1;
	}

	else return 0;
}

int isFull(QUEUE * q){
	if((((*q).r+2)%size)==(*q).f){
		return 1;
	}

	else return 0;
}

void insertcq (QUEUE * q, char *str){
	if(isFull(q)){
		printf("Queue full, can't enqueue\n");
	}

	else {
		(*q).r=(((*q).r+1)%size);
		(*q).arr[(*q).r]=(char*)malloc(strlen(str)+1*sizeof(char));
		strcpy((*q).arr[(*q).r],str);
	}
}

char * deletecq(QUEUE * q){
	if(isEmpty(q)){
		printf("Queue empty, can't dequeue\n");
	}

	else {
		//printf("Deleting ");
		(*q).f=((*q).f+1)%size;
		printf("Deleting %s\n",(*q).arr[(*q).f]);
		return (*q).arr[(*q).f];
	}
}

void displaycq(QUEUE *q){
	for (int i=(((*q).f+1)%size);i<=(*q).r;i=(i+1)%size){
		printf("%s\n",(*q).arr[i]);
	}
}


int main() {
	QUEUE * q=(QUEUE*)malloc(sizeof(QUEUE));
	//(*q).size=3;
	(*q).f=(*q).r=0;
	//(*q).arr=(char**)malloc(size*sizeof(char*));

	insertcq(q, "hello");
	insertcq(q,"Arnab here");
	insertcq(q,"hehe");

	displaycq(q);
	printf("\n\n");
	deletecq(q);
	deletecq(q);



	//printf("%s\n",deletecq(q));

	//printf("%s\n",(*q).arr[(*q).r]);

	printf("\n\nNew queue:\n");

	displaycq(q);







}