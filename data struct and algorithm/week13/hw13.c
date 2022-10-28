#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct {
	int id,height;
	char sex;
	int weight;
}datatype;
typedef struct node{
	datatype data;
	struct node *left,*right;
}ptr;

void insertNode(ptr **root,datatype newdata)
{
	ptr *run,*prev,*newnode;
	newnode = (ptr*)malloc(sizeof(ptr));
	newnode->data = newdata;
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
				 if(newnode->data.id < run->data.id)
					{
						run = run->left;
					}else 
						{
							run = run->right;
						}
			} //end while loop
			if(newnode->data.id < prev->data.id)
			{
				prev->left = newnode;
			}else
				if(newnode->data.id > prev->data.id)
				{
					prev->right = newnode;
				}
				
		}
}

void printInorder(ptr *run)
{
   if(run != NULL)
   {
       printInorder(run->left);       //left (L)
       printf("ID= %d | Height = %d | Sex = %c | Weight = %d\n",run->data.id,run->data.height,run->data.sex,run->data.weight);  //Root(Rt)
       printInorder(run->right);     //Right (R)   
   }     
}

ptr* createBST(ptr *root)
{
	int numfree;
	datatype newdata;
	
	FILE *inf;
	inf = fopen("inputdata.txt","r");
	
	fscanf(inf,"%d",&numfree);
	while(!feof(inf))
	{
		fscanf(inf,"%d%d %c%d",&newdata.id,&newdata.height,&newdata.sex,&newdata.weight);
		insertNode(&root,newdata);
	}
	
	
	fclose(inf);
	return(root);
}
int countMale(ptr *run)
{
	int total = 0 ;
	if(run!=NULL)
	{
	   
	   if(run->data.sex == 'M')
       {
    		++total;
	   }
	   total +=countMale(run->left);       //left (L)
       total +=countMale(run->right); 	 //Right (R)  
	}
	return total;
}
int main()
{
	ptr *root=NULL;
	int total;
	root = createBST(root); 
    printf("---------------------Inorder---------------------\n");
    printInorder(root);
    total = countMale(root);
    
    printf("Total Male = %d",total);
  
	return 0;
}
