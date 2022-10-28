#include <stdio.h>
int powernumber1(int base, int power)  //Iteration
{
	int i,ans=1;
	for(i=0;i<power;i++)
	{
		ans = ans*base;
	}
	return ans;
}
int powernumber2(int base, int power)  //Recursion
{
	if(power==0)
	{
		return 1 ;
	}else 
		{
			return (base*powernumber2(base,power-1));
		}
}
int main()
{
	int base,power,ans;
	printf("Enter base: ");
	scanf("%d",&base);
	printf("Enter power: ");
	scanf("%d",&power);
	//ans = powernumber1(base,power);
	ans = powernumber2(base,power);
	printf("Base = %d, Power = %d, Ans = %d\n",base,power,ans);
	return 0;
}
