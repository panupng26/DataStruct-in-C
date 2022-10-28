#include <stdio.h>
#include <string.h>
int getdata(char id[][15])
{
	int i=0;
	FILE *inf;
	inf = fopen("ids
	.txt","r");
	
	fscanf(inf,"%s",&id[i]);
	while(!feof(inf))
	{
		i++;
		fscanf(inf,"%s",&id[i]);
	}
	
	fclose(inf);
	return (i);
}
void printdata(char id[][15],int cnt)
{
	int i;
	for(i=0;i<cnt;i++)
	{
		printf("ID[%d] = %s\n",i,id[i]);	
	}
		
}
void bubble1(char id[][15],int cnt)
{
	int i,j;
	char temp[15];
	for(i=cnt-1; i>0; i--)
	{
		for(j=0; j<i; j++)
		{
			if(strcmp(id[j],id[j+1]) > 0)
			{
				strcpy(temp,id[j]);
				strcpy(id[j] ,id[j+1]);
				strcpy(id[j+1] ,temp);
			}
		}
	}
}
int main()
{
	int cnt=0;
	char id[20][15];
	cnt = getdata(id);
	printdata(id,cnt);
	printf("------ Sorting by ascending --------\n");
	bubble1(id,cnt);
	printdata(id,cnt);
}
