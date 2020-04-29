#include<stdio.h>
#define me 10
void display(int q[],int  rear, int front)
{
	int i;
	printf("deque elements\n");
	for(i=front; i<=rear;i++)
	 printf("%d\t",q[i]);


}
void insert_rear(int q[],int  *rear, int *front)
{
	int ele;
	
	printf("enter element to be inserted\n");
	scanf("%d",&ele);
	if(*rear==me-1)
	{
		printf("overflow condition\n");
		return;
	}
	(*rear)++;
	q[*rear]=ele;
	display(q,*rear,*front);
	//printf("element is %d",ele);
}				
void insert_front(int q[],int *rear,int *front)
{
	int ele;
	
	printf("enter element\n");
	scanf("%d",&ele);	
	if(*front > *rear)
	{
		insert_rear(q,rear,front);
	}
	else if(*rear>=*front && *front!=0)
	{
		
	
	        (*front)++;
	       q[*front]=ele;
	 }      
	else
	{
		printf("insersion not possible\n");
	}
	display(q,*rear,*front);
}
void delete_rear(int q[],int *front,int *rear)
{
	int ele;
	if(*front > *rear)
	{
		printf("queue is empty\n");
		return;
	}
	ele=q[*rear];
	(*rear)--;
	printf("deleted element is %d",ele);
	display(q,*front,*rear);
}
void delete_front(int q[],int *front,int *rear)
{
	int ele;
	if(*front>*rear)
	{
		printf("que is empty\n");
		return;
	}
	ele=q[*front];
	(*front)++;
	printf("deleted element is %d",ele);
	printf("queue elements are\n");
	display(q,*front,*rear);
}			
			
		
int main()
{
	int rear=-1,front=0,choice,q[20];
	while(1)
	{
		printf("\nenter choice\n 1.insert_rear\n 2.insert_front\n 4.delete_front\n 3.delete_rear\n 5.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : insert_rear(q,&rear,&front);
					break;
			case 2 : insert_front(q,&rear,&front);
				break;
			case 3:	delete_rear(q,&front,&rear);
				break;
			case 4:delete_front(q,&front,&rear);
				break;
					
		}
	}
}						
	
										
