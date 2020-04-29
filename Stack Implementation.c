#include<stdio.h>
#include<stdlib.h>
void push(int s[10],int *top,int max)
{
	int ele;
	printf("enter element\n");
	scanf("%d",&ele);
	if(*top ==max-1)
	{
		printf("overflow\n");
		return;
	}
	(*top)++;
	s[*top]=ele;
	
}
int pop(int s[10],int *top)
{
	int ele;
	if(*top ==-1)
	{
		printf("underflow\n");
		return -1;
	}
	ele=s[*top];
	(*top)--;
	return ele;
}
void display(int s[10],int top)
{
	int i;
	if(top==-1)
	{
		printf("stack is empty\n");
		return;
	}
	printf("stack is\n");
	for(i=top;i>-1;i--)
	{
		printf("%d\n",s[i]);
	}
}	
		
		
int main()
{
	int s[20];
	int top=-1,max=10,res,choice;
	while(1)
	{
		printf("enter choice\n 1.push\n 2.pop\n 3.display\n 4.exit\n");
		scanf("%d",&choice);
		
			switch(choice)
			{
				case 1 : push(s,&top,max);
					break;
				case 2 : res=pop(s,&top);
					if(res !=-1)
					{
						printf("deleted ele is %d\n",res);
					} 	
					break;
				case 3 : display(s,top);
					break;
				default : exit(0);
				
			
				
			}
	}
}
				
	
	
	
