#include <stdio.h>
int serial1(int num)  //Iteration
{
	int i ,sum = 0;
	for(i=num;i>0;i--)
	{
		sum = sum+i;
	}
	return (sum);
}
int serial2(int num) //Recursion
{
	if(num==0)
	{
		return(num+1); 
	}else
		{
			return (1 + serial2(num-1));
		}
}
int main()
{
	int num,ans;
	printf("Enter a number: ");
	scanf("%d",&num);
//	ans = serial1(num);
	ans = serial2(num);
	printf("A number = %d, Serial of Number = %d\n",num,ans);
	return 0;
}
