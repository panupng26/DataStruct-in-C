#include <stdio.h>
#include <string.h>
typedef struct{
		int day;
		int month;
		int year;
}checkindate;

typedef struct{
		char id[11];
		char Name[25];
		char Gender;
		float GPA;
		checkindate date;
}studentType;

int getdata(studentType std[])
{
	int i=0,j;
	char education[20];
	FILE *inf;
	inf = fopen("data.txt","r");
	fgets(education,20,inf);
	
	fscanf(inf,"%s%s %c%f%d%d%d",&std[i].id,&std[i].Name,&std[i].Gender,&std[i].GPA,&std[i].date.day,&std[i].date.month,&std[i].date.year);
	while(!feof(inf))
	{
	
		i++;		

		fscanf(inf,"%s%s %c%f%d%d%d",&std[i].id,&std[i].Name,&std[i].Gender,&std[i].GPA,&std[i].date.day,&std[i].date.month,&std[i].date.year);
	}
	
	for(j=0;j<i;j++)
	{
		printf("%s\n%s\n%c\n%0.2f\n%d/%d/%d \n",std[j].id,std[j].Name,std[j].Gender,std[j].GPA,std[j].date.day,std[j].date.month,std[j].date.year);
	}
	fclose(inf);
	return i ;
}
void checkgpaupper(studentType std[],int cnt)
{
	FILE *out,*out1,*out2;
	out = fopen("Upper.txt","w");
	out1 = fopen("Lower.txt","w");
	out2 = fopen("Normal.txt","w");
	int total1=0,total2=0,total3=0;
	int i;
	fprintf(out,"The Educational Profile of Student in High GPA\n");
	fprintf(out,"==============================================\n");
	fprintf(out,"   ID               Name          Gender       GPA 	Check-in Date\n");
	
	fprintf(out1,"The Educational Profile of Student in Low GPA\n");
	fprintf(out1,"==============================================\n");
	fprintf(out1,"   ID               Name          Gender       GPA 	Check-in Date\n");
	
	fprintf(out2,"The Educational Profile of Student in Low GPA\n");
	fprintf(out2,"==============================================\n");
	fprintf(out2,"   ID               Name          Gender       GPA 	Check-in Date\n");
	for(i=0;i<cnt;i++)
	{
			if(std[i].GPA>3.00)
			{
				total1++;
				if(std[i].Gender=='F')
					{
						fprintf(out,"%-3s %-10s        Female %-5.2f %d/%d/%d\n",std[i].id,std[i].Name,std[i].GPA,std[i].date.day,std[i].date.month,std[i].date.year);
					}else{
						fprintf(out,"%-3s %-10s        Male %-5.2f %d/%d/%d\n",std[i].id,std[i].Name,std[i].GPA,std[i].date.day,std[i].date.month,std[i].date.year);
					}
				
			}else if (std[i].GPA<2.00)
				{
						total2++;
					if(std[i].Gender=='F')
					{
						fprintf(out1,"%-3s %-10s        Female %-5.2f %d/%d/%d\n",std[i].id,std[i].Name,std[i].GPA,std[i].date.day,std[i].date.month,std[i].date.year);
					}else{
						fprintf(out1,"%-3s %-10s        Male %-5.2f %d/%d/%d\n",std[i].id,std[i].Name,std[i].GPA,std[i].date.day,std[i].date.month,std[i].date.year);
					}
				}else{
						total3++;
						if(std[i].Gender=='F')
					{
						fprintf(out2,"%-3s %-10s        Female %-5.2f %d/%d/%d\n",std[i].id,std[i].Name,std[i].GPA,std[i].date.day,std[i].date.month,std[i].date.year);
					}else{
						fprintf(out2,"%-3s %-10s        Male %-5.2f %d/%d/%d\n",std[i].id,std[i].Name,std[i].GPA,std[i].date.day,std[i].date.month,std[i].date.year);
					}
				}
			
	}	
		fprintf(out,"Total = %d",total1);
		fprintf(out1,"Total = %d",total2);
		fprintf(out2,"Total = %d",total3);
	fclose(out);
	fclose(out1);
	fclose(out2);
}
int main()
{
	studentType std[10];
	int cnt;
	cnt = getdata(std);
	checkgpaupper(std,cnt);
	return 0 ;
}
