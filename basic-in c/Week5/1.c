#include <stdio.h>
int main()
{       
    int i,num,sum=0;
	float avg;
	printf("Input the 10 numbers : \n");
	for (i=1;i<=10;i++)
	{
        printf("Number#%d :",i);
		scanf("%d",&num);
		sum +=num;
	}
	avg=sum/10.0;
	printf("The sum of 10 no is : %d\nThe Average is : %f\n",sum,avg);
 return 0 ;
}

