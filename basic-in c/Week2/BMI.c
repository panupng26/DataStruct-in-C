#include <stdio.h>
int main()
{
	char name[50],phone[15],month[20],color[50],birth[30];
	float weight,height,year,age,bmi,hei;
	
	
	printf("#######################################################\n");
	printf("##               Storing profile a program           ##\n");
	printf("#######################################################\n");
	printf("Enter full name : ");
	scanf("%s",&name);
	printf("Enter mobile phone : ");
	scanf("%s",&phone);
	printf("Enter date of birth : ");
	scanf("%s",&birth);
	printf("Enter month of birth : ");
	scanf("%s",&month);
	printf("Enter Year of birth : ");
	scanf("%f",&year);
	printf("Enter your weight(kg.) : ");
	scanf("%f",&weight);
	printf("Enter your height(cm.) : ");
	scanf("%f",&height);
	printf("Enter your favorite color : ");
	scanf("%s",&color);
	
 	printf("#######################################################\n");
	printf("##                       Profile                     ##\n");
	printf("#######################################################\n");
	printf("Hi %s \n",name);
	printf("Mobile Phone: %s \n",phone);
	
	age = 2018 - year;
	
	printf("Your age = %0.0f \n",age);
	printf("Your height = %0.0f (meter), and weight = %0.0f (kg.) \n",height,weight);
	
	hei = height/100;
	bmi = weight/(hei*hei);
	
	printf("Your BMI = %0.2f \n",bmi);
	printf("Your favorite color is %s \n",color);
	
	printf("#######################################################\n");
	printf("##   BMI range (18.5 to 24.9) is considered healthy. ##\n");
	printf("#######################################################\n");
	return 0;
}
