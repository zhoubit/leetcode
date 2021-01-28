/*
674. 最长连续递增序列

给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。
连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，
都有 nums[i] < nums[i + 1] ，那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。

示例 1：
输入：nums = [1,3,5,4,7]
输出：3
解释：最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为 5 和 7 在原数组里被 4 隔开。
 
示例 2：
输入：nums = [2,2,2,2,2]
输出：1
解释：最长连续递增序列是 [2], 长度为1。
 
提示：
0 <= nums.length <= 104
-109 <= nums[i] <= 109
*/

int findLengthOfLCIS(int* nums, int numsSize)
{
	if (numsSize < 1)
		return 0;
	
	int ret = 1, pre = nums[0], len = 1;
	int i;
	
	for (i = 1; i < numsSize; i++)
	{
		if (nums[i] > pre)
			len++;
		else
		{
			ret = fmax(ret, len);
			len = 1; //这里细节，每次重新开始的初始长度都是1 
		}
		pre = nums[i];
	}
	ret = fmax(ret, len); //这里细节。避免最长的长度在最后，所以遍历完之后还要再替换一次
	
	return ret;
}
