#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct
{
	int id;
	char fname[15],lname[15];
	int age,listen,talk,read,write;
	char skill[15];
}profile;

int getdata (profile emp[])
{
	int i = 0 ;
	FILE *inf;
	inf = fopen("employee.txt","r");
	
	fscanf(inf,"%d%s%s%d%d%d%d%d%s",&emp[i].id,&emp[i].fname,&emp[i].lname,&emp[i].age,&emp[i].listen,&emp[i].talk,&emp[i].read,&emp[i].write,&emp[i].skill);

	while(!feof(inf))
	{
	//	fscanf(inf,"%s%s",&emp[i].fname,&emp[i].lname); 													//don't focus
	//	fscanf(inf,"%d%d%d%d%d",&emp[i].age,&emp[i].listen,&emp[i].talk,&emp[i].read,&emp[i].write)	;
	//	fscanf(inf,"%s",&emp[i].skill);
		i++;	
		fscanf(inf,"%d%s%s%d%d%d%d%d%s",&emp[i].id,&emp[i].fname,&emp[i].lname,&emp[i].age,&emp[i].listen,&emp[i].talk,&emp[i].read,&emp[i].write,&emp[i].skill);
	}
	
	fclose(inf);
	return (i);
}
int showmenu()
{
	int menu;
	printf("Main Menu of Student Management Program (SMP)\n");
	printf("=============================================\n");
	printf("  1. List all of applicant\n");
	printf("  2. Searching by age\n");
	printf("  3. Searching by English skill\n");
	printf("  4. Searching by Computer skill\n");
	printf("  5. Exit\n");
	
	printf("Select Menu(1-5): ");
	scanf("%d",&menu);
	
	return (menu);
}
void display1(profile emp[],int cnt)
{
	int i ;
	for(i=0;i<cnt;i++)
	{
		printf("%-5d %-10s %-20s %-15d %-5d %-5d %-5d %-5d %-3s\n",emp[i].id,emp[i].fname,emp[i].lname,emp[i].age,emp[i].listen,emp[i].talk,emp[i].read,emp[i].write,emp[i].skill);
	}
}

void display2(profile emp[],int cnt)
{
	int i ;
	int bet1,bet2;
	
	printf("Enter number : ");
	scanf("%d",&bet1);
	printf("Enter between : ");
	scanf("%d",&bet2);
	
	for(i=0;i<cnt;i++)
	{
		if(emp[i].age>=bet1 && emp[i].age<=bet2)
		{
			printf("%-5d %-10s %-20s %-15d %-5d %-5d %-5d %-5d %-3s\n",emp[i].id,emp[i].fname,emp[i].lname,emp[i].age,emp[i].listen,emp[i].talk,emp[i].read,emp[i].write,emp[i].skill);
		}
	}
}
void display3(profile emp[],int cnt)
{
		float grade;
		int i ;
		for(i=0;i<cnt;i++)
		{
			grade = (emp[i].write + emp[i].talk + emp[i].listen + emp[i].read) / 4 ;
			
			if(grade >=3.00 )
			{
			printf("%-5d %-10s %-20s %-15d %-5d %-5d %-5d %-5d %-3.2f %-3s\n",emp[i].id,emp[i].fname,emp[i].lname,emp[i].age,emp[i].listen,emp[i].talk,emp[i].read,emp[i].write,grade,emp[i].skill);
			}
		}
		
}
void display4(profile emp[],int cnt)
{
	int i;
	for(i=0;i<cnt;i++)
{	if(strcmp(emp[i].skill,"Good")==0 || strcmp(emp[i].skill,"Excellent")==0)

	{
			printf("%-5d %-10s %-20s %-15d %-5d %-5d %-5d %-5d %-3s\n",emp[i].id,emp[i].fname,emp[i].lname,emp[i].age,emp[i].listen,emp[i].talk,emp[i].read,emp[i].write,emp[i].skill);
	}

}
}
void displaymain(profile emp[],int menu,int cnt)
{
	int i ;
	if(menu==1)
	{
		display1(emp,cnt);
	}else if(menu==2)
		{
			display2(emp,cnt);
		}else if (menu==3)
			{
				display3(emp,cnt);
			}else if (menu==4)
				{
					display4(emp,cnt);
				}else if (menu==5)
				{
					printf("Exit...");
				}
}
int main ()
{
	int menu;
	int cnt = 0;
	profile emp[9];
	
	cnt = getdata(emp);
	
	menu = showmenu();
	
	displaymain(emp,menu,cnt);
	
	return 0;
}
