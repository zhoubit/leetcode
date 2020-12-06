/*
283. �ƶ���
����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��

ʾ��:
����: [0,1,0,3,12]
���: [1,3,12,0,0]

˵��:
������ԭ�����ϲ��������ܿ�����������顣
�������ٲ���������

˼·��
1. �����֣����Ǿ���Ҫһ����λ��add0����¼��һ�����λ��
2. ��ʼun0=0��Ȼ������һ�������Ķ�λ��current��ֻҪ�Ƿ���ľͷ���un0��λ���ϣ�ͬʱun0++
*/

#include <stdio.h>

void moveZeroes(int* nums, int numsSize)
{
	int add0 = 0; //���㶨λ��
	int current; //������λ��
	
	//�ҵ�һ�����λ��
	while (add0 < numsSize && nums[add0] != 0)
		add0++;
	
	//�ƶ�λ��
	for (current = add0+1; current < numsSize; current++)
	{
		if (nums[current] != 0)
		{
			nums[add0++] = nums[current]; //������ǰ�� 
			nums[current] = 0; //0������ 
		}
	}
}

void print (int *nums, int numsSize)
{
	int i;
	for (i = 0; i < numsSize; i++)
		printf ("%d ", nums[i]);
	putchar ('\n');
}

int main (void)
{
	int numsSize = 5;
	int nums[5] = {0,1,0,3,12};
	
	print (nums, numsSize);
	moveZeroes (nums, numsSize);
	print (nums, numsSize);
	
	return 0;
}
