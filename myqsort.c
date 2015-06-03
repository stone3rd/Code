#include <stdio.h>
#include <stdlib.h>

#define SWAP(a,b) {\
	int tmp;\
	tmp = (a);\
	(a) = (b);\
	(b) = tmp;\
}

void quick_sort(int *ptr, char len);
uint8 partition(int *ptr,uint8 len);

uint8 partition(int *ptr, uint8 len)
{
	uint8 i,k;
	int pivot;

	i = 0;
	k = len-1;
	pivot = *ptr;

	while(1)
	{
		while((pivot >= (*(ptr + i)))&&(i<k))
		{
			i++;
		}
		while((pivot < (*(ptr+k)))&&(i<k))
		{
			k--;
		}
		if(i>=k)
		{
			break;
		}
		else
		{
			SWAP(*(ptr+i),*(ptr+k));
		}
	}
	if(pivot >= *(ptr+i))
	{
		SWAP(*ptr,*(ptr+i));
	}
	return i;
}

void quick_sort(int *ptr, char len)
{
	uint8 left_len;
	
	if(len<=1)
		return;
	left_len = partition(ptr,len);
	
	quick_sort(ptr,left_len);
	quick_sort(ptr+left_len,len-left_len);
}

int main()
{
	int i;
	int ary[10] = {2,4,2,5,3,5,3,1,7,6};
	
	quick_sort(ary,10);
	for(i=0;i<10;i++)
	{
		printf("%d ",ary[i]);
	}
	printf("\n");
  return 0;
}