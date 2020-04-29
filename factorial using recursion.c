#include<stdio.h>
int fact(int n)
{
	if(n==0)
	{
		return 1;
	}
	return (n*fact(n-1));
}
int main()
{
	int n,res;
	printf("enter number\n");
	scanf("%d",&n);
	res=fact(n);
	printf("factorial of %d is %d",n,res);	
}	
			
