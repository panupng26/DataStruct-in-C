#include <stdio.h>
#include <ctype.h>
int main ()
{
	float hei,pala1,pala2,diagone1,radius,area;
	char exit,shape;
	exit = 'N';
	while(toupper(exit)!='Y')
	{
		
	printf("Menu for calculating area of geometric shape\n");
	printf("============================================\n");
	printf("   select : (T) -> Trapezoid shape \n");
	printf("            (K) -> Kite shape \n");
	printf("            (C) -> Circle shape \n");	
	printf("============================================\n");
	printf("Choose goometric shape : ");
	scanf(" %c",&shape);
	
	if(toupper(shape)=='T')
	{
		printf("--------Trapezoid Shape---------\n");
		printf("Enter first parallel : ");
		scanf("%f",&pala1);
		
		printf("Enter second parallel : ");
		scanf("%f",&pala2);
		
		printf("Enter height : ");
		scanf("%f",&hei);
		
		area = 0.5 * (pala1+pala2) * hei;
		printf("\tArea = %0.2f\n",area);
		printf("--------------------------------\n");
		
	}else if(toupper(shape)=='K')
		{
			printf("--------Kite Shape---------\n");
			printf("Enter diagonal : ");
			scanf("%f",&diagone1);
			
			area = 0.5 * (diagone1*diagone1);
			printf("\tArea = %0.2f\n",area);
			printf("----------------------------\n");
		}else if(toupper(shape)=='C')
			{
				printf("------------Circle Shape----------\n");
				printf("Enter radius : ");
				scanf("%f",&radius);
			
				area = 3.14 * (radius*radius);
				printf("\tArea = %0.2f\n",area);
				printf("----------------------------------\n");
			}else
				{
					printf("Error !!!!!\n");
				}
	

		printf("\nDo you want to exit this program (Y/N) : ");
		scanf(" %c",&exit);
	}
	
	return 0;
}
