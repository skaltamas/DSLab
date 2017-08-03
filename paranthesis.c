#include<stdio.h>
#include<ctype.h>

typedef struct conversion
{
	char a[30];
	int top;
}stack;

void push(stack*,char);
char pop(stack*);
void checkContinuity(char []);
int isMatchingPair(char,char);

int main()
{
	char exp[30];
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
	int i;
	char c;
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
			else
			{
				c=pop(&s);
				if(isMatchingPair(c,exp[i]))
					continue;
				else{
					printf("Invalid Expression\n");
					return;
				}
			}
		}
	}
	if(s.top==-1)
		printf("Expression is valid\n");
	else
		printf("Expression is invalid\n");
}
				

void push(stack *s,char opr)
{
	s->top++;
	s->a[s->top]=opr;
}

char pop(stack *s)
{
	if (s->top==-1)
	{
		printf("stack is empty\n");
		return 0;
    }
    else
    {
		char data=s->a[s->top--];
		return data;
    }
}

