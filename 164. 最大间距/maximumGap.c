/*
164. 最大间距

给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。
如果数组元素个数小于 2，则返回 0。

示例 1:
输入: [3,6,9,1]
输出: 3
解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。

示例 2:
输入: [10]
输出: 0
解释: 数组元素个数小于 2，因此返回 0。

说明:
1. 你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
2. 请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。

思路解析：
1. 由于规定了线性时间复杂度和空间复杂度，所以简单的排序就不能排上用场了
2. 在这里，只能使用基数排序和桶排序，这也是我重新学的，所以我会将两种方法独立地敲出来
3. 由于桶排序是基数排序的基础，所以我先桶排序再基数排序
*/

/*
桶排序:
1. 找出imax和imin，则maximumGap > (imax-imin)/(n-1)
2. 所以我们桶的间隔就可以设置成 gap = (imax-imin)/(n-1)+1 (+1是避免gap == 0)
3. 然后按间隔大小，将所有的数据放入桶中
4. 但是由于这题只需要查找最大间隔，所以我们只需要记录每一个桶中数据的最大值和最小值即可,可用二维数组存放
5. 最大间隔就是相邻的两个桶中，数组的最大间隔值 = 前桶的最小值-后桶的最大值
*/
#include <stdio.h>
#include <stdlib.h>

int MinForArr (int *nums, int len) //求数组中的最小值
{
	if (nums == NULL)
	{
		printf ("Error！MinForArr函数中查找了空的数组！\n");
		exit(-1); 
	}
	
	int i;
	int result = nums[0];
	
	for (i = 1; i < len; i++)
		if (result > nums[i])
			result = nums[i];
	
	return result;
}
int MaxForArr (int *nums, int len) //求数组中的最大值
{
	if (nums == NULL)
	{
		printf ("Error！MaxForArr函数中查找了空的数组！\n");
		exit(-1); 
	}
	
	int i;
	int result = nums[0];
	
	for (i = 1; i < len; i++)
		if (result < nums[i])
			result = nums[i];
	
	return result;
}

int maximumGap(int *nums, int numsSize)
{
	if (numsSize < 2)
		return 0;
	
	int imin, imax, d; //最小最大值，间隔d
	int bucket_num, **bucket; //桶的大小及桶结构（0位记录最小值，1位记录最大值）
	int i; //循环用
	int current, result = 0; //result初始化为0（避免全是同一个数值的数组）
	int next; //下一个桶（因为有些桶内无数据，所以一定要标记好下一个桶）
	
	imax = MaxForArr(nums, numsSize);
	imin = MinForArr(nums, numsSize);
	d = (imax-imin)/(numsSize-1);
	if (d == 0)
		d = 1; //防止数组内出现大量重复元素
	
	//申请桶内存并初始化最大值和最小值
	bucket_num = (imax-imin)/d + 1;
	bucket = (int**)malloc(sizeof(int*) * bucket_num);
	if (bucket == NULL)
	{
		printf ("Error！maximumGap函数中bucket申请内存失败！\n");
		exit (-1);
	}
	for (i = 0; i < bucket_num; i++)
	{
		bucket[i] = (int*)malloc(sizeof(int) * 2);
		if (bucket[i] == NULL)
		{
			printf ("Error！maximumGap函数中bucket[i]申请内存失败！\n");
			exit (-1);
		}
		bucket[i][0] = INT_MAX; //0存放最小值，初始化位最大值
		bucket[i][1] = INT_MIN; //1存放最大值，初始化为最小值
	}
	
	//统计每个桶内的最大值和最小值
	for (i = 0; i < numsSize; i++)
	{
		current = (nums[i]-imin)/d; //计算归属
		
		if (nums[i] < bucket[current][0])
			bucket[current][0] = nums[i];
		if (nums[i] > bucket[current][1])
			bucket[current][1] = nums[i];
	}
	
	//查找最大间隔
	i = 0;
	next = 1; //下一个桶的位置增量
	while (i < bucket_num-1) //-1的原因是最后一个坐标是 bucket_num-1, 但是i为前一个桶，只需要到倒数第二个就行了
	{
		//一定要跳过无数据的桶
		while (i < bucket_num-1 && bucket[i][1] == INT_MIN)
			i++;
		while (i+next < bucket_num && bucket[i+next][0] == INT_MAX)
			next++;
		
		if (i+next < bucket_num && bucket[i+next][0]-bucket[i][1] > result) //要确保读取数组不越界
			result = bucket[i+next][0]-bucket[i][1];
		
		next = 1; //初始化下一个桶的next的值
		i++;
	}
	
	return result;
}

/*
基数排序：待补
*/

int main (void)
{
	int nums[] = {3,6,9,1};
	int len = 4;
//	
//	int nums[] = {10};
//	int len = 1;
//	
//	int nums[] = {1, 3, 100};
//	int len = 3;
	
	printf ("max = %d, min = %d\n", MaxForArr(nums, len), MinForArr(nums, len));
	printf ("最大间距：%d\n", maximumGap (nums, len));
	
	return 0;
}
