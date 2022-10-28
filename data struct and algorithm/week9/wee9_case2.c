#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
typedef struct {
	int data[100];
	int top;
}stacktype;

void clearstack(stacktype *stack)
{
	(*stack).top = -1;    //stack->top
}
int fullstack(stacktype stack)
{
	if(stack.top == max-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int emptystack(stacktype stack)
{
	if(stack.top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void push(stacktype *stack,int newdata)
{
	if(!fullstack(*stack))
	{
		(*stack).data[++(*stack).top] = newdata;
	}
	else
	{
		printf("Stack is full!\n");
	}
}
int pop(stacktype *stack)
{
	int popdata;
	if(!emptystack(*stack))
	{
		popdata = (*stack).data[(*stack).top--];//popdata = stack[(*top)--]; 
	}
	else
	{
		printf("Stack is empty\n");
	}
	return popdata;
}

void countoddeven(stacktype stack)
{
	int odd=0,even=0,popdata;
	while(!emptystack(stack))
	{
		popdata = pop(&stack);
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

void createstack(stacktype *stack)
{
	FILE *inf;
	int newdata;
	inf = fopen("stackdata.txt","r");
	while(!feof(inf))
	{
		fscanf(inf,"%d",&newdata);
		push(&*stack,newdata);
	}
	fclose(inf);
}
void printstack(stacktype stack)
{
	int popdata;
	while(!emptystack(stack))
	{
	    popdata = pop(&stack);
		printf("Popdata = %d\n",popdata);	
	}
}
int main()
{
    stacktype stack;
    clearstack(&stack);
    createstack(&stack);
    printstack(stack);
    countoddeven(stack);    
	return 0;
}
