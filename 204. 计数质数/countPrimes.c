/*
204. 计数质数
统计所有小于非负整数 n 的质数的数量。

示例 1：
输入：n = 10
输出：4
解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。

示例 2：
输入：n = 0
输出：0

示例 3：
输入：n = 1
输出：0

提示：0 <= n <= 5 * 10^6

解题思路：
1. 太简单了，就是双重循环就能搞定的事
*/
#include <stdio.h>

int isPrimeNum (int num)
{
	int i;
	for (i = 2; i*i <= num; i++) //num
		if (num % i == 0)
			return 0; //不是质数 
	
	return 1; //是质数
}

int countPrimes(int n)
{
	if (n < 3)
		return 0;
	
	int i, PrimeNums = 1; //质数2已经算在内
	for (i = 3; i < n; i++)
		PrimeNums += isPrimeNum(i);
	
	return PrimeNums;
}

int main (void)
{
	printf ("%d\n", countPrimes(10));
	
	return 0;
}
