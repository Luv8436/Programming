#include<stdio.h>
int main()
{
    int t; 
    scanf("%d",&t);
    for(int l=0;l<t;l++)  
    {
        int n,i; 
        scanf("%d",&n);
        int a[n];
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        int h[n];
        for(i=1;i<=n;i++)
        {
            for(int j=i;j>0;j--)
            {
                int sum=0;
                for(int k=0;k<i;k++)
                {
                    if(a[k]>=j)
                    { sum=sum+1;
                    }
                }    
                if(sum>=j)
                {
                h[i-1]=j;
                break;
                }
        
            }
            
        }
        printf("Case #%d: ",l+1);
        for(i=0;i<n;i++)
        {
        printf("%d ",h[i]);
        }
        printf("\n");
        
    }
}
