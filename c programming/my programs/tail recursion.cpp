#include<stdio.h>
int fact(int a , int b);
int main()
{
	int n;
	printf("enter the number\n");
	scanf("%d",&n);
	int ans=fact(1,n);
	printf("%d",ans);
}
int fact(int a , int b)
{
	if(b==1)
	return a;
	else 
	fact(a*b , b-1);
}
