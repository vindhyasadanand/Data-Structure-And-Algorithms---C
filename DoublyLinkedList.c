#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node * llink;
	char ssn[20];
	char name[20];
	char dept[20];
	char desi[20];
	char phno[20];
	int sal;
	struct node*rlink;
};
typedef struct node* NODE;
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
//to insert from front
NODE insert_front(NODE first)
{
	NODE temp,cur;
	temp=getnode();
	temp->llink=NULL;
	temp->rlink=NULL;
	printf("enter ssn\n");
	scanf("%s",temp->ssn);
	printf("enter name\n");
	scanf("%s",temp->name);
	printf("enter department\n");
	scanf("%s",temp->dept);
	printf("enter designation\n");
	scanf("%s",temp->desi);
	printf("enter phno\n");
	scanf("%s",temp->phno);
	printf("enter salary\n");
	scanf("%d",&(temp->sal));
	//to no nodes are present
	if(first==NULL)
	{
		return temp;
	}
	cur=first;
	cur->llink=temp;
	temp->rlink=cur;
	return temp;
}
NODE insert_rear(NODE first)
{
	NODE temp,end;
	temp=getnode();
	temp->llink=NULL;
	temp->rlink=NULL;
	printf("enter ssn\n");
	scanf("%s",temp->ssn);
	printf("enter name\n");
	scanf("%s",temp->name);
	printf("enter department\n");
	scanf("%s",temp->dept);
	printf("enter designation\n");
	scanf("%s",temp->desi);
	printf("enter phno\n");
	scanf("%s",temp->phno);
	printf("enter phno\n");
	scanf("%d",&(temp->sal));
	//check for no nodes
	if(first==NULL)
	{
		return temp;
	}
	end=first;
	while(end->rlink!=NULL)
	{
		end=end->rlink;
	}
	end->rlink=temp;
	temp->llink=end;
	return first;
}
//to count nodes
int count(NODE first)
{
	NODE next=first;
	int i=0;
	while(next!=NULL)
	{
		i++;
		next=next->rlink;
	}
	return i;
}	
NODE delete_front(NODE first)
{
	NODE next;
	if(first==next)
	{
		return NULL;
	}
	else if(first->rlink==NULL)
	{
		printf("deleted info is  ssn=%s\t name=%s\t designation=%s\t phno=%s\t,department=%s\t,sal=%d\n",first->ssn,first->name,first->desi,first->phno,first->dept, first->sal);
		free(first);
	}
	else
	{
		next=first->rlink;
		printf("deleted info ssn=%s\t name=%s\t designation=%s\t phno=%s\t,department=%s\t,sal=%d\n",first->ssn,first->name,first->desi,first->phno,first->dept, first->sal); 
		free(first);
		if(next!=NULL)
		{
			next->llink=NULL;
		}
		return next;
	}
}
//to delete from rear
NODE delete_rear(NODE first)
{
	NODE pre,cur;
	if(first==NULL)
	{
		printf("empty\n");
		return NULL;
	}
	else if(first->rlink==NULL)
	{
			
		printf("deleted info ssn=%s\t name=%s\t designation=%s\t phno=%s\t,department=%s\t,sal=%d\n",cur->ssn,cur->name,cur->desi,cur->phno,cur->dept, cur->sal);
	free(first);
	return NULL;
	}
	else
	{
		pre=first;
		cur=first->rlink;
		while(cur->rlink!=NULL)
		{
			pre=cur;
			cur=cur->rlink;
		}
		printf("deleted info ssn=%s\t name=%s\t designation=%s\t phno=%s\t,department=%s\t,sal=%d\n",cur->ssn,cur->name,cur->desi,cur->phno,cur->dept, cur->sal); 
		free(cur);
		pre->rlink=NULL;
		return first;
	}
}
void dequeue()
{
	int choice;
	NODE dq=NULL;
	while(1)
	{
		printf("enter choice\n 1.insert_rear\n2.insert_front\n3.delete_front\n4.delete rear\n");
		scanf("%d",&choice);
		switch(1)
		{
			case 1:dq=insert_front(dq);
				break;
			case 2:dq=insert_rear(dq);
				break;
			case 3:dq=delete_front(dq);
				break;
			case 4:dq=delete_rear(dq);
				break;
			default:return;
		}
	}
}
void display(NODE first)
{
	NODE cur;
	cur=first;
	printf("informations are\n");
	while(cur->rlink!=NULL)
	{
		printf("deleted info ssn=%s\t name=%s\t designation=%s\t phno=%s\t,department=%s\t,sal=%d\n",cur->ssn,cur->name,cur->desi,cur->phno,cur->dept, cur->sal); 
		cur=cur->rlink;
	}
}		
			
			
	

int main()
{
	NODE first=NULL;
	int nodes,n,i,choice;
	while(1)
	{
		printf("enter choice 1.insert_front\n2.insert_rear\n3delete_front\n.4delete_rear\n 5.to impliment doubleended queue\n 6.display\n 7. to count nodes\n8.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:first=insert_front(first);
				break;
			case 2:printf("enter value of n\n");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					first=insert_rear(first);
				}
				break;
			case 3:first=delete_front(first);
				break;
			case 4:first=delete_rear(first);
				break;
			case 5:dequeue();
				break;
			case 6:display(first);
				break;
			case 7:nodes=count(first);
				printf("number of nodes=%d",nodes);
				break;
			
	
				
	
		}
	}
}
