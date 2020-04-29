#include<stdio.h>
int towerh(int n,char a,char b,char c)
{
	if(n==0)
	{
		return 0;
	}	
	towerh(n-1,a,c,b);
	printf("move %d from %c to %c\n",n,a,c); 
	towerh(n-1,b,a,c);
}
int main()
{
	int n;
	printf("enter number\n");
	scanf("%d",&n);
	towerh(n,'b','a','c');
}		
