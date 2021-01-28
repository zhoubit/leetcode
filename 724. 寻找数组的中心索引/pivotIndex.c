/*
724. 寻找数组的中心索引

给定一个整数类型的数组 nums，请编写一个能够返回数组 “中心索引” 的方法。
我们是这样定义数组 中心索引 的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。
如果数组不存在中心索引，那么我们应该返回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。
 
示例 1：
输入：
nums = [1, 7, 3, 6, 5, 6]
输出：3
解释：
索引 3 (nums[3] = 6) 的左侧数之和 (1 + 7 + 3 = 11)，与右侧数之和 (5 + 6 = 11) 相等。
同时, 3 也是第一个符合要求的中心索引。

示例 2：
输入：
nums = [1, 2, 3]
输出：-1
解释：
数组中不存在满足此条件的中心索引。
 
说明：
1. nums 的长度范围为 [0, 10000]。
2. 任何一个 nums[i] 将会是一个范围在 [-1000, 1000]的整数。

解题思路：
1. 很显然，使用双指针就可以解决这个问题了
2. 左右指针中，谁指向的值的和小，谁就往中间移动一个位置，如果两个值的和相等的话，那么同时往中间移动一个位置
3. 我一不小心就写了一个标准的错误，看了答案后才大惊，原来还可以直接将和算出来，然后再遍历一次，利用数学公式判断是否符合题意
*/

//下面这个解答就是经典的错误，因为和可能为负数，这样就不能按照数值和的大小来判断是否移动
int pivotIndex(int* nums, int numsSize)
{
	if (numsSize < 3) //处理 0，1，2 的长度的数据
	{
		if (numsSize % 2 == 0)
			return -1;
		else 
			return 0;
	}
	
	int left = 0, right = numsSize-1, Lval = nums[left], Rval = nums[right];
	
	while (left + 2 < right)
	{
		if (Lval > Rval)
			Rval += nums[--right];
		else if (Lval < Rval)
			Lval += nums[++left];
		else
		{
			Rval += nums[--right];
			Lval += nums[++left];
		}
	}
	
	if (left + 2 == right && Rval == Lval)
		return left+1;
	
	return -1;
}

int pivotIndex(int* nums, int numsSize)
{
	int i, sum = 0, lsum = 0;
	
	for (i = 0; i < numsSize; i++)
		sum += nums[i];
	
	for (i = 0; i < numsSize; i++)
	{
		if (lsum == sum - nums[i] - lsum)
			return i;
		
		lsum += nums[i];
	}
	
	return -1;
}
