#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct{
	int salary;
	float com,income;
}allmoney;
typedef struct{
	int id;
	char name[35];
	allmoney money;
}employee;

int getdata(employee emp[])
{
	FILE *inf1,*inf;
	int i = 0 ; 
	char string[35];
	int j=0;
	char string1[38];
	inf =fopen("employee.txt","r");
	inf1 = fopen("salary.txt","r");
		
	fgets(string1,38,inf1);
	fscanf(inf1,"%d%d",&emp[j].id,&emp[j].money.salary);
	while(!feof(inf1))
	{
		j++;
		fscanf(inf1,"%d%d",&emp[j].id,&emp[j].money.salary);
	}

	fgets(string,35,inf);
	fscanf(inf,"%d",&emp[i].id);
	fgets(emp[i].name,35,inf);
	while(!feof(inf))
	{
		i++;
		fscanf(inf,"%d",&emp[i].id);
		fgets(emp[i].name,35,inf);
	}
	fclose(inf);
	fclose(inf1);
	return (j);
}
void getdata1(employee emp[])
{
	int i = 0 ;
	FILE *inf;
	inf =fopen("employee.txt","r");
	char string[35];
	
	fgets(string,35,inf);
	fscanf(inf,"%d",&emp[i].id);
	fgets(emp[i].name,35,inf);
	while(!feof(inf))
	{
		i++;
		fscanf(inf,"%d",&emp[i].id);
		fgets(emp[i].name,35,inf);
	}

}

void checktest(employee emp[],int cnt)
{
	int i ;
	for(i=0;i<cnt;i++)
	{
		if(emp[i].money.salary>=15000)
		{
			emp[i].money.com = (emp[i].money.salary * 10)/100;
			emp[i].money.income = (15000 + emp[i].money.com);
		}else if (emp[i].money.salary>=10000 && emp[i].money.salary<15000)
			{
				emp[i].money.com = (emp[i].money.salary * 7)/100;
				emp[i].money.income = (15000 + emp[i].money.com);
			}else 
				{
					emp[i].money.com = (emp[i].money.salary * 4)/100;
					emp[i].money.income = (15000 + emp[i].money.com);
				}
	}
}
void display(employee emp[],int cnt)
{
	float max=0;
	int id;
	float total=0,avg=0;
	FILE *out;
	out = fopen("out.txt","w");
	int i ;
	fprintf(out,"--------------------------The Bangkok Company----------------------\n");
	fprintf(out,"Emploee ID	||	Sales	||	Comission	||	Net Income	||		Name\n");
	fprintf(out,"-------------------------------------------------------------------\n");
	for(i=0;i<cnt;i++)
	{
		total = total + emp[i].money.com;
		avg = (avg + emp[i].money.income);
		fprintf(out,"%-13d\t||%-10d\t||%10.2f\t||%10.2f\t||%-10s\n",emp[i].id,emp[i].money.salary,emp[i].money.com,emp[i].money.income,emp[i].name);
		if(max<emp[i].money.com)
		{
			max = emp[i].money.com;
			id = emp[i].id;
		}
	}
	fprintf(out,"-------------------------------------------------------------------\n");
	fprintf(out,"Total Commission : %0.2f\n",total);		
	fprintf(out,"-------------------------------------------------------------------\n");
				avg = avg / 10 ; 
	fprintf(out,"Average Net Income : %0.2f\n",avg);		
	fprintf(out,"-------------------------------------------------------------------\n");
	fprintf(out,"Maximum Comission : %0.2f\n",max);
	fprintf(out,"By ID : %d\n",id);
	fprintf(out,"-------------------------------------------------------------------\n");
	fclose(out);
}
int main()
{
	employee emp[10];
	int cnt;
	cnt = getdata(emp);
	checktest(emp,cnt);
	display(emp,cnt);
	
	return 0 ;
}
