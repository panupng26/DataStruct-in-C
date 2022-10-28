#include <stdio.h>
int main()
{
	int i,no ;
	char subject[10],name[50],lname[50];
	float midterm,final,total;
	printf("Enter your subject : ");
	scanf("%s",&subject);
	
	printf("Enter student amount : ");
	scanf("%d",&no);
	
	for(i=1;i<=no;i++)
	{
		printf("*---------------------------------------------------------------------------*\n");
		printf("*---------------------------------------------------------------------------*\n");
		printf("Enter your full name : ");
		scanf("%s%s",&name,&lname);
		printf("Enyer midterm score : ");
		scanf("%f",&midterm);
		printf("Enyer final score : ");
		scanf("%f",&final);
		total = midterm + final ;
		if(total>=80 && total<=100)
		{
	
			printf("Name = %s %s Grade = A Excellent!!!\n",name,lname);
			printf("*---------------------------------------------------------------------------*\n");
			printf("*---------------------------------------------------------------------------*\n");
			
			
		}else if (total>=70 && total<=79)
			{
				
				printf("Name = %s %s Grade = B very good\n",name,lname);
				printf("*---------------------------------------------------------------------------*\n");
				printf("*---------------------------------------------------------------------------*\n");
				
			}else if (total>=60 && total<=69)
				{
					printf("Name = %s %s Grade = C Normal\n",name,lname);
					printf("*---------------------------------------------------------------------------*\n");
					printf("*---------------------------------------------------------------------------*\n");
					
				}else if (total>=50 && total<=59)
					{
						printf("Name = %s %s Grade = D Fair\n",name,lname);
						printf("*---------------------------------------------------------------------------*\n");
						printf("*---------------------------------------------------------------------------*\n");
						
					}else 
					    {
							
							printf("Name = %s %s Grade = F Not worry...try again\n",name,lname);
							printf("*---------------------------------------------------------------------------*\n");
							printf("*---------------------------------------------------------------------------*\n");
				    	}
				    		
				
	}
							
				    		printf("*-----------------------------Program terminated----------------------------*\n");
				    		
	
	
	return 0;
}
