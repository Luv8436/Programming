#include<stdio.h>
int exchange(int diff ,int sum , int num[] , int count);
int main()
{
	int sum = 0;
	FILE* ptr = fopen("C:\\Users\\luvku\\Downloads\\e_also_big.in","r");
	if(ptr == NULL)
	{
		printf("cannot open the file\n");
		return 0;
	}
	int arr[2];
	for (int i = 0; i < 2; i++)
    {
        fscanf(ptr, "%d", &arr[i]);
    }

    int count = arr[1];
    int num[count];
    for (int i = 0; i <count ; i++)
    {
        fscanf(ptr, "%d", &num[i]);
    }

  
    
    for(int i = 0 ; i < count ; i++)
    {
    	sum = sum + num[i] ;
	}
    
    int diff;
    
    diff = sum - arr[0];
    
    while(diff > 0)
    {
    	sum = exchange(diff ,sum , num , count);
    	count = count - 1;
     	diff = sum - arr[0]; 
    	
	}
	
	FILE* fileptr = fopen("C:\\Users\\luvku\\CS 2019\\Programming\\c programming\\google hash code\\final code\\solution_e_also_big.in","w");
	if(fileptr == NULL)
	{
		printf("cannot write into the file\n");
		return 0;
	}
	fprintf(fileptr , "%d\n" , count);
	for(int i = 0 ; i < arr[1] ; i++)
	{
		if(num[i] == 0)
		continue;
		fprintf(fileptr , "%d ", i);
	}
	
    
	fclose(ptr);
	fclose(fileptr);
	
		
}
int exchange(int diff , int sum , int num[] , int count)
{
	int index = 0;
	while((num[index] < diff )&& (index < count - 1 ))
	{
		index++ ;	
	}
	sum = sum - num[index];
	num[index ] = 0;
	
	return sum;
}
