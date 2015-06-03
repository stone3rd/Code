/*
brief:求最长非降子序列长度
eg: 5,3,4,8,6,7
*/

#include <stdio.h>
#include <stdlib.h>

#define N 6

int L[N] = {5,3,4,8,6,7};

int main()
{
	int i,j,mlen = 0,tmp= 0;
	int d[N+1] = {0};
	
	for(i = 0; i < N; i++)
	{
		for(j = 0; j <= i; j++)
		{
			//这里是否可以优化一下？ 
			if(L[i] >= L[j])
			{
				tmp = d[j] + 1;
			}
			else
			{
				tmp = d[j];
			}
			mlen = tmp>mlen ? tmp:mlen;
		}
		d[i] = mlen;
		printf("d[%d]=%d\n",i,d[i]);
	}
	printf("d[%d]=%d\n",N-1,d[N-1]);
	return 0;
}
