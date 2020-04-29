#include<stdio.h>
#include<stdlib.h>
#define me 5
void display(char q[], int front,int count,int rear)
{
	int i;
	if(front>rear)
	{
		printf("empty queue\n");
		return;
	}
	printf("elements of queue are\n");
	for(i=front;i<=rear ;i++ )
	{
		printf(" %c\t ",q[i]);
	
		
		
	}
}		
		
				
//to insert from rear
void insert_rear(char q[],int *count , int *front,int *rear)
{
	char ele;
	printf("enter element to be inserted\n");
	scanf(" %c",&ele);
	if(*count == me-1)
	{
		printf("queue is full\n");
		return;
	}
	(*rear)=((*rear)+1)%me;
	q[*rear]=ele;
	(*count)++;
	display(q,*front,*rear,*count);
}
//to delete from the front
void delete_front(char q[],int *front ,int *rear,int *count)
{
	char ele;
	if(*count==0)
	{
		printf("empty queue\n");
		return;
	}
	q[*front]=ele;
	printf("deleted ele is  %c", ele);
	(*front)=((*front)+1)%me;
	(*count)--;
	display(q,*front,*rear,*count);
}		
			
int main()
{
	char q[10];
	int front=0,rear=me-1,count=0,choice;
	
	while(1)
	{
		printf("enter the choice\n 1 insert_rear\n 2 delete front\n 3 display\n");
	scanf("%d",&choice);
					
		switch(choice)
		{
			case 1 : insert_rear(q,&count,&front,&rear);	
				break;
			case 2 :delete_front(q,&front,&rear,&count);
				break;	
					
			case 4 :display(q,front,rear,count);
				break;
		}
	}
}				
					
