/*
321. ƴ�������
�������ȷֱ�Ϊ m �� n ���������飬��Ԫ���� 0-9 ���ɣ���ʾ������Ȼ����λ�ϵ����֡�
���ڴ�������������ѡ�� k (k <= m + n) ������ƴ�ӳ�һ���µ�����Ҫ���ͬһ��������ȡ�������ֱ�������ԭ�����е����˳��
���������������������������һ����ʾ��������ĳ���Ϊ k �����顣

˵��: �뾡���ܵ��Ż����㷨��ʱ��Ϳռ临�Ӷȡ�

ʾ�� 1:
����:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
���:
[9, 8, 6, 5, 3]

ʾ�� 2:
����:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
���:
[6, 7, 6, 0, 4]

ʾ�� 3:
����:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
���:
[9, 8, 9]

����˼·��
1. ������ѶȻ��У���Ȼ�����ѣ����������������
2. �򵥵�˵��������a��b���������зֱ�ѡȡx��y��Ԫ�� x+y = k (k <= m + n) 
3. ���������Ҫʹ��̰���㷨�ˣ��������еĽ�����������Ȼ��ѡȡ��ѵķ���
4. ����������ѧ����һ���µ��㷨�����ǵ���ջ�����ﲻ������ˣ��Ժ�����л��ῴ��δ���Ļ�����ٶ�ѧϰ
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//��һ�������а�˳��ѡ��n��Ԫ�أ��������ֵ����
int* MaxNumsN (int* nums, int numsSize, int n)
{
	if (n == 0)
		return NULL;
	
	int *result = NULL;
	int i = 0, max = -1, current = 0;
	
	result = (int*)malloc(sizeof(int)*(n));
	if (result == NULL)
	{
		printf ("MakeNumsN������result�����ڴ�ʧ�ܣ�\n");
		exit(-1);
	}
	
	for (current = 0; current < n; current++)
	{
		i = max+1;
		max = i;
		while (i <= numsSize-(n-current)) //�ڿ�ѡ�ķ�Χ��ѡһ������
		{
			if (nums[i] > nums[max])
				max = i;
			i++;
		}
		result[current] = nums[max];
	}
	
	return result;
}

//�����������зֱ�ѡ��x��y��Ԫ�أ�Ȼ��ԭ˳���������ֵ
int* MakeNumsXY (int* nums1, int nums1Size, int x, int* nums2, int nums2Size, int y)
{
	int *result;
	int *nums1_x, *nums2_y; //�ֱ�������1��2�а�����������
	int i1 = 0, i2 = 0, ir; //��λ
	int i, j; //��Ԫ����ͬʱʹ��
	
	nums1_x = MaxNumsN (nums1, nums1Size, x);
	nums2_y = MaxNumsN (nums2, nums2Size, y);
	if (x == 0)
		return nums2_y;
	if (y == 0)
		return nums1_x;
	
	result = (int*)malloc(sizeof(int)*(x+y));
	if (result == NULL)
	{
		printf ("MakeNumsN������result�����ڴ�ʧ�ܣ�\n");
		exit(-1);
	}
	
	//��ʼ�����������
	for (ir = 0; i1 < x && i2 < y; ir++)
	{
		i = 0; //λ����
		j = 0;
		while (nums1_x[i1+i] == nums2_y[i2+j]) //����λ����
		{
			if (i1+i < x-1)
				i++;
			if (i2+j < y-1)
				j++;
			if (i1+i == x-1 && i2+j == y-1) //����������һ��������������������һ��Ԫ����ȣ������ͻ�������ѭ��
				break;
		}
		if (nums1_x[i1+i] > nums2_y[i2+j])
			result[ir] = nums1_x[i1++];
		else
			result[ir] = nums2_y[i2++];
	}
	
	//����ʣ�µ�Ԫ��
	while (i1 < x)
		result[ir++] = nums1_x[i1++];
	while (i2 < y)
		result[ir++] = nums2_y[i2++];
	
	free (nums1_x);
	free (nums2_y);
	
	return result;
}

//�ж������������󷵻ش�ģ�����С���ڴ��ͷ��� 
int* Choice (int* nums1, int* nums2, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (nums1[i] > nums2[i])
		{
			free (nums2);
			return nums1;
		}
		if (nums1[i] < nums2[i])
		{
			free (nums1);
			return nums2;
		}
	}
	free (nums2);
	return nums1;
}

int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize)
{
	int *result, *temp;
	int x, y;
	int begin, end;
	
	*returnSize = k;
	result = (int*)malloc(sizeof(int)*k);
	memset (result, 0, sizeof(int)*k); //�ȳ�ʼ��
	
	begin = fmax (0, k-nums2Size);
	end = fmin (k, nums1Size);
	for (x = begin; x <= end; x++) //����һ�Ĵ�ѡ����
	{
		y = k-x; //������Ĵ�ѡ����
		temp = MakeNumsXY (nums1, nums1Size, x, nums2, nums2Size, y);
		result = Choice (result, temp, k); //�鿴������Ƿ����һ�������
	}
	
	return result;
}

//���淽����ʱ�������Ǳ�׼��, 
//��������޸ģ��������� MakeNumsXY �е�while��������ѭ��
//int compare(int* subseq1, int subseq1Size, int index1, int* subseq2, int subseq2Size, int index2) {
//    while (index1 < subseq1Size && index2 < subseq2Size) {
//        int difference = subseq1[index1] - subseq2[index2];
//        if (difference != 0) {
//            return difference;
//        }
//        index1++;
//        index2++;
//    }
//    return (subseq1Size - index1) - (subseq2Size - index2);
//}
//
//int* merge(int* subseq1, int subseq1Size, int* subseq2, int subseq2Size) {
//    if (subseq1Size == 0) {
//        return subseq2;
//    }
//    if (subseq2Size == 0) {
//        return subseq1;
//    }
//    int mergeLength = subseq1Size + subseq2Size;
//    int* merged = malloc(sizeof(int) * (subseq1Size + subseq2Size));
//    int index1 = 0, index2 = 0, i;
//    for (i = 0; i < mergeLength; i++) {
//        if (compare(subseq1, subseq1Size, index1, subseq2, subseq2Size, index2) > 0) {
//            merged[i] = subseq1[index1++];
//        } else {
//            merged[i] = subseq2[index2++];
//        }
//    }
//    return merged;
//}
//
//int* MaxSubsequence(int* nums, int numsSize, int k) {
//    int* stack = malloc(sizeof(int) * k);
//    memset(stack, 0, sizeof(int) * k);
//    int top = -1, i;
//    int remain = numsSize - k;
//    for (i = 0; i < numsSize; i++) {
//        int num = nums[i];
//        while (top >= 0 && stack[top] < num && remain > 0) {
//            top--;
//            remain--;
//        }
//        if (top < k - 1) {
//            stack[++top] = num;
//        } else {
//            remain--;
//        }
//    }
//    return stack;
//}
//
//void swap(int** a, int** b) {
//    int* tmp = *a;
//    *a = *b, *b = tmp;
//}
//
//int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize) {
//    int* maxSubsequence = malloc(sizeof(int) * k);
//    memset(maxSubsequence, 0, sizeof(int) * k);
//    *returnSize = k;
//    int start = fmax(0, k - nums2Size), end = fmin(k, nums1Size), i;
//    for (i = start; i <= end; i++) {
//        int* subseq1 = MaxSubsequence(nums1, nums1Size, i);
//        int* subseq2 = MaxSubsequence(nums2, nums2Size, k - i);
//        int* curMaxSubsequence = merge(subseq1, i, subseq2, k - i);
//        if (compare(curMaxSubsequence, k, 0, maxSubsequence, k, 0) > 0) {
//            swap(&curMaxSubsequence, &maxSubsequence);
//        }
//    }
//    return maxSubsequence;
//}
//
//���ߣ�LeetCode-Solution
//���ӣ�https://leetcode-cn.com/problems/create-maximum-number/solution/pin-jie-zui-da-shu-by-leetcode-solution/
//��Դ�����ۣ�LeetCode��
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������

int main (void)
{
//	int nums1[] = {2};
//	int nums2[] = {2};
	int nums1[] = {1,1,1,0,0,1,1,0,2,1,0,1,2,1,0,2,2,1,0,2,0,1,1,0,0,2,2,0,1,0,2,0,2,2,2,2,1,1,1,1,0,0,0,0,2,1,0,2,1,1,2,1,2,2,0,2,1,0,2,0,0,2,0,2,2,1,0,1,0,0,2,1,1,1,2,2,0,0,0,1,1,2,0,2,2,0,1,0,2,1,0,2,1,1,1,0,1,1,2,0,2,0,1,1,2,0,2,0,1,2,1,0,2,0,1,0,0,0,1,2,1,2,0,1,2,2,1,1,0,1,2,1,0,0,1,0,2,2,1,2,2,0,0,0,2,0,0,0,1,0,2,0,2,1,0,0,1,2,0,1,1,0,1,0,2,2,2,1,1,0,1,1,2,1,0,2,2,2,1,2,2,2,2,0,1,1,0,1,2,1,2,2,0,0,0,0,0,1,1,1,2,1,2,1,1,0,1,2,0,1,2,1,2,2,2,2,0,0,0,0,2,0,1,2,0,1,1,1,1,0,1,2,2,1,0,1,2,2,1,2,2,2,0,2,0,1,1,2,0,0,2,2,0,1,0,2,1,0,0,1,1,1,1,0,0,2,2,2,2,0,0,1,2,1,1,2,0,1,2,1,0,2,0,0,2,1,1,0,2,1,1,2,2,0,1,0,2,0,1,0};
	int nums2[] = {4,2,32,0,2,1,2,2,2,2,0,1,0,0,2,0,2,0,2,1,0,1,1,0,1,0,1,2,1,1,1,0,1,2,2,1,0,0,1,2,1,2,2,1,1,0,1,2,0,2,0,1,2,0,2,1,1,1,2,0,0,1,0,2,1,2,0,1,0,0,0,1,2,1,0,1,1,2,0,2,2,0,0,1,1,2,2,1,1,2,2,1,0,1,2,0,1,2,2,0,0,0,2,0,2,0,2,2,0,1,1,1,1,2,2,2,2,0,0,2,2,2,2,0,2,0,1,0,0,2,1,0,0,2,0,2,1,1,1,1,0,1,2,0,2,1,0,1,1,1,0,0,2,2,2,0,2,1,1,1,2,2,0,0,2,2,2,2,2,0,2,0,2,0,2,0,0,1,0,1,1,0,0,2,1,1,2,2,2,1,2,2,0,0,2,1,0,2,1,2,1,1,1,0,2,0,1,1,2,1,1,0,0,1,0,1,2,2,2,0,2,2,1,0,1,2,1,2,0,2,2,0,1,2,2,1,2,2,1,1,2,2,2,2,2,1,2,0,1,1,1,2,2,2,0,2,0,2,0,2,1,1,0,2,2,2,1,0,2,1,2,2,2,0,1,1,1,1,1,1,0,0,0,2,2,0,1,2,1,0,0,2,2,2,2,1,0,2,0,1,2,0};
	int k = 10, returnSize, i;
	int nums1Size = sizeof(nums1)/sizeof(int);
	int nums2Size = sizeof(nums2)/sizeof(int);
	int *result;
	
	result = maxNumber (nums1, nums1Size, nums2, nums2Size, k, &returnSize);
	for (i = 0; i < returnSize; i++)
		printf ("%d ", result[i]);
	
	return 0;
} 
