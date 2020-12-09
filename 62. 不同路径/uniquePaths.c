/*
62. 不同路径

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
问总共有多少条不同的路径？

示例 1：
输入：m = 3, n = 7
输出：28

示例 2：
输入：m = 3, n = 2
输出：3
解释：
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右

示例 3：
输入：m = 7, n = 3
输出：28

示例 4：
输入：m = 3, n = 3
输出：6

提示：
1 <= m, n <= 100
题目数据保证答案小于等于 2 * 109

看了题解后：我还是太菜了！
解题历程：
1. 太简单了吧，直接递归就完事！啪的一下，很快的，直接给我个时间超时
2. 算了吧，本来还想用非数学的方法解题，看来只能用数学的方法解题了，这就是高中初中学的嘛C(n,m)
3. 好家伙！这题原来没想的那么简单，竟然会溢出！！！我是万万没想到的，原来公式是不能随便乱用的！
4. 没办法，既然从大乘到小这条路走不通了，那么我就从小乘到大，同时只要能除，那么就除
5. 我真的佩服这题，更佩服我的智商，算了，还是建两个数组吧！完事，击败100%
6. 数学方法就是我也忘了什么名字了，就是Cnm，先将分母消掉，然后再将分子相乘。
*/

//leetcode题解更简单

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//辗转相除法(求最大公约数
int gcd(int a,int b)
{ 
	if(a%b==0)
		return b;
	else;
		return gcd(b,a%b);
}

int uniquePaths(int m, int n){
	if (m == 1 || n == 1)
		return 1;
	
	int big = m-1 + n-1;
	int small = fmin(m, n)-1;
	int ret = 1, i, j, tmp;
	int *up, *down;
	int deta = big-small;
	
	up = (int*)malloc(sizeof(int)*small);
	down = (int*)malloc(sizeof(int)*small);
	
	for (i = 0; i < small; i++)
	{
		down[i] = i+1;
		up[i] = down[i] + deta;
	}
	
	for (i = 0; i < small; i++)
	{
		for (j = 1; j < small; j++)
		{
			tmp = gcd (up[i], down[j]);
			up[i] /= tmp;
			down[j] /= tmp;
		}
		
		ret *= up[i];
	}
	
	return ret;
}

int main (void)
{
	printf ("\n#%d#\n", uniquePaths(51, 9));
	
	return 0;
}
