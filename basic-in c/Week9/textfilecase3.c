#include <stdio.h>
#include <ctype.h>
int main ()
{
	int amount,credits,point,totalcredits=0,totalgrade=0 ;
	char code[8],grade,line[50],line1[50];
	FILE *inf; //create variable file
	
	inf = fopen("case3.txt","r"); // variable = open  file
	fgets(line,50,inf);
	fgets(line1,50,inf);
	
	printf("%s%s",line,line1);
	
	fscanf(inf,"%s%d %c",&code,&credits,&grade); //start 
	while(!feof(inf)) //test
	{
	
		if(grade == 'A')
		{
			point = 4;
		}else if (grade == 'B')
			{
				point = 3;
			}else if (grade == 'C')
				{
					point = 2;
				}else if (grade == 'D')
					{
						point = 1;
					}else 
						{
							point = 0;
						}
		totalgrade = totalgrade + (point*credits);
		totalcredits = totalcredits + credits ;
		
		printf("Code = %s, credit = %d, grade = %c\n",code,credits,grade);
		fscanf(inf,"%s%d %c",&code,&credits,&grade); // action
	}
	
	printf("GPA = %0.2f, Total credits = %d",(float)totalgrade/totalcredits,totalcredits); //chang int to float
	fclose(inf);  // close file
	return 0 ;
}
