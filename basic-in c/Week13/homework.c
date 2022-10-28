#include <stdio.h>

void getscore(int number[],int *cnt)
{
	int i = 0;
	int exit = -1;

	printf("Enter Score (-1 TO Exit) : ");
	scanf("%d",&number[i]);
	
	while(number[i] != exit)
	{
		i++;
		printf("Enter Score (-1 TO Exit) : ");
		scanf("%d",&number[i]);
		*cnt = i;
	}
	
}

void output(int number[],int cnt)
{
	int max = -1;
	int min ;
	float total=0,avg;
	int i ;
	for(i=0;i<cnt;i++)
	{
		printf("Score[%d] = %d\n",i,number[i]);
		
		total = total + number[i];
		if(number[i]>max)
		{
			max = number[i];
		}
		if(number[i]!=max)
		{
			min = number[i];
		}
	}
	avg = total / cnt;
	printf("Average = %0.2f\n",avg);
	printf("Max = %d\n",max);
	printf("Min = %d\n",min);
	
}

int main()
{
	int scoreA[40],scoreB[40],cntA,cntB;
	printf("Class A\n");
	getscore(scoreA,&cntA);
	
	printf("\nClass B\n");
	getscore(scoreB,&cntB);
	
	printf("\nOutput Class A\n");
	output(scoreA,cntA);
	
	printf("\nOutput Class B\n");
	output(scoreB,cntB);
	
	return 0;	
}
