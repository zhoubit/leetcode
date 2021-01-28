/*
9. 回文数

判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:
输入: 121
输出: true

示例 2:
输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

示例 3:
输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。

进阶:
你能不将整数转为字符串来解决这个问题吗？

解决进阶问题也很简单，直接用一个数组来存放余数即可，我认为和转换为数组的效果一样，所以就不写了，反正思路都是 一样的 
*/

bool isPalindrome(int x)
{
	char str[9];
	
	sprintf (str, "%d", x);
	
	int xlen = strlen(str), limit = xlen/2, i;
	
	for (i = 0; i < limit; i++)
		if (str[i] != str[xlen-i])
			return false;
	
	return true;
}
