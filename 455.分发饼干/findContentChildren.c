/*
假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。

对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；
并且每块饼干 j，都有一个尺寸 s[j]。
如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。
你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
 
示例1:
输入: g = [1,2,3], s = [1,1]
输出: 1
解释: 
你有三个孩子和两块小饼干，3个孩子的胃口值分别是：1,2,3。
虽然你有两块小饼干，由于他们的尺寸都是1，你只能让胃口值是1的孩子满足。
所以你应该输出1。

示例2:
输入: g = [1,2], s = [1,2,3]
输出: 2
解释: 
你有两个孩子和三块小饼干，2个孩子的胃口值分别是1,2。
你拥有的饼干数量和尺寸都足以让所有孩子满足。
所以应该输出2.

提示：
1 <= g.length <= 3 * 104
0 <= s.length <= 3 * 104
1 <= g[i], s[j] <= 231 - 1
*/
#include <stdio.h> 
#include <stdlib.h>

int cmp (const void *_a, const void *_b)
{
	int *a = (int*)_a;
	int *b = (int*)_b;
	
	return *a - *b; //从小到大排序
}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
	int i, j; //循环用
	int temp; //排序时，交换位置的中转站
	int result = 0; //统计的结果
	
	//对孩子胃口排序
	qsort (g, gSize, sizeof(int), cmp);
	
	//对饼干大小排序
	qsort (s, sSize, sizeof(int), cmp);
	
	//开始分发饼干
	for (i = 0, j = 0; i < gSize && j < sSize ; j++)
	{
		if (g[i] <= s[j])
		{
			result++; //合适的话，结果加 1 
			i++;
		}
	}
	
	return result;
}

int main (void)
{
	int g[] = {4,5,8,9,5,6,4,1,23,1};
	int gSize = sizeof(g)/sizeof(int);
	int s[] = {};
	int sSize = sizeof(s)/sizeof(int);
	
	printf ("%d", findContentChildren(g, gSize, s, sSize));
	
	return 0;
}
