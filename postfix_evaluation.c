#include<stdio.h>
#include<math.h>
void push(float e, float s[100], int *t);
float pop(float s[100], int *t);
float value(int a, int b, char ch);

int main()
{
    float stack[100];
    int top = -1; char post[100];
    int i = 0;
    int a, b; float val;
    printf("Enter postfix expression:  ");
    scanf("%s", post);
    while(post[i]!='\0')
    {
        if(post[i]>='0'&&post[i]<='9')
        {
            push((post[i]-'0'), stack, &top);
        }
        else 
        {
            b = pop(stack,&top);
            a = pop(stack, &top);
            val = value(a, b, post[i]);
            push(val, stack, &top);
        }
        i = i + 1;
    }
    printf("%f", pop(stack, &top));
    return 0;
}

void push(float e, float s[100], int *t)
{
    if (*t==99)
    {
        printf("Stack Overflow\n");
        return;
    }
    s[++(*t)] = e;
}

float pop(float s[100], int *t)
{
    if(*t == -1)
    {
        printf("Stack Underflow\n");
        return -9999;
    }
    return s[(*t)--];
}

float value(int a, int b, char ch)
{
    if(ch=='+')
        return(a+b);
        else if(ch=='-')
            return (a-b);
        else if(ch=='*')
            return (a*b);
        else if(ch=='/')
            return ((float)a/(float)b);
        else if(ch=='^')
            return (pow(a,b));
}
