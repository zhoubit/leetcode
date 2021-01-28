/*
435. 无重叠区间
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:
可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。

示例 1:
输入: [ [1,2], [2,3], [3,4], [1,3] ]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。

示例 2:
输入: [ [1,2], [1,2], [1,2] ]
输出: 2
解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。

示例 3:
输入: [ [1,2], [2,3] ]
输出: 0
解释: 你不需要移除任何区间，因为它们已经是无重叠的了。

解题历程：
1. 一开始看到这个题，又是懵逼的，看来这种类型的题目还是做的太少了 
2. 看了题解后就知道，直接一个快排，然后动态规划，遍历一次即可
*/

int cmp (const void *_a, const void *_b)
{
	int *a = *(int**)_a, *b = *(int**)_b;
	
	if (a[0] == b[0])
		return a[1]-b[1];
	else
		return a[0]-b[0];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize)
{
	if (intervalsSize < 2)
		return 0;
	
	int cur, ret = 0, pre = 0;
	
	qsort (intervals, intervalsSize, sizeof(int)*2, cmp);
	
	for (cur = 1; cur < intervalsSize; cur++)
	{
		if (intervals[cur][0] < intervals[pre][1])
		{
			if (intervals[cur][1] < intervals[pre][1])
				pre = cur;
			ret++;
		}
		else
			pre = cur;
	}
	
	return ret;
}
