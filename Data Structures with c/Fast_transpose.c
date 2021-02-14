//C program to find transpose of a sparse matrix by fast Transpose method

#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int row,col,value;
}term;

void transpose(term a[],term b[])
{
	int i,j,row_terms[50],start_pos[50];
	int numCols=a[0].col,numTerms=a[0].value;
	b[0].row=a[0].col;
	b[0].col=a[0].row;
	b[0].value=numTerms;
	if(numTerms > 0)
	{
		for(i=0;i<numCols;i++)
			row_terms[i]=0;
		for(i=1;i<=numTerms;i++)
			row_terms[a[i].col]++;
		start_pos[0]=1;
		for(i=1;i<numCols;i++)
			start_pos[i] = start_pos[i-1]+row_terms[i-1];
		for(i=1;i<=numTerms;i++)
		{
			j=start_pos[a[i].col]++;
			b[j].row=a[i].col;
			b[j].col=a[i].row;
			b[j].value=a[i].value;
		}
	}
	printf("\nTranspose Matrix\n");
	for(i=1;i<=b[0].value;i++)
		printf("%d\t%d\t%d\n",b[i].row,b[i].col,b[i].value);
}

void main()
{
	term a[50],t[50];
	int i;
	printf("\nEnter the number of rows and columns\n");
	scanf("%d%d",&a[0].row,&a[0].col);
	printf("\nEnter the number of values\n");
	scanf("%d",&a[0].value);
	for(i=1;i<=a[0].value;i++)
	{
		printf("\nEnter %dth row, column and element values\n",i);
		scanf("%d%d%d",&a[i].row,&a[i].col,&a[i].value);
	}
	printf("\nOriginal Matrix\n");
	for(i=1;i<=a[0].value;i++)
		printf("%d\t%d\t%d\n",a[i].row,a[i].col,a[i].value);
	transpose(a,t);
}
