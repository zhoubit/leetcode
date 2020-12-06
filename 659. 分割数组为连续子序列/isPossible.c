/*
659. 分割数组为连续子序列

给你一个按升序排序的整数数组 num（可能包含重复数字），
请你将它们分割成一个或多个子序列，其中每个子序列都由连续整数组成且长度至少为 3 。
如果可以完成上述分割，则返回 true ；否则，返回 false 。

示例 1：
输入: [1,2,3,3,4,5]
输出: True
解释:
你可以分割出这样两个连续子序列 : 
1, 2, 3
3, 4, 5
 
示例 2：
输入: [1,2,3,3,4,4,5,5]
输出: True
解释:
你可以分割出这样两个连续子序列 : 
1, 2, 3, 4, 5
3, 4, 5

示例 3：
输入: [1,2,3,4,4,5]
输出: False
 
提示：输入的数组长度范围为 [1, 10000]

解题思路：
1. 这就跟斗地主一样，一定要将短的尽量变长，不可满足最长的那一条变更长
2. 我采取哈希表，表的长度为nums[numsSize-1]-nums[0]+1 记录元素出现次数 (缺点是在首位元素差距很大得情况下，十分浪费内存)
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
	hash = (int*)malloc(sizeof(int)*(hashLen)); //哈希表，存放元素出现次数
	if (hash == NULL)
	{
		printf ("isPossible函数中hash申请内存失败！\n");
		exit (-1);
	}
	memset (hash, 0, sizeof(int)*hashLen); //次数归零
	
	for (i = 0; i < numsSize; i++) //统计次数 
		hash[nums[i]-nums[0]]++;
	
	for (prenum = 0; prenum < hashLen; prenum++) //开始检测是否符合题意
	{
		if (hash[prenum] != 0)
		{
			isprenum = 0; //标记没有设置序列起始元素
			sequenceLen = 0; //单个序列的当前长度
			
			for (i = prenum; i < hashLen; i++)
			{
				if (isprenum == 0 && hash[i] > 1) //设置下一个连续序列的 
				{
					prenum = i-1; //这-1是为了消除外面for循环中最后的prenum++的影响
					isprenum = 1;
				}
				
				hash[i]--;
				sequenceLen++;
				
				if ((i == hashLen-1) || (i+1 < hashLen && hash[i] >= hash[i+1])) //数据断裂
				{
					if (sequenceLen < 3) //不满足要求 
						return false;
					else //满足要求
						break;
				}
			}
			
			if (isprenum == 0)
				prenum = i-1; //这-1是为了消除外面for循环中最后的prenum++的影响
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
