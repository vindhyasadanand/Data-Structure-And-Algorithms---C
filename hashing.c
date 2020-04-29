#include<stdio.h>
#include<stdlib.h>
//structure to save employee information
struct emp
{
	int eid;
	char ename[20];
	int esal;
};
typedef struct emp E;
//structure for hash table
struct hashtable
{
	int key;
	//K
	long int adder;
};
typedef struct hashtable ht;
//function to find hashvalue
int hash(int num,int hz)
{
	int index;
	index=num%hz;
	return index;
}
//to insert vales inside the hash table
void insert(FILE *fp,ht h[10],int m)
{
	E e;
	int i,hval,countindex;
	for(i=0;i<m;i++)
	{
		printf("enter eid ename,esal\n");
		scanf("%d%s",&e.eid,e.ename);
		scanf("%d",&e.esal);
		hval=hash(e.eid,m);
		countindex=hval;
		//condition for linear probing
		while(h[hval].key!=-1)
		{
			hval=(hval+1)%m;
			printf("%d",hval);
			if(hval==countindex)
			{
				printf("hash table is full insersion not possible\n");
				return;
			}}
			fseek(fp,0,SEEK_END);
			h[hval].adder=ftell(fp);
			h[hval].key=e.eid;
			fwrite(&e,sizeof(E),1,fp);
		
	}
}
void search(FILE *fp,ht h[],int m)
{
	E e;
	int hval,countindex;
	printf("enter eid to be searched\n");
	scanf("%d",&e.eid);
	hval=hash(e.eid,m);
	countindex=hval;
	while(h[hval].key!=e.eid)
	{
		hval=(hval+1)%m;
		if(hval==countindex)
		{
			printf("search unsuccesful\n");
			return;
		}
}
		fseek(fp,h[hval].adder,SEEK_SET);
		fread(&e,sizeof(E),1,fp);
		printf("%d\t%s\t%d",e.eid,e.ename,e.esal);
	
}
//to display
void display(FILE *fp,ht h[10],int m)
{
	E e;
	int i;
	for(i=0;i<m;i++)
	{
		if(h[i].key!=-1)
		{
			fseek(fp,h[i].adder,SEEK_SET);
			fread(&e,sizeof(E),1,fp);
			printf("%d\t%s\t%d\n",e.eid,e.ename,e.esal);
		}
	}
}
int main()
{
	ht hz[10];
	int m,choice,i;
	printf("accept no of employees\n");
	scanf("%d",&m);
	FILE *fp;
	fp=fopen("emp.txt","w+");
	for(i=0;i<m;i++)
	{
		hz[i].key=-1;
	}
		while(1)
		{
			printf("enter choice\n 1.insert\n 2.search\n 3.display\n4.exit\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:insert(fp,hz,m);
					break;
				case 2:search(fp,hz,m);
					break;
				case 3:display(fp,hz,m);
					break;
				default:exit(0);
			}
		}

}
	
				
					
				
		
