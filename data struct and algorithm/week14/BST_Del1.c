#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int info;
    struct node *left,*right;     
}ptr;

void insertNode(ptr **root, int newdata)
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
          else if (newnode->info<run->info)
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
       printf("Node = %d\n",run->info);  //Root(Rt)
       printInorder(run->right);     //Right (R)   
   }     
}
ptr* createBST(ptr *root)
{
	FILE *inf;
	int newdata;
	inf = fopen("nodedata4.txt","r");
	while(!feof(inf))
	{
		fscanf(inf,"%d",&newdata);
		printf("%d\n",newdata);
		insertNode(&root,newdata);
	}
	fclose(inf);
	return(root);
}

void deleteNode(ptr **root,ptr *prev,ptr *run)
{
	ptr *temp;
	//delete leaf node
	if(run->left == NULL && run->right == NULL)
    {
    	if(run == *root)  //delete root node
    	   *root = NULL;
    	else              //
		   if(prev->left == run)  //leaf node at the left side
		      prev->left = NULL;
		   else
		      prev->right = NULL;   //leaf node at the right side
	}
	else if(run->left != NULL && run->right != NULL) //case of 2 childs node
	{
		prev = run;
		temp = run->left;
		while(temp->right != NULL)
		{
			prev = temp;
			temp = temp->right;
		}
		run->info = temp->info;  //copy value of rightmost
		if(prev == run)          //is not the rightmost
		   prev->left = temp->left;
		else
		   prev->right = temp->left;  //is has the rightmost
		free(temp);   
	}
	else if(run->left != NULL) //delete a child at left side
	{
		if(run == *root)
		   *root = run->left;
		else 
		{
			if(prev->left == run)        // delete node is at the left subtree 
		       prev->left = run->left;   //  a child node at the left side
		    else                         // delete node is at the right subtree
		       prev->right = run->left;   //  a child node at the left side
		}
	}
	else //delete a node at right side
	{
		if(run == *root)
		   *root = run->right;
		else 
	    {
	    	if(prev->left == run)           // delete node is at the left subtree 
	    	   prev->left = run->right;     //  a child node at the right side
	    	else                             // delete node is at the right subtree
	    	   prev->right = run->right;      //  a child node at the right side
		}
		free(run);	
	}
}

void deleteBST(ptr **root,int target)
{
	ptr *run,*prev;
	run = *root;
	while(run != NULL && target != run->info)
	{
		prev = run;
		if(target > run->info)
		   run = run->right;
		else
		   run = run->left;		
	}
	if(run == NULL)
	{
		printf("\nTarget not found!");
		//return 0;
	}
	else
	{
		printf("\nTarget = %d found!\n",target);
	    deleteNode(&*root,prev,run);	//call delnode to deleting the node from BST
    }
}
int main()
{
    ptr *root=NULL;
    int i,newdata,ans,nodeamt,odd=0,even=0,leaf=0;
    int target;
    root = createBST(root); 
    printf("----------------- Inorder ---------------\n");
    printInorder(root);  
	target=15;  
    //call delete function to delete node 15

    printf("----------------- Print after delete process ---------------\n");
    printInorder(root);
    target=9;  
    //call delete function to delete node 9

    printf("----------------- Print after delete process ---------------\n");
    printInorder(root);
    target=2;  
    //call delete function to delete node 2

    printf("----------------- Print after delete process ---------------\n");
    printInorder(root);
    return(0);
}
