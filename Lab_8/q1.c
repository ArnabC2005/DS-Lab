#include<stdio.h>
#include<stdlib.h>

#define MAX 5

typedef struct{
	int f;
	int r;
	int arr[MAX];
}apq;

int isEmpty(apq * ptr){
	return (ptr->r==-1);
}

int isFull(apq * ptr){
	return (ptr->r==MAX-1);
}

void enqueue(apq * ptr, int elem){
	if(isFull(ptr)){
		printf("Queue full, can't enqueue\n");
	}

	else {
		printf("Enqueing element %d\n",elem);
		ptr->r++;
		ptr->arr[ptr->r]=elem;
	}
}

int dequeue(apq * ptr){
	if(isEmpty(ptr)){
		printf("Queue empty, can't dequeue\n");
	}

	else {
		int min=ptr->arr[0];

		for(int i=0;i<=ptr->r-1;i++){
			min=ptr->arr[i];
			int min_pos=0;
			for(int j=i+1;j<=ptr->r;j++){
				if(ptr->arr[j]<min){
					min=ptr->arr[j];
					min_pos=j;
				}
			}

			//got min and min_pos
			for(int i=min_pos;i<=ptr->r;i++){
				ptr->arr[i]=ptr->arr[i+1];
			}

			ptr->r--;

				return min;
		}
	}


}


int main() {
	apq * q=(apq*)malloc(sizeof(apq));
	q->r=q->f=-1;

	printf("Empty: %d\n",isEmpty(q));
	enqueue(q,14);
	enqueue(q,11);
	enqueue(q,15);
	printf("Dequeued element %d\n",dequeue(q));
}