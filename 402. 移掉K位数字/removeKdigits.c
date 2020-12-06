/*
402. 移掉K位数字
给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。

注意:
num 的长度小于 10002 且 ≥ k。
num 不会包含任何前导零。

示例 1 :
输入: num = "1432219", k = 3
输出: "1219"
解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。

示例 2 :
输入: num = "10200", k = 1
输出: "200"
解释: 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。

示例 3 :
输入: num = "10", k = 2
输出: "0"
解释: 从原数字移除所有的数字，剩余为空就是0。

思路：
1.先看规律，移除数字后，剩下的数字按原来的顺序排好
2.所以每次都默认最后几位数为最小值，不断查找有没有比它更小的数子
	例如：	示例一:num = "1432219", k = 3
	2.1 总共7位数，移除3位还有4位，所以先malloc一个4大小的char数组，假设最小值为末尾的2219
	2.2 先取出2219中的第一个2，对比2之前是否存在比2小的数，选出最小的那位，目标数是1(从右往左查找)
	2.3 将目标数放在malloc的数组里，同时标记1的位置，下次只能在1以后查找最小值，毕竟顺序很重要
	2.4 同理，得到num中的第一位2，记住，这里就算是相等的，也要找最早出现的相等的数
	2.5 到1时，只有大于1的数存在，所以直接将1和9复制到新的数组里即可，并返回新数组
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* removeKdigits(char *num, int k)
{
	int len = strlen(num); //目标字符串的长度
	int num_begin = 0; //num的起始点
	int num_i; //当前num的位置
	int result_i; //当前result的位置
	int result_num; //结果的位数
	int min_i; //记录最小值的位置
	char *result;
	
	if (len == k)
		return "0";
	
	result = (char*)malloc(sizeof(char)*(len-k+1));
	
	result_num = len-k; //这是结果的位数
	for (result_i = 0; result_i < result_num; result_i++) //外循环是结果的位置
	{
		min_i = len-result_num+result_i; //初始位置
		for (num_i = (min_i-1); num_i >= num_begin; num_i--) //内循环是查找合适的元素
		{
			if (num[num_i] <= num[min_i]) //寻找最小的位置
				min_i = num_i;
		}
		
		//result_num != 1 结果只有一位数，那么就让0进去
		if (result_i == 0 && num[min_i] == '0' && result_num != 1)
		{
			result_i--;
			result_num--;
			num_begin = min_i+1;
		}
		else if (min_i == len-k+result_i) //本身就是最小值的位置
		{
			while (result_i < len-k)
				result[result_i++] = num[min_i++];
		}
		else
		{
			result[result_i] = num[min_i];
			num_begin = min_i+1;
		}
	}
	result[result_num] = '\0';
	
	return result;
}

int main (void)
{
//	char *num = "1432219";
//	int k = 3;
//	char *num = "10";
//	int k = 2;
	char *num = "100001";
	int k = 1;
	
	printf ("转换前：%s\n", num);
	num = removeKdigits(num, k);
	printf ("转换后：%s\n", num);
	
	return 0;
}
