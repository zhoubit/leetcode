/*
1081. 不同字符的最小子序列
返回字符串 text 中按字典序排列最小的子序列，该子序列包含 text 中所有不同字符一次。

示例 1：
输入："cdadabcc"
输出："adbc"

示例 2：
输入："abcd"
输出："abcd"

示例 3：
输入："ecbacba"
输出："eacb"

示例 4：
输入："leetcode"
输出："letcod"

提示：
1 <= text.length <= 1000
text 由小写英文字母组成
*/

char * smallestSubsequence(char * s){
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
