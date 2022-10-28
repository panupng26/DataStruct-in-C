#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node{
	char id[5],fname[20],lname[20];
	float sale,com,income;
	struct node *next;
}ptr; 


ptr* createlist2(ptr *root)
{
	FILE *inf;
	inf = fopen("employee.txt","r");
	ptr *newnode ,*last;
	
	while(!feof(inf))
	{
		newnode = (ptr*)malloc(sizeof(ptr));
		fscanf(inf,"%s%s%s%f",&newnode->id,&newnode->fname,&newnode->lname,&newnode->sale);
		newnode->next = NULL;
		if(root==NULL)
		{
			root = newnode;
			last = newnode;
		}else
			{
				last->next = newnode ; 
				last = newnode;
			}
	}

	fclose(inf);
	return (root);
}

void comission(ptr *root)
{
	ptr *run ;
	float com1 ;
	run = root;
	while(run !=NULL)
	{
		if(run->sale>=15000)
		{
			com1 = (run->sale * 12) / 100 ; 
			run->com = com1;
		}else if(run->sale>=10000 && run->sale <=15000)
			{
				com1 = (run->sale * 8) / 100;
				run->com = com1;
			}else 
				{
					com1 = (run->sale * 5) / 100 ;
					run->com = com1;
				}
		run = run->next;
	}
}
void printlist(ptr *root)
{
	FILE *out;
	out = fopen("income.txt","w");
	
	ptr *run ,*run1 ;
	float salaryP = 13500,salaryE=9500;
	char nameE[30],nincomeE[30];
	float maxcom=0,maxincome=0;
	fprintf(out," | ID | Name | Salary  | Com  | Income \n");
	fprintf(out,"=======================================\n");
	run = root;
	while(run !=NULL)
	{
		if(run->id[0]=='P')
		{
			run->income = salaryP + run->com;
			fprintf(out," | %s | %s %s | %0.2f | %0.2f | %0.2f\n",run->id,run->fname,run->lname,salaryP,run->com,run->income);
			if(run->com>maxcom)
			{
				maxcom = run->com ; 
				strcpy(nameE,run->fname);
			}
			if(run->income>maxincome)
			{
				maxincome = run->income ; 
				strcpy(nincomeE,run->fname);	
			}
		}
		run = run->next;
	}
	
	run1 = root;
	while(run1 !=NULL)
	{
		if(run1->id[0]=='E')
		{
			run1->income = salaryE + run1->com;
			fprintf(out," | %s | %s %s | %0.2f | %0.2f | %0.2f\n",run1->id,run1->fname,run1->lname,salaryE,run1->com,run1->income);
			
			if(run1->com>maxcom)
			{
				maxcom = run1->com ; 
				strcpy(nameE,run1->fname);
			}
			if(run1->income>maxincome)
			{
				maxincome = run1->income ; 
				strcpy(nincomeE,run1->fname);
			}
		}
		run1 = run1->next;
	}
	
	fprintf(out,"=============================================\n");
	fprintf(out,"Maximum commission = %0.0f by %s\n",maxcom,nameE);
	fprintf(out,"Maximum income = %0.0f by %s\n",maxincome,nincomeE);
	fclose(out);
}
int main()
{
	ptr *root=NULL;
	root = createlist2(root);
	comission(root);
	printlist(root);
	return 0 ;
}
