#include <stdio.h>
#include <ctype.h>
int main ()
{	int listjob,readingskill,writingskill,speakingskill,sales,skale;
	int total,totaljob1=0,totalemployee1=0,totaljob2=0,totalemployee2=0,totaljob3=0,totalemployee3=0,totaljob4=0,totalemployee4=0;
	float wei,hei,bmi,height;
	char name[50],lname[50],communication,java,cprogram,python,lvlskill;
	char loop ;
	do
	{
	
	printf("=============================================================\n");
	printf("@                    List of Job Position                   @\n");
	printf("@                    --------------------                   @\n");
	printf("@                   (1) Secretary                           @\n");
	printf("@                   (2) Programmer                          @\n");
	printf("@                   (3) Sale Marketing                      @\n");
	printf("@                   (4) Public Relations                    @\n");
	printf("@                                                           @\n");
	printf("=============================================================\n");
	printf("Please select a job number : ");
	scanf("%d",&listjob);
	
	if(listjob == 1)
	{
		printf("\n");
		printf("------------------Secretary------------------\n");
		printf("Enter name : ");
		scanf("%s%s",&name,&lname);
		printf("Please select your english skill :\n");
		printf("	Reading skill (1-4)  : ");
		scanf("%d",&readingskill) ;
		printf("	Writing skill (1-4)  : ");
		scanf("%d",&writingskill) ;
		printf("	Speaking skill (1-4) : ");
		scanf("%d",&speakingskill) ;
		printf("Do you have good communication (Y/N) : ");
		scanf(" %c",&communication) ;
		totaljob1 ++ ;
		if(toupper(communication)=='Y' && readingskill>2 && writingskill>2 && speakingskill>3)
		{
			printf("\nCongratulation! You got this job.\n");
			totalemployee1++;
		}else
		{
			printf("\nSorry, see you next time.\n");
		}
		
	}else if (listjob == 2)
		{
			printf("------------------Programmer------------------\n");
			printf("Enter name : ");
			scanf("%s%s",&name,&lname);
			printf("Can you write a java program(Y/N) : ");
			scanf(" %c",&java);
			printf("Can you write a c program(Y/N) : ");
			scanf(" %c",&cprogram);
			printf("Can you write a python program(Y/N) : ");
			scanf(" %c",&python);
			totaljob2 ++;
			if(toupper(java)=='Y' && toupper(cprogram)=='Y' && toupper(python)=='Y')
			{
				printf("\nCongratulation! You got this job.\n");
				totalemployee2++;
			}else
				{
					printf("\nSorry, see you next time.\n");
				}
			
		}else if (listjob == 3)
			{
				printf("------------------Sale Marketing------------------\n");
				printf("Enter name : ");
				scanf("%s%s",&name,&lname);
				printf("Level of communication skill (Perfect/Good/Normal) : ");
				scanf(" %c",&lvlskill);
				printf("Enter annual sales : ");
				scanf("%d",&sales);
				totaljob3++;
				if(toupper(lvlskill)=='P'&& sales>=50000)
				{
					printf("\nCongratulation! You got this job.\n");
					totalemployee3++;
				}else if (toupper(lvlskill)=='G'&& sales>=90000)
					{
						printf("\nCongratulation! You got this job.\n");
						totalemployee3++;
					}else if (toupper(lvlskill)=='N')
					{
						printf("\nCongratulation! You got this job.\n");
						totalemployee3++;
					}else
					{
						printf("\nSorry, see you next time.\n");
					}
			}else if (listjob == 4)
				{
					printf("------------------Public Relations------------------\n");
					printf("Enter name : ");
					scanf("%s%s",&name,&lname);
					printf("Enter weight (kg.) : ");
					scanf("%f",&wei);
					printf("Enter height (cm.) : ");
					scanf("%f",&height);
					printf("Select personality skale(1-5) : ");
					scanf("%d",&skale);
					totaljob4++;
					
					if(height>164)
					{
					hei = height/100;
					bmi = wei/(hei*hei);
					printf("BMI = %0.2f\n",bmi);
						if(bmi >=18.5 && bmi <= 22 && skale >=3)
					{
						printf("\nCongratulation! You got this job.\n");
						totalemployee4++;
					}else
						{
							printf("\nSorry, see you next time.\n");
						}
					}else
						{
							printf("\nSorry, see you next time.\n");
						}
				}else
				{
					printf("Key Job Error");
				}
	printf("Do you want to exit (Y/N) : ");
	scanf(" %c",&loop);
	}	while(toupper(loop) !='Y');
	total=totaljob1+totaljob2+totaljob3+totaljob4;
	printf("Total of applicant = %d\n",total);
	printf("Total employee of job1 = %d, Total applicant = %d\n",totalemployee1,totaljob1);
	printf("Total employee of job2 = %d, Total applicant = %d\n",totalemployee2,totaljob2);
	printf("Total employee of job3 = %d, Total applicant = %d\n",totalemployee3,totaljob3);
	printf("Total employee of job4 = %d, Total applicant = %d\n",totalemployee4,totaljob4);
	
	return 0;
}
