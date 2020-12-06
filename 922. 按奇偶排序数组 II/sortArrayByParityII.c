/*
����һ���Ǹ���������A�� A ��һ��������������һ��������ż����
��������������Ա㵱A[i] Ϊ����ʱ��iҲ����������A[i]Ϊż��ʱ��iҲ��ż����
����Է����κ���������������������Ϊ�𰸡�

ʾ����
���룺[4,2,5,7]
�����[4,5,2,7]
���ͣ�[4,7,2,5]��[2,5,4,7]��[2,7,4,5] Ҳ�ᱻ���ܡ�

��ʾ��
2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000

����˼·��
1.��ϣ��
2.�±� = A[i] % 2 + A[i]��Ӧ��˫�������� * 2
3.��˫�����������ü�����ʵ��
*/

#include <stdio.h>
#include <stdlib.h>

/*
Note: The returned array must be malloced, assume caller calls free().
*/
int* sortArrayByParityII(int* A, int ASize, int* returnSize){
	int i, j; //��λ��
	int oddnum, evennum; //��˫��������
	int remainder; //����
	int *result; //�������
	
	result = (int*)malloc(sizeof(int)*ASize);
	oddnum = 0;
	evennum = 0;
	
	for (i = 0; i < ASize; i++)
	{
		remainder = A[i]%2; //����
		if (remainder == 0) //ż��
		{
			j = remainder + evennum*2;
			result[j] = A[i];
			evennum++; //ż����һ
		}
		else
		{
			j = remainder + oddnum*2;
			result[j] = A[i];
			oddnum++; //������һ
		}
	}
	
	*returnSize = ASize;
	return result;
}

int main (void)
{
	int A[4] = {4, 2, 5, 7};
	int ASize=4, returnSize, i;
	int *result;
	
	result = sortArrayByParityII(A, ASize, &returnSize);
	
	for (i = 0; i < returnSize; i++)
		printf ("%d ", result[i]);
}
