#include<stdio.h>
# define S 100
void insert(int item, int *r, int q[])
{
    if(*r==S-1)
    {
        printf("Queue Overflow\n");
        return;
    }
    q[++(*r)]=item;
}
int main()
{
    int  b[S];
    int i, n, it;
    int re= -1;
    printf("Enter the no. of processes:  \n");
    scanf("%d", &n);
    printf("Enter the burst time of each process:  \n");
    for (i=0; i<n; i++)
    {
        scanf("%d", &it);
        insert(it, &re, b);
    }
    printf("Process 1 starts at 0th and ends at %dth second\n", b[0]);
    for(i=1;i<n;i++)
    {
        b[i]=b[i-1]+b[i];
        printf("Process %d starts at %d th and ends at %dth second\n", (i+1), b[i-1], b[i]);
    }
    return 0;
}
