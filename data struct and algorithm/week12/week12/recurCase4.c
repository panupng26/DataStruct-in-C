#include <stdio.h>
int countseven(int id)
{
	if(id==0)
	{
		return 0 ;
		
	}else if(id%10 == 7)
		{
			return(1+countseven(id/10));
		}else
			{
				return(countseven(id/10));
			}
}
int main()
{
	int rabbitid,count;
	printf("Enter rabbit id: ");
	scanf("%d",&rabbitid);
	count = countseven(rabbitid);
	printf("Total number of 7 = %d",count); 
	return 0;
}
