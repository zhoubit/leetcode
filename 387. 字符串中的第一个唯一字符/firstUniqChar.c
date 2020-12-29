/*
387. 字符串中的第一个唯一字符
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

示例：
s = "leetcode"
返回 0

s = "loveleetcode"
返回 2
 
提示：你可以假定该字符串只包含小写字母。

解题历程：
1. 哈希表记录字母数量以及该字母出现的第一个位置
2. 第二步就是遍历出数量为1，且位置最小的字母
3. 最后再输出目前字母的位置
*/

int firstUniqChar(char * s)
{
	int num[26], addr[26];
	int slen = strlen (s);
	int i, ret = slen;
	
	memset (num, 0, sizeof(int)*26);
	
	for (i = 0; i < slen; i++)
	{
		num[s[i]-'a']++;
		addr[s[i]-'a'] = i;
	}
	
	for (i = 0; i < 26; i++)
		if (num[i] == 1 && ret > addr[i])
			ret = addr[i];
	
	return ret == slen ? -1:ret;
}
