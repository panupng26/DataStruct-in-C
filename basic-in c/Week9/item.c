#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int main () 
{
	FILE *inf,*item1,*item2;
	char id[8],product[33],idproduct;
    int amonut,price,total1=0,total2=0;
	inf = fopen("item.txt","r");
	item1 = fopen("itemA.txt","w");
	item2 = fopen("itemB.txt","w");

	fprintf(item1,"List of Item A\n============\n") ;
	fprintf(item2,"List of Item B\n============\n") ;

    fscanf(inf,"%s",&id);
	fgets(product,28,inf);
	fscanf(inf,"%d%d %c",&amonut,&price,&idproduct);
	
	while(!feof(inf)) //test
	{
		if(idproduct=='A')
		{
			fprintf(item1,"%s %s   %d  %d  %c\n",id,product,amonut,price,idproduct);
			total1++;
		}else
		{
				fprintf(item2,"%s %s   %d  %d  %c\n",id,product,amonut,price,idproduct);
				total2++;
		}
		    fscanf(inf,"%s",&id);
			fgets(product,28,inf);
			fscanf(inf,"%d%d %c",&amonut,&price,&idproduct); //action
	}
	fprintf(item1,"-----\n");
	fprintf(item2,"-----\n");
	fprintf(item1,"Total list(s) = %d",total1);
	fprintf(item2,"Total list(s) = %d",total2);
	fclose(inf);
	fclose(item1);
	fclose(item2);
	
	return 0;
}
