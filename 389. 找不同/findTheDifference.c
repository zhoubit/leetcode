/*
389. 找不同

给定两个字符串 s 和 t，它们只包含小写字母。
字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
请找出在 t 中被添加的字母。

示例 1：
输入：s = "abcd", t = "abcde"
输出："e"
解释：'e' 是那个被添加的字母。

示例 2：
输入：s = "", t = "y"
输出："y"

示例 3：
输入：s = "a", t = "aa"
输出："a"

示例 4：
输入：s = "ae", t = "aea"
输出："a"

提示：
0 <= s.length <= 1000
t.length == s.length + 1
s 和 t 只包含小写字母

解题历程：
1. 定睛一看！太简单了吧，直接一个哈希表统计s的字母种类及个数，然后再遍历t，同理相减，最后为-1的项就是多出来的字母
2. 再看看提示，还要什么哈希表，直接将s的ASCII加起来，再减t的ASCII，反正不可能溢出
*/

char findTheDifference(char * s, char * t)
{
	int ascii_sum = 0, i;
	int slen = strlen(s);
	
	for (i = 0; i < slen; i++)
		ascii_sum += t[i]-s[i];
	ascii_sum += t[slen];
	
	return ascii_sum;
}

//看了下题解的异或解法，第一次见到这种方法，标记一下，很有用
char findTheDifference(char* s, char* t) {
	int n = strlen(s), m = strlen(t);
	int as = 0, at = 0;
	for (int i = 0; i < n; i++) {
		as += s[i];
	}
	for (int i = 0; i < m; i++) {
		at += t[i];
	}
	return at - as;
}
