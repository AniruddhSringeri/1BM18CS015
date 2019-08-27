#include<stdio.h>
int precedence(char c);
void push(char c,char s[100],int *top);
char pop(char s[100],int *top);

int precedence(char c)
{
	if(c=='^') return 3;
	else if(c=='*'||c=='/') return 2;
	else if(c=='+'||c=='-') return 1;
    else return 10000;
}

void push(char c,char s[100],int *top)
{
	if(*top==99)
	{
		printf("Stack overflow.\n");
	}
	else
		s[++(*top)]=c;
}
char pop(char s[100],int *top)
{
	if(*top==-1)
		return -3;
	else
		return s[(*top)--];
}


int main()
{
	int i=0;
    char stack[100];
    char infix[100];
	int top=-1;
    char x;
	printf("Enter the infix expression:  ");
        gets(infix);
	
	while(infix[i]!='\0')
	{
		if((infix[i]>='A'&&infix[i]<='Z')||(infix[i]>='a'&&infix[i]<='z'))
			printf("%c",infix[i]);
		else if(infix[i]=='(')
			push(infix[i],stack,&top);
		else if(infix[i]==')')
		{
			while((x=pop(stack,&top))!='(')
				printf("%c",x);
		}
		else
		{
			if(precedence(stack[top])>=precedence(infix[i]))
				push(infix[i],stack,&top);
			else
			{
				while(precedence(stack[top])>=precedence(infix[i]))
					x=pop(stack,&top);
				push(infix[i],stack,&top);
			}
		}
		i++;
	}
	while(top!=-1)
	{
		printf("%c",pop(stack,&top));
	}
	return 0;
}
