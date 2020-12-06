/*
976. 三角形的最大周长
给定由一些正数（代表长度）组成的数组 A，返回由其中三个长度组成的、面积不为零的三角形的最大周长。
如果不能形成任何面积不为零的三角形，返回 0。

示例 1：
输入：[2,1,2]
输出：5

示例 2：
输入：[1,2,1]
输出：0

示例 3：
输入：[3,2,3,4]
输出：10

示例 4：
输入：[3,6,2,3]
输出：8
 
提示：
3 <= A.length <= 10000
1 <= A[i] <= 10^6

解题思路：
1. 先将数组排序（快速）
2. 从最后三个开始，逐一检查是否构成三角形
3. 最后返回结果
*/
#include <stdio.h>
#include <stdlib.h>

int cmp (const void *_a, const void *_b)
{
	int *a = (int *)_a;
	int *b = (int *)_b;
	
	return *a - *b; //降序
}

int largestPerimeter(int* A, int ASize)
{
	int a, b, c, i; //三边及遍历专用
	
	qsort (A, ASize, sizeof(int), cmp);
	
	for (i = ASize-1; i >= 2; i--)
	{
		a = A[i];
		b = A[i-1];
		c = A[i-2];
		
		if (b+c>a) //降序数组，a一定是最大的
			return a+b+c;
	}
	
	return 0;
}
