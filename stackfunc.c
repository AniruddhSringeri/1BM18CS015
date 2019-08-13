#include<stdio.h>
int stack[100];
int top=-1;
void push(int ele);
int pop();
void display();
int main()
{
int e;
push(1);
push(2);
push(3);
display();
e=pop();
if(e!=9999)
printf("The popped element is %d\n",e);
display();

return 0;
}

void push(int ele)
{
if (top==99)
{
printf("Stack overflow\n");
return;
}
stack[++top]=ele;
}

int pop()
{
if(top==-1)
{
printf("Stack underflow.\n");
return -9999;
}
return stack[top--];
}

void display()
{
int i;
if (top==-1)
{
printf("Stack is empty.\n");
return;
}
else{

for(i=top;i>-1;i--)
{
printf("%d\n",stack[i]);
}
return;}
}
