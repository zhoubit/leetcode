/*
283. 移动零
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]

说明:
必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。

思路：
1. 像这种，我们就需要一个定位器add0，记录第一个零的位置
2. 初始un0=0，然后再来一个遍历的定位器current，只要是非零的就放在un0的位置上，同时un0++
*/

#include <stdio.h>

void moveZeroes(int* nums, int numsSize)
{
	int add0 = 0; //非零定位器
	int current; //遍历定位器
	
	//找第一个零的位置
	while (add0 < numsSize && nums[add0] != 0)
		add0++;
	
	//移动位置
	for (current = add0+1; current < numsSize; current++)
	{
		if (nums[current] != 0)
		{
			nums[add0++] = nums[current]; //非零往前移 
			nums[current] = 0; //0往后移 
		}
	}
}

void print (int *nums, int numsSize)
{
	int i;
	for (i = 0; i < numsSize; i++)
		printf ("%d ", nums[i]);
	putchar ('\n');
}

int main (void)
{
	int numsSize = 5;
	int nums[5] = {0,1,0,3,12};
	
	print (nums, numsSize);
	moveZeroes (nums, numsSize);
	print (nums, numsSize);
	
	return 0;
}
