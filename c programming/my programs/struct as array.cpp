// create an structure of array
#include<stdio.h>
struct cordinate{
	int x;
	int y;
};
int main()
{
	struct cordinate pts[4];
	for(int i=1;i<=4;i++)
	{
		printf("enter the x cordinate of point%d\n",i);
		scanf("%d",&pts[i].x);
		printf("enter the y cordinate of point%d\n",i);
		scanf("%d",&pts[i].y);
	}
	for(int i=1;i<=4;i++)
	{
		printf("\nco-ordinates of point%d are\n(%d,%d)",i,pts[i].x,pts[i].y);
	}
	
	
}
