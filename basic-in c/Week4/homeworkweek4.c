#include <stdio.h>
int main()
{
	int size ;
	printf("*--------------------------------------*\n");
	printf("*               Find Size              *\n");
	printf("*--------------------------------------*\n");
	
	printf(" Enter Your feet's length  : ");
	scanf("%d",&size);
	
	switch(size)
	{
		case 3:	
		case 4:
		case 5: 
				  printf("*--------------------------------------*\n");
				  printf("*        Size of shoes = Small         *\n");
				  printf("*--------------------------------------*\n");
				  break;
		case 6:
		case 7:
		case 8:
		case 9:
				  printf("*--------------------------------------*\n");
				  printf("*         Size of shoes = Medium       *\n");
				  printf("*--------------------------------------*\n");
			      break;
		case 10:
		case 11:
		case 12:
		case 13:
				  printf("*--------------------------------------*\n");
				  printf("*         Size of shoes = Large        *\n");
				  printf("*--------------------------------------*\n");
			      break;
				  
		default: 
					printf("*--------------------------------------*\n");
					printf("*             Invalid Size             *\n");
					printf("*--------------------------------------*\n");
					break;
	}
	
	return 0 ;
}
