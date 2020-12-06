/*
34. �����������в���Ԫ�صĵ�һ�������һ��λ��

����һ�������������е��������� nums����һ��Ŀ��ֵ target���ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�
��������в�����Ŀ��ֵ target������ [-1, -1]��

���ף�
�������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨�����������

ʾ�� 1��
���룺nums = [5,7,7,8,8,10], target = 8
�����[3,4]

ʾ�� 2��
���룺nums = [5,7,7,8,8,10], target = 6
�����[-1,-1]

ʾ�� 3��
���룺nums = [], target = 0
�����[-1,-1]

��ʾ��
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums ��һ���ǵݼ�����
-109 <= target <= 109

����˼·��
1. ����Ŀ����O(log n)��������ѡ���ֲ��ҷ�
2. ��ǰ�Ķ��ֲ��ҷ��������������������еĵ���Ŀ�꣬���������Ҫ�������������е�һ�ε���Ŀ���ͷ��β 
3. ͷ���ص������û����ͬ�����ˣ�β���ص����ұ�û����ͬ������
4. ok��ץס����ص㣬�������ɵò���ˣ���һ������Ҫ���ӻ᲻��Խ���ˣ�С��0λ�����һλ
*/
#include <stdio.h>
#include <stdlib.h>

int* searchRange(int *nums, int numsSize, int target, int *returnSize)
{
	int *result = NULL;
	int front, rear, current; //ѭ��
	
	*returnSize = 2;
	result = (int*)malloc(sizeof(int)*2);
	if (result == NULL)
	{
		printf ("searchRange������result�����ڴ�ʧ�ܣ�\n");
		exit (-1);
	}
	
	//��ͷ
	front = 0;
	rear = numsSize-1;
	current = (front+rear)/2;
	while (front < rear)
	{
		if (nums[current] > target || (current > 0 && nums[current-1] == target))
			rear = current-1;
		else if (nums[current] < target)
			front = current+1;
		else
			break;
		
		current = (front+rear)/2;
	}
	// numsSize == 0һ��Ҫд����ߣ�����Խ�����
	if (numsSize == 0 || nums[current] != target) //û���ҵ��Ļ�����ʱreturn
	{
		result[0] = -1;
		result[1] = -1;
		return result;
	}
	else
		result[0] = current;
	
	//��β��
	front = current;
	rear = numsSize-1;
	current = (front+rear)/2;
	while (front < rear)
	{
		if (nums[current] < target || (current < numsSize-1 && nums[current+1] == target))
			front = current+1;
		else if (nums[current] > target)
			rear = current-1;
		else
			break;
		
		current = (front+rear)/2;
	}
	result[1] = current;
	
	return result;
}

int main (void)
{
	int nums[] = {8,9};
	int numsSize = sizeof(nums)/sizeof(int);
	int returnSize;
	int target = 8;
	
	int *result =  searchRange(nums, numsSize, target, &returnSize);
	printf ("ͷ��%d, β��%d\n", result[0], result[1]);
	
	return 0;
}
