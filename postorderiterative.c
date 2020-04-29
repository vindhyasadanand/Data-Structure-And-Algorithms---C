#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *llink;
	struct node *rlink;
	int info;
};
typedef struct node *NODE;
NODE getnode()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("memory cannot be allocated\n");
		exit(0);
	}
	return temp;
}
NODE insert_BST(NODE root,int item)
{
	NODE cur,prev,temp;
	cur=root;
	prev=NULL;
	temp=getnode();
	temp->llink=NULL;
	temp->rlink=NULL;
	temp->info=item;
	if(root==NULL)
	{
		return temp;
	}
	//for multiple elements
	while(cur!=NULL)
	{
		prev=cur;
		if(cur->info>item)
		{
			cur=cur->llink;
		}
		else
		{
			cur=cur->rlink;
		}
	}
	//insertion takes place at previous
	if(prev->info>item)
	{
		prev->llink=temp;
	}
	else
	{
		prev->rlink=temp;
	}
	return root;
}
void postorder(NODE root)
{
	struct stack
	{
		NODE addr;
		int flag;
	};
	NODE cur=root;
	int top=-1;
	struct stack s[20];
	//structure used to save the address and the flag
	if(root==NULL)
	{
		printf("Binary search tree is empty\n");
		return;
	}
	printf("Postorder expression of the numbers is\n");
	for(;;)
	{
		while(cur!=NULL)
		{
			top++;
			s[top].addr=cur;
			s[top].flag=1;
			cur=cur->llink;
		}
		while(s[top].flag<0)
		{
			cur=s[top].addr;
			top--;
			printf("%d\n",cur->info);
			//for right traversal
			if(top==-1)
			{
				return;
			}
		}
		cur=s[top].addr;
		cur=cur->rlink;
		s[top].flag=-1;
	}
}
int main()
{
	NODE root=NULL;
	int ch,n,number,key;
	while(1)
	{
		printf("enter the choice\n1.insert\n2.traverse postorder\n3.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter the number\n");
				scanf("%d",&number);
				root=insert_BST(root,number);
				break;
			case 2:postorder(root);
				break;
			default:exit(0);
				break;
		}
	}
}
			
