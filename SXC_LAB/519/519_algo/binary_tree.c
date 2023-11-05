#include<stdio.h>
#include<stdlib.h>


void create_binary_tree(int);
void rec_inorder();

//void inorder(int);


/*
void allocateStack(int);
void push(NODE);
int pop();
*/



typedef struct tree
{
	int key;
	struct tree *left,*right;
} NODE;

NODE *root=NULL;
//int *stack, top = -1, stackSize;


int main()
{
  int n,i,k;
  printf("How many elements are to be inserted?: ");
  scanf("%d",&n);
  for (i=0;i<n;i++)
  {
  		printf("\nEnter the element number %d:\t",i+1);
  		scanf("%d",&k);
  		create_binary_tree(k);
  }
	rec_inorder();
	return 0;
}



void create_binary_tree(int k)
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
		printf("\n%d will be at the left or right sub tree of %d (0/1):\t",k,q->key);
		scanf("%d",&ch);
		if(ch)
		{
			q=q->right;
		}
		else
		{
			q=q->left;
		}
	}
	
	if(ch)
	{
		r->right=p;
	}
	else
	{
		r->left=p;
	}

}



void rec_inorder()
{
	NODE *p=root;
	if(p)
	{
		rec_inorder(p->left);
		printf("\t%d\t",p->key);
		rec_inorder(p->right);
	}

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




