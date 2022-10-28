#include <stdio.h>
#include <ctype.h>
int main ()
{
	FILE *inf;

	
	int i,amount,credits;
	char code[8],grade;
	
	inf = fopen("case1.txt","r"); //open inf
	fscanf(inf,"%d",&amount); // read inf loop
	
	
	for(i=1;i<=amount;i++)
	{
		fscanf(inf,"%s%d %c",&code,&credits,&grade);
		printf("Code = %s, credit = %d, grade = %c\n",code,credits,grade);
	
	}
	fclose(inf);
	return 0 ;
}
