#include <stdio.h>
#include <string.h>
#include <ctype.h>

void getdata(float *base,float *height)
{
	printf("Enter base : ");
	scanf("%f",&base);
	printf("Enter height : ");
	scanf("%f",&height);
}
void getfile(int ArrayNum[])
{
	FILE *inf;
	inf = fopen("arraynum.txt","r");
	int i=0;
	fscanf(inf,"%d",&ArrayNum[i]);
	while(!feof(inf))
	{
		i++;
		fscanf(inf,"%d",&ArrayNum[i]);
	}
	fclose(inf);
}
int FindMaxNumber(int ArrayNum[])
{
	int total=0;
	int i ;
	for(i=0;i<10;i++)
	{
		if(ArrayNum[i] > total)
		{
			total = ArrayNum[i];
		}
	}
	printf("%d ",total);
	return (total);
}
float find_area_triangle(float base, float height)
{
	float triangle;
	triangle = (1/2)* base * height ; 
	return (triangle);
}

int FindtheLetterT(char word[],int amt)
{
	int totalt,i;
	for(i=0;i<amt;i++)
	{
		if(toupper(word[i])=='T')
		{
			totalt++;
		}
	}
	return (totalt);
}
int main()
{
	int ArrayNum[10],amt=0,total;
	float base,height,tri;
	char word[15]="competitions";
	int amtt=15,totalt;
	getdata(&base,&height);
	tri = find_area_triangle(base,height);
	
	getfile(ArrayNum);
	total = FindMaxNumber(ArrayNum);
	totalt = FindtheLetterT(word,amtt);
	
	return 0;
}
