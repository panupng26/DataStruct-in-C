#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int no,score;
	char grade;
	struct node *next;
	
}ptr;
int main()
{
	ptr *root=NULL ,*newnode ,*run;
	FILE *inf;
	inf = fopen("list1.txt","r");
	
	while(!feof(inf))
	{
		newnode = (ptr*)malloc(sizeof(ptr));
		fscanf(inf,"%d%d",&newnode->no,&newnode->score);
		newnode->next = NULL;
		newnode->next = root;
		root = newnode;
		
	}
	fclose(inf);
	run = root;
	while(run != NULL)
	{
		printf("No = %d, Score = %d\n",run->no,run->score);
		run = run->next;
	}
	return 0 ;
}
