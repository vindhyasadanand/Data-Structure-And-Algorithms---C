#include<stdio.h>
#include<stdlib.h>
struct node
{
	char name[20];
	char usn[20];
	char branch[10];
	char phno[20];
	int marks;
	int sem;
	struct node*link;
};
typedef struct node* NODE;
//to create node
NODE getnode()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("insufficient memory\n");
		exit(0);
	}
	return temp;
}
//to display
void display(NODE first)
{
	if(first==NULL)
	{
		printf("empty sll\n");
	}
	printf("elements of sll are\n");
	while(first!=NULL)
	{
		printf("name:%s\n usn:%s\n branch:%s\n phono:%s\n marks:%d\n sem:%d\n",first->name,first->usn,first->branch,first->phno,first->marks,first->sem);
		first=first->link;
	}
	
} 
//to insert from front
NODE insert_front(NODE first)
{
	int ele;
	NODE temp;
	temp=getnode();
	temp->link=NULL;
	printf("enter name\n");
	scanf("%s",temp->name);
	printf("enter usn\n");
	scanf("%s",temp->usn);
	printf("enter branch\n");
	scanf("%s",temp->branch);
	printf("enter phono\n");
	scanf("%s",temp->phno);
	printf("enter marks\n");
	scanf("%d",&(temp->marks));
	printf("enter sem\n");
	scanf("%d",&(temp->sem));
	
	//no nodes exist
	if(first==NULL)
	{
		return temp;
	}
	temp->link=first;
	return temp;
	
}
//to insert node from front
NODE insert_rear(NODE first)
{
	NODE cur,pre,temp;
	temp=getnode();
	temp->link=NULL;
	printf("enter name\n");
	scanf("%s",temp->name);
	printf("enter usn\n");
	scanf("%s",temp->usn);
	printf("enter branch\n");
	scanf("%s",temp->branch);
	printf("enter phono\n");
	scanf("%s",temp->phno);
	printf("enter marks\n");
	scanf("%d",&(temp->marks));
	printf("enter sem\n");
	scanf("%d",&(temp->sem));
	if(first==NULL)
	{
		return temp;
	}
	else if(first->link==NULL)
	{
		first->link=temp;
		return first;
	}
	else
	{
		cur=first;
		pre=NULL;
		while(cur!=NULL)
		{
			pre=cur;
			cur=cur->link;
		}
		pre->link=temp;
		return first;
	}
}
NODE delete_front(NODE first)
{
	NODE next;
	if(first==NULL)
	{
		return NULL;
	}
	else if(first->link==NULL)
	{
		printf(" deleted info is %s\t%s\t%s\t%s\t%d\t%d\n", first->name,first->usn,first->branch,first->phno,first->marks,first->sem);
		free(first);
		return NULL;
	}
	else
	{
		next=first->link;
		printf(" deleted info is %s\t%s\t%s\t%s\t%d\t%d\n", first->name,first->usn,first->branch,first->phno,first->marks,first->sem);
		free(first);
		return next;
	}
}				
NODE delete_rear(NODE first)
{
	NODE cur,pre;
	if(first==NULL)
	{
		printf("empty sll\n");
		return NULL;
	}
	else if(first->link==NULL)
	{
		printf(" deleted info is %s\t%s\t%s\t%s\t%d\t%d\n", first->name,first->usn,first->branch,first->phno,first->marks,first->sem);
		free(first);
		return NULL;
	}
	else
	{
		cur=first;
		while(cur->link!=NULL)
		{
			pre=cur;
			cur=cur->link;
		}
		
		printf(" deleted info is %s\t%s\t%s\t%s\t%d\t%d\n", cur->name,cur->usn,cur->branch,cur->phno,cur->marks,cur->sem);
		free(cur);
		pre->link=NULL;
		return first;
	}
}
void stack()
{
	int choice;
	NODE top=NULL;
	printf("enter choice\n 1.push\n 2.pop\n 3.display\n");
	scanf("%d",&choice);
	while(1)
	{
	    switch(choice)
	    {
		case 1:top=insert_front(top);
			break;
		case 2:top=delete_front(top);
			break;
		case 3:display(top);
			break;
		default:return;
	  }
	}	
} 	
void queue()
{
	NODE lq=NULL;
	int choice;
	while(1)
	{
		printf("enter choice 1.insert_rear\n 2.delete_front\n3.display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:lq=insert_rear(lq);
				break;
			case 2:lq=delete_front(lq);
				break;
			case 3:display(lq);
				break;
			default:return;
		}
	}
}
int count(NODE first)
{
	int i=0;
	NODE next=first;
	while(next!=NULL)
	{
		i++;
	}
	return i;
}			
int main()
{
	int choice,n,i,nodes;
	NODE first=NULL;
	while(1)
	{
		printf("enter choice 1.insert_front\n2.insert_rear\n 3.delete_front\n 4.delete_rear\n 5.display\n 6.to demonstrate stack\n 7.to demonstrate queue\n 8.to count nodes 9.exit\n ");
		scanf("%d",&choice);
		switch(choice)
		{
					
			case 1://to create sll of n students
				printf("enter value of n\n");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					
					first=insert_front(first);
					
				}
				break;
			case 2:first=insert_rear(first);
				break;
			case 3:first=delete_front(first);
				break; 
			case 4:first=delete_rear(first);
				break;
			case 5:display(first);
				break;
			case 6:stack();
				break;
			case 7:queue();
				break;
			case 8:nodes=count(first);
				printf("number of nodes=%d",nodes);
				break;
			default:exit(0);
			
		}
	}
}

