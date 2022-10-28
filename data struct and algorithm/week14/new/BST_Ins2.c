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
void printMale(ptr *root)
{
	if(root != NULL)
	{
	
		printMale(root->left);
		if(root->info.sex =='M')
		{
			printf("ID = %d, Sex= %c, Height=%d, Weight=%d\n",root->info.id,root->info.sex,root->info.hei,root->info.wei);
		}
		printMale(root->right);
	}
}
void printFemale(ptr *root)
{
	if(root != NULL)
	{
		printFemale(root->left);
		if(root->info.sex =='F')
		{
			printf("ID = %d, Sex= %c, Height=%d, Weight=%d\n",root->info.id,root->info.sex,root->info.hei,root->info.wei);
		}
		printFemale(root->right);
	}
}
void printMaleFemale(ptr *root,FILE *out1,FILE *out2)
{
	if(root != NULL)
	{
		printMaleFemale(root->left,out1,out2);
		if(root->info.sex =='F')
		{
			fprintf(out2,"ID = %d, Sex= %c, Height=%d, Weight=%d\n",root->info.id,root->info.sex,root->info.hei,root->info.wei);
		}else{
			fprintf(out1,"ID = %d, Sex= %c, Height=%d, Weight=%d\n",root->info.id,root->info.sex,root->info.hei,root->info.wei);
		}
		printMaleFemale(root->right,out1,out2);
	}
	
	
}
int main()
{
	ptr *root=NULL;
	FILE *out1,*out2;
	out1 = fopen("Male.txt","w");
	out2 = fopen("Female.txt","w");
//	root = createBST1(root);
	createBST2(&root);
	printf("----------------- Inorder ---------------\n");
	printInorder(root);
	printf("----------------- Men ---------------\n");
	printMale(root);
	printf("----------------- Women ---------------\n");
	printFemale(root);
	
	
	printMaleFemale(root,out1,out2);
	
	fclose(out2);
	fclose(out1);
}
