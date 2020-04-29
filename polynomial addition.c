#include<stdio.h>
struct poly
{
	int cf;
	int pow;
};
typedef struct poly p;
p a[10],b[10],c[10];
void accept (p a[], int n)
{
	int i;
	printf("enter coefficients and powers\n");
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a[i].cf,&a[i].pow);
	}
}
void display(p a[],int n)
{
	int cf,pow,i;
	printf("polynomial is\n");
	for(i=0;i<n;i++)
	{
		cf=a[i].cf;
		pow=a[i].pow;
		if(cf<0)
		{
			printf("%dx^%d",cf,pow);
		}
		else
		{
			printf("+%dx^%d",cf,pow);
		}
	
	}
	printf("\n");
}
int search_pow(p b[10],p term,int m)
{
	int i;
	for(i=0;i<m;i++)
	{
		if(b[i].pow==term.pow)
		{
			return i;
		}
	}
	return -1;
}
int addpoly(p a[10],p b[10],p c[10],int n,int m)
{
	int cindex=0,i,pos;
	for(i=0;i<n;i++)
	{
		pos=search_pow(b,a[i],m);
		if(pos!=-1)
		{
			c[cindex].cf=a[i].cf+b[pos].cf;
			c[cindex].pow=a[i].pow;
			b[pos].cf=-999;
		}
		else
		{
			c[cindex]= a[i];
		}
		cindex ++;
		for(i=0;i<m;i++)
		{
			if(b[i].cf!=-999)
			{
				c[cindex]=b[i];
				cindex++;
			}
		}
	}
		
	return cindex;
				
				
				
}				
int main()
{
	p a[10],b[10],c[10];
	int m,n,k;
	//accept number of terms
	printf("enter terms in polynomials\n");
	scanf("%d%d",&n,&m);
	accept(a,n);
	display(a,n);
	accept(	b,m);
	display(b,m);
	k= addpoly(a,b,c,n,m);
	printf("resultant polynomial is\n");
	display(c,k);
}	
							
	
	
	
