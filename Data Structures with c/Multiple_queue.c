//C program to implement multiple queues and perform operations on them

#include<stdio.h>
#include<stdlib.h>


typedef struct{
	int n;
}element;

struct queue
{
	element data;
	struct queue *link;
};

typedef struct queue *queueptr;

queueptr front[20],rear[20];

void insert(element item,int i)
{
	queueptr temp;
	temp = (queueptr)malloc(sizeof(queueptr*));
	temp ->data = item;
	if (front[i])
	{
		rear[i]->link=temp;
	}
	else
		front[i]=temp;
	rear[i]=temp;
	rear[i]->link = NULL;
}


element delete(int i)
{
	queueptr temp;
	temp = front[i];
	element item;
	if(front[i])
	{
		item = temp->data;
		front[i] = temp->link;
	}
	else
		item.n=-1;
	free(temp);
	return item;
}

void display(int i)
{	
	queueptr temp;
	temp = front[i];
	if(!(front[i]))
	{
		printf("Queue is Empty\n");
		return;
	}
	printf("Queue is:");
	for(;temp;temp=temp->link)
		printf("%d\t",temp->data.n);
	printf("\n");
}


int main(){
	int choice,qno;
	element item;
	while(1){
		printf(" 1.Insert \n 2.Delete \n 3.Display \n 4.Quit \n");
		printf("Enter the Choice:");
		scanf("%d",&choice);
		if(choice != 4)
		{
			printf("Enter The Queue no from 1 to 10 : ");
			scanf("%d",&qno);
		}
		switch(choice)
		{
			case 1:
				printf("Enter Data to be inserted:");
				scanf("%d",&item.n);
				insert(item,qno-1);
				break ;
			case 2:
				item = delete(qno-1);
				if(item.n==-1)
					printf("Queue empty....\n");
				else
					printf("Element deleted:%d \n",item.n);
				break;
			case 3:
				display(qno-1);
				break;
			case 4: 
				exit(0);
			default : 
				printf("Invalid Input...");
		}
	}
}

