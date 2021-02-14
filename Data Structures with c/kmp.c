//C program to do pattren matching using kmp algorithm

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int failure[20];

void fail(char *pat)
{
	int n = strlen(pat);
	int i,j;
	failure[0]=-1;
	for(j=1;j<n;j++)
	{
		i = failure[j-1];
		while((pat[j] != pat[i-1] ) && (i>=0))
			i = failure[i];
		if(pat[j] == pat[j-1])
			failure[j] = i+1;
		else
			failure[j] = i;
	}
}


int match(char *string, char *pat)
{
	int lens=strlen(string);
	int lenp=strlen(pat);
	int i=0,j=0;
	while(i<lens && j<lenp)
	{
		if(string[i] == pat[j]){
			i++;
			j++;
		}
		else if(j == 0){
			i++;
		}
		else
			j=failure[j-1]+1;
	}
	return ((j==lenp)?(i-lenp):-1);
}

void main(){
	int i;
	char str[30],sub[20];
	printf("Enter a String :");
	scanf("%s",str);
	printf("Enter a Substring :");
	scanf("%s",sub);
	fail(sub);
	i=match(str,sub);
	if(i==-1)
		printf("Not Found \n");
	else
		printf("Found At position %d",i+1);
}

