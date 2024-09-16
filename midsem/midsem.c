#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char ** words;
	int size;
}StringArray;

#define MAX 50

void findLongestWord(StringArray *strArray, int index, char*longestWord);

void displayLongestWord(char * longestWord);

int main() {
	char *longest=(char*)malloc(MAX*sizeof(char));
	char ex[MAX];
	StringArray s;
	printf("Enter the number of words:\n");
	scanf("%d",&s.size);

	s.words=(char**)malloc(s.size*sizeof(char*));

	for(int i=0;i<s.size;i++) {
		printf("Enter the %d index word:\n",i);
		scanf("%s",ex);

		int len=strlen(ex);

		s.words[i]=(char*)malloc((strlen(ex)+1)*sizeof(char));

		s.words[i][0]=len;

		for(int j=0;j<len;j++){
			s.words[i][j+1]=ex[j];
		}

	}

	findLongestWord(&s,0,longest);
	displayLongestWord(longest);

}

void findLongestWord(StringArray *strArray, int index, char *longestWord){
	strcpy(longestWord,(*strArray).words[index]);
	int longest_length=(*strArray).words[index][0];

	for(int m=index+1; m<(*strArray).size;m++){
		if((*strArray).words[m][0]>longest_length){
			longest_length=(*strArray).words[m][0];
			strcpy(longestWord,(*strArray).words[m]);
		}

	}
}

void displayLongestWord(char * longestWord){
	printf("The longest word is: %s\n",longestWord);
}