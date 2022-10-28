#include <stdio.h>
#include <string.h>

typedef struct{
	char id[8];
	char fname[15],lname[20];
	char address[35];
	char province[20];
	int zip;
	float income;
}profile;

int getdata(profile emp[])
{
	int i=0;
	FILE *inf;
	inf = fopen("data1.txt","r");
	
	fscanf(inf,"%s",&emp[i].id);
	while(!feof(inf))
	{
		fscanf(inf,"%s%s",&emp[i].fname,&emp[i].lname);
		fgets(emp[i].address,34,inf);
		fscanf(inf,"%s%d%f",&emp[i].province,&emp[i].zip,&emp[i].income);
		i++;
		fscanf(inf,"%s",&emp[i].id);
	}
	fclose(inf);
	return (i);
}
void display(profile emp[],int cnt)
{
	int i;
	for(i=0;i<cnt;i++)
	{
		printf("%-5s %-10s %-15s %-15s  %-5s %-3d %-3.2f\n",emp[i].id,emp[i].fname,emp[i].lname,emp[i].address,emp[i].province,emp[i].zip,emp[i].income);
	}
}
void displayprov(profile emp[],int cnt)
{
	int i ;
	printf("============ Display by Province ==============\n");
	for(i=0;i<cnt;i++)
	{
		if(strcmp(emp[i].province,"Lopburi")==0)
		{
			printf("%-5s %-10s %-15s %-15s  %-5s %-3d %-3.2f\n",emp[i].id,emp[i].fname,emp[i].lname,emp[i].address,emp[i].province,emp[i].zip,emp[i].income);
		}
	}
}
int main()
{
	profile emp[15];
	 
	int cnt = 0;
	cnt = getdata(emp);
	display(emp,cnt);
	displayprov(emp,cnt);
	return 0 ;
}
