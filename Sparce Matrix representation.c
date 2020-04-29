#include<stdio.h>
typedef struct sparce
{
	int row;
	int col;
	int val;
}s;
s a[20],b[20];
//to accept members of structure
void accept(s a[],int row,int col)
{
	int i,j,c_zero = 0,sindex=0;
	printf("accept structure members\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&c_zero);
			if(c_zero!=0)
			{
				sindex++;
				a[sindex].val=c_zero;
				a[sindex].row = i;
				a[sindex].col = j;
			}
		}
	}
	a[0].row = row;
	a[0].col = col;
	a[0].val = sindex;
}
void display(s a[],int row,int col)
{
	int i,j,sindex=1;
	printf("structure members are\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(a[sindex].row==i && a[sindex].col == j)
			{
				printf("%d\t",a[sindex].val);
				sindex++;
			}
			else
			{
				printf("0\t");
			}
		}
		printf("\n");
	}
}
void transporse(s a[],s b[])
{
	int j,n;
	int sindex=0;
	b[0].row = a[0].col;
	b[0].col=a[0].row;
	b[0].val=a[0].val;
	for(j=0;j<a[0].col;j++)
	{
		for(n=1;n<=a[0].val;n++)
		{
			if(a[n].col==j)
			{
				sindex++;
				b[sindex].val=a[n].val;
				b[sindex].row=a[n].col;
				b[sindex].col=a[n].row;
			}
		}
	}
}

						
int main()
{
	int row,col;
	printf("enter row and column\n");
	scanf("%d%d",&row,&col);
	accept(a,row,col);
	display(a,row,col);
	transporse(a,b);
	display(b,row,col);
}	 		
								
				
										
