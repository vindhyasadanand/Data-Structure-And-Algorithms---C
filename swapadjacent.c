#include <stdio.h>
int main()
{
   int n,i,temp;
   printf("Enter the value of n");
   scanf("%d",&n);
   int arr[n];
   for( i=0;i<n;i++)
   {
       scanf("%d",&arr[i]);
      
   }
   for(i=0;i<n;i+=2)
   {
      temp = arr[i];
      arr[i] = arr[i+1];
      arr[i+1] = temp;
   }
   for(i=0;i<n;i++)
   {
       printf("%d ",arr[i]);
   }
  return 0;
    
}
