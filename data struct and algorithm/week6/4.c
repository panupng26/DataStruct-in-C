#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int info;
	struct node *next;
}ptr;

int main ()
{
	ptr *p,*q,*r,*run;
	p = (ptr*)malloc(sizeof(ptr));
	q = (ptr*)malloc(sizeof(ptr));
	r = (ptr*)malloc(sizeof(ptr));

	
	p->info = 10;
	p->next = NULL;
	
	q->info = 20;
	q->next = NULL;
	
	r->info = 30 ;
	r->next = NULL;
	
	p->next = q;
	q->next = r;
	
	run = p ;
	
	
	printf("Info = %d\n",p->info);
	printf("Info = %d\n",p->next->info);
	printf("Info = %d\n\n",p->next->next->info);
	
	while(run!=NULL)
	{
		printf("Info = %d\n",run->info);
		run = run->next ;
	}
	printf("\n");
	run = p ;
	while(run != NULL)
	{
		if(run->info>20)
		{
			printf("Info = %d\n",run->info);
		}
		run = run->next;
	}
	return 0 ;
}
