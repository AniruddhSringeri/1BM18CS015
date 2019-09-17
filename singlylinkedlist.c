#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *next;
};

typedef struct node *NODE;

NODE getnode()
{
    NODE p;
    p = (NODE) malloc(sizeof(struct node));
    if(p!=NULL) return p;
    else
    {
        printf("Memory could not be allocated\n");
        exit(0);
    }
}

NODE insertfront(int item, NODE head)
{
    NODE p;
    p = getnode();
    p -> data = item;
    p -> next = head;
    head = p;
    return head;
}

void display(NODE head)
{
    NODE p;
    if(head==NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    p = head;
    while(p!=NULL)
    {
        printf("%d, ", p->data);
        p = p->next;
    }
    printf("\b\b \n");
}

void insertend(int item, NODE head)
{
    NODE p, q;
    q = getnode();
    q->data = item;
    p = head;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = q;
    q->next = NULL;
}

NODE insertpos(NODE head, int item, int pos)
{
    NODE curr, prev = NULL, newn;
    int count = 1;
    newn = getnode();
    newn->data = item;
    newn->next = NULL;
    if(head==NULL)
    {
        if(pos==1) return newn;
        else {
            printf("Invalid posn\n");
            return head;
        }
    }
    if (pos==1)
    {
        newn->next = head;
        head = newn;
        return head;
    }
    else
    {
        curr = head;
        while(curr!=NULL && count != pos)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        if(count == pos)
        {
            prev->next = newn;
            newn ->next = curr;
            return head;
        }
        else{
            printf("\nInvalid position\n");
            return head;
        }
    }
}



int main()
{
    NODE head = NULL;
    int op, ele, pos, value;
    while(1)
    {
        printf("1: Insert from front\n2:Insert from end\n3:Insert at some position\n4: Display\n5: Exit program\n");
        printf("Enter option:  ");
        scanf("%d", &op);
        switch(op)
        {
            case 1: {
                printf("Enter element to be inserted\n");
                scanf("%d", &ele);
                head = insertfront(ele, head);
                break;
                }
            case 2: {
                printf("Enter element: \n");
                scanf("%d", &ele);
                insertend(ele, head);
                break;
            }
            case 3: {
                printf("Enter position(1 indexed) and value:  \n");
                scanf("%d %d", &pos, &value);
                head = insertpos(head, value, pos);
                break;
            }
            case 4: {
                printf("Elements in the singly linked list are:   \n");
                display(head);
                break;
            }
            case 5: exit(0);
            default: printf("Invalid option :(\n");
        }
        
    }
    return 0;
}