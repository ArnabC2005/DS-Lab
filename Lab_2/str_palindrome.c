#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int str_pal(char str[],int i, int j){

	if(i==j){
		return 1;
	}


		if(str[i]!=str[j]){
			//printf("Not palindrome\n");
			return 0;
		}

		else str_pal(str,i+1,j-1);
		//printf("Palindrome\n");
		//return 1;

}


int main() {
	char str[100];
	printf("Enter the string: ");
	scanf("%s",str);

	

	if(str_pal(str,0,strlen(str)-1)){
		printf("Palindrome\n");
	}

	else printf("Not palindrome\n");

}