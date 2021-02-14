//C program to perform operations on dynamic circular queue

#include<stdio.h>
#include<stdlib.h>
#define MALLOC(x,size,type)(x=(type*)malloc(size*sizeof(type)))
typedef struct {
	int data;
}element;

element *queue;

int front=0,rear=0,capacity;

void copy(element *start,element *end,element *newQueue)
{
	element* i=start;
	element* j=newQueue;
	for(;i<end;i++,j++)
		*j=*i;
}


void queuefull()
{
	element *newQueue;
	MALLOC(newQueue,2*capacity,element);
	int start = (front+1)%capacity;
	if(start<2)
		copy(queue+start,queue+start+capacity-1,newQueue);
	else
	{
		copy(queue+start,queue+capacity,newQueue);
		copy(queue,queue+rear+1,newQueue+capacity-start);
	}
	front = 2*capacity-1;
	rear = capacity-1;
	capacity*=2;
	free(queue);
	queue = newQueue;
}

void insert(element item)
{
	rear = (rear+1)%capacity;

	if(front == rear)
		queuefull();
	queue[rear] = item;
}

element delete()
{
	element item;
	if(front==rear){
		item.data=-1;
		return item;
	}
	front = (front+1)%capacity;
	return queue[front];
}

void display()
{
	int i;
	if(front == rear){
		printf("Queue Empty.......\n");
		return;
	}
	
	for(i=(front+1)%capacity ; i!=rear ; i=(i+1) % capacity)
		printf("%d\t",queue[i].data);
	printf("%d",queue[i].data);
	printf("\n");
	printf("Front: %d Rear: %d\n", front, rear);     

}
int main()
{
	int ch;
	element item;
	printf("Enter intial Size:");
	scanf("%d",&capacity);
	MALLOC(queue,capacity,element);

while(1){
		printf(" 1.ADD \n 2.DELETE \n 3.DISPLAY \n 4.QUIT\n");
		printf("Enter the choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:  printf("Enter item to add:");
			 	 scanf("%d",&item.data);
				 insert(item);
				 break;
			case 2: item=delete();
				if(item.data==-1)
			  		printf("Queue Empty..........\n");
			  	else
			  		printf("Item deleted: %d\n", item.data);
			  	break;
			case 3:display();
			       break;
			case 4:exit(0);
			       break;
			default : printf("Invalid input....\n");
		}
	}
}
	
