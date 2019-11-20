// return a duplicate of string from function
#include<stdio.h>
#include<stdlib.h>
char *duplicate(char *s);
int main()
{
	int n;
	printf("enter the length of your name\n");
	scanf("%d",&n);
	char my_name[n+1];
	printf("enter your name\n");
	scanf("%s",my_name);
	char *copy_name=duplicate(my_name);
	printf("the duplicate of your name is \n");
	printf("%s\n",copy_name);
	free(copy_name);
	
}
char *duplicate(char s[])//function taking string as input and returning its duplicate
{
	int i=0;
	int str_len=0;//length of string
	char *t;/*declaring new string (also written as char t[])*/
	// finding length of string
	for(i=0;s[i]!='\0';i++)
	{
	}
	str_len=i;
	t=(char *)malloc((str_len+1) * sizeof(char));
	for(i=0;i<str_len;i++)
	{
		t[i]=s[i];
	}
	t[i]='\0';
	return t;
}

	
	
