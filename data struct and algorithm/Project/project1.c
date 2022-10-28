#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int id;
	char idperson[15];
	char name[35];
	char lastname[35];
	char tel[11];
	float grade;
}datatype;

typedef struct node{
	datatype info;
	struct node *left,*right;
}ptr;

typedef struct {
	int id;
	char name[30];
	int price;
	int item;
	int total;
}datastore;

typedef struct nod{
	datastore info;
	struct nod *left,*right;
}ptrstore;

void printInorderproduct(ptrstore *root,int *totalpriceproduct)
{
	if(root != NULL)
	{
		printInorderproduct(root->left,&*totalpriceproduct);
		printf("ID = %-2d , Nameproduct = %-10s , price = %d , Item = %d , Totalprice = %d\n",root->info.id,root->info.name,root->info.price,root->info.item,root->info.total);
		*totalpriceproduct = *totalpriceproduct + root->info.total;
		printInorderproduct(root->right,&*totalpriceproduct);
	}
}
void paymoney(int pay_money,int price)
{
	int bank1000,bank500,bank100,bank50,bank20,coin10,coin5,coin1,amount;
	amount = pay_money-price;
	if(pay_money < price)
	{
		printf("Try again\n");
	}else{
	printf("This is money %d Baht\n",amount);
	bank1000 = amount/1000;
	printf("Bank 1000 %d bank\n",bank1000);
	bank500 = (amount%1000)/500;
	printf("Bank 500 %d bank\n",bank500);
	bank100 = ((amount%1000)%500)/100;
	printf("Bank 100 %d bank\n",bank100);
	bank50 = (((amount%1000)%500)%100)/50;
	printf("Bank 50  %d bank\n",bank50);
	bank20 = ((((amount%1000)%500)%100)%50)/20;
	printf("Bank 20  %d bank\n",bank20);
	coin10 = (((((amount%1000)%500)%100)%50)%20)/10;
	printf("coin 10  %d coin\n",coin10);
	coin5 = ((((((amount%1000)%500)%100)%50)%20)%10)/5;
	printf("coin 5  %d coin\n",coin5);
	coin1 = (((((((amount%1000)%500)%100)%50)%20)%10)%5)/1;
	printf("coin 1  %d coin\n",coin1);
	}
	
}
void printInorderstore(ptrstore *root)
{
	if(root != NULL)
	{
		printInorderstore(root->left);
		printf("ID = %-2d , Nameproduct = %-10s , price = %d\n",root->info.id,root->info.name,root->info.price);
		printInorderstore(root->right);
	}
}

