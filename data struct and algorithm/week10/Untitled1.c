#include <stdio.h>
typedef struct node{
	float value;
	struct node *next;
}stacktype;

void clearstack(stacktype **stack)
{
	*stack =NULL;
}
int emtystack(stack *stack)
{
	if(stack == NULL)
	{
		return 1;
	}else {
		return 0;
	}
}
void push(stacktype **stack ,float newdata)
{
		stacktype *newnode;
		newnode = (stacktype*)malloc(sizeof(stacktype));
		newnode->value = newdata;
		newnode->next = *stack;
		*stack = newnode;
}
float pop(stacktype **stack)
{
	float popdata;
	stacktype *popnode;
	if(!emtystack(*stack))
	{
		popnode = *stack;
		popdata = popnode->value;
		*stack = (*stack)->next;
	}else
		{
			printf("Stack is empty. \n");
		}
}
int main()
{
	stacktype *stack;
	return 0 ;
}
