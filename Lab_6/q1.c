#include<stdio.h>
#include "header.h"
#include <stdlib.h>
#include<string.h>


int isOperator(char a){
	if(a=='+' || a=='-' || a=='/' || a=='*' || a=='%'){
		return 1;
	}

	else return 0;
}

int eval_prefix(char *prefix){
	struct stack *s=(struct stack*)malloc(sizeof(struct stack));
	(*s).size=100;
	(*s).top=-1;
	(*s).arr=(int*)malloc((*s).size*sizeof(int));
	//char * po=(char*)malloc(strlen(postfix)*sizeof(char));

	int i=strlen(prefix)-1;
	int n=0;
	while(n!=strlen(prefix)){
		if(!isOperator(prefix[i])){
			push(s,prefix[i]-'0');
		}

		else {
			char k=prefix[i];
			int op1=pop(s);
			int op2=pop(s);

			if(k=='+'){
				push(s,(op1+op2));
			}

			else if(k=='-'){
				push(s,(op1-op2));
			}

			else if(k=='*'){
				push(s,(op1*op2));
			}

			else if(k=='/'){
				push(s,(op1/op2));
			}

			else if(k=='%'){
				push(s,(op1%op2));
			}

		}
		i--;
		n++;

	}

	return pop(s);
}






int main() {

	char * prefix="/42";

	printf("Value is %d\n",eval_prefix(prefix));




}