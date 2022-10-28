#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int no,score;
	char grade;
	struct node *next;
	
}ptr;

ptr* createlist(ptr *root)
{
	FILE *inf;
	inf = fopen("list1.txt","r");
	
	ptr *newnode;
	
	while(!feof(inf))
	{
		newnode = (ptr*)malloc(sizeof(ptr));
		fscanf(inf,"%d%d",&newnode->no,&newnode->score);
		newnode->next = NULL;
		newnode->next = root;
		root = newnode;
	}
	
	
	fclose(inf);
	return(root);
}
ptr* createlist2(ptr *root)
{
	FILE *inf;
	inf = fopen("list1.txt","r");
	
	ptr *newnode,*last;
	
	while(!feof(inf))
	{
		newnode = (ptr*)malloc(sizeof(ptr));
		fscanf(inf,"%d%d",&newnode->no,&newnode->score);
		newnode->next = NULL;
		if(root == NULL)
		{
			root = newnode;
			last = newnode;
		}else 
		{
			last->next = newnode;
			last = newnode;
		}
	}
	
	
	fclose(inf);
	return(root);
}
void printlist(ptr *root)
{
	ptr *run;
	
	run = root;
	while(run != NULL)
	{
		printf("No = %d, Score = %d Grade = %c\n",run->no,run->score,run->grade);
		run = run->next;

	}
}

void grade(ptr *root)
{
	ptr *run;
	run = root;
	while(run != NULL)
	{
		if(run->score > 79)
		{
			run->grade = 'A';
		}else if (run->score > 69)
			{
				run->grade = 'B';
			}else if (run->score > 59)
				{
					run->grade = 'C';
				}else if (run->score > 49)
					{
						run->grade = 'D';
					}else
						{
							run->grade = 'F';
						}
						run = run->next;
	}
}
int main()
{
	ptr *root=NULL;
	root = createlist2(root);
	grade(root);
	printlist(root);
	return 0 ;
}
