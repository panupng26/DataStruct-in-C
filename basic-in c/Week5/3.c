#include <stdio.h>
int main()
{       
    int i,num,pos = 0 ,neg = 0;
	for (i=1;i<=10;i++)
	{
        printf("Enter Number #%d :",i);
		scanf("%d",&num);
		if(num>0)
		{
			pos ++;
		}else
		{
			neg ++;
		}
	}

	printf("Positive number = %d\nNegative number = %d\n",pos,neg);
 return 0 ;
}
