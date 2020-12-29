/*
316. 去除重复字母
给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。

示例 1：
输入：s = "bcabc"
输出："abc"

示例 2：
输入：s = "cbacdcbc"
输出："acdb"

提示：
1 <= s.length <= 104
s 由小写英文字母组成

解题历程：
1. 一开始看这题，感觉超简单的…不就哈希表完事儿了嘛…
2. 结果没那么简单，对我来说，完全没遇到过这种类型的
3. 看了题解后，恍然大悟，原来看着难，其实就是简单的双重循环+栈
*/

char * removeDuplicateLetters(char * s)
{
	int hash[26], vis[26];
	int i, slen = strlen(s), top, n;
	
	memset (hash, 0, sizeof(int)*26); //存放个数
	memset (vis, 0, sizeof(int)*26); //是否入栈
	
	for (i = 0; i < slen; i++)
		hash[s[i]-'a']++;
	
	char *stack;
	stack = (char*)malloc(sizeof(char)*27); //栈
	top = 0;
	
	for (i = 0; i < slen; i++)
	{
		n = s[i]-'a';
		if (vis[n] == 0)
		{
			while (top > 0 && stack[top-1] > s[i] && hash[stack[top-1]-'a'] > 0)
				vis[stack[--top]-'a'] = 0;
			
			stack[top++] = s[i];
			vis[n] = 1;
		}
		hash[n]--;
	}
	stack[top] = '\0';
	
	return stack;
}
