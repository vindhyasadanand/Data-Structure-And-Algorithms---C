#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node*llink;
	int info;
	
	struct node*rlink;
};
typedef struct node*NODE;
NODE getnode()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		return NULL;
	}
	else
	{
		return temp;
	}
}
NODE insert_bst(NODE root,int ele)
{
	NODE cur,temp,pre;
	temp=getnode();
	temp->llink=NULL;
	temp->rlink=NULL;
	temp->info=ele;
	if(root==NULL)
	{
		return temp;
	}
	pre=NULL;
	cur=root;
	while(cur!=NULL)
	{
		pre=cur;
		if(cur->info>ele)
		{
			cur=cur->llink;
		}
		else
		{
			cur=cur->rlink;
		}
	}
	if(pre->info>ele)
	{
		pre->llink=temp;
	}
	else
	{
		pre->rlink=temp;
	}
	return root;
}
//to search 

void search_bst(NODE root)
{
	int key;
	NODE cur=NULL;
	printf("enter element to be searched\n");
	scanf("%d",&key);
	printf("traversal\n");
	//preorder(root);
	if(root==NULL)
	{
		printf("empty bst\n");
		
	}
	else
	{
		cur=root;
		while(cur!=NULL)
		{
			printf("entered search \n");
			if(cur->info==key)
			{
				printf("successful search\n");
				return;
			}
			else if(cur->info<key)
			{
				cur=cur->rlink;
			}
			else
			{
				cur=cur->llink;
			}
		}
		printf("unsuccessful search\n");
	}
	
		
}			

//to traverse inorder in  bst
void inorder(NODE root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->llink);
	printf("%d\t",root->info);
	inorder(root->rlink);
}
//to create  bst
NODE create_bst(NODE root)
{
	int i,n,ele;
	printf("enter number of elements to be inserted\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter ele\n");
		scanf("%d",&ele);
		root=insert_bst(root,ele);
	}
	return root;
}

NODE delete_bst(NODE root,int key)
{
	NODE cur,parent,suc,next;
	if(root==NULL)
	{
		printf("bst is empty\n");
		return NULL;
	}
	parent=NULL;
	cur=root;
	while(cur!=NULL)
	{
		if(cur->info==key)
		{
			break;
		}
		parent=cur;
		if(cur->info<key)
		{
			cur=cur->rlink;
		}
		else
		{
			cur=cur->llink;
		}
	}
	//if key element exists then also we will come out of the while loop
	//if key element does not exist then also we will come out of the loop
	//so there can be two chances when we exist while loop
	if(cur==NULL)
	{
		printf("element doesnot exist\n");
		return root;
	}
	//we are checking if it is a leaf node
	if(cur->llink==NULL)
	{
		next=cur->rlink;
	}
	//to check it is a leaf node
	else if(cur->rlink==NULL)
	{
		next=cur->rlink;
	}
	else
	{      //if it is not a leaf node then this will be executed
		suc=cur->rlink;
		while(suc->llink!=NULL)
		{
			suc=suc->rlink;
		}
		suc->llink=cur->llink;
		next=cur->rlink;
	}
	if(parent==NULL)
	{
		free(cur);
		return next;
	}
	if(cur=parent->llink)
	{
		parent->rlink=next;
	}
	else
	{
		parent->rlink=next;
	}
	free(cur);
	return root;
	
}
		
int height(NODE root)
{
    if(root==NULL)
    {
        return 0;
    }
    return height(root->llink) + height(root->rlink) + 1;
}
		
			
int main()
{
	NODE root=NULL;
	int choice,key,ele,h;
	while(1)
	{
		printf("enter choice\n 1.create_bst\n 2.to traverse\n 3.search_bst\n 4.delete\n 5.to display\n 6.height\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:root=create_bst( root);
				break;
			case 2:inorder(root);
				break;
			case 3:
				search_bst( root);
				break;
			case 4:printf("enter element to be deleted\n");
				scanf("%d",&ele);
				root=delete_bst(root,ele);
				break;
			case 5:inorder(root);
				break;
			case 6: h = height(root);
			        printf("height: %d\n",h);
			        break;
			
		}
	}
}
