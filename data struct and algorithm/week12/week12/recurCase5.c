#include <stdio.h>
void countstar(int star)
{
	if(star==0)
	{
		printf("");
		
	}else {
		if(star % 2 == 1)
		{
			countstar(star-1);
			printf("Oreo count star number %d.\n",star);
		}else{
			countstar(star-1);
			printf("Daisy count star number %d.\n",star);
		}
		  }
}
int main()
{
	int star,cnt=1;
	printf("Enter total counting star: ");
	scanf("%d",&star);
	countstar(star);
	return 0;
}
