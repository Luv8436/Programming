#include<stdio.h>
int main()
{
	int a,b,c;
	printf("enter the value of a,b,c");
	scanf("%d%d%d",&a,&b,&c);
	if(a>b&&a>c)
	{
		printf("a is eldest");
	}
	else if(c>a&&c>b)
	{
		printf("c is eldest");
	}
	else if(b>c&&b>a)
	{
		printf("b is eldest");
	}
	return(0);
}

