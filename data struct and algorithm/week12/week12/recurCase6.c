#include <stdio.h>
//build function sumdigit1() to find a summation of each digits 
//build function sumdigit2() to find a summation of each digits 
int sumdigit2(int num)
{
	if(num==0)
	{
		return 0 ;
	}else{
		if(num > 0)
		{
			return(num%10+sumdigit2(num/10));
		}
	}
}
int main()
{
	int num,ans;
	printf("Enter a number: ");
	scanf("%d",&num);
	//ans = sumdigit(num);
	ans = sumdigit2(num);
	printf("Sumation = %d\n",ans);
	return 0;
}
