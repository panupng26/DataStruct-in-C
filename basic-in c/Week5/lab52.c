#include <stdio.h>
int main()
{
	int i,table,no;
	float total,rdish,bdish,gdish,discount,perperson,net,member,totalr,totalb,totalg ;
	float reddish=0,bluedish=0,greendish=0 ;
	
	printf("***********************************************************************\n");
	printf("****************************Bu Sushi Buffet****************************\n");
	printf("***********************************************************************\n");
	printf("** Sushi Menu :                                                      **\n");
	printf("**     (R)ed dish = 69 bahts                                         **\n");
	printf("**     (B)lue dish = 49 bahts                                        **\n");
	printf("**     (G)reen dish = 39 bahts                                       **\n");
	printf("***********************************************************************\n\n");
	
	printf("Enter number of table : ");
	scanf("%d",&table);
	for(i=1;i<=table;i++)
	{
		printf("Enter table no. : ");
		scanf("%d",&no);
		printf("Enter member amount : ");
		scanf("%f",&member);
		printf("Amount of red dish : ");
		scanf("%f",&rdish);
		printf("Amount of blue dish : ");
		scanf("%f",&bdish);
		printf("Amount of green dish : ");
		scanf("%f",&gdish);
		totalr= rdish*69;
		totalb= bdish*49;
		totalg= gdish*39;
		total = totalr + totalb + totalg;
		if(rdish>10)
		{
			discount = (total * 10) / 100 ; 
	
		}else
		{
			discount = 0 ;
		}
		
		net = total - discount ;
		perperson = net / member ;
		printf("***********************************************************************\n");
		printf("*--------------------------------Bill---------------------------------*\n");
		printf("***********************************************************************\n");
		printf("Table no %d , Member Amount = %0.0f \n",no,member);
		printf("Red dish = %0.0f , Total = %0.2f\n",rdish,totalr);
		printf("Blue dish = %0.0f , Total = %0.2f\n",bdish,totalb);
		printf("Green dish = %0.0f , Total = %0.2f\n",gdish,totalg);
		printf("Total Amount = %0.2f , discount = %0.2f NET = %0.2f\n",total,discount,net);
		printf("Net amount per person = %0.2f\n",perperson);
		printf("***********************************************************************\n");
		reddish = reddish + totalr ;
		bluedish = bluedish + totalb ; 
		greendish = greendish + totalg ; 
	}
	
	printf("Total Amount of Red Dish = %0.2f\n",reddish);
	printf("Total Amount of Blue Dish = %0.2f\n",bluedish);
	printf("Total Amount of Green Dish = %0.2f\n",greendish);
		printf("*--------------------------------Thank you-----------------------------*\n");
	
}
