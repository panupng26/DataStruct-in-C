#include <stdio.h>
int main ()
{
	int id[20],i=0,j;
	char code[20][6];
	float grade[20];
	
	FILE *inf,*out;
	inf = fopen("list.txt","r");
	out = fopen("Grade.txt","w");
	
	fscanf(inf,"%d%s%f",&id[i],&code[i],&grade[i]);
	while(!feof(inf))
	{
		i++;
		fscanf(inf,"%d%s%f",&id[i],&code[i],&grade[i]);
	}
	
	for(j=0;j<i;j++)
	{
		if(grade[j]>=80 && grade[j]<=100)
		{
			fprintf(out,"%d %s %0.2f A\n",id[j],code[j],grade[j]);
		}else if(grade[j]>=70 && grade[j]<=79)
			{
				fprintf(out,"%d %s %0.2f B\n",id[j],code[j],grade[j]);
			}else if(grade[j]>=60 && grade[j]<=69)
				{
					fprintf(out,"%d %s %0.2f C\n",id[j],code[j],grade[j]);
				}else if (grade[j]>=50 && grade[j]<=59)
					{
						fprintf(out,"%d %s %0.2f D\n",id[j],code[j],grade[j]);
					}else
						{
							fprintf(out,"%d %s %0.2f F\n",id[j],code[j],grade[j]);
						}
	}	
	
	fclose(inf);
	fclose(out);
	return 0 ;
}
