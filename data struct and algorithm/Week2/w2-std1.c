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

void display1(struct sport sp1)
{
	printf("=============== display ============\n");
	printf("%s %s %s %s %s ",sp1.sporttype,sp1.fname,sp1.lname,sp1.id,sp1.tel);
	if(sp1.relsult == 1)
	{
		printf("Pass\n");
	}else 
		{
			printf("Fail\n");
		}
}	
void display2(sport2 sp2)
{
	printf("=============== display ============\n");
	printf("%s %s %s %s %s ",sp2.sporttype,sp2.fname,sp2.lname,sp2.id,sp2.tel);
	if(sp2.relsult == 1)
	{
		printf("Pass\n");
	}else 
		{
			printf("Fail\n");
		}
}
int main()
{
	struct sport sp1;
	sport2 sp2;
	strcpy(sp1.sporttype,"Football");
	strcpy(sp1.fname,"suplarak");
	strcpy(sp1.lname ,"praisri");
	strcpy(sp1.id ,"30421038-6");
	strcpy(sp1.tel, "087-204-2872");
	sp1.relsult = 1;
	strcpy(sp2.sporttype , "Football");
	strcpy(sp2.fname , "sittisak");
	strcpy(sp2.lname , "Mannasoom");
	strcpy(sp2.id , "304031159-0");
	strcpy(sp2.tel , "086-020-6148");
	sp2.relsult = 1;
	display1(sp1);
	display2(sp2);

	
	return 0;
}
