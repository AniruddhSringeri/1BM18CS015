#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
};

struct node* getnode(int data)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->lchild = newnode->rchild = NULL;
	return newnode;
}

struct node* insert(struct node* root, int key) 
{ 
    if (root == NULL) return getnode(key); 
  
    if (key < root->data) 
        root->lchild  = insert(root->lchild, key); 
    else if (key > root->data) 
        root->rchild = insert(root->rchild, key);    
  
    return root; 
} 

void display(struct node* root) 
{ 
    int h = height(root); 
    for (int i=1; i<=h; i++) 
    { 
        DisplayGivenLevel(root, i); 
        printf("\n"); 
    } 
} 

void DisplayGivenLevel(struct node* root, int level) 
{ 
    if (root == NULL) 
        return; 
    if (level == 1) 
        printf("%d ", root->data); 
    else if (level > 1) 
    { 
        DisplayGivenLevel(root->lchild, level-1); 
        DisplayGivenLevel(root->rchild, level-1); 
    } 
} 
	
int height(struct node* root)  
{ 
   if (root == NULL)  
       return 0; 
   else 
   { 
       
       int lheight = height(root->lchild); 
       int rheight = height(root->rchild); 
  
       if (lheight > rheight)  
           return(lheight+1); 
       else return(rheight+1); 
   } 
}  

void inorder(struct node* root)
{
	if(root == NULL) return;
	inorder(root->lchild);
	printf("%d, ", root->data);
	inorder(root->rchild);
}

void preorder(struct node* root)
{
	if(root == NULL) return;
	printf("%d, ", root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}

void postorder(struct node* root)
{
	if(root == NULL) return;
	postorder(root->lchild);	
	postorder(root->rchild);	
	printf("%d, ", root->data);
}

int main()
{
	struct node* root = NULL;	
	int ch, n;
	printf("Binary Search Tree\n");
	do
	{
		printf("Insert: 1\nDisplay: 2\nPreorder: 3\nInorder: 4\nPostorder: 5\nEnter your choice:   ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: {
					printf("Enter the value to be inserted:   ");
					scanf("%d", &n);
					root = insert(root, n);
					break;
				} 
			
			case 2: {
					display(root);
					break;
				}
			
		
			case 3: {
					printf("The elements of the BST in preorder are:    ");
					preorder(root);
					printf("\b\b \n");
					break;
				}	

			case 4: {
					printf("The elements of the BST in inorder are:    ");
					inorder(root);
					printf("\b\b \n");
					break;
				}	
	
			case 5: {
					printf("The elements of the BST in postorder are:    ");
					postorder(root);
					printf("\b\b \n");
					break;
				}
		} 

	}while(1);
}
									




































