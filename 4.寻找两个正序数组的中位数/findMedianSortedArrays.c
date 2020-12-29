/*
4. 寻找两个正序数组的中位数
给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数。

进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？

示例 1：
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2

示例 2：
输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5

示例 3：
输入：nums1 = [0,0], nums2 = [0,0]
输出：0.00000

示例 4：
输入：nums1 = [], nums2 = [1]
输出：1.00000

示例 5：
输入：nums1 = [2], nums2 = []
输出：2.00000
 

提示：
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

解题思路：
1. 之前觉得这样的题很难，但是现在一看就没那么难了
2. 首先题目要求，所以只能使用二分法
3. 每次分别对比两个数组的中间值，然后分为三种情况依次处理
*/
#include <stdio.h>
#include <math.h>

double OneAndArrayOfMedian (int one, int *nums, int a, int b)
{
	int m = (a+b)/2;
	int mid;
	
	if (nums[m] == one)
		return one;
	else if (nums[m] < one)
	{
		mid = nums[m+1];
		if (one <= mid)
			mid = one;	
		if ((b-a)%2 == 0)
			return 1.0*(nums[m]+mid)/2;
		else
			return 1.0*mid;
	}
	else
	{
		mid = nums[m-1];
		if (one >= mid)
			mid = one;
		if ((b-a)%2 == 0)
			return 1.0*(nums[m]+mid)/2;
		else
			return 1.0*nums[m];
	}
	
}

double findMedianSortedArrays (int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int a1, b1, m1, a2, b2, m2;
	int len1, len2, len;
	
	a1 = 0;
	a2 = 0;
	b1 = nums1Size-1;
	b2 = nums2Size-1;
	
	if (nums1Size == 0)
	{
		if (nums2Size == 0)
			return 0;
		
		m2 = b2/2;
		if ((b2-a2)%2 == 1)
			return 1.0*(nums2[m2]+nums2[m2+1])/2;
		else
			return 1.0*nums2[m2];
	}
	else if (nums2Size == 0)
	{
		m1 = b1/2;
		if ((b1-a1)%2 == 1)
			return 1.0*(nums1[m1]+nums1[m1+1])/2;
		else
			return 1.0*nums1[m1];
	}
	
	while (a1 < b1 && a2 < b2)
	{
		m1 = (b1-a1+1)/2;
		m2 = (b2-a2)/2;
		printf ("%d %d %d %d %d %d\n", a1, b1, m1, a2, b2, m2);
		if (nums1[m1] > nums2[m2])
		{
			len1 = b1-m1;
			len2 = m2-a2;
		
			len = fmax(fmin(len1,len2),1);
			if (m1 == b1)
			b1 -= len;
			a2 += len;
		}
		else if (nums1[m1] < nums2[m2])
		{
			len1 = m1-a1;
			len2 = b2-m2;
			
			len = fmax(fmin(len1,len2),1);
			a1 += len;
			b2 -= len;
		}
		else
			return 1.0*nums1[m1];
	}
	
	if (a1 == b1)
	{
		if (a2 == b2)
			return 1.0*(nums1[a1]+nums2[a2])/2;
		else //a1 == b1 && a2 != b2
			return OneAndArrayOfMedian (nums1[a1], nums2, a2, b2);
	}
	else //a1 != b1 && a2 == b2
		return OneAndArrayOfMedian (nums2[a2], nums1, a1, b1);
}

int main (void)
{
	int nums1[] = {2,3}, nums2[] = {0,4};
	
	printf ("\nresult = %lf\n", findMedianSortedArrays(nums1, sizeof(nums1)/sizeof(int), nums2, sizeof(nums2)/sizeof(int)));
	
	return 0;
}
