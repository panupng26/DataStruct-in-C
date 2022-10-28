#include <stdio.h>
#include <ctype.h>
int main ()
{
	
	int i,amount,vote,iti=0,eng=0,acc=0,bus=0,faildept=0,max=-1,no;
	int v1=0,v2=0,v3=0,v4=0,failv=0;
	char dept;
	printf("===================================================\n");
	printf("	Candidate no.1 : Toon Toon\n");
	printf("	Candidate no.2 : Prayayuth\n");
	printf("	Candidate no.3 : Moo Pha\n");
	printf("	Candidate no.4 : BU BU\n");
	printf("===================================================\n");
	printf("Department of Voters are: \n");
	printf("	(I)nformation Technology and Innovation\n");
	printf("	(E)ngineering\n");
	printf("	(A)ccounting\n");
	printf("	(B)usiness Administration\n");
	printf("===================================================\n");
	printf("Enter amount of voters : ");
	scanf("%d",&amount);
	
	i=1;
	while(i<=amount)
	{
	printf("Who are you voting for (1,2,3,4) ? : ");
	scanf("%d",&vote);
	printf("Enter department of voter#%d : ",i);
	
	scanf(" %c",&dept);	
	
	if(toupper(dept)=='I')
	{
		iti++;
	}else if (toupper(dept)=='E')
		{
			eng++;
		}else if (toupper(dept)=='A')
			{
				acc++;
			}else if (toupper(dept)=='B')
				{
					bus++;
				}else 
				{
					faildept++;
		 	}
				
	if (vote == 1)
	{
		v1++;
	}else if (vote ==2)
		{
			v2++;
		}else if (vote ==3)
			{
				v3++;
			}else if (vote ==4)
			{
				v4++;
			}else
				{
					failv++;
				}
			

	i++;
	}
	printf("ITI = %d En = %d Acc = %d Bus = %d fail = %d \n",iti,eng,acc,bus,faildept);
	printf("Total vote1 = %d\n",v1);
	printf("Total vote2 = %d\n",v2);
	printf("Total vote3 = %d\n",v3);
	printf("Total vote4 = %d\n",v4);
	printf("Total fail = %d\n",failv);
	if(v1> max)
	{
		max = v1;
		no = 1;
		
	}
	 if(v2 > max)
		{
			max = v2;
			no = 2;
		} 
	if (v3 > max)
		{
			max = v3;
				no = 3;
		}
	if (v4 > max)
	 {
		max = v4;
		no = 4;
	 }
		if(no == 1)
		{
			printf("The winner is no.1 -> Toon Toon\n");
		}else if (no == 2)
			{
				printf("The winner is no.2 -> Prayayuth\n");
			}else if (no ==3)
				{
					printf("The winner is no.3 -> Moo Pha\n");
				}else if (no ==4)
					{
						printf("The winner is no.4 -> BU BU\n");	
					}
	return 0;
}
