/*
*����һ�� n λ��������Ҫɾ�����е� k λ���������ɾ������ʹ��ʣ�µ������
*���統��Ϊ 2319274�� k=1 ʱ��ɾȥ 2 ��� 319274 ���ǿ��ܵ����ֵ��
*/

#include <stdio.h>
#include <stdlib.h>

/*
*@fn		ProcData
*
*@brief
*
*@param		num:Ҫ���������
			bit:Ҫɾ����λ�� 
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
