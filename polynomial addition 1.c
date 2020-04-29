#include<stdio.h>

typedef struct poly
{
	int cf;
	int px;
	int py;
	int pz;
}p;
p a[10],b[10],c[10];
//accept structure members
void accept(p a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i].cf,&a[i].px,&a[i].py,&a[i].pz);
	}
}
void display(p a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i].cf<0)
		{
		     	printf("%dx^%dy^%dz^%d",a[i].cf,a[i].px,a[i].py,a[i].pz);
		}
		else
		{
			printf("+%dx^%dy^%dz^%d",a[i].cf,a[i].px,a[i].py,a[i].pz);
		}
	}
	printf("\n");
}
int powsearch(p b[],p term,int m)
{
	int i;
	for(i=0;i<m;i++)
	{
		if(b[i].px==term.px && b[i].py ==term.py && b[i].pz==term.pz)
		{
			return i;
		}
		
	}
	return -1;
}
int addpoly(p a[],p b[],p c[],int n,int m)
{
	int i, pos,cindex=0;
	for(i=0;i<n;i++)
	{
		pos = powsearch(b,a[i],m);
		if(pos ==-1)
		{
			c[cindex].cf= a[i].cf+b[pos].cf;
			c[cindex].px= a[i].px;
			c[cindex].py=a[i].py;
			c[cindex].pz=a[i].pz;
			cindex++;
		}
		else
		{
			c[cindex]=a[i];
			cindex++;
		}
	}
	b[pos].cf = -999;
	for(i =0;i<m;i++)
	{
		if(b[i].cf!=-999)
		{
			c[cindex]=b[i];
			cindex++;
		}
	}
		return cindex;
}	

			

	
	
		
		
int main()
{
	int m,n,k;
	printf("enter no of terms in polynomial1\n");
	scanf("%d",&n);
	printf("accept 1st polynomial\n");
	accept(a,n);
	printf(" 1st polynomial is\n");
	display(a,n);
	printf("enter no of terms in polynomial 2\n");
	scanf("%d",&m);
	printf("accept 2nd polynomial\n");
	accept(b,m);
	printf(" 2nd polynomial is\n");
	display(b,m);
	k = addpoly(a,b,c,n,m);
	printf("resultant polynomial is\n");
	display(c,k);
	
	
}
