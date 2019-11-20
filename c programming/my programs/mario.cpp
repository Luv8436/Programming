#include<stdio.h>
int main(void)
{
int n;
printf("n: ");
scanf("%d",&n);
for(int i=0;  i<n ; i++)
{
for( int j=0; j<2*n+1 ; j++)
{
if(       ((j<n-1-i)       ||      (j>n+1+i))         ||     (j==n)       )
{
printf(" ");
}        
else
printf("#");
}
printf("\n");
}
}

