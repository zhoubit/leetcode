/*
659. �ָ�����Ϊ����������

����һ��������������������� num�����ܰ����ظ����֣���
���㽫���Ƿָ��һ�����������У�����ÿ�������ж���������������ҳ�������Ϊ 3 ��
���������������ָ�򷵻� true �����򣬷��� false ��

ʾ�� 1��
����: [1,2,3,3,4,5]
���: True
����:
����Էָ�������������������� : 
1, 2, 3
3, 4, 5
 
ʾ�� 2��
����: [1,2,3,3,4,4,5,5]
���: True
����:
����Էָ�������������������� : 
1, 2, 3, 4, 5
3, 4, 5

ʾ�� 3��
����: [1,2,3,4,4,5]
���: False
 
��ʾ����������鳤�ȷ�ΧΪ [1, 10000]

����˼·��
1. ��͸�������һ����һ��Ҫ���̵ľ����䳤���������������һ�������
2. �Ҳ�ȡ��ϣ����ĳ���Ϊnums[numsSize-1]-nums[0]+1 ��¼Ԫ�س��ִ��� (ȱ��������λԪ�ز��ܴ������£�ʮ���˷��ڴ�)
3. 
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPossible(int* nums, int numsSize)
{
	if (numsSize < 3)
		return false;
	
	int *hash, i, hashLen, sequenceLen, prenum, isprenum;
	
	hashLen = nums[numsSize-1]-nums[0]+1;
	hash = (int*)malloc(sizeof(int)*(hashLen)); //��ϣ�����Ԫ�س��ִ���
	if (hash == NULL)
	{
		printf ("isPossible������hash�����ڴ�ʧ�ܣ�\n");
		exit (-1);
	}
	memset (hash, 0, sizeof(int)*hashLen); //��������
	
	for (i = 0; i < numsSize; i++) //ͳ�ƴ��� 
		hash[nums[i]-nums[0]]++;
	
	for (prenum = 0; prenum < hashLen; prenum++) //��ʼ����Ƿ��������
	{
		if (hash[prenum] != 0)
		{
			isprenum = 0; //���û������������ʼԪ��
			sequenceLen = 0; //�������еĵ�ǰ����
			
			for (i = prenum; i < hashLen; i++)
			{
				if (isprenum == 0 && hash[i] > 1) //������һ���������е� 
				{
					prenum = i-1; //��-1��Ϊ����������forѭ��������prenum++��Ӱ��
					isprenum = 1;
				}
				
				hash[i]--;
				sequenceLen++;
				
				if ((i == hashLen-1) || (i+1 < hashLen && hash[i] >= hash[i+1])) //���ݶ���
				{
					if (sequenceLen < 3) //������Ҫ�� 
						return false;
					else //����Ҫ��
						break;
				}
			}
			
			if (isprenum == 0)
				prenum = i-1; //��-1��Ϊ����������forѭ��������prenum++��Ӱ��
		}
		
	}
	
	return true;
}

int main (void)
{
	int a[] = {1,2,3,4};
	if (isPossible(a, sizeof(a)/sizeof(int)))
		printf ("%d\n", 1);
	
	return 0;
}
