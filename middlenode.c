#include<malloc.h>
#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
typedef struct node * NODE;
NODE getnode()
{
    NODE temp;
    temp = (NODE) malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("In suffient memory");
        exit(0);
    }
    return temp;
}
NODE insert_front(NODE first)
{
    int data;
    NODE temp=NULL;
    temp = getnode();
    temp->next = NULL;
    printf("Enter the data");
    scanf("%d",&data);
    temp->data = data;
    if(first==NULL)
	{
		return temp;
	}
	temp->next = first;
	return temp;
    
}
/*NODE reverse(NODE first)
{
    if(first!=NULL)
    {
       printf("Empty");
       return NULL;
    }
    NODE prev = NULL;
    
    while(first!=NULL)
    {
        NODE nextnode = first->next;
        first->next = prev;
        prev = first;
        first = nextnode;
    }
    return prev;
}*/
void middle(NODE first)
{
    NODE slow = first;
    NODE fast = first;
    while(fast!=NULL&& fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
       
    }
    
    printf("middle node is:%d",slow->data);
           
}
void display(NODE first)
{
	if(first==NULL)
	{
		printf("empty\n");
	}
	printf("elements are\n");
	while(first!=NULL)
	{
		printf("%d\t",first->data);
		first=first->next;
	}
	
} 
int main()
{
    NODE first  = NULL;
   for(int i=0;i<5;i++)
   {
       first = insert_front(first);
   }
  // reverse(first);
//   display(first);
    middle(first);

    return 0;
}
