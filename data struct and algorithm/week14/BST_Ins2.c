#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
	int id;
	int hei;
	char sex;
	int wei;
}datatype;
typedef struct node{
	datatype info;
	struct node *left,*right;
}ptr;
ptr* insertnode1(ptr *root,datatype newdata)
{
	ptr *run,*prev,*newnode;
	newnode = (ptr*)malloc(sizeof(ptr));
	newnode->info = newdata;
	newnode->left = NULL;
	newnode->right = NULL;
	if(root == NULL)
	{
		root = newnode;
	}
	else
	{
		run = root;
		while(run != NULL)
		{
			prev = run;
			if(newnode->info.id == run->info.id)
			{
				printf("Duplicated data\n");
				run = NULL;
			}
			else if(newnode->info.id > run->info.id)
			   run = run->right;
			else
			   run = run->left;
		}
		if(newnode->info.id > prev->info.id)
		   prev->right = newnode;
		else
		   prev->left = newnode;
	}
	return(root);
}
void insertnode2(ptr **root,datatype newdata)
{
	ptr *run,*prev,*newnode;
	newnode = (ptr*)malloc(sizeof(ptr));
	newnode->info = newdata;
	newnode->left = NULL;
	newnode->right = NULL;
	if(*root == NULL)
	{
		*root = newnode;
	}
	else
	{
		run = *root;
		while(run != NULL)
		{
			prev = run;
			if(newnode->info.id == run->info.id)
			{
				printf("Duplicated data\n");
				run = NULL;
			}
			else if(newnode->info.id > run->info.id)
			   run = run->right;
			else
			   run = run->left;
		}
		if(newnode->info.id > prev->info.id)
		   prev->right = newnode;
		else
		   prev->left = newnode;
	}
}
ptr* createBST1(ptr *root)
{
	FILE *inf;
	datatype newdata;
	inf = fopen("inputdata.txt","r");
	while(!feof(inf))
	{
		fscanf(inf,"%d%d %c%d",&newdata.id,&newdata.hei,&newdata.sex,&newdata.wei);
	//	root = insertnode1(root,newdata);
		insertnode2(&root,newdata);
	}
	fclose(inf);
	return(root);
}
void createBST2(ptr **root)
{
	FILE *inf;
	datatype newdata;
	inf = fopen("inputdata.txt","r");
	while(!feof(inf))
	{
		fscanf(inf,"%d%d %c%d",&newdata.id,&newdata.hei,&newdata.sex,&newdata.wei);
	//	*root = insertnode1(*root,newdata);
		insertnode2(&*root,newdata);
	}
	fclose(inf);
}
void printInorder(ptr *root)
{
	if(root != NULL)
	{
		printInorder(root->left);
		printf("ID = %d, Sex= %c, Height=%d, Weight=%d\n",root->info.id,root->info.sex,root->info.hei,root->info.wei);
		printInorder(root->right);
	}
}
void printMale(ptr *root,FILE *out1)
{
	if(root != NULL)
	{
	
		printInorder(root->left);
			if(root->info.sex =='M')
		{
			printf("ID = %d, Sex= %c, Height=%d, Weight=%d\n",root->info.id,root->info.sex,root->info.hei,root->info.wei);
		}
		printInorder(root->right);
	}
}
void printFemale(ptr *root)
{

}
int main()
{
	ptr *root=NULL;
	
//	root = createBST1(root);
	createBST2(&root);
	printInorder(root);
	printMale(root);
	printFemale(root);
}
