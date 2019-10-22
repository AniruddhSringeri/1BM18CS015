//doubly linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* getnode()
{
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->next = NULL;
    p->prev = NULL;
    return p;
}

struct node* insertfront(struct node* head, int item)
{
    struct node* p = getnode();
    p->data = item;
    if(head == NULL)
    {
        head = p;
        return head;
    }
    p->next = head;
    head->prev = p;
    head = p;
    return head;
}

struct node* insertend(struct node* head, int item)
{
    struct node* p = getnode();
    p->data = item;
    if(head == NULL)
    {
        head = p;
        return head;
    }
    struct node* ptr = head;
    while(ptr->next)
    {
        ptr = ptr->next;
    }
    ptr->next = p;
    p->prev = ptr;
    return head;
}

//this function inserts a new node to the left of a specified node
struct node* insertleft(struct node* head, int item, int numToRight)
{
    struct node* newnode = getnode();
    newnode->data = item;
    struct node* ptr = head;
    while(ptr->data != numToRight)
    {
        if(ptr->next == NULL)
        {
            printf("Error :( Such node not found in list.\n");
            return head;
        }
        ptr = ptr->next;
    }
    if(ptr == head)
    {
        newnode->next = ptr;
        ptr->prev = newnode;
        head = newnode;
        return head;
    }
    newnode->next = ptr;
    newnode->prev = ptr->prev;
    ptr->prev->next = newnode;
    ptr->prev = newnode;
    return head;
}

struct node* deleteval(struct node* head, int val)
{
    struct node* ptr = head;
    if(head == NULL)
    {
        printf("List is empty :( \n");
        return head;
    }
    if(ptr->data == val)
    {
        ptr->next->prev = NULL;
        head = ptr->next;
        free(ptr);
        return head;
    }
    while(ptr->data != val)
    {
        if(ptr->next == NULL)
        {
            printf("Value not found :(\n");
            return head;
        }
        ptr = ptr->next;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
    return head;
}

void display(struct node* head)
{
    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node* ptr = head;
    printf("The list is:  ");
    while(ptr)
    {
        printf("%d <=> ", ptr->data);
        ptr = ptr->next;
    }
    printf("\b\b\b\b\b    \n");
}

int main()
{
    int ch, n, x;
    struct node* head = NULL;
    printf("Doubly linked list program having functions to insert from front, end, & to the left of an element, to delete a value from linked list, and to display the whole linked list.\n");
    do
    {
        printf("1: Insert from front\n2: Insert from end\n3: Insert to the left of an element of your choice\n4: Delete a value\n5: Display the linked list\n6: Exit\nEnter your choice:  ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: {
                printf("Enter the number to be inserted:  ");
                scanf("%d", &n);
                head = insertfront(head, n);
                break;
            }
            case 2: {
                printf("Enter the number to be inserted:  ");
                scanf("%d", &n);
                head = insertend(head, n);
                break;
            }
            case 3: {
                printf("Which element do you wish to insert an element to the left of ???  ");
                scanf("%d", &n);
                printf("Enter number to be inserted:  ");
                scanf("%d", &x);
                head = insertleft(head, x, n);
                break;
            }
            case 4: {
                printf("Which element do you want to delete ???  ");
                scanf("%d", &n);
                head = deleteval(head, n);
                break;
            }
            case 5: {
                display(head);
                break;
            }
            case 6: exit(0);
            default: printf("Invalid input :(\n");
        }
    }while(1);
}