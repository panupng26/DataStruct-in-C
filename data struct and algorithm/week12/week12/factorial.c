#include <stdio.h>
int factorial (int n)
{
	if(n==0)
	{
		return 1;
	}else{
		return(n*factorial(n-1));
	}
}
int main()
{
	int num,ans;
	printf("Enter a number : ");
	scanf("%d",&num);
	ans = factorial(num);
	printf("Factorial of %d = %d\n",num,ans);
	return 0 ;
}
