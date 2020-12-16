/*
290. 单词规律
给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1:
输入: pattern = "abba", str = "dog cat cat dog"
输出: true

示例 2:
输入:pattern = "abba", str = "dog cat cat fish"
输出: false

示例 3:
输入: pattern = "aaaa", str = "dog cat cat dog"
输出: false

示例 4:
输入: pattern = "abba", str = "dog dog dog dog"
输出: false

说明:
你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。

解题历程：
1. 第一反应是哈希表，细看题目后，觉得这题不应该放在简单，因为我觉得这题并不简单
2. 再一个需要并查集，因为这个跟集合有关
3. 我现在的思路是：先对pattern进行并集，然后用哈希表记录好str的每个单词的字母个数，这比较浪费空间（节约空间的话，可以记录单词首字母位置）
4. 我选择浪费空间的，因为记录首字母的话就比较麻烦
5. 其实还有个问题，就是左右字符串的个数可能不一致，其实这很简单来判断，str中的空格数一定是pattern_len-1，同时空格左右一定是字母，
   我可以在制作哈希表的时候就检测好是否是对应的 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define HASHLEN 26

bool isSame (int *hash1, int *hash2)
{
	int i;
	for (i = 0; i < HASHLEN; i++)
		if (hash1[i] != hash2[i])
			return false;
	return true;
}

bool wordPattern(char * pattern, char * s)
{
	int patternlen = strlen (pattern), slen = strlen (s);
	int *set, **hash;
	int i, j;
	
	set = (int*)malloc(sizeof(int)*patternlen);
	hash = (int**)malloc(sizeof(int*)*patternlen);
	
	memset (set, -1, sizeof(int)*patternlen);
	
	for (i = 0; i < patternlen; i++)
	{
		for (j = 0; j < i; j++) //确定集合
		{
			if (pattern[i] == pattern[j])
			{
				set[j]--;
				set[i] = j;
				break;
			}
		}
		
		hash[i] = (int*)malloc(sizeof(int)*HASHLEN);
		memset (hash[i], 0, sizeof(int)*HASHLEN);
	}
	
	j = 0;
	for (i = 0; i < slen; i++) //记录hash
	{
		if (s[i] == ' ')
		{
			if (i == 0 || i == slen-1 || s[i-1] == ' ' || s[i+1] == ' ')
				return false;
			
			if (++j >= patternlen) //单词数量过多，在此防止后面越界访问
				return false;
		}
		else
			hash[j][s[i]-'a']++;
	}
	if (j < patternlen-1) //单词数量不够
		return false;
	
	for (i = 0; i < patternlen; i++)
	{
		for (j = i+1; set[i] < 0 && j < patternlen; j++)
		{
			if (set[j] == i && isSame (hash[i], hash[j]) == false) //同一个集合但是元素不相等 
				return false; 
			else if (set[j] < 0 && set[i] < 0 && isSame (hash[i], hash[j]) == true) //不同集合但元素相等
				return false;
			//无需考虑子元素之间是否相等
		}
	}
	
	return true;
}

int main (void)
{
	char pattern[] = "abba", s[] = "dog dog dog dog";
	if (wordPattern(pattern, s))
		printf ("\n%d\n", 1);
	
	return 0;
}
