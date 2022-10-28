#include <stdio.h>
#include <string.h>


int getdata(char name[][50],int compet[][8])
{
	int i = 0,j;
	FILE *inf,*inf1;
	inf = fopen("name.txt","r");
	inf1 = fopen("competition.txt","r");
	
	fgets(name[i],50,inf);
	while(!feof(inf))
	{
		for(j=0;j<7;j++)
		{
			fscanf(inf1,"%d",&compet[i][j]);
		}
		i++;
		fgets(name[i],50,inf);
	}
	fclose(inf);
	fclose(inf1);
	return (i);
}

void display(char name[][50],int compet[][8],int cnt)
{

	int i,j;
	for(i=0; i<cnt; i++)
	{
		printf("%s ",name[i]);
		for(j=0;j<8;j++)
		{
			printf("%-3d",compet[i][j]);
		}
	
		printf("\n");
	}
}
void displaytxt1(char name[][50],int compet[][8],int cnt)
{
	FILE *out;
	out = fopen("report1.txt","w");
	int i,j;
	for(i=0;i<cnt;i++)
	{
		fprintf(out,"%d.%s %d %d %d\n",i+1,name[i],compet[i][1],compet[i][2],compet[i][3]);
	}
	fclose(out);
}

void displaytxt2(char name[][50],int compet[][8],int cnt)
{
	FILE *out;
	out = fopen("report2.txt","w");
	int i,j;
	for(i=0;i<cnt;i++)
	{
		fprintf(out,"%d.%s",i+1,name[i]);
		fprintf(out,"%d",compet[i][7]);
		
	}
	fclose(out);
}
void totalcompet(int compet[][8],int cnt)
{
	int i;
	for(i=0;i<cnt;i++)
	{
		compet[i][7]=compet[i][1]*3+compet[i][2];
	}
}

int main()
{
	int compet[20][8],cnt=0;
	char name[20][50];
	cnt = getdata(name,compet);
	totalcompet(compet,cnt);
	display(name,compet,cnt);
	displaytxt1(name,compet,cnt);
	displaytxt2(name,compet,cnt);
	return 0 ;
}

