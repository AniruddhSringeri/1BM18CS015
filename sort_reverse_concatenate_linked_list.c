#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* getnode(int item)
{
	struct node* newn = (struct node*)malloc(sizeof(struct node));
	newn->data = item;
	newn->next = NULL;
	return newn;
}

void display(struct node* head)
{
	if(head == NULL)
	{
		printf("List is empty.\n");
		return;
	}
	struct node* ptr = head;
	while(ptr)
	{
		printf("%d->", ptr->data);
		ptr = ptr->next;
	}
	printf("\b \b\b \n");
}

struct node* insertfront(struct node* head, int item)
{
	struct node* newn = getnode(item);
	newn->next = head;
	head = newn;
	return head;
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


struct node* sort (struct node* head)
{
	int sorted;
	if(head == NULL) return head;
	struct node* ptr = head;
	do
	{
		ptr = head;
		sorted = 0;
		while(ptr->next)
		{
			if(ptr->data > ptr->next->data)
			{
				swap(&ptr->data, &ptr->next->data);
				sorted = 1;
			}
			ptr = ptr->next;
		}
	} while(sorted == 1);
	return head;
}

void reverse(struct node** head) 
{ 
    struct node* prev = NULL; 
    struct node* current = *head; 
    struct node* next = NULL; 
    while (current != NULL) { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    *head = prev; 
} 

struct node* concatenate(struct node* head1, struct node* head2)
{
	struct node* ptr = head1;
	while(ptr->next)
	{
		ptr = ptr->next;
	}
	ptr->next = head2;
	return head1;
}

int main()
{
	printf("Linked list program containing sort, reverse, and concatenate functions.\n");
	int n1, n2, n, ch, flag = 0;
	struct node* head1 = NULL; struct node* head2 = NULL;
	do 
	{
		printf("Enter 1: Linked list 1\n2: Linked list 2\n3: Exit\n");
		scanf("%d", &n1);
		switch(n1)
		{
			case 1: 
				{
					do
					{
						printf("Enter 1: Insert from front\n2: Sort\n3: Reverse\n4: Concatenate with list 2\n5: Display list\n6: Go back to main menu\n7: Exit\n");
						scanf("%d", &n2);
						switch(n2)
						{
							case 1: {
									printf("Enter item to be inserted:  ");
									scanf("%d", &n);
									head1 = insertfront(head1, n);
									break;
							        }
							case 2: {
									head1 = sort(head1);
									break;
								}
							case 3: {
									reverse(&head1);
									break;
								}
							case 4: {
									head1 = concatenate(head1, head2);
									break;
								}
							case 5: {
									display(head1);
									break;
								}
							case 6: {
									flag = 1;
									break;
								}
							case 7: {
									exit(0);
								}
							default: printf("Invalid input.\n");
						}
						if(flag == 1)
						{
							break;
						}
					}while(1);
					break;
				}
			case 2: {
					flag = 0;
					do
					{
						printf("Enter 1: Insert from front\n2: Sort\n3: Reverse\n4: Concatenate with list 1\n5: Display list\n6: Go back to main menu\n7: Exit\n");
						scanf("%d", &n2);
						switch(n2)
						{
							case 1: {
									printf("Enter item to be inserted:  ");
									scanf("%d", &n);
									head2 = insertfront(head2, n);
									break;
							        }
							case 2: {
									head2 = sort(head2);
									break;
								}
							case 3: {
									reverse(&head2);
									break;
								}
							case 4: {
									head2 = concatenate(head2, head1);
									break;
								}
							case 5: {
									display(head2);
									break;
								}
							case 6: {
									flag = 1;
									break;
								}
							case 7: {
									exit(0);
								}
							default: printf("Invalid input.\n");
						}
						if(flag == 1)
						{
							flag = 0; break;
						}
					}while(1);
					break;
				}
			case 3: exit(0);
			default: printf("Invalid input.\n");
		}
	}while(1);
	return 0;
}
							
		

