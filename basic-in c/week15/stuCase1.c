#include <stdio.h>
void getdata1(int id[],int *cnt)
{
	int i=0;
	FILE *inf;
	inf = fopen("id.txt","r");
	
	fscanf(inf,"%d",&id[i]);
	while(!feof(inf))
	{
		i++;
		fscanf(inf,"%d",&id[i]);
	}
	fclose(inf);
	*cnt = i;
} 
int getdata2(int id[])
{
	int i=0;
	FILE *inf;
	inf = fopen("id.txt","r");
	
	fscanf(inf,"%d",&id[i]);
	while(!feof(inf))
	{
		i++;
		fscanf(inf,"%d",&id[i]);
	}
	fclose(inf);
	return(i);
}
void printdata(int id[],int cnt)
{
	int i;
	for(i= 0; i<cnt ; i++)
	{
		printf("ID[%d] = %d\n",i,id[i]);		
	}
}
void bubble1(int id[],int cnt)
{
	int i,j,temp;
	for(i=cnt-1; i>0; i--)
	{
		for(j=0; j<i; j++)
		{
			if(id[j]>id[j+1])
			{
				temp = id[j];
				id[j] = id[j+1];
				id[j+1] = temp;
			}
		}
	}
}
int main()
{
	int id[20],cnt=0;
//	getdata1(id,&cnt);v
	cnt=getdata2(id);
	printdata(id,cnt);
	printf("------ Sorting by ascending --------\n");
	bubble1(id,cnt);
	printdata(id,cnt);
	
}
