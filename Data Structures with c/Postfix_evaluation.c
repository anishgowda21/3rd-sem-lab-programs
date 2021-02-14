//C program to evaluate an postfix expression

#include<stdio.h>
#include<stdlib.h>
typedef enum
{
	lparen,rparen,plus,minus,times,divide,mod,eos,operand
}precedence;

int stack[30],top=-1;
char EXPR[30];


precedence get_token(char *symbol,int *n)
{
	*symbol = EXPR[(*n)++];
	switch(*symbol)
	{
		case '(' : return lparen;
		case ')' : return rparen;
		case '+' : return plus;
		case '-' : return minus;
		case '*' : return times;
		case '/' : return divide;
		case '%' : return mod;
		case '\0' : return eos;
		default : return operand;
	}
}

void push(int item)
{
	stack[++top] = item;
}

int pop()
{
	return stack[top--];
}


int eval()
{
	int n=0,op1,op2;
	char symbol;
	precedence token;
	for(token = get_token(&symbol,&n) ; token != eos ; token = get_token(&symbol,&n))
	{
		if(token == operand)
			push(symbol - '0');
		else
		{
			op2=pop();
			op1=pop();
			switch(token)
			{
				case plus:
					push(op1+op2);
					break;
				case minus:
					push(op1-op2);
					break;
				case times:
					push(op1*op2);
					break;
				case divide:
					push(op1/op2);
					break;
				case mod:
					push(op1%op2);
					break;
			}
		}
	}
	return pop();
}


void main()
{
	int res;
	printf("Enter the expression:");
	scanf("%s",EXPR);
	res=eval();
	printf("\nAfter evaluation:%d\n",res);
}


