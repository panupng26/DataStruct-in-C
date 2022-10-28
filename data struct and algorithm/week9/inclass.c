#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
typedef struct
{
	int id;
	char name[30];
	int score;
}datatype;
typedef struct{
	datatype data[max];
	int top;
}stacktype;
void clearstack(stacktype *stack)
{
	(*stack).top = -1;
}
int emptystack(stacktype stack)
{
	if(stack.top == -1)
	{
		return 1;
	}else
		{
			return 0;
		}
}
int fullstack(stacktype stack)
{
	if(stack.top == max-1)
	{
		return 1 ;
	}else 
	{
		return 0;
	}
}
void push(stacktype *stack,datatype newdata)
{
	if(!fullstack(*stack))
	{
		(*stack).data[++(*stack).top] = newdata;
	}else
	{
		printf("Stack is Full.\n");
	}
}

datatype pop(stacktype *stack)
{
	datatype popdata;
	if(!emptystack(*stack))
	{
		popdata = (*stack).data[(*stack).top--];
	}else
		{
			printf("Stack is empty.\n");
		}
		return(popdata);
}
void createstack(stacktype *stack)
{
	FILE *inf;
	datatype newdata;
	inf = fopen("stackdata2.txt","r");
	
	while(!feof(inf))
	{
		fscanf(inf,"%d%s%d",&newdata.id,&newdata.name,&newdata.score);
		push(&*stack,newdata);
	}
	fclose(inf);
}
void printstack(stacktype stack)
{
	datatype popdata;
	while(!emptystack(stack))
	{
	    popdata = pop(&stack);
		printf("ID = %d | Name = %-10s | score = %d\n",popdata.id,popdata.name,popdata.score);	
	}
}
int main()
{
	stacktype stack;
	clearstack(&stack);
	createstack(&stack);
	printstack(stack);
	return 0 ;
}
