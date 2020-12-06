/*
34. 在排序数组中查找元素的第一个和最后一个位置

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：
你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？

示例 1：
输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]

示例 2：
输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]

示例 3：
输入：nums = [], target = 0
输出：[-1,-1]

提示：
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums 是一个非递减数组
-109 <= target <= 109

解题思路：
1. 由于目标是O(log n)，所以首选二分查找法
2. 以前的二分查找法是用来查找有序数据中的单个目标，但今天就需要查找有序数据中的一段单个目标的头和尾 
3. 头的特点是左边没有相同数据了，尾的特点是右边没有相同数据了
4. ok，抓住这个特点，这题就完成得差不多了，下一步就需要重视会不会越界了，小心0位和最后一位
*/
#include <stdio.h>
#include <stdlib.h>

int* searchRange(int *nums, int numsSize, int target, int *returnSize)
{
	int *result = NULL;
	int front, rear, current; //循环
	
	*returnSize = 2;
	result = (int*)malloc(sizeof(int)*2);
	if (result == NULL)
	{
		printf ("searchRange函数中result申请内存失败！\n");
		exit (-1);
	}
	
	//找头
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
	// numsSize == 0一定要写在左边，避免越界访问
	if (numsSize == 0 || nums[current] != target) //没有找到的话，及时return
	{
		result[0] = -1;
		result[1] = -1;
		return result;
	}
	else
		result[0] = current;
	
	//找尾巴
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
	printf ("头：%d, 尾：%d\n", result[0], result[1]);
	
	return 0;
}
