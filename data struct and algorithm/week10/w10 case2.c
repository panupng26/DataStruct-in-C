#include <stdio.h>
#include <ctype.h>
typedef struct node{
	float value;
	struct node *next;
}stacktype;

void clearstack(stacktype **stack)
{
	*stack =NULL;
}

int emtystack(stacktype *stack)
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
float evaluate(stacktype *stack)
{
	FILE *inf;
	char token;
	float num,ans,oper1,oper2;
	inf = fopen("postdata1.txt","r");
	while(!feof(inf))
	{
		fscanf(inf,"%c",&token);		
		
		if(isdigit(token))
		{
			num = (float)token - '0';
			push(&stack,num);
		}else{
				oper2 = pop(&stack);
				oper1 = pop(&stack);
				if(token == '+')
				{
					ans = oper1 + oper2;
					push(&stack,ans);
				}else if(token == '-')
					{	
						ans = oper1 - oper2;
						push(&stack,ans);
					}
					else if(token == '*')
						{		
							ans = oper1 * oper2;
							push(&stack,ans);
						}else if(token == '/')
							{
								ans = oper1 / oper2;
								push(&stack,ans);
							}
			 }
			
	fclose(inf);
	ans = pop(&stack);
}
int main()
{
	stacktype *stack;
	float ans;
	clearstack(&stack);
	ans = evaluate;
	return 0 ;
}
