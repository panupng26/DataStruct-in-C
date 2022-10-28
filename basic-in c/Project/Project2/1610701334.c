#include <stdio.h>
#include <ctype.h>
void menu()  
{
	
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("+          Programe Calculate Salary tax          +\n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("+              Select Menu Programe               +\n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("+   1.Menu   Calculate Salary tax                 +\n");
	printf("+   2.Menu   Insert profile employee              +\n");
	printf("+   3.Menu   Report employee                      +\n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	
}
void insert(int *select)
{
	
	printf("Enter Select Menu : ");
	scanf("%d",&*select);
	
}
void showmoney(float vat, float money)
{
	
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("	Vat = %0.2f baht\n",vat);
	printf("	Your money is %0.2f baht \n",money - vat);
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	
}
void report()
{
	
	int i=0,j;
	int id[50];
	char name[50][30],lastname[50][30],phone[50][11];
	FILE *inf;
	inf = fopen("insertemployee.txt","r");
	
	fscanf(inf,"%d%s%s%s",&id[i],&name[i],&lastname[i],&phone[i]);
	while(!feof(inf))
	{
		i++;
		
		fscanf(inf,"%d%s%s%s",&id[i],&name[i],&lastname[i],&phone[i]);
	}
	
	for(j=0;j<i;j++)
	{
		printf("ID: %d ,Name: %s %s ,Phone: %s\n",id[j],name[j],lastname[j],phone[j]);
	}
	
	fclose(inf);
}
void runprograme(int run)
{
	if(run == 1)
	{
		float salary,vat,totalvat;
		printf("Enter salary : ");
		scanf("%f",&salary);
		printf("Enter vat : ");
		scanf("%f",&vat);
		totalvat = (salary * vat)/100;
		
		showmoney(totalvat,salary);
		
	}else if(run == 2)
		{
			char name[30],lastname[30];
			int id;
			char phone[11];
			FILE *insert ;
			insert = fopen("insertemployee.txt","a+");
			printf("Enter Name & Lastname example(Panupong Kongsanae) : ");
			scanf("%s %s",&name,&lastname);
			
			printf("Enter ID card number : ");
			scanf("%d",&id);
			
			printf("Enter Telephone number : ");
			scanf("%s",&phone);
		
			fprintf(insert,"%d %s %s %s\n",id,name,lastname,phone);
			
			fclose(insert);
		}else if (run == 3)
			{
				report();
			}else
				{
					printf("Error. Please enter New menu ");
				}
}
int main ()
{
	int slmenu;
	char exit = 'N';

	while(toupper(exit)!= 'Y')
	{
	menu();
	insert(&slmenu);
	runprograme(slmenu);
	
	printf("Do you want to Exit (Y/N) : ");
	scanf(" %c",&exit);
	
	}
}

