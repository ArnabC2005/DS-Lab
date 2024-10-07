#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * next;
};

struct Node *createNode(struct Node * head, int value){
	struct Node * ptr=head;
	while((*ptr).next!=NULL){
		ptr=(*ptr).next;
	}

	struct Node * n=(struct Node*)malloc(sizeof(struct Node));
	(*ptr).next=n;
	(*n).data=value;
	(*n).next=NULL;

	return head;
}


struct Node * Union(struct Node * head1, struct Node *  head2){
	struct Node * ptr1=head1;
	struct Node * ptr2=head2;

	struct Node * head3=(struct Node*)malloc(sizeof(struct Node));
	(*head3).data=0;

	//int count=0;
	while(ptr1!=NULL && ptr2!=NULL){
		if((*ptr1).data<(*ptr2).data){
			head3=createNode(head3,(*ptr1).data);
			ptr1=(*ptr1).next;
		}

		else if((*ptr2).data<(*ptr1).data){
			head3=createNode(head3, (*ptr2).data);
			ptr2=(*ptr2).next;
		}

		else {
			head3=createNode(head3, (*ptr1).data);
			ptr1=(*ptr1).next;
			ptr2=(*ptr2).next;
		}
	}

	while(ptr1!=NULL){
		head3=createNode(head3,(*ptr1).data);
		ptr1=(*ptr1).next;
	}

	while(ptr2!=NULL){
		head3=createNode(head3,(*ptr2).data);
		ptr2=(*ptr2).next;
	}

	return head3;

}

struct Node * Intersection(struct Node * head1, struct Node * head2){
	struct Node * ptr1=head1;
	struct Node * ptr2=head2;
	struct Node * head4=(struct Node*)malloc(sizeof(struct Node));

	(*head4).data=0;

	while(ptr1!=NULL){
		while(ptr2!=NULL){
			if((*ptr1).data==(*ptr2).data){
				head4=createNode(head4,(*ptr1).data);
			}
			ptr2=(*ptr2).next;
		}
		ptr1=(*ptr1).next;
	}

	return head4;


}

void display(struct Node * head){
	struct Node * ptr=(*head).next;
	while(ptr!=NULL){
		printf("Element: %d\n",(*ptr).data);
		ptr=(*ptr).next;
	}
}

int main(){
	struct Node * head1=(struct Node*)malloc(sizeof(struct Node));
	(*head1).data=2;
	head1=createNode(head1,3);
	head1=createNode(head1,4);
	head1=createNode(head1,5);

	struct Node * head2=(struct Node*)malloc(sizeof(struct Node));
	(*head2).data=5;
	head2=createNode(head2,7);
	head2=createNode(head2,8);
	head2=createNode(head2,10);
	printf("Union:\n");


	struct Node * head3=Union(head1, head2);
	display(head3);


	printf("Intersection\n");

	struct Node * head4=Intersection(head1, head2);
	display(head4);
}