/*
321. 拼接最大数
给定长度分别为 m 和 n 的两个数组，其元素由 0-9 构成，表示两个自然数各位上的数字。
现在从这两个数组中选出 k (k <= m + n) 个数字拼接成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。
求满足该条件的最大数。结果返回一个表示该最大数的长度为 k 的数组。

说明: 请尽可能地优化你算法的时间和空间复杂度。

示例 1:
输入:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
输出:
[9, 8, 6, 5, 3]

示例 2:
输入:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
输出:
[6, 7, 6, 0, 4]

示例 3:
输入:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
输出:
[9, 8, 9]

解题思路：
1. 这道题难度还行，虽然是困难，但是理解起来不难
2. 简单点说，就是在a、b两个数组中分别选取x、y个元素 x+y = k (k <= m + n) 
3. 我们这就需要使用贪心算法了，即将所有的结果都算出来，然后选取最佳的方案
4. 这里我们又学到了一个新的算法，就是单调栈，这里不多解释了，以后如果有机会看这段代码的话，请百度学习
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//在一个数组中按顺序选出n个元素，组成最大的值返回
int* MaxNumsN (int* nums, int numsSize, int n)
{
	if (n == 0)
		return NULL;
	
	int *result = NULL;
	int i = 0, max = -1, current = 0;
	
	result = (int*)malloc(sizeof(int)*(n));
	if (result == NULL)
	{
		printf ("MakeNumsN函数中result申请内存失败！\n");
		exit(-1);
	}
	
	for (current = 0; current < n; current++)
	{
		i = max+1;
		max = i;
		while (i <= numsSize-(n-current)) //在可选的范围内选一个最大的
		{
			if (nums[i] > nums[max])
				max = i;
			i++;
		}
		result[current] = nums[max];
	}
	
	return result;
}

//在两个数组中分别选出x、y个元素，然后按原顺序组成最大的值
int* MakeNumsXY (int* nums1, int nums1Size, int x, int* nums2, int nums2Size, int y)
{
	int *result;
	int *nums1_x, *nums2_y; //分别是数组1、2中按次序最大的数
	int i1 = 0, i2 = 0, ir; //定位
	int i, j; //在元素相同时使用
	
	nums1_x = MaxNumsN (nums1, nums1Size, x);
	nums2_y = MaxNumsN (nums2, nums2Size, y);
	if (x == 0)
		return nums2_y;
	if (y == 0)
		return nums1_x;
	
	result = (int*)malloc(sizeof(int)*(x+y));
	if (result == NULL)
	{
		printf ("MakeNumsN函数中result申请内存失败！\n");
		exit(-1);
	}
	
	//开始组合两个数组
	for (ir = 0; i1 < x && i2 < y; ir++)
	{
		i = 0; //位移量
		j = 0;
		while (nums1_x[i1+i] == nums2_y[i2+j]) //调整位移量
		{
			if (i1+i < x-1)
				i++;
			if (i2+j < y-1)
				j++;
			if (i1+i == x-1 && i2+j == y-1) //必须增加这一条，避免两个数组的最后一个元素相等，这样就会陷入死循环
				break;
		}
		if (nums1_x[i1+i] > nums2_y[i2+j])
			result[ir] = nums1_x[i1++];
		else
			result[ir] = nums2_y[i2++];
	}
	
	//复制剩下的元素
	while (i1 < x)
		result[ir++] = nums1_x[i1++];
	while (i2 < y)
		result[ir++] = nums2_y[i2++];
	
	free (nums1_x);
	free (nums2_y);
	
	return result;
}

//判断两个数组大，最后返回大的，并把小的内存释放了 
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
	memset (result, 0, sizeof(int)*k); //先初始化
	
	begin = fmax (0, k-nums2Size);
	end = fmin (k, nums1Size);
	for (x = begin; x <= end; x++) //数组一的待选长度
	{
		y = k-x; //数组二的待选长度
		temp = MakeNumsXY (nums1, nums1Size, x, nums2, nums2Size, y);
		result = Choice (result, temp, k); //查看该情况是否比上一个情况好
	}
	
	return result;
}

//上面方法超时，下面是标准答案, 
//上面答案已修改，错误在于 MakeNumsXY 中的while陷入了死循环
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
//作者：LeetCode-Solution
//链接：https://leetcode-cn.com/problems/create-maximum-number/solution/pin-jie-zui-da-shu-by-leetcode-solution/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

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
