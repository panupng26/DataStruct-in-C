#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char info;
    struct node *left,*right;     
}ptr;

void insertNode(ptr **root,char newdata)
{ 
   ptr *run,*prev,*newnode;
   newnode = (ptr*) malloc (sizeof(ptr));
   newnode->info = newdata;
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
          if (newnode->info == run->info)
          {
               printf("Duplicated Record!\n");  
               run = NULL;
          }
          else if (newnode->info < run->info)
                  run = run->left;
               else
                  run = run->right;
       }//end of while-Loop      
       if (newnode->info<prev->info)
          prev->left = newnode;
       else
          if (newnode->info>prev->info)
             prev->right = newnode;
   }// end if BST have nodes
}//end of function InsertNode    

printInorder(ptr *run)
{
   if(run != NULL)
   {
       printInorder(run->left);       //left (L)
       printf("Node = %c\n",run->info);  //Root(Rt)
       printInorder(run->right);     //Right (R)   
   }     
}

void printpreorder(ptr *run)
{
   if(run != NULL)
   {
       printf("Node = %c\n",run->info);  //Root(Rt)
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
   	   printf("Node = %c\n",run->info);  //Root(Rt)
   }     
}

ptr* createBST(ptr *root)
{
	char newdata;
	FILE *inf;
	inf = fopen("nodedata2.txt","r");
	while(!feof(inf))
	{
		fscanf(inf,"%c ",&newdata);
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
