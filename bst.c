/*Description:Implementation of Binary Search Tree
 * Learner:Shaikh Altamas shakeel
 * Roll no:16co11
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct bst
{
	int data;
	struct bst *left,*right;
}node;

void insert(node **r,int num)
{
	node *temp,*ptr;
	temp=*r;
	if(temp==NULL)
	{	
		ptr=(node*)malloc(sizeof(node));
		ptr->data=num;
		ptr->left=NULL;
		ptr->right=NULL;
		*r=ptr;
	}
	else
	{
		if(num > temp->data)
		{
				insert(&temp->right,num);
		}
		else
		{
			insert(&temp->left,num);
		}
	}
}

void traverse_inorder(node *q)
{
	if(q!=NULL)
	{
		traverse_inorder(q->left);
		printf("%d\t",q->data);
		traverse_inorder(q->right);
	}
}

int search_bst(node *q,int num)
{
	if(q==NULL)
		return 0;
	else
	{
		if(q->data==num)
			return 1;
		else
		{
			if(num>q->data)
			{	
				return search_bst(q->right,num);
				return search_bst(q->left,num);
			}
		}
	}
}

void search_node(node **x,node *root,node **parent,int num,int *f)
{
	node *temp;
	temp=root;
	if(temp==NULL)
		return;
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
		*f=1;
		*x=temp;
		return;
		}
	*parent=temp;
	if(num>temp->data)
		temp=temp->right;
	else
		temp=temp->left;
	}
}

void delete(node **r,int num)
{
	node *temp,*parent,*xsucc,*x;
	int f=0;
	parent=NULL;x=NULL;xsucc=NULL;
	temp=*r;
	search_node(&x,temp,&parent,num,&f);
		if(f==0){
		printf("\nTHE ELEMENT %d IS NOT FOUND");
		return;
	}
	//x has no child
	if(x->left==NULL && x->right==NULL)
	{
		if(x->data > parent->data)
			parent->right=NULL;
		else
			parent->left=NULL;
	}
	//x has left child
	else if(x->left!=NULL && x->right==NULL)
	{
		if(x->data > parent->data)
			parent->right=x->left;
		else
			parent->left=x->left;
	}
	//x hAS right child
	else if(x->right!=NULL && x->left==NULL)
	{
		if(x->data > parent->data)
			parent->right=x->right;
		else
			parent->left=x->right;
	}
	//x has both left and right child
	else if(x->left!=NULL && x->right!=NULL)
	{
		parent=x;
		xsucc=x->right;
		while(xsucc->left!=NULL)
		{
			parent=xsucc;
			xsucc=xsucc->left;
		}
		if(xsucc->data > parent->data)
			parent->right=NULL;
		else
		{
			parent->left=NULL;
			x->data=xsucc->data;
			x=xsucc;
		}
	}free(x);
}

int main()
{
	node *root;
    int c,n,e,d,s,i;
	root=NULL;
	do
	{
		printf("ENETR\n1.INSERT\n2.DELETE\n3.SEARCH\n4.TRAVERSE INORDER\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("\nENTER HOW MANY NO YOU WANT TO INSERT\n");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					scanf("%d",&e);
					insert(&root,e);
				}
				break;
			case 2:
				printf("THE NO YOU WANT TO DELETE : ");
				scanf("%d",&d);
				delete(&root,d);
				break;
			case 3:
				printf("ENTER THE NO YOU WANT TO SEARCH : ");
				scanf("%d",&s);
				if(search(root,s)==1)
					printf("\n THE NUMBER %d IS PRESENT IN THE TREE\n",s);
				else
					printf("\n THE NUMBER %d IS IS NOT FOUND\n",s);
				break;
			case 4:
				traverse_inorder(root);
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("INVALID CHOICE!!");
		}
	}while(1);
	return 0;
}

