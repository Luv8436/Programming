#include<stdio.h>
int main()
{
	int n;
	printf("enter the number:\n");
	scanf("%d",&n);
	printf("\n");
	int rem;
	while(n>0){
	rem=n%10;
	printf("%d",rem);
	n=(n-rem)/10;
	}
	return 0;
}
