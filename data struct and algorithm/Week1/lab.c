#include <stdio.h>
void getdata(double data[][7],int *i)
{
	int j;
	FILE *inf;
	inf = fopen("lab.txt","r");
	fscanf(inf,"%lf",&data[*i][0]);
	while(!feof(inf))
	{
		for (j= 1; j<6 ;j++)
		{
			fscanf(inf,"%lf",&data[*i][j]);
		}
		(*i)++;
		fscanf(inf,"%lf",&data[*i][0]);
	}
	fclose(inf);
}
void display(double data[][7],int cnt)
{
	int i,j;
	for (i=0 ;i<cnt;i++)
	{
		for(j=0;j<6;j++)
		{
			printf("%0.0lf  ",data[i][j]);
		}
		printf("\n");
	}
}

void calculate(double data[][7],int cnt)
{
	int i,j;
	double total= 0;
	printf("List of Score Average\n");
	printf("=======================\n");
	for(i=0; i<cnt;i++)
	{
		
		for(j=1; j<6;j++)
		{
			total = total + data[i][j];
			
		}
			data[i][6] = total /5;
			printf("ID = %0.0lf AVG = %0.2lf\n",data[i][0],data[i][6]);
			total = 0 ;
			
			
	}
}
void avgnaltug(double data[][7],int cnt)
{
	int i,j=1 ;
	double total = 0;
	printf("AVG Score by colomn\n");
	printf("=======================\n");
	for(i=0;i<6;i++)
	{
		while(j!=i)
		{
			total = total + data[i+2][j];
			j++;
		}
	
		printf("AVG of Col %d = %.0lf\n",i,total);
		
	}
}
int main()
{
	double data[20][7];
	int cnt=0;
	getdata(data,&cnt);
	display(data,cnt);
	calculate(data,cnt);
	avgnaltug(data,cnt);
	return 0;
}
