#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int no,score;
	char grade;
	struct node *next;
}ptr;
ptr* createlist1(ptr *root)
{
	FILE *inf;
	ptr *newnode;
	inf = fopen("list11.txt","r");
	while(!feof(inf))
	{
		newnode = (ptr*)malloc(sizeof(ptr));
		fscanf(inf,"%d%d",&newnode->no,&newnode->score);
		newnode->next = root;
		root = newnode;
	}
	fclose(inf);
	return(root);
}
void grade(ptr *root)
{
	ptr *run;
	run = root;
	while(run != NULL)
	{
		if(run->score > 79)
		{run->grade = 'A';}
		else if(run->score > 69)
		{run->grade = 'B';}
		else if(run->score > 59)
		{run->grade = 'C';}
		else if(run->score > 49)
		{run->grade = 'D';}
		else
		{run->grade = 'F';}
		run = run->next;
	}
}
void printlist(ptr *root,char title[])
{
	ptr *run;
	printf("%s",title);
	run = root;
	while(run != NULL)
	{
		printf("| NO %d | Score %d | Grade %c |\n",run->no,run->score,run->grade);
		run = run->next;
	}
}
ptr* createlist2(ptr *root)
{
	FILE *inf;
	ptr *newnode,*last;
	inf = fopen("list11.txt","r");
	while(!feof(inf))
	{
		newnode = (ptr*)malloc(sizeof(ptr));
		fscanf(inf,"%d%d",&newnode->no,&newnode->score);
		newnode->next = NULL;
		if(root == NULL)
		{
			root = newnode;
			last = newnode;
		}
		else
		{
			last->next = newnode;
			last = newnode;
		}
	}
	fclose(inf);
	return(root);
}
void createlist11(ptr **root)
{
	FILE *inf;
	ptr *newnode;
	inf = fopen("list11.txt","r");
	while(!feof(inf))
	{
		newnode = (ptr*)malloc(sizeof(ptr));
		fscanf(inf,"%d%d",&newnode->no,&newnode->score);
		newnode->next = *root;
		*root = newnode;
	}
	fclose(inf);
}
void createlist22(ptr **root)
{
	FILE *inf;
	ptr *newnode,*last;
	inf = fopen("list11.txt","r");
	while(!feof(inf))
	{
		newnode = (ptr*)malloc(sizeof(ptr));
		fscanf(inf,"%d%d",&newnode->no,&newnode->score);
		newnode->next = NULL;
		if(*root == NULL)
		{
			*root = newnode;
			last = newnode;
		}
		else
		{
			last->next = newnode;
			last = newnode;
		}
	}
	fclose(inf);
}
ptr* createlist3(ptr *root)
{
	FILE *inf;
	ptr *newnode,*prev,*run;
	inf = fopen("list11.txt","r");
	while(!feof(inf))
	{
		newnode = (ptr*)malloc(sizeof(ptr));
		fscanf(inf,"%d%d",&newnode->no,&newnode->score);
		newnode->next = NULL;
		if(root == NULL)
		{
			root = newnode;
		}
		else
		{
			run = root;
			while(newnode->no > run->no && run->next != NULL)
			{
				prev = run;
				run = run->next;
			}
			if(newnode->no==run->no)//dupicate
			{
				printf("Duplicated NO.!!!\n");
			}
			else if(newnode->no > run->no)//like to end
			{
				run->next = newnode;
			}
			else if(run == root)//link to front
			{
				newnode->next = root;
				root = newnode;
			}
			else //link to middle 
			{
				prev->next = newnode;
				newnode->next = run;
			}
		}
	}
	fclose(inf);
	return(root);
}
void createlist33(ptr **root)
{
	FILE *inf;
	ptr *newnode,*prev,*run;
	inf = fopen("list11.txt","r");
	while(!feof(inf))
	{
		newnode = (ptr*)malloc(sizeof(ptr));
		fscanf(inf,"%d%d",&newnode->no,&newnode->score);
		newnode->next = NULL;
		if(*root == NULL)
		{
			*root = newnode;
		}
		else
		{
			run = *root;
			while(newnode->no > run->no && run->next != NULL)
			{
				prev = run;
				run = run->next;
			}
			if(newnode->no==run->no)//dupicate
			{
				printf("Duplicated NO.!!!\n");
			}
			else if(newnode->no > run->no)//like to end
			{
				run->next = newnode;
			}
			else if(run == *root)//link to front
			{
				newnode->next = *root;
				*root = newnode;
			}
			else //link to middle 
			{
				prev->next = newnode;
				newnode->next = run;
			}
		}
	}
	fclose(inf);
}
void delete1(ptr **root,int target)
{
	ptr *run,*prev;
	run = *root;
	while ((run->no != target) && (run->next != NULL))
	{
		prev = run;
		run = run->next;
	}
	if (run->no != target)
	printf("Record not found!\n");
	else
	{
		if (run == *root)
			*root = (*root)->next;
		else
			prev->next = run->next;
		free(run);
	}
}
void delete2(ptr **root,int target)
{
	ptr *run,*prev;
	run = *root;
	while ((target > run->no) && (run->next != NULL))
	{
		prev = run;
		run = run->next;
	}
	if (run->no != target)
	printf("Record not found!\n");
	else
	{
		if (run == *root)
			*root = (*root)->next;
		else
			prev->next = run->next;
		free(run);
	}
}
int main()
{
	ptr *root = NULL;
	createlist11(&root);
	//root = createlist1(root);
	grade(root);
	printlist(root,"========================== Creatlist(1)  ================================\n");
	root = NULL;
	createlist22(&root);
	//root = createlist2(root);
	grade(root);
	printlist(root,"========================== Creatlist(2)  ================================\n");
	root = NULL;
	createlist33(&root);
	//root = createlist3(root);
	grade(root);
	printlist(root,"========================== List after delete ================================\n");
	printlist(root,"========================== Creatlist(33) ================================\n");
	delete2(&root,1);
	delete2(&root,3);
	delete2(&root,8);
	printlist(root,"====================== Creatlist(33) after delete ============================\n");
	return 0;
}
