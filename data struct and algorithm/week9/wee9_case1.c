#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
void clearstack(int *top)
{
	*top = -1;
}
int fullstack(int top)
{
	if(top == max-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int emptystack(int top)
{
	if(top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void push(int stack[],int *top,int newdata)
{
	if(!fullstack(*top))
	{
		stack[++(*top)] = newdata;
	}
	else
	{
		printf("Stack is full!\n");
	}
}
int pop(int stack[],int *top)
{
	int popdata;
	if(!emptystack(*top))
	{
		popdata = stack[(*top)--];
	}
	else
	{
		printf("Stack is empty\n");
	}
	return popdata;
}

void countoddeven(int stack[],int top)
{
	int odd=0,even=0,popdata;
	while(!emptystack(top))
	{
		popdata = pop(stack,&top);
		if(popdata % 2 == 0 )
		{
			even++;
		}else
			{
				odd++;
			}
		
	}
	printf("Even = %d \nodd = %d\n",even,odd);
}

void createstack(int stack[],int *top)
{
	FILE *inf;
	int newdata;
	inf = fopen("stackdata.txt","r");
	while(!feof(inf))
	{
		fscanf(inf,"%d",&newdata);
		push(stack,&*top,newdata);
	}
	fclose(inf);
}
void printstack(int stack[],int top)
{
	int popdata;
	while(!emptystack(top))
	{
	    popdata = pop(stack,&top);
		printf("Popdata = %d\n",popdata);	
	}
}
int main()
{
    int stack[100],top;
    clearstack(&top);
    createstack(stack,&top);
    printstack(stack,top);
    countoddeven(stack,top);    
	return 0;
}
