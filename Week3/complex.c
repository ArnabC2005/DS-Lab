#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Complex{
	float mag;
	float coefficient;

	
};

void Add(struct Complex c1, struct Complex c2){
		printf("Sum is %f+(%fi)", ((c1).mag+(c2).mag),((c1).coefficient+(c2).coefficient));

	}


void Multiply(struct Complex c1, struct Complex c2) {
	printf("The product is %f+(%fi)", ((c1).mag*(c2).mag)-((c1).coefficient*(c2).coefficient),((c1).mag*(c2).coefficient)+((c2).mag*(c1).coefficient));
}

void Subtract(struct Complex c1, struct Complex c2){
	printf("Difference is %f+(%fi)", ((c1).mag-(c2).mag),((c1).coefficient-(c2).coefficient));

}



int main() {
	struct Complex c1;
	(c1).mag=2;
	(c1).coefficient=-3;

	struct Complex c2;
	(c2).mag=5;
	(c2).coefficient=+2;

	Add(c1,c2);
	printf("\n");

	Multiply(c1,c2);
	printf("\n");

	Subtract(c1,c2);
	printf("\n");

	return 0;



}