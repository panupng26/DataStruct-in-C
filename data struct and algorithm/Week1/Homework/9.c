#include <stdio.h>
#include <string.h>
#include <ctype.h>

int getemployee(int id[],char name[][30],char sex[],int dept[],int age[])
{
	int i = 0 ;
	FILE *inf;
	inf = fopen("employee.txt","r");

	fscanf(inf,"%d%s %c%d%d",&id[i],&name[i],&sex[i],&dept[i],&age[i]);
	while(!feof(inf))
	{
		
		i++;
		fscanf(inf,"%d%s %c%d%d",&id[i],&name[i],&sex[i],&dept[i],&age[i]);
	}
	
	fclose(inf);
	return(i);
}
void printinfo(int id[],char name[][30],char sex[],int dept[],int age[],int amt)
{
	int i,total=0,total1=0 ;
	FILE *out,*out1;
	out = fopen("account.txt","w");
	out1 = fopen("market.txt","w");
	fprintf(out,"ID\t Name\t  Sex\tAge\n");
	fprintf(out1,"ID\t Name\t  Sex\tAge\n");
	for(i=0;i<amt;i++)
	{
		if(dept[i]==1)
		{
			if(sex[i]=='F')
			{
				fprintf(out,"%d\t%s\t Female \t %d\n",id[i],name[i],age[i]);
			}else if(sex[i]=='M')
				{
					fprintf(out,"%d\t%s\t Male \t %d\n",id[i],name[i],age[i]);
				}
				total++;
		}else if (dept[i]==2)
			{
					if(sex[i]=='F')
			{
				fprintf(out1,"%d\t%s\t Female \t %d\n",id[i],name[i],age[i]);
			}else if(sex[i]=='M')
				{
					fprintf(out1,"%d\t%s\t Male \t %d\n",id[i],name[i],age[i]);
				}
				total1++;
			}
	}
			fprintf(out,"Total = %d\n",total);
			fprintf(out1,"Total = %d\n",total1);
	fclose(out);
	fclose(out1);
}
int main()
{
	int id[10],dept[10],age[10];
	int amt;
	char name[10][30],sex[10];
	amt = getemployee(id,name,sex,dept,age);
	printinfo(id,name,sex,dept,age,amt);
	return 0 ;
}
