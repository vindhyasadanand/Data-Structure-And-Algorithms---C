#include <string.h>
 
void stringconcatenate(char *s1,char *s2)
{
	int i;
	int j=strlen(s2);
	
    for(i=0;s2[i];i++)  
    {
    	s1[i+j]=s2[i];
	}
	s1[i+j]='\0';
    
 	
}
int main()
{
 
    char s1[1000],s2[1000];  
 
    printf("Enter  string1: ");
    gets(s1);
    printf("Enter  string2: ");
    gets(s2);
    stringconcatenate(s1,s2);
    printf("combined two strings ='%s'\n",s1);
 
    return 0;
    
}
