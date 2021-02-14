//C program to perform operations on max heap

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 50
typedef struct{
       int key;
}element;
element heap[MAX_SIZE];

void insert(element item,int *n)
{
	int i;
	if((*n) == MAX_SIZE-1)
	{
		printf("Heap full...\n");
		return;
	}
	i=++(*n);
	while((i!=1) && item.key > heap[i/2].key)
	{
		heap[i] = heap[i/2];
		i/=2;
	}
	heap[i]=item;
}

element deleteHeap(int *n)
{
	int parent,child;
	element temp,item;
	parent =1;
	child = 2;
	if(*n==0)
	{
		printf("\nHeap Empty...\n");
		item.key=-1;
		return item;
	}
	item = heap[1];
	temp = heap[(*n)--];
	while(child <= *n)
	{
		if(child < *n && heap[child].key< heap[child+1].key)
			child++;
		if(temp.key >= heap[child].key)
			break;
		heap[parent]=heap[child];
		parent =child;
		child*=2;
	}
	heap[parent]=temp;
	return item;
}

element display(int n)
{
	int i;
	for(i=1;i<=n;i++){
		printf("%d\t",heap[i].key);
	}
	printf("\n");
}


int main()
{
	int choice,n=0;
	element item;
	while(1)
	{
		printf(" 1.Insert \n 2.Display \n 3.Delete \n 4.Quit \n");
		printf("\nEnter Your Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter element to insert:");
				scanf("%d", &item.key);
				insert(item, &n);
				break;

			case 2:
				display(n);
				break;

			case 3:
				item = deleteHeap(&n);
				if(item.key!=-1)
				printf("\nElement Deleted: %d\n",item.key);
				break;

			case 4: exit(0);
		}
		
	}
	return 0;
}

