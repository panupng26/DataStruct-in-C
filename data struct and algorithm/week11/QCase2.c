#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
    int data;
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
    return q->front == q->rear->next; 
}
void enqueue(queue **q, int newdata)
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
int dequeue(queue **q)
{
    nodetype *deqnode;
    int deqdata;
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

queue* createQ1(queue *q)
{
	int newdata;
	FILE *inf;
	inf = fopen("qdata1.txt","r");
	while(!feof(inf))
	{
		fscanf(inf,"%d",&newdata);
		enqueue(&q,newdata);
	}
	fclose(inf);
	return (q);
}
void createQ2(queue **q)
{
	int newdata;
	FILE *inf;
	inf = fopen("qdata1.txt","r");
	while(!feof(inf))
	{
		fscanf(inf,"%d",&newdata);
		enqueue(&*q,newdata);
	}
	fclose(inf);
}

void printQ(queue *q)
{
	int deqdata;
	while(!emptyq(q))
	{
		deqdata = dequeue(&q);
		printf("Number = %d\n",deqdata);
	}
}
int main()
{
    queue *q;
    q = malloc(sizeof(queue));
    clearQ(&q);
    //q = createQ1(q);
    createQ2(&q);
    printQ(q);
    //next build function crateQ1 and createQ2 for get data from qdata1.txt
    
    return 0;
}
