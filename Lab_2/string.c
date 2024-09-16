#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int String_Copy(char str1[], char str2[], int i){
	str1[i]=str2[i];

	if(str2[i+1]=='\0'){
		return 0;
	}

	else String_Copy(str1,str2,i+1);

}

int main() {
	char str1[100];
	char str2[100];

	printf("Enter first string: ");
	scanf("%s",str1);
	scanf("%*[^\n]");

	printf("Enter second string: ");
	scanf("%s",str2);

	printf("\n");

	printf("First string: %s\n",str1);
	printf("Second string: %s\n",str2);

	String_Copy(str1,str2,0);

	printf("After copying str1:%s\n",str1);
	printf("After copying str2: %s\n",str2);


}