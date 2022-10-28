#include <stdio.h>
#include <ctype.h>
int main ()
{
	int amount,credits;
	char code[8],grade;
	FILE *inf; //create variable file
	
	inf = fopen("case2.txt","r"); // variable = open  file
	
	fscanf(inf,"%s%d %c",&code,&credits,&grade); //start 
	while(!feof(inf)) //test
	{
	
		printf("%s %d %c\n",code,credits,grade);
		
		fscanf(inf,"%s%d %c",&code,&credits,&grade); // action
	}
	fclose(inf);  // close file
	return 0 ;
}
