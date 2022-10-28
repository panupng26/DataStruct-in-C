#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node *left,*right;     
}ptr;

void createBST(ptr **root, int newdata)
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
       if (newnode->info < prev->info)
          prev->left = newnode;
       else
          if (newnode->info > prev->info)
             prev->right = newnode;
   }// end if BST have nodes
}//end of function InsertNode    

void printInorder(ptr *run)
{
   if(run != NULL)
   {
       printInorder(run->left);       //left (L)
       printf("Node = %d\n",run->info);  //Root(Rt)
       printInorder(run->right);     //Right (R)   
   }     
}

void printpreorder(ptr *run)
{
   if(run != NULL)
   {
       printf("Node = %d\n",run->info);  //Root(Rt)
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
   	   printf("Node = %d\n",run->info);  //Root(Rt)
   }     
}
int main()
{
    ptr *root=NULL;
    int i,newdata,nodeamt;
    printf("Enter a total nodes: ");
    scanf("%d",&nodeamt);
    for(i=0; i<nodeamt; i++)
    {
      printf("Enter a newdata to insert: ");
      scanf("%d",&newdata);       
      createBST(&root,newdata);
    }    
    printf("---------------------Inorder---------------------\n");
    printInorder(root);
    printf("---------------------preorder---------------------\n");
    printpreorder(root);
    printf("---------------------postorder---------------------\n");
    printpostorder(root);
    return(0);
}
