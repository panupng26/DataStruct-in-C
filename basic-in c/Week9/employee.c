#include <stdio.h>
#include <ctype.h>
int main ()
{
	FILE *inf,*emp1,*emp2;
	char id[5];
	int dept,age,aver1=0,aver2=0,total1=0,total2=0;
	inf = fopen("employee.txt","r");
	emp1 = fopen("Emp1.txt","w");
	emp2 = fopen("Emp2.txt","w");
	
	fprintf(emp1,"Accounting and Marketing\n") ;
	fprintf(emp2,"IT and Engineer\n") ;
	
	fscanf(inf,"%s%d%d",&id,&dept,&age); //start
	while(!feof(inf)) //test
	{
		if(dept == 1 || dept == 4)
		{
		
			
			if(dept == 1)
			{
				fprintf(emp1,"%s Accounting %d\n",id,age);
				aver1=aver1+age;
				total1++;
			}else
				{
					fprintf(emp1,"%s Marketing %d\n",id,age);
					aver1=aver1+age;
					total1++;
				}
			
				
		}else if(dept == 2 || dept == 3)
			{
				
				
				if(dept == 2)
				{
					
					fprintf(emp2,"%s IT %d\n",id,age);
					aver2=aver2+age;
					total2++;
				}else
					{
						fprintf(emp2,"%s Engineer %d\n",id,age);
						aver2=aver2+age;
						total2++;
					}
			}
		
		fscanf(inf,"%s%d%d",&id,&dept,&age); //action
	}
	fprintf(emp1,"Average age = %0.2f",(float)aver1/total1);
	fprintf(emp2,"Average age = %0.2f",(float)aver2/total2);
	fclose(inf);
	fclose(emp1);
	fclose(emp2);
	return 0;
}
