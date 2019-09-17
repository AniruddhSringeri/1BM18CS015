#include <stdio.h>
#define SIZE 10
void insert(int q[], int *r, int item);
int delete(int q[], int *r, int *f);
void display(int q[], int r, int f);
void insert(int q[], int *r, int item)
{
    if(*r == SIZE-1)
    {
        printf("Queue Overflow\n");
        return;
    }
    *r = *r + 1;
    q[*r] = item;
}
int delete(int q[], int *r, int *f)
{
    int item;
    if(*f>*r)
    {
        printf("Queue Underflow\n");
        return -9999;
    }
    item = q[*f];
    (*f)+=1;
    return item;

}

void display(int q[], int r, int f)
{
    int i;
    if(f>r)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Contents of the queue are:  ");
    for(i=f;i<=r;i++)
    {
        printf("%d, ", q[i]);
    }
    printf("\b\b \n");
}

int main()
{
    int f=0, r=-1;
    int q[SIZE];
    int ch, cont;
    do
    {
        printf("Choose an operation to perform:  \n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:{
                int item;
                printf("Enter the item to be inserted\n");
                scanf("%d", &item);
                insert(q, &r, item);
                break;
            }
            case 2:{
                int x;
                x = delete(q, &r, &f);
                if(x==-9999)
                {
                    break;
                }
                printf("The deleted element is %d\n", x);
                break;
            }
            case 3:{
                display(q, r, f);
                break;
            }
            default: printf("Invalid option\n");
        }
        printf("\nPress 1 to continue or otherwise:  \n");
        scanf("%d", &cont);
    } while (cont==1);
    
}
