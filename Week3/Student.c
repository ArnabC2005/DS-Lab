#include<stdio.h>
#include<stdlib.h>

struct Student{
	char Name[100];
	int RollNo;
	float CGPA;
};

void Read(struct Student *s) {
	printf("Enter student details:\nEnter name:\n");
	scanf("%s",(*s).Name);

	printf("Enter Roll No:\n");
	scanf("%d",&(*s).RollNo);

	printf("Enter CGPA:\n");
	scanf("%f",&(*s).CGPA);
}

void Display(struct Student *s){
	printf("Student details are:\n");
	printf("Name: %s\n",(*s).Name);
	printf("Roll No: %d\n",(*s).RollNo);
	printf("CGPA: %f\n",(*s).CGPA);
}

void Sort(struct Student * array[2]) {
	struct Student * ptr;
	for(int i=0;i<2;i++) {
		for(int j=0;j<2-i-1;j++) {
			if((*(array)[j]).RollNo>(*(array)[j+1]).RollNo){
				ptr=array[j];
				array[j]=array[j+1];
				array[j+1]=ptr;

			}
		}
	}


}

int main() {
	struct Student* array[2];

	struct Student * s1=(struct Student*)malloc(sizeof(struct Student));

	Read(s1);
	//Display(s1);
	array[0]=s1;

	struct Student *s2=(struct Student*)malloc(sizeof(struct Student));

	Read(s2);
	//Display(s2);

	array[1]=s2;

	Sort(array);
	printf("Sorted order:\n");
	for(int i=0;i<2;i++) {
		printf("%s %d %f\n",((*array[i]).Name),((*array[i]).RollNo), ((*array[i]).CGPA));
	}



	return 0;
	
}