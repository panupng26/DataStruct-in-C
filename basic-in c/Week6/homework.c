#include <stdio.h>
#include <ctype.h>
int main ()
{
	float price,discount,net,quantity,totalp=0,totalq=0;
	char product,loop;
	
	loop = 'N' ;
	while(toupper(loop) != 'Y')
	{

	printf("Product Code(A or B) : ");
	scanf(" %c",&product);
	printf("Quantity : ");
	scanf("%f",&quantity);
	
	if(product=='A')
	{
		price = quantity * 500 ;
		if(quantity > 9)
		{
			discount = price * 0.1 ;
		}else
			{
				discount = 0 ;
			}
			
			net = price - discount ;
			printf("Buying %0.0f Product %c(s) = %0.2f\n",quantity,product,price);
			printf("Discount (10 percent) = %0.2f\n",discount);
			printf("Net = %0.2f baht(s)\n",net);
			
		
	}else if (product =='B')
		{
			price = quantity * 250 ;
		
		if(quantity > 9)
		{
			discount = price * 0.1 ;
		}else
			{
				discount = 0 ;
			}
			net = price - discount ;
			printf("Buying %0.0f Product %c(s) = %0.2f\n",quantity,product,price);
			printf("Discount (10 percent) = %0.2f\n",discount);
			printf("Net = %0.2f baht(s)\n",net);
				
		}else
			{
				printf("Invalid software code!!!\n");
				totalq = totalq - quantity ;
				totalp = totalp - net ;
			}
			
			totalq = totalq + quantity ;
			totalp = totalp + net ;
			printf("-------------------------------------------------\n");
			printf("Quit (Y/N) : ");
			scanf(" %c",&loop);
			printf("-------------------------------------------------\n");
			printf("\n");
		}
		printf("Total Quantity = %0.0f\nTotal Price = %0.2f baht",totalq,totalp);
		
		
		
	return 0 ;
}
