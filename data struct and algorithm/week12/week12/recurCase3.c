#include <stdio.h>
int calcarrot1(int rabbit)  //Iteration
{
	int i ,carrot =0;
	for(i=1;i<=rabbit;i++)
	{
		if(i%2 == 0)
		{
			carrot = carrot + 3 ;
		}else {
			carrot = carrot + 2 ;
		}
	}
	return (carrot);
}
int calcarrot2(int rabbit)  //Recursion
{
	if(rabbit == 0 )
	{
		return (0);
	}else{
		if(rabbit %2 ==0)
		{
			return(3+calcarrot2(rabbit-1));
		}else{
			return(2+calcarrot2(rabbit-1));
		}
	}
}
int main()
{
	int rabbits,ans;
	printf("Enter amount of rabbit come to the party: ");
	scanf("%d",&rabbits);
	ans = calcarrot1(rabbits);
	//ans = calcarrot2(rabbits);
	printf("A number of rabbits = %d, Total carrots = %d\n",rabbits,ans);
	return 0;
}
