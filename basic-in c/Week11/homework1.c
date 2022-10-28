#include <stdio.h>
int main ()
{
	int id[20],i=0,j;
	char code[20][6],chek[20];
	float grade[20];
	int total=0,total1=0;
	FILE *inf,*out,*out1;
	inf = fopen("Grade.txt","r");
	out = fopen("GE.txt","w");
	out1 = fopen("CS.txt","w");
	
	fscanf(inf,"%d%s%f %c",&id[i],&code[i],&grade[i],&chek[i]);
	while(!feof(inf))
	{
		i++;
		fscanf(inf,"%d%s%f %c",&id[i],&code[i],&grade[i],&chek[i]);
	}
	
	for(j=0;j<i;j++)
	{
		if(strcmp(code[j],"GE112"))
		{
			fprintf(out,"%d %s %0.2f %c\n",id[j],code[j],grade[j],chek[j]);
			total++;
		}else
			{
				fprintf(out1,"%d %s %0.2f %c\n",id[j],code[j],grade[j],chek[j]);
				total1++;
			}
			
	}	
	fprintf(out,"Total student = %d",total);
	fprintf(out1,"Total student = %d",total1);
	
	fclose(inf);
	fclose(out);
	fclose(out1);
	return 0 ;
}
