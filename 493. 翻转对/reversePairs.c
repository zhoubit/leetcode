/*
493. 翻转对
给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j]，
我们就将 (i, j) 称作一个重要翻转对。
你需要返回给定数组中的重要翻转对的数量。

示例 1:
输入: [1,3,2,3,1]
输出: 2

示例 2:
输入: [2,4,3,5,1]
输出: 3

注意:
1. 给定数组的长度不会超过50000。
2. 输入数组中的所有数字都在32位整数的表示范围内。

解题思路：
*/

#include <stdio.h>
#include <stdlib.h>

int cmp (const void *_a, const void *_b)
{
	int *a = (int*)_a;
	int *b = (int*)_b;
	return *a - *b; //升序
}

int reversePairs(int* nums, int numsSize)
{
	if (numsSize < 2)
		return 0;
	
	int big, sma; //大值和小值
	
	qsort (nums, numsSize, sizeof(int), cmp); //升序
	
	for (big = numsSize-1; big > 0)
}
