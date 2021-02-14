//C program to do a DFS of an graph from the given starting node

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	struct node *next;
	int vertex;
}node;
node *G[20];
int visited[100];
int n;


void insert(int vi,int vj)
{
	node *p,*q;
	q=(node*)malloc(sizeof(node));
	q->vertex=vj;
	q->next=NULL;
	if(G[vi]==NULL)
		G[vi]=q;
	else
	{
		p=G[vi];
		while(p->next != NULL)
			p=p->next;
		p->next=q;
	}
}
void readgraph()
{
	int i,vi,vj,noe;
	printf("Enter no of vertices:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		G[i]=NULL;
	printf("Enter The no of edges:");
	scanf("%d",&noe);
	for(i=0;i<noe;i++)
	{
		printf("Enter an edge (u,v):");
		scanf("%d%d",&vi,&vj);
		insert(vi,vj);
		insert(vj,vi);
	}
}

void DFS(int i)
{
	node *p;
	visited[i]=1;
	printf("\t%d",i);
	for(p=G[i];p;p=p->next)
		if(!(visited[p->vertex]))
			DFS(p->vertex);
}

int main()
{
	int i,ch;
	while(1)
	{
		printf("\n 1.Create \n 2.DFS \n 3.Quit \n ");
		printf("Enter Your Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : readgraph();
				 break;
			case 2 : for(i=0;i<n;i++)
					 visited[i]=0;
				 printf("Enter The Starting Node:");
				 scanf("%d",&i);
				 DFS(i);
				 break;

			case 3 : exit(0);
				 break;


		}
	}
}
