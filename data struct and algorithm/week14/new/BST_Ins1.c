#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
	int id;
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
	}else
		{
			run = root;
			while(run!=NULL)
			{
				prev = run;
				if(newnode->info.id < run->info.id)
				{
					run = run->left;
				}else
					{
						run = run->right;
					}
			}//end while
			if(newnode->info.id < prev->info.id)
			{
				prev->left = newnode;
			}else if(newnode->info.id > prev->info.id)
				{
					prev->right = newnode;
				}
		}
	return root;
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
	}else
		{
			run = *root;
			while(run!=NULL)
			{
				prev = run;
				if(newnode->info.id < run->info.id)
				{
					run = run->left;
				}else
					{
						run = run->right;
					}
			}//end while
			if(newnode->info.id < prev->info.id)
			{
				prev->left = newnode;
			}else if(newnode->info.id > prev->info.id)
				{
					prev->right = newnode;
				}
		}
}
ptr* createBST1(ptr *root)
{
	FILE *inf;
	datatype newdata;
	inf = fopen("nodedata4.txt","r");
	while(!feof(inf))
	{
		fscanf(inf,"%d",&newdata);
		insertnode1(root,newdata);
		insertnode2(&root,newdata);
	}
	fclose(inf);
	return(root);
}
void createBST2(ptr **root)
{
	FILE *inf;
	datatype newdata;
	inf = fopen("nodedata4.txt","r");
	while(!feof(inf))
	{
		fscanf(inf,"%d",&newdata);
		insertnode1(*root,newdata);
		insertnode2(&*root,newdata);
	}
	fclose(inf);
}
void printInorder(ptr *root)
{
	if(root != NULL)
	{
		printInorder(root->left);
		printf("Node = %d\n",root->info.id);
		printInorder(root->right);
	}
}
void countOddEven(ptr *root,int *odd,int *even)
{
	ptr *run;
	run = root;
	if(run != NULL)
	{
		if(run->info.id % 2 == 0)
		{
			++(*even);
		}else {
			++(*odd);
		}
		countOddEven(run->left,&*odd,&*even);
		countOddEven(run->right,&*odd,&*even);
	}
}
void countleafnode(ptr *root,int *leaf)
{
	ptr *run ;
	run = root ;
	if(run !=NULL)
	{
		
	  if(run->left == NULL && run->right == NULL)
		{
			++(*leaf);
		}
		
		countleafnode(run->left,&*leaf);
		countleafnode(run->right,&*leaf);
	}
		
}

void counttwonode(ptr *root,int *leaf)
{
	ptr *run ;
	run = root ;
	if(run !=NULL)
	{
		
	  if(run->left != NULL && run->right != NULL)
		{
			++(*leaf);
		}
		
		counttwonode(run->left,&*leaf);
		counttwonode(run->right,&*leaf);
	}
		
}
int main()
{
	ptr *root=NULL;
	int odd=0,even=0,leaf=0,two = 0 ;
//	root = createBST1(root);
	createBST2(&root);	
	printInorder(root);
	printf("-----------------  Odd/Even ---------------\n");
    countOddEven(root,&odd,&even);
    printf("Odd = %d, Even = %d\n",odd,even);
    printf("-----------------  leaf node ---------------\n");
    countleafnode(root,&leaf);
    printf(" Leaf node = %d\n",leaf);
    printf("-----------------  two childer ---------------\n");
    counttwonode(root,&two);
    printf(" two node = %d\n",two);
	return 0;
}
