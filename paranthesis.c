/*Description:Check continuity of different types of paranthesis using stack
 * Learner:Shaikh Altamas shakeel
 * Roll no:16co11
 */
#include<stdio.h>
#include<ctype.h>
#define MAX 100

typedef struct stack
{
	char a[MAX];
	int top;
}stack;

void push(stack*,char);
char pop(stack*);
void checkContinuity(char []);
int isMatchingPair(char,char);

int main()
{
	char exp[MAX];
	printf("Enter an Expression containing only brackets\n");
	scanf("%s",exp);
	checkContinuity(exp);
	return 0;
}

int isMatchingPair(char left,char right)
{
	switch(left)
	{
		case '(':if(right==')')
					return 1;
					else return 0;
		case '{':if(right=='}')
					return 1;
					else return 0;
		case '[':if(right==']')
					return 1;
					else return 0;
		default: return 0;
	}
}

void checkContinuity(char exp[])
{
	int i,c;
	stack s;
	s.top=-1;
	for(i=0;exp[i]!='\0';i++)
	{
		if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
			push(&s,exp[i]);
		else
		{
			if(s.top==-1)
			{
				printf("Invalid Expression\n");
				return;
			}
			c=pop(&s);
			if(isMatchingPair(c,exp[i]))
				continue;
			else{
				printf("Invalid Expression\n");
				return;
				}
		}
	}
	if(s.top==-1)
		printf("Expression is valid\n");
	else
		printf("Expression is invalid\n");
}
				
void push(struct stack *s,char opr)
{
	if(s->top!=MAX-1)
	{
		s->top++;
		s->a[s->top]=opr;
	}
	else
		printf("\nStack is full\n");
}

char pop(struct stack *s)
{
	return(s->a[s->top--]);
}

