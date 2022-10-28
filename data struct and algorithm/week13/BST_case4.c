#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char info[10];
    struct node *left,*right;     
}ptr;

void insertNode(ptr **root,char newdata[])
{ 
   ptr *run,*prev,*newnode;
   newnode = (ptr*) malloc (sizeof(ptr));
   strcpy(newnode->info , newdata);
   newnode->left = NULL;
   newnode->right = NULL;
   if (*root == NULL) //the first node
      *root = newnode;
   else
   { //BST have nodes
      run = *root;
      while (run != NULL)
      {
          prev = run;
          if (strcmp(newnode->info , run->info)==0)
          {
               printf("Duplicated Record!\n");  
               run = NULL;
          }
          else if (strcmp(newnode->info ,run->info)<0)
                  run = run->left;
               else
                  run = run->right;
       }//end of while-Loop      
       if (strcmp(newnode->info,prev->info)<0)
          prev->left = newnode;
       else
          if (strcmp(newnode->info,prev->info)>0)
             prev->right = newnode;
   }// end if BST have nodes
}//end of function InsertNode    

printInorder(ptr *run)
{
   if(run != NULL)
   {
       printInorder(run->left);       //left (L)
       printf("Node = %s\n",run->info);  //Root(Rt)
       printInorder(run->right);     //Right (R)   
   }     
}

void printpreorder(ptr *run)
{
   if(run != NULL)
   {
       printf("Node = %s\n",run->info);  //Root(Rt)
       printpreorder(run->left);       //left (L)
       printpreorder(run->right);     //Right (R)   
   }     
}

void printpostorder(ptr *run)
{
   if(run != NULL)
   {
       
       printpostorder(run->left);       //left (L)
       printpostorder(run->right);     //Right (R)   
   	   printf("Node = %s\n",run->info);  //Root(Rt)
   }     
}

ptr* createBST(ptr *root)
{
	char newdata[10];
	FILE *inf;
	inf = fopen("nodedata3.txt","r");
	while(!feof(inf))
	{
		fscanf(inf,"%s",&newdata);
		insertNode(&root,newdata);
	}
	fclose(inf);
	return(root);
}

int main()
{
    ptr *root=NULL;
    int i,newdata,ans,nodeamt;
    root = createBST(root); 
    printf("---------------------Inorder---------------------\n");
    printInorder(root);
    printf("---------------------preorder---------------------\n");
    printpreorder(root);
    printf("---------------------postorder---------------------\n");
    printpostorder(root);
    return(0);
}
