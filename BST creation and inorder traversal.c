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
void inorder(NODE root)
{
	NODE cur,s[10];
	int top=-1;
	cur=root;
	printf("Inorder traversal of numbers are\n"); 
	for( ; ;)
	{
		while(cur!=NULL)
		{
			top++;
			s[top]=cur;
			cur=cur->llink;
			//for left traversal
		}
		if(top!=-1)
		{
			cur=s[top];
			top--;
			printf("%d\n",cur->info);
			//info on the left side is printed
			cur=cur->rlink;
		}
		else
		{
			return;
		}
	}
}
int main()
{
	NODE root=NULL;
	int ch,n,number,key;
	while(1)
	{
		printf("enter the choice\n1.insert\n2.traverse inorder\n3.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter the number\n");
				scanf("%d",&number);
				root=insert_BST(root,number);
				break;
			case 2:inorder(root);
				break;
			default:exit(0);
				break;
		}
	}
}
			
