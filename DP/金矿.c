#include <stdio.h>
#include <stdlib.h>

#define N 5
#define C 10
/*
//4,10 19
int V[N] = {4,3,5,2,5};//大小 
int W[N] = {9,6,1,4,1};//价值 
*/
/*
//4,9 40
int V[N] = {4,3,4,2};
int W[N] = {20,6,20,4};
*/

//5,10 15 
int V[N] = {2,2,6,5,4};
int W[N] = {6,3,5,4,6};

int d[N][C];
int main()
{
	int i,j;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < C; j++)
		{
			d[i][j] = i==0? 0:d[i-1][j];
			if(((d[i-1][j-V[i]]+W[i]) > d[i-1][j])&&(j >= V[i]))
			d[i][j] = d[i-1][j-V[i]]+W[i];
		}
	}
	printf("%d\n",d[N-1][C-1]);
	
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < C; j++)
		{
			printf("%2d ",d[i][j]);
		}
		printf("\n");
	}
	for(i = 0; i < 128; i++)
	{
		printf("%c ",i);
	}
	return 0;
}
