/*Description:Evaluation of postfix expression
 * Learner:Shaikh Altamas shakeel
 * Roll no:16co11
 */
#include<stdio.h>
#include<ctype.h>
#define MAX_SIZE 30

typedef struct conversion
{
	char a[30];
	int top;
}stack;

int push(stack *,char);
char pop(stack*);
int operation(int,int,char);
int evaluate(char []);

int main()
{
	char postfix[30];
	printf("Enter POSTFIX Expression\n");
	scanf("%s",postfix);
	printf("Evaluation of postfix expresssion =%d",evaluate(postfix));
	return 0;
}

int push(stack *s,char opr)
{
	if (s->top==MAX_SIZE-1)
	return 1;
	else
	{
	s->top++;
	s->a[s->top]=opr;
	return 0;
	}
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

int operation(int num1,int num2,char opr)
{
	switch(opr)
	{
		case '+':return num1+num2;
		break;
		case '-':return num1-num2;
		break;
		case '*':return num1*num2;
		break;
		case '/':return num1/num2;
		break;
	}
	return 0;
}                                           

int evaluate(char pos[])
{
	int result,e1,e2,i;
	char opr;
	stack s;
	s.top=-1;
	for(i=0;pos[i]!='\0';i++)
	{
		opr=pos[i];
		if(isdigit(opr))
		push(&s,opr-'0');
		else
		{                                                                                                     
		e1=pop(&s);
		e2=pop(&s);
		result=operation(e1,e2,opr);
		push(&s,result);
		}
	}
	return pop(&s);
}

/*OUTPUT:
Enter POSTFIX Expression
2345*+-
Evaluation of postfix expresssion =21

------------------
(program exited with code: 0)
Press return to continue
*/

