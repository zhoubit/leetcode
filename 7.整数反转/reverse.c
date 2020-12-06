/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例1:
输入: 123
输出: 321

示例 2:
输入: -123
输出: -321

注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为[-2147483648,2147483647]。
请根据这个假设，如果反转后整数溢出那么就返回 0。
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DATA -2147483641

int reverse(int x)
{
	int result = 0;
	int MAX = 2147483647;
	int MIN = -2147483648;
	
	while (x != 0)
	{
		//最后一位的大小一定是小于3的，所以不需要判定
		//同时可以防止result溢出
		if (result < MIN / 10 || result > MAX / 10)
			return 0;
		
		result *= 10; //每次乘10
		result += x % 10; //加个位的数
		x = x / 10; //去除个位
	}
	
	return result;
}

int main(void)
{
	printf ("%d", reverse(DATA));
	
	return 0;
}
