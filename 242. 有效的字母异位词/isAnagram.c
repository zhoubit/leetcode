/*
242. 有效的字母异位词
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1:
输入: s = "anagram", t = "nagaram"
输出: true

示例 2:
输入: s = "rat", t = "car"
输出: false

说明:
你可以假设字符串只包含小写字母。

解题思路：
1. 字符串只包含小写字母，这就十分简单了，可以使用哈希表
2. 数组空间大小为26
*/

#include <stdio.h>
#include <string.h>

bool isAnagram(char *s, char *t){
	int slen=strlen(s), tlen=strlen(t);
	
	if (slen != tlen)
		return false;
	
	int hash[26]; //初始化为0
	int i, j;
	
	memset(hash, 0, 26); //将hash的前26个元素替换成0
	//制作哈希表
	for (i = 0; i < slen; i++)
	{
		j = (int)(s[i]-'a');
		hash[j]++; //计算数量
	}
	
	//测试数据
	for (i = 0; i < tlen; i++)
	{
		j = (int)(t[i]-'a');
		
		if (hash[j] == 0)
			return false;
		hash[j]--;
	}
	return true;
}