void printInorder(ptr *root)
{
	if(root != NULL)
	{
		printInorder(root->left);
		printf("ID = %d , ID person = %s ,Name-lastname = %s %s ,Tel = %s,Grade = %0.2f\n",root->info.id,root->info.idperson,root->info.name,root->info.lastname,root->info.tel,root->info.grade);
		printInorder(root->right);
	}
}
void deleteNodestore(ptrstore **root,ptrstore *prev,ptrstore *run)
{
	ptrstore *temp;
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

void deleteBSTstore(ptrstore **root,int target)
{
	ptrstore *run,*prev;
	run = *root;
	while(run != NULL && target != run->info.id)
	{
		prev = run;
		if(target > run->info.id)
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
	    deleteNodestore(&*root,prev,run);	//call delnode to deleting the node from BST
    }
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
	while(run != NULL && target != run->info.id)
	{
		prev = run;
		if(target > run->info.id)
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

int Menushow()
{
	int menu;
	printf("================ Menu store ================\n");
	printf("\t1.Registerprogram\n");
	printf("\t2.Employee\n");
	printf("\t3.product\n");
	printf("\t4.insertproduct\n");
	printf("\t5.Remove product\n");
	printf("\t6.exit\n");
	printf("============================================\n");
	printf("\tselect : ");
	scanf("%d",&menu);
	system("cls");
	
	return (menu);
}

void insertnode(ptr **root,datatype newdata)
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

void insertnodestore(ptrstore **root,datastore newdata)
{
	ptrstore *run,*prev,*newnode;
	newnode = (ptrstore*)malloc(sizeof(ptrstore));
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
void createBST2(ptr **root)
{
	char check = 'N';
	FILE *inf;
	datatype newdata;
	inf = fopen("employee.txt","a+");
	
	while(toupper(check) != 'Y')
	{
	printf("================== Register ==================\n");
	printf("ID register : ");
	scanf("%d",&newdata.id);
	
	printf("ID person : ");
	scanf("%s",&newdata.idperson);
	
	printf("Name : ");
	scanf("%s",&newdata.name);
	
	printf("Lastname : ");
	scanf("%s",&newdata.lastname);
	
	printf("Tel : ");
	scanf("%s",&newdata.tel);
	
	printf("Grade : ");
	scanf("%f",&newdata.grade);
	
	printf("You are sure (Y/N) : ");
	scanf(" %c",&check);	
	system("cls");
	}
	
	fprintf(inf,"\n%d %s %s %s %s %0.2f",newdata.id,newdata.idperson,newdata.name,newdata.lastname,newdata.tel,newdata.grade);
	
	fclose(inf); 
}

void buystore(ptrstore *root,ptrstore **choose,int target,int item)
{
	datastore newdata;
	if(root != NULL)
	{
		buystore(root->left,&*choose,target,item);
		if(target == root->info.id)
		{
			newdata.id = root->info.id;
			strcpy(newdata.name,root->info.name);
			newdata.price = root->info.price ;
			newdata.item = item;
			newdata.total = root->info.price * item ;
			insertnodestore(&*choose,newdata);
		}	
		buystore(root->right,&*choose,target,item);
	}	


	
	
}
ptrstore* createBSTstore(ptrstore **root)
{
	FILE *inf;
	datastore newdata;
	inf = fopen("product.txt","r");
	while(!feof(inf))
	{
		fscanf(inf,"%d%s%d",&newdata.id,&newdata.name,&newdata.price);
		insertnodestore(&*root,newdata);
	}
	fclose(inf);
}

ptr* createBST1(ptr *root)
{
	FILE *inf;
	datatype newdata;
	inf = fopen("employee.txt","r");
	while(!feof(inf))
	{
		fscanf(inf,"%d%s%s%s%s%f",&newdata.id,&newdata.idperson,&newdata.name,&newdata.lastname,&newdata.tel,&newdata.grade);
		insertnode(&root,newdata);
	}
	fclose(inf);
	return(root);
}

void creatforstore(ptrstore **root,ptrstore *rootstore)
{
	char check = 'N';
	FILE *inf;
	datastore newdata;
	inf = fopen("product.txt","a+");
	
	while(toupper(check) != 'Y')
	{
	printf("================ Product ================\n");
	printInorderstore(rootstore);
	printf("=========================================\n");
	printf("================== Insert ==================\n");
	printf("ID product : ");
	scanf("%d",&newdata.id);
	
	printf("Name product : ");
	scanf("%s",&newdata.name);
	
	printf("Price : ");
	scanf("%d",&newdata.price);
	
	printf("You are sure (Y/N) : ");
	scanf(" %c",&check);	
	system("cls");
	}
	
	fprintf(inf,"\n%d %s %d",newdata.id,newdata.name,newdata.price);
	
	fclose(inf); 
}
void checkmenu(ptr *root,ptrstore *rootstore,ptr *root1,ptrstore *choose,ptrstore *rootcreate)
{	
	int menu;
	char exit = 'N';
	char remove = 'N' ;
	char buy = 'N';
	int target,newitem,totalpriceproduct=0,money;
	char exitbuy ='N'; 
	
	while(toupper(exit) != 'Y')
	{
		menu = Menushow();
	
	if(menu == 1)
	{
		createBST2(&root);
		root1 = NULL;
		root1 = createBST1(root1);
	}else if (menu == 2)
		{	
			printf("================ Employee ================\n");
			printInorder(root1);
			printf("==========================================\n");
			printf("Do you want Remove Employee (Y/N) : ");
			scanf(" %c",&remove);
			if(toupper(remove) == 'Y')
			{
				printf("ID remove : ");
				scanf("%d",&target);
				deleteBST(&root1,target);
				printInorder(root1);
			}
			
		}else if (menu == 3)
			{
				
			
				printf("================ Product ================\n");
				printInorderstore(rootstore);
				printf("=========================================\n");
	
				printf("Do you want buy (Y/N) : ");
				scanf(" %c",&buy);
				
			if(toupper(buy) == 'Y')
			{
				while(toupper(exitbuy) !='Y')
				{
				printf("Pick ID : ");
				scanf("%d",&target);
				printf("Select Item : ");
				scanf("%d",&newitem);
				buystore(rootstore,&choose,target,newitem);
			
				printf("Do you okay (Y/N) : ");
				scanf(" %c",&exitbuy);
				}
				printInorderproduct(choose,&totalpriceproduct);
				printf("Total = %d\n",totalpriceproduct);
				printf("Pay Money : ");
				scanf("%d",&money);
				paymoney(money,totalpriceproduct);
			}
				
			}else if (menu == 4)
				{
					creatforstore(&rootcreate,rootstore);
					rootstore = NULL;
					createBSTstore(&rootstore);
				}else if (menu == 5)
					{
						printf("================ Product ================\n");
						printInorderstore(rootstore);
						printf("=========================================\n");
						printf("Do you want Remove Product (Y/N) : ");
						scanf(" %c",&remove);
						if(toupper(remove) == 'Y')
						{
							printf("ID remove : ");
							scanf("%d",&target);
							deleteBSTstore(&rootstore,target);
							system("cls");
							printf("================ Product ================\n");
							printInorderstore(rootstore);
							printf("=========================================\n");
						}
					}
			
		printf("Do you want to Exit (Y/N): ");
		scanf(" %c",&exit);
		system("cls");
	}
}

int main()
{
	int menu;
	ptrstore *choose=NULL;
	ptr *root1=NULL;
	ptr *root = NULL;
	ptrstore *rootcreate=NULL;
	ptrstore *rootdelete=NULL;
	ptrstore *rootstore = NULL;
	root1 = createBST1(root1);
	createBSTstore(&rootstore);
	checkmenu(root,rootstore,root1,choose,rootcreate);
	
	return 0 ;
}
