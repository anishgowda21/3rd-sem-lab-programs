//C program to implement multiple stacks and perform operations on them

#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int key;
}element;

struct stack{
	element data;
	struct stack *link;
};

typedef struct stack *stkptr;
stkptr top[20];

void push(element item,int i)
{
	stkptr temp=(stkptr)malloc(sizeof(stkptr*));
	temp->data = item;
	temp ->link = top[i];
	top[i] = temp;
}

element pop(int i)
{
	stkptr temp = top[i];
	element item;
	if(temp == NULL)
	{
		item.key=-1;
		return item;
	}
	item = temp->data;
	top[i] = temp->link;
	free(temp);
	return item;
}

void display(int i)
{
	stkptr temp=top[i];
	printf("\nStack Elements Are:");
	for(;temp;temp=temp->link)
		printf("%d\t",temp->data.key);
	printf("\n");
}

void main()
{
	int z,ch,i;
	element item;
	for(z=0;z<10;z++)
		top[z]=NULL;

	do{
		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
		printf("Enter Your Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			printf("\nEnter item to be inserted:");
			scanf("%d",&item.key);
			printf("\nEnter stack number:");
			scanf("%d",&i);
			push(item,i-1);
			break;
		case 2:
         		printf("\nEnter stack number from which you would like to pop element:");
			scanf("%d",&i);
			item=pop(i-1);
			if(item.key==-1)
				printf("\nEmpty stack.........\n");
			else
				printf("\nDeleted element:%d\n",item.key);
			break;
		case 3:
			printf("\nEnter stack number you would like to display:");
			scanf("%d",&i);
			display(i-1);
			break;
		case 4:
			break;
		default:
			printf("\nWrong choice......\n");
			break;
	}
	}while(ch!=4);
}


