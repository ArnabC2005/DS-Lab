#include<stdio.h>
#include "header.h"
#include <stdlib.h>


/*int eval(char x, int op1, int op2){
	if(x=='+'){
		return (op1+op2);
	}

	if(x=='-')
return(op1-op2);
if(x=='*')
return(op1*op2);
if(x=='/')
return(op1/op2);
if(x=='%')
return(op1%op2);
}*/

int isOperator(char a){
	if(a=='+' || a=='-' || a=='/' || a=='*' || a=='%'){
		return 1;
	}

	else return 0;
}

int eval_postfix(char *postfix){
	struct stack *s=(struct stack*)malloc(sizeof(struct stack));
	(*s).size=100;
	(*s).top=-1;
	(*s).arr=(int*)malloc((*s).size*sizeof(int));
	//char * po=(char*)malloc(strlen(postfix)*sizeof(char));

	int i=0;
	while(postfix[i]!='\0'){
		if(!isOperator(postfix[i])){
			push(s,postfix[i]-'0');
		}

		else {
			char k=postfix[i];
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
		i++;

	}

	return pop(s);
}






int main() {

	char * postfix="68*";

	printf("Value is %d\n",eval_postfix(postfix));




}