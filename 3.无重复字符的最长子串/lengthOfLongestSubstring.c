/*给定一个字符串，请你找出其中不含有重复字符的?最长子串?的长度。

示例?1:
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是?"wke"，所以其长度为 3。
   请注意，你的答案必须是 子串 的长度，"pwke"?是一个子序列，不是子串。
*/

/*
解题思路：
 先找到一个头字符，在移动尾字符，每次判断尾字符是否与头字符之后尾字符之前的字符相等
1.出现相等，则记录与尾字符相等的坐标，使下一个头字符初始化为该字符的下一个字符
2.无相等字符，则使尾字符加一
3.若执行过程中，最长的不连续字符串长度比剩余的字符串长度长，则直接退出查找循环，返回当前MaxLen
*/
#include <string.h>

int lengthOfLongestSubstring(char * s)
{
	int MaxLen = 1;
	int searchLen = 1;
	int sLen = (int)strlen(s);
	int i, j, l;
	char head, tail, test;
	
	i = 0;
	if (sLen == 0)
		return sLen;

        for (j = i + 1; j < sLen; j++)
        {
        	head = s[i];
        	tail = s[j];
        	
        	//测试尾巴 
		for (l = i; l < j; l++)
		{
		        test = s[l];
		        if (tail == test)
		        {
		        	i = l+1;
		        	j = i; //不能是j = i + 1; 因为后面还要进行一次j++ 
		        	break;
		        }
		        searchLen++;
		}

	        if (searchLen > MaxLen)
	        	MaxLen = searchLen;
	        
	        if (MaxLen >= sLen - i)
	        	break;
		
		searchLen = 1; //初始化 
        }

	return MaxLen;
}
