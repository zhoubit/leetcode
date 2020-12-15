/*
738. 单调递增的数字
给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。

（当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）

示例 1:
输入: N = 10
输出: 9

示例 2:
输入: N = 1234
输出: 1234

示例 3:
输入: N = 332
输出: 299

说明: N 是在 [0, 10^9] 范围内的一个整数。

解题思路：
1. 这题是真简单，直接一个数组nums存放每位数字就行了，然后不断调整数ret 
2. 调整的话只有两种情况：
	2.1 nums是递增的数组，那么返回N
	2.2 nums是非递增的数组，那么ret[0] = nums[0]-1,后面的都为9
*/
#include <math.h>
#include <stdio.h>

int monotoneIncreasingDigits(int N)
{
	int nums[10];
	int numslen, tmp, ret, i;
	
	for (numslen = -1, tmp = N; tmp > 0; tmp /= 10)
		nums[++numslen] = tmp%10; //倒序的
	
	if (numslen > 0 && nums[numslen-1] < nums[numslen])
		return nums[numslen]*pow(10, numslen)-1;
	else if (numslen > 0)
		ret = nums[numslen]*pow(10, numslen);
	
	for (i = numslen; i > 0; i--)
	{
		if (nums[i-1] < nums[i]) //非递增
		{
			while (i < numslen && nums[i] == nums[i+1]) //非递增数字前，处理连续相等的情况 
				ret -= nums[i]*pow(10, i++);
			
			return ret-1;
		}
		
		ret += nums[i-1]*pow(10, i-1); //递增
	}
	
	return N;
}


int main (void)
{
	printf ("\n%d\n", monotoneIncreasingDigits(10));
	
	return 0;
}
