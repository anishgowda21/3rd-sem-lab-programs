//C program to perform operations on circular doubly linked list

#include<stdio.h>
#include<stdlib.h>
typedef struct node* nodeptr;
typedef struct node{
	int data;
	nodeptr llink;
	nodeptr rlink;
}node;

nodeptr head;


void insert()
{
	int n;
	nodeptr temp;
	temp = (nodeptr)malloc(sizeof(node));
	printf("Enter the element to be inserted:");
	scanf("%d",&n);
	temp->data = n;
	if(head ->rlink == head)
	{
		temp->llink=head;
		temp->rlink=head;
		head->llink=temp;
		head->rlink=temp;
	}
	else
	{
	temp->rlink=head;
	temp->llink=head->llink;
	head->llink->rlink=temp;
	head->llink=temp;
	}
}

void delete()
{
	if(head ->rlink == head){
		printf("List is empty..");
		return;
	}
	nodeptr temp;
	temp = head ->rlink;
	head->rlink = temp->rlink;
	temp ->rlink ->llink =head;
	printf("deleted data  %d\n",temp->data);
	free(temp);
}


void printfirst()
{
	if(head -> rlink == head)
	{
		printf("List empty...");
		return;
	}
	nodeptr temp;
	for(temp = head->rlink;temp !=head ; temp = temp->rlink)
		printf("%d\t",temp -> data);
	printf("\n");
}

void printlast()
{
	if(head -> rlink == head)
	{
		printf("List empty...");
		return;
	}
	nodeptr temp;
	for(temp = head->llink ; temp !=head ; temp=temp->llink)
		printf("%d\t",temp->data);
        printf("\n");
}

int main()
{
	int c;
	head = (nodeptr)malloc(sizeof(node));
	head ->llink=head;
	head ->rlink = head;
	while(1)
	{
		printf("1.Insert\n2.Delete\n3.Reverse Display\n4.forward Display\n5.Exit\nEnter your choice:");
                scanf("%d",&c);
                switch(c)
                {
			case 1 : insert();
				 break;

			case 2:delete();
                                break;
                        case 3:printlast();
                                break;
                        case 4:printfirst();
                                break;
                        case 5:exit(0);
                }
        }
        return 0;
}
