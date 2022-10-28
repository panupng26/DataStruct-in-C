#include <stdio.h>
#include <string.h>
#include <ctype.h>
struct sport{
	char sporttype[25];
	char fname[50],lname[30];
	char id[12],tel[13];
	int relsult;
};
typedef struct{
	char sporttype[25];
	char fname[50],lname[30];
	char id[12],tel[13];
	int relsult;
}sport2;

void display1(struct sport sp1[])
{
	printf("=============== display ============\n");
	int i;
	for(i=0;i<2;i++)
	{
			printf("%s %s %s %s %s ",sp1[i].sporttype,sp1[i].fname,sp1[i].lname,sp1[i].id,sp1[i].tel);
	if(sp1[i].relsult == 1)
	{
		printf("Pass\n");
	}else 
		{
			printf("Fail\n");
		}
	}
	

}	
void display2(sport2 sp2[])
{
	printf("=============== display ============\n");
	int i;
	for(i=0;i<2;i++)
	{
	printf("%s %s %s %s %s ",sp2[i].sporttype,sp2[i].fname,sp2[i].lname,sp2[i].id,sp2[i].tel);
	if(sp2[i].relsult == 1)
	{
		printf("Pass\n");
	}else 
		{
			printf("Fail\n");
		}
	}
}
int main()
{
	struct sport sp1[10];
	sport2 sp2[10];
	strcpy(sp1[0].sporttype,"Football");
	strcpy(sp1[0].fname,"suplarak");
	strcpy(sp1[0].lname ,"praisri");
	strcpy(sp1[0].id ,"30421038-6");
	strcpy(sp1[0].tel, "087-204-2872");
	sp1[0].relsult = 1;
	strcpy(sp1[1].sporttype,"football");
	strcpy(sp1[1].fname,"panupong");
	strcpy(sp1[1].lname ,"kongsanae");
	strcpy(sp1[1].id ,"30421038-8");
	strcpy(sp1[1].tel, "093-786-7607");
	sp1[1].relsult = 1;
	
	strcpy(sp2[0].sporttype , "Football");
	strcpy(sp2[0].fname , "sittisak");
	strcpy(sp2[0].lname , "Mannasoom");
	strcpy(sp2[0].id , "304031159-0");
	strcpy(sp2[0].tel , "086-020-6148");
	sp2[0].relsult = 1;
	strcpy(sp2[1].sporttype,"football");
	strcpy(sp2[1].fname,"panupong");
	strcpy(sp2[1].lname ,"kongsanae");
	strcpy(sp2[1].id ,"30421038-8");
	strcpy(sp2[1].tel, "093-786-7607");
	sp2[1].relsult = 1;
	display1(sp1);
	display2(sp2);

	
	return 0;
}
