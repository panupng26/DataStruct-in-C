#include <stdio.h>

int main() {
	char fname[50],lname[50];
	float score ;
	
	printf("Enter Your Name : ");
	scanf("%s%s",&fname,&lname);
	printf("Enter total score : ");
	scanf("%f",&score);
	
	if(score>=80 && score<=100)
	{
		printf("You got grade : A ");
	}
	else if(score>=70 && score<=79)
		{
			printf("You got grade : B ");		
		}
		else if(score>=60 && score<=69)
			{
				printf("You got grade : C");
			}
			else if (score>=50 && score<=59)	
				{
					printf("You got grade : D");
				}
				else if(score<50)
					{
						printf("You got grade : F");						
					}
					else 
					{
						printf("Error score :P ");
					}
					

			
		
	return 0;
}
