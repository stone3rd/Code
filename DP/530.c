/*
����һ����ΪiӢ��ĸ����ļ۸�ΪPi���������Ⱦ�Ϊ��������Ŀ�����£�
����i	1	2	3	4	5	6	7	8	9	10
�۸�Pi	1	5	8	9	10	17	17	20	24	30
*/

#include <stdio.h>
#include <stdlib.h>

#define L 5	//�������� 

int P[11] = {0,1,5,8,9,10,17,17,20,24,30};
int d[L+1];

int max(int a,int b)
{
	return (a>b)? a:b;
}

int main()
{
	int i,j,tmp = 0;
	
	for(i = 0; i < L+1; i++)
	{
		tmp = 0;
		for(j = 0 ; j < i; j++)
		{
			tmp = max(tmp,P[j]+P[i-j]);
		}
		d[i] = tmp;
		printf("d[%d]:%d\n",i,d[i]);
	}
	printf("%d\n",d[L]);
	return 0;
}