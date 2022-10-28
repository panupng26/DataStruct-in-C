#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100
typedef struct{
	int id;
	char name[30];
	int score;
}datatype;

typedef struct{
	datatype data[max];
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
void enQ(qtype *q,datatype newdata)
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
datatype deQ(qtype *q)
{
	datatype deqdata;
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
	datatype newdata;
	FILE *inf;
	inf = fopen("qdata2.txt","r");
	while(!feof(inf))
	{
		fscanf(inf,"%d%s%d",&newdata.id,&newdata.name,&newdata.score);
		enQ(&q,newdata);
	}
	fclose(inf);
	return (q);
}
void createQ2(qtype *q)
{
	datatype newdata;
	FILE *inf;
	inf = fopen("qdata2.txt","r");
	while(!feof(inf))
	{
		fscanf(inf,"%d%s%d",&newdata.id,&newdata.name,&newdata.score);
		enQ(&*q,newdata);
	}
	fclose(inf);
}
void printQ(qtype q)
{
	datatype data;
	while(!emptyQ(q))
	{
		data = deQ(&q);
		printf("ID = %d | Name = %s | score = %d\n",data.id,data.name,data.score);
	}
}
int main()
{
	qtype q;
	clearQ(&q);
	q = createQ1(q);
//	createQ2(&q);
	printQ(q);
	return 0;
}
