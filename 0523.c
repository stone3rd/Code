/*
*现有一个 n 位数，你需要删除其中的 k 位，请问如何删除才能使得剩下的数最大？
*比如当数为 2319274， k=1 时，删去 2 变成 319274 后是可能的最大值。
*/

#include <stdio.h>
#include <stdlib.h>

/*
*@fn		ProcData
*
*@brief
*
*@param		num:要处理的数字
			bit:要删除的位数 
*
*@return	char
*/
int ProcData(int num, char bit)
{
	char buf[10];
	char tmp,i,j;
	int res;
	
	tmp = bit;
	
	itoa(num,buf,10);
	if(strlen(buf) < bit)
	{
		printf("bit error\n");
		return -1;
	}
	
	while(tmp)
	{
		for(i = 0; i < strlen(buf); i++)
		{
			if(buf[i]<buf[i+1])
			{
				break;
			}
		}
		
		for(j = i; j < strlen(buf) - i-1; j++)
		{
			buf[j] = buf[j+1];
		}
		buf[j+1] = '\0';
		tmp--;
	}
	
	res = atoi(buf);
	return res;	
}


int main()
{
	int res;
	
	printf("LINE:%d\n",__LINE__);
	
	printf("n = 2319274 ,k = 2\n");
	res = ProcData(2319274,2);
	
	printf("result = %d\n",res);
	return 0;
}
