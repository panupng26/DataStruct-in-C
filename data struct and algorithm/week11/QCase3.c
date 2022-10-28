#include <stdlib.h>
#include <stdio.h>
typedef struct {
	int id;
	char name[30];
	int score;
}datatype;
typedef struct node
{
    datatype data;
    struct node *next;
}nodetype;

typedef struct 
{
    nodetype *front;
    nodetype *rear;
}queue;

void clearQ(queue **q)
{
    (*q)->front = NULL;
    (*q)->rear = NULL;
}
int emptyq(queue *q)
{
    return (q->front == q->rear->next);
}
void enqueue(queue **q, datatype newdata)
{
    nodetype *newnode;
    newnode = malloc(sizeof(nodetype));
    newnode->data = newdata;
    newnode->next = NULL;
    if((*q)->rear == NULL) //queue or linklist is empty (NULL)
    {
        (*q)->front = (*q)->rear = newnode;
    }
	else 
    {
        (*q)->rear->next = newnode;
        (*q)->rear = newnode;
    }     
}
datatype dequeue(queue **q)
{
    nodetype *deqnode;
    datatype deqdata;
    if(!emptyq(*q))
	{
		deqdata = (*q)->front->data;
	    deqnode = (*q)->front;
	    (*q)->front = (*q)->front->next;
	    free(deqnode);
	    return(deqdata);
	}
	else
	{
		printf("empty queue.\n");
	}
}

void printQ(queue *q)
{
	datatype data;
	while(!emptyq(q))
	{
		data = dequeue(&q);
			printf("ID = %d | Name = %-10s | score = %d\n",data.id,data.name,data.score);
	}
}
queue* createQ1(queue *q)
{
	datatype newdata;
	FILE *inf;
	inf = fopen("qdata2.txt","r");
	while(!feof(inf))
	{
		fscanf(inf,"%d%s%d",&newdata.id,&newdata.name,&newdata.score);
		enqueue(&q,newdata);
	}
	fclose(inf);
	return (q);
}
void createQ2(queue **q)
{
	datatype newdata;
	FILE *inf;
	inf = fopen("qdata2.txt","r");
	while(!feof(inf))
	{
		fscanf(inf,"%d%s%d",&newdata.id,&newdata.name,&newdata.score);
		enqueue(&*q,newdata);
	}
	fclose(inf);
}
int main()
{
    queue *q;
    q = malloc(sizeof(queue));
    clearQ(&q);
    q = createQ1(q);
    //createQ2(&q);
    printQ(q);
	return 0;
}
