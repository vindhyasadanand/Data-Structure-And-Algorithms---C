#include<stdio.h>
#include<stdlib.h>
void push(int s[],int *top,int *max)
{
	int ele;
	printf("enter element\n");
	scanf("%d",&ele);
	if(*top ==(*max)-1)
	{
		printf("overflow\n");
		printf("reallocate memory\n");
		(*max)++;
		s =(int*)realloc(s,sizeof(int)*(*max));
	}
	(*top)++;
	s[*top] = ele;
	printf("%d",s[*top]);
}
int pop(int s[],int *top,int *max)
{
	int ele;
	if(*top==-1)
	{
		printf("underflow\n");
		return -1;
	}
	ele=s[*top];
	(*top)--;
	(*max)--;
	s=(int*)realloc(s,sizeof(int)*(*max));
	return ele;
}
void display(int s,int top)
{
	int i;
	printf("stack elements are\n");
	for(i=top;i>-1;i--)
	{
		printf("%d\n",s[i]);
	}
}
	
int main()
{
	int *s,res;
	int top=-1,max=1;
	s=(int*)malloc(sizeof(int));
	while(1)
	{
		printf("enter choice\n
		1.push\n 2.pop\n 3.display\n 4.exit\n ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : push(s,&top,&max);
				break;
			case 2 :res= pop(s, &top,&max);
				if(res!=-1)
				{
					printf("deleted ele is %d\n",res);
				}
				break;
		 
			case 3 :display(s,top);
				break;
			default: exit(0);
		}
	}
}
		 	
