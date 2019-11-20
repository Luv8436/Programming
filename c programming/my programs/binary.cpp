#include<stdio.h>	
	int main()
	{
	int max1_curr=0,max1_prev=0,highest_max1=0,n;
	printf("Enter the number:\n");
	scanf("%d",&n);

    while(!(n==1))
    {
        if(n%2==1)
        {
            max1_curr=max1_curr+1;
        }
        else {
            if(max1_prev>max1_curr)
            {
                highest_max1=max1_prev;
            }
            else {
                highest_max1=max1_curr;
                }
        max1_prev=max1_curr;
        max1_curr=0;    

        }
        n=(n-(n%2))/2;
        
    }
   
        if(highest_max1<max1_curr+1)
        highest_max1=max1_curr+1;

    
    printf("%d",highest_max1);
    return 0;
}
