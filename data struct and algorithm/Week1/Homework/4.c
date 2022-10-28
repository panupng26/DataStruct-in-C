#include <stdio.h>
#include <string.h>
#include <ctype.h>

void getdata(int *hei,int *wei)
{
	printf("Enter Height (cm) : ");
	scanf("%d",&*hei);
	printf("Enter Weight (kilograms) : ");
	scanf("%d",&*wei);
}
void report(char sex,int hei,int wei)
{
	int stan;
	printf("========= Report =========\n");
	if(toupper(sex)== 'M')
	{
		stan = hei - 100;
		printf("Weight standard = %d \n",stan);
		if(wei>stan)
		{
			printf("Your weight is greater than weight standard\n");
		}else if (wei<stan)
			{
				printf("Your weight is less than weight standard\n");
			}else if (wei==stan)
				{
					printf("Your have a perfect shape\n");
				}
		
	}else if (toupper(sex)== 'F')
		{
			stan = hei - 110;
			printf("Weight standard = %d\n",stan);
		if(wei>stan)
		{
			printf("Your weight is greater than weight standard\n");
		}else if (wei<stan)
			{
				printf("Your weight is less than weight standard\n");
			}else if (wei==stan)
				{
					printf("Your have a perfect shape\n");
				}
		}else
			{
			}
}
int main()
{
	char name[30],sex,check = 'Y';
	int hei,wei;
	
	while(toupper(check)!='N')
	{
	printf("Enter Name : ");
	scanf("%s",&name);
	printf("Enter Sex : ");
	scanf(" %c",&sex);
	getdata(&hei,&wei);
	report(sex,hei,wei);
	
	printf("\n****************************************\n");
	printf("Do you want to continue? (Y/N) : ");
	scanf(" %c",&check);
	printf("\n****************************************\n");
	}
	return 0;
}
