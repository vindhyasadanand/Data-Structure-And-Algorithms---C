#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#define me 10
int compute(char , int ,int); 
//push for character stack
void push(char s[],int *top,char ele)
{

	(*top)++;
	s[*top]=ele;

}
//pop for character stack
char pop(char s[],int *top)
{
	char ele;
	
	
		ele=s[*top];
		(*top)--;
		return ele;
	
	
}
//integer stack for evaluation

void epush(int s[],int *top,int ele)
{
	if(*top==me-1)
	{
		
		printf("overflow\n");
		return;
	}
	(*top)++;
	s[*top]=ele;
}
int epop(int s[],int *top)
{
	int ele;
	
	
		ele=s[*top];
		(*top)--;
			
	
	return  ele;
}
//to compute the result
int compute(char operator,int op1,int op2)
{
	switch(operator)
	{
		case '+' : return op1+op2;
		case '-' :return op1-op2;
		case '*' :return op1*op2;
		case '/' :return op1/op2;
		case '%' :return op1%op2;
		case '^' :
		case '$' :return pow(op1,op2);
	}
}

//function for stack pecidence
int F(char symbol)
{
	switch(symbol)
	{
		case '+':
		case '-':return 2;
		case '/':
		case '%':
		case '*':return 4;
		case '^':
		
		case '$':return 5;
		case '(':return 0;
		case '#':return -1;
		default : return 8;
	}
}
//function for input precidence
int G(char symbol)
{
	switch(symbol)
	{
		case '+':
		case '-':return 1;
		case '/':
		case '%':
		case '*':return 3;
		case '^':
		case '$':return 6;
		case '(':return 9;
		case ')': return 0;
		default : return 7;
	}
}
void infix_to_postfix(char infix[20],char postfix[20])
{
	int i,pindex=0,top=-1;
	char symbol,pelement,s[20];
	push(s,&top,'#');
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		while(F(s[top])>G(symbol))
		{
			postfix[pindex]=pop(s,&top);
			pindex++;
		}
	
		if(F(s[top])!=G(symbol))
		{
			push(s,&top,symbol);
		}
		else
		{
			pop(s,&top);
			
		}
	}	
		pelement=pop(s,&top);
		while(pelement!='#')
		{
			postfix[pindex]=pelement;
			pindex++;
			pelement=pop(s,&top);	
		}
		
	   postfix[pindex]='\0';
	 printf("%s\n",postfix);
}
//to evaluate
void evaluate(char postfix[])
{
	int i,s[20],top=-1,res,op1,op2;
	char symbol;
	for(i=0;i<strlen(postfix);i++)
	{
		symbol=postfix[i];
		if(isdigit(symbol))
		{
			epush(s,&top,symbol-'0');
		}
		else
		{
			op2 = epop(s,&top);
			op1=epop(s,&top);
			res=compute(symbol,op1,op2);
		}
	}
	printf("res=%d\n",epop(s,&top));	
}

			
int main( )
{
	char infix[20],postfix[20];
	printf("enter infix expression\n");
	scanf("%s",infix);
	infix_to_postfix(infix,postfix);
	evaluate(postfix);
}	
							
	


		 
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
				 								
