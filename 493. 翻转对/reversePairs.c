/*
493. ��ת��
����һ������ nums ����� i < j �� nums[i] > 2*nums[j]��
���Ǿͽ� (i, j) ����һ����Ҫ��ת�ԡ�
����Ҫ���ظ��������е���Ҫ��ת�Ե�������

ʾ�� 1:
����: [1,3,2,3,1]
���: 2

ʾ�� 2:
����: [2,4,3,5,1]
���: 3

ע��:
1. ��������ĳ��Ȳ��ᳬ��50000��
2. ���������е��������ֶ���32λ�����ı�ʾ��Χ�ڡ�

����˼·��
*/

#include <stdio.h>
#include <stdlib.h>

int cmp (const void *_a, const void *_b)
{
	int *a = (int*)_a;
	int *b = (int*)_b;
	return *a - *b; //����
}

int reversePairs(int* nums, int numsSize)
{
	if (numsSize < 2)
		return 0;
	
	int big, sma; //��ֵ��Сֵ
	
	qsort (nums, numsSize, sizeof(int), cmp); //����
	
	for (big = numsSize-1; big > 0)
}
