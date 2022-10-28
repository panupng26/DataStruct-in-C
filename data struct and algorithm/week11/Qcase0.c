#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100
typedef struct{
	int data[max];
	int front,rear;	
}qtype;

void clearQ(qtype *q)
{
	(*q).rear = -1;
	(*q).front = -1;
}
int emptyQ(qtype q)
{
	if(q.front-1 == q.rear)
	  return 1;
	else
	  return 0;
}
int fullQ(qtype q)
{
	if(q.rear == max-1)
	  return 1;
	else
	  return 0;
}
void enQ(qtype *q,int newdata)
{
	if(!fullQ(*q))
	{
		(*q).data[++(*q).rear] = newdata;
		if((*q).front == -1)
		{
			(*q).front = 0;
		}
	}
	else
	{
		printf("Q is full.\n");
	}
}
int deQ(qtype *q)
{
	int deqdata;
	if(!emptyQ(*q))
	{
		deqdata = (*q).data[(*q).front++];
		return deqdata;
	}
	else
	{
		printf("Q is empty.\n");
	}
}
qtype createQ1(qtype q)
{
	int newdata;
	FILE *inf;
	inf = fopen("qdata1.txt","r");
	while(!feof(inf))
	{
		fscanf(inf,"%d",&newdata);
		enQ(&q,newdata);
	}
	fclose(inf);
	return (q);
}
void createQ2(qtype *q)
{
	int newdata;
	FILE *inf;
	inf = fopen("qdata1.txt","r");
	while(!feof(inf))
	{
		fscanf(inf,"%d",&newdata);
		enQ(&*q,newdata);
	}
	fclose(inf);
}
void printQ(qtype q)
{
	int data;
	while(!emptyQ(q))
	{
		data = deQ(&q);
		printf("Deq data = %d \n",data);
	}
}
int main()
{
	qtype q;
	clearQ(&q);
//	q = createQ1(q);
  	createQ2(&q);
    printQ(q);
    //next build function crateQ1 and createQ2 for get data from qdata1.txt
	return 0;
}
