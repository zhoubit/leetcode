/*
1370. 上升下降字符串

给你一个字符串 s ，请你根据下面的算法重新构造字符串：
从 s 中选出 最小 的字符，将它 接在 结果字符串的后面。
从 s 剩余字符中选出 最小 的字符，且该字符比上一个添加的字符大，将它 接在 结果字符串后面。
重复步骤 2 ，直到你没法从 s 中选择字符。
从 s 中选出 最大 的字符，将它 接在 结果字符串的后面。
从 s 剩余字符中选出 最大 的字符，且该字符比上一个添加的字符小，将它 接在 结果字符串后面。
重复步骤 5 ，直到你没法从 s 中选择字符。
重复步骤 1 到 6 ，直到 s 中所有字符都已经被选过。
在任何一步中，如果最小或者最大字符不止一个 ，你可以选择其中任意一个，并将其添加到结果字符串。

请你返回将 s 中字符重新排序后的 结果字符串 。

示例 1：
输入：s = "aaaabbbbcccc"
输出："abccbaabccba"
解释：第一轮的步骤 1，2，3 后，结果字符串为 result = "abc"
第一轮的步骤 4，5，6 后，结果字符串为 result = "abccba"
第一轮结束，现在 s = "aabbcc" ，我们再次回到步骤 1
第二轮的步骤 1，2，3 后，结果字符串为 result = "abccbaabc"
第二轮的步骤 4，5，6 后，结果字符串为 result = "abccbaabccba"

示例 2：
输入：s = "rat"
输出："art"
解释：单词 "rat" 在上述算法重排序以后变成 "art"

示例 3：
输入：s = "leetcode"
输出："cdelotee"

示例 4：
输入：s = "ggggggg"
输出："ggggggg"

示例 5：
输入：s = "spo"
输出："ops"

提示：
1 <= s.length <= 500
s 只包含小写英文字母。

解题思路：
1. 由于只有小写英文字母，所以使用哈希表是最简单的方法，依次从前往后、再从后往前遍历，如此往复
2. 第二种方法是先qsort一遍，然后也是从前往后从后往前
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *sortString(char *s){
	int hash[26]; //哈希表
	int slen = strlen(s); //字符串长度
	int i, j; //循环用
	
	if (slen <= 1)
		return s;
	
	memset (hash, 0, 26*sizeof(int)); //将哈希表初始化为0
	
	//统计字符个数
	for (i = 0; i < slen; i++)
		hash[s[i]-'a']++;
	
	//在原字符串上进行赋值
	for (i = 0; i < slen;)
	{
		for (j = 0; j < 26; j++) //从小到大
		{
			if (hash[j] > 0)
			{
				s[i++] = (char)(j + 'a');
				hash[j]--;
			}
		}
		
		for (j = (26-1); j >= 0; j--) //从大到小
		{
			if (hash[j] > 0)
			{
				s[i++] = (char)(j + 'a');
				hash[j]--;
			}
		}
	}
	
	return s;
}

int main (void)
{
	char s[24] = "gggggg";
	printf ("%s\n", sortString(s));
	
	return 0;
}
