#include <stdio.h>
#include <string.h>
#include <ctype.h>

void test(char dept)
{

	printf("======= Output =======\n");
	switch(toupper(dept)) {
    case 'M' :
    printf("Your code (M) is Monday.\n");
    printf("It is represented in Yellow.\n.");
      break; 
	
    case 'T' :
        printf("Your code (T) is Tuesday.\n");
    	printf("It is represented in Pink.\n.");
      break; 
  
    case 'W' :
     	printf("Your code (W) is Wednesday.\n");
    	printf("It is represented in Green.\n.");
      break; 
       
	case 'H'  :
      	printf("Your code (H) is Thursday.\n");
    	printf("It is represented in Orange.\n.");
      break; 
      
    case 'F'  :
      	printf("Your code (F) is Friday.\n");
    	printf("It is represented in Blue.\n.");
      break; 
      
   default : 
   	printf("Your code (%c) is invalid.\nPlease try again.",dept);
   

	}
}
int main ()
{
	char dept;
	printf("Enter a character code (M,T,W,H,F) : ");
	scanf(" %c",&dept);

	test(dept);

	return 0 ;
}
