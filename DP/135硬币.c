#include <stdio.h>
#include <stdlib.h>
/*
brief:有1,3,5三种面值的硬币。 问最少用用几个硬币可以凑成N元。 
*/
#define N 11 

int coin[3] = {1,3,5};
int d[N+1];

int min(int *a)
{
	int i,minvol;
	minvol = a[0];
	
	for(i = 1; i < 3; i++)
	{
		if((a[i] < minvol)&&(a[i]!= 0))
		{
			minvol = a[i];
		}
	}
	return minvol;
}

int main()
{
	int i,j;
	int tmp[3]= {0,0,0};
	
	for(i = 1; i < N+1; i++)
	{
		for(j = 0;j <3; j++)
		{
			if(i >= coin[j])
			{
				tmp[j] = d[i - coin[j]] + 1;
				//printf("tmp[%d]:%d ",j,tmp[j]);
			}
		}
		printf("\n");
		d[i] = min(tmp);
		printf("d[%d]:%d ",i,d[i]);
	}
	return 0;
}