#include <stdio.h>
int main()
{

	
	int data1,data2,data3;
	char name[50],answer,lname[50];
	float gpa;
	printf("Enter your name  : ");
	scanf("%s%s",&name,&lname);
	
	
	printf("Select (Y/N): ");
	scanf(" %c",&answer);
	
	if(answer=='y')
	printf("Hello Y \n");
	else printf("Do you want know BMI \n\n\n\n\n\n\n ");
	



	printf("Enter your GPA(x.xx) : ");
	scanf("%f",&gpa);

	


	
	printf("===============================\n");
	printf("Your name is %s %s\n",name,lname);
	printf("Your selected %c\n",answer);
	printf("Your GPA = %0.2f\n",gpa);
	printf("===============================\n");
	
	/*
	printf("Enter 3 Numbers: ");
	scanf("%d%d%d",&data1,&data2,&data3);
	printf("Data1=%d, Data2=%d, Data3=%d",data1,data2,data3);
	*/
	
	
	
	
	
	
	
	
	return 0;

}
