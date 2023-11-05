#include<stdio.h>
#include<stdlib.h>


void create_bst(int);

typedef struct tree
{
	int key;
	struct tree *left,*right;
} NODE;

NODE *root=NULL;
void inorder(NODE *root);



int main()
{
  int n,i,k;
  printf("How many elements are to be inserted?: ");
  scanf("%d",&n);
  for (i=0;i<n;i++)
  {
  		printf("\nEnter the element number %d:\t",i+1);
  		scanf("%d",&k);
  		create_bst(k);
  }
  inorder(root);
	return 0;
}



void create_bst(int k)
{
	NODE *p=(NODE*) malloc (sizeof(NODE));
	NODE *r,*q=root;
	int ch;
	
	p->key=k;
	p->left=NULL;
	p->right=NULL;
	
	if(!root)
	{
		root=p;
		return;
	}
	
	
	while(q)
	{
		r=q;
		
		if(k>q->key)
		{
			q=q->right;
			r->right=p;
			printf("\nright insertion");
		}
		else
		{
			q=q->left;
			r->left=p;
			printf("\nleft insertion");
		}
	}
	

}







void inorder(NODE *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("\n%d",root->key);
		inorder(root->right);
	}
	printf("\n");

}























/*

void inorder(int n)
{
	allocateStack(n);
	NODE *p=root;
		while(p)
		{
			push(p);
			push(p->key);
			p=p->left;
		}
		p=pop();
		printf("%d\t",p->key);
		p=p->right;
	


}



void allocateStack(int n)
{
	stackSize = n;
	stack = (int *)malloc(stackSize * sizeof(int));
}


void push(NODE)
{
	if(top == -1)
	{
		
		stack[top++] = element;
	}
	else if (top >= stackSize)
		printf("Stack Overflow !!");
	else
		stack[top++] = element;
}

int pop()
{
	int temp = -999;
	if(top == -1)
		printf("Stack is empty !!");
	else
	{
		temp = stack[top];
		top--;
	}
	
	return temp;
}


*/




