#include<stdio.h>
#include<string.h>
void push(char s[10],char ele,int *top,int max)
{
	if(*top==max-1)
	{
		printf("overflow\n");
		return;
	}
	(*top)++;
	s[*top]=ele;
}
int pop(char s[10],int *top)
{
	char ele;
	if(*top ==-1)
	{
		printf("underflow\n");
		return -1;
	}
	ele=s[*top];
	(*top)--;
	return ele;
}
int pali(char str[10])
{
	int top = -1,i,max=10;
	char s[max];
	for(i=0;i<strlen(str);i++)
	{
		push(s,str[i],&top,max);
	}
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]!=pop(s,&top))
		{
			return -1;
		}
	}
	return 1;
}
int main()
{
	int res;
	char str[10];
	printf("read the string\n");
	scanf("%s",str);
	res=pali(str);
	if(res ==-1)
	{
		printf("not palindrome\n");
	}
	else
	{
		printf("palindrome\n");
	}
} 		
	

