#include <stdio.h>
#include <ctype.h>
int main(){
	int menu,credit;
	char fname[50],lname[50],dept;  							
	float score,amount ;
	printf("==========================================================\n");
	printf(" Please select menu(1-3) for working  \n ");
	printf("\t 1  : calculate credit\n");
	printf("\t 2  : calculate grade\n");
	printf("\t 3  : exit program \n");
	printf("==========================================================\n");
	printf("select menu : ");
	scanf("%d",&menu);
	
	if (menu==1)															//start loop 1
	{
																												//start if else TCB
	
		printf("*------------------------------------------------------------*\n");
		printf(" Select Your department (T,B,C)  \n ");
		printf("\t T  : (T)echnology \t  (fee = 7000)\n");
		printf("\t B  : (B)usiness   \t  (fee = 4000)\n");
		printf("\t C  : (C)omunication Arts (fee = 5000)\n");
		printf("*------------------------------------------------------------*\n");
		printf("Select dept : ");
		scanf(" %c",&dept);
		printf("Enter Your Name : ");
		scanf("%s%s",&fname,&lname);
		printf("Enter credit(s) for registration : ");
		scanf("%d",&credit);
	
		if(toupper(dept)=='T')
		{
			amount = credit * 2000 + 7000;
			printf("*------------------------------------------------------------*\n");
			printf("*------------------------------------------------------------*\n");
			printf("\t\t Amount of registration fee = %0.2f \n",amount);
			printf("*------------------------------------------------------------*\n");
			printf("*------------------------------------------------------------*\n");
		}
		else if (toupper(dept)=='B')
			{				
				amount = credit * 2000 + 4000;
				printf("*------------------------------------------------------------*\n");
				printf("*------------------------------------------------------------*\n");
				printf("\t\t Amount of registration fee = %0.2f \n",amount);
				printf("*------------------------------------------------------------*\n");
				printf("*------------------------------------------------------------*\n");
			}
			else if (toupper(dept)=='C')
				{
					amount = credit * 2000 + 5000;
					printf("*------------------------------------------------------------*\n");
					printf("*------------------------------------------------------------*\n");
					printf("\t\t Amount of registration fee = %0.2f \n",amount);
					printf("*------------------------------------------------------------*\n");
					printf("*------------------------------------------------------------*\n");
				}
				else
					{
						printf("Error select dept");
					}
					
					//endif else TCB
				
							
					
					
				
	}																		//end   loop 1
	else if(menu==2)
		{																	//start loop2
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
					}												//end loop2
						
		}
		else if(menu==3)
			{
			
			}
			else 
			{
				printf("Error select menu");
			}
	return 0;
	}
