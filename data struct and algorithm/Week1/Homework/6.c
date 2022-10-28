#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main ()
{
	int id[10],cclass[10];
	char name[10][30];
	float grade[10];
	int i=0;
	FILE *inf;
	inf = fopen("student.txt","r");
	
	printf("List of students (GPA 2.00 - 3.24)\n");
	printf("ID\tName\tGPA\tYear\n");

	fscanf(inf,"%d%s%d%f",&id[i],&name[i],&cclass[i],&grade[i]);
	while(!feof(inf))
	{
		printf("%d %s %d %0.2f\n",id[i],name[i],cclass[i],grade[i]);
		i++;
		fscanf(inf,"%d%s%d%f",&id[i],&name[i],&cclass[i],&grade[i]);
	}
	printf("Total = %d",i);


	
	
	
	
	fclose(inf);
	return 0;
}
