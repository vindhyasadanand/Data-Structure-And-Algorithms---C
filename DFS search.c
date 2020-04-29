#include<stdio.h>
#include<stdlib.h>
//to read and create adjacent matrix
void read_am(int a[10][10],int n)
{
	int s,d;
	for(s=0;s<n;s++)
	{
		printf("enter nodes to be connected with %d\n",s);
		for(d=0;d<n;d++)
		{
			scanf("%d",&(a[s][d]));
		}
	}
}
//to print all the nodes reachable from starting node
void bfs(int node,int a[10][10],int n)
{
	int q[10],front=0,rear=-1,i,j,v[10]={0};
	printf("\nnodes reachable from %d:\n",node);
	q[++rear]=node;
	v[node]=1;
	while(front<=rear)
	{
		i=q[front++];
		printf("%d \n ",i);
		for(j=0;j<n;j++)
		{
			if(a[i][j]==1&&v[j]==0)
			{
				q[++rear]=j;
				v[j]=1;
			}
		}
	}
}
void dfs(int node,int a[10][10],int n)
{
	int s[10],top=-1,i,j,v[10]={0},des;
	printf("enter destination\n");
	scanf("%d",&des);	
	top++;
	s[top]=node;
	v[node]=1;
	
	while(top>-1)
	{
		i=s[top];
		top--;
		
		for(j=0;j<n;j++)
		{
			if(a[i][j]==1&&v[j]==0)
			{
				if(j==des)
				{
					printf("path exist\n");
					return;
				}
			
				top++;
				s[top]=j;
				v[j]=1;
				
			}
		}
	}
	printf("path does not exist\n");
	
}
int main()
{
	int a[10][10],n,choice,i,src;
	printf("enter number of nodes\n");
	scanf("%d",&n);
	while(1)
	{
		printf("enter choice 1.create graph of cities\n 2.to print all reachable nodes using BFS\n 3.to check connectivity of given graph\n 4.to exit the loop\n");           scanf("%d",&choice);
		switch(choice)
		{
			case 1:read_am(a,n);
				break;
			case 2:for(i=0;i<n;i++)
				{
					bfs(i,a,n);
				}
				break;
			case 3:printf("enter source\n");
				scanf("%d",&src);	
				dfs(src,a,n);
				break;
			case 4:exit(0);
		}
	}
}		
			

