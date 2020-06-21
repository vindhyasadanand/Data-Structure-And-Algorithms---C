#include <stdio.h>

void main()
{
   char s1[6],s2[6];
     int i=0;
     printf("enter strings\n");
     gets(s1);
     gets(s2);
     while(s1[i]==s2[i]&& s1[i]!='\0'&& s2[i]!='\0')
     {
         i = i+1;
     }
     if(s1[i]=='\0'&&s2[i]=='\0')
    {
        printf("Strings are equal");
    }
    else
    {
        printf("Strings are not equal");
        
    }
}

