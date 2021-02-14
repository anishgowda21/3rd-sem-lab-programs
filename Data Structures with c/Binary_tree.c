//C program to perform operations on binary tree

#include<stdio.h>
#include<stdlib.h>

struct tree{
	int data;
	struct tree *llink;
	struct tree *rlink;
};

typedef struct tree* treeptr;

void insert(treeptr *root,int item)
{
	if(!(*root))
	{
		*root = (treeptr)malloc(sizeof(treeptr*));
		(*root)->data=item;
		(*root)->llink=NULL;
		(*root)->rlink=NULL;
	}
	else if((*root)->data > item)
		insert(&((*root)->llink),item);
	else if((*root)->data < item)
		insert(&((*root)->rlink),item);
}

void inorder(treeptr root)
{
	if(root)
	{
		inorder(root->llink);
		printf("%d\t",root->data);
		inorder(root->rlink);
	}
}

void search(treeptr root,int item)
{
	if(root == NULL)
	{
		printf("Not found....\n");
		return;
	}
	else if(root->data == item)
	{
		printf("Found..\n");
		return;
	}
	else if(root->data > item)
	{
		search(root->llink,item);
	}
	else if(root->data < item)
		search(root->rlink,item);
}


int main(){
	int ch,item;
	treeptr root;
	root=NULL;
	while(1)
	{
		printf(" 1.Insert \n 2.In Order Traversal \n 3.Search \n 4.Exit \n");
		printf("\nEnter the Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter element to be inserted:");
				scanf("%d",&item);
				insert(&root,item);
				break;
			case 2:
				inorder(root);
				printf("\n");
				break;
			case 3:
				printf("\nEnter element to be Searched:");
				scanf("%d",&item);
				search(root,item);
				break;
			case 4:
				exit(1);
		}
	}
	return 0;
}

