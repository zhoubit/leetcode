/* 
49. 字母异位词分组
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:
输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

说明：
所有输入均为小写字母。
不考虑答案输出的顺序。

解题历程：
1. 一看到所有输入均为小写字母，我就立马想到了哈希表 
2. 很简单，直接建立与字符串数组一样大小的哈希表就行了，然后再统计是否相同
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define HASHLEN 26

bool isEqual (int *hash1, int *hash2, int hashlen)
{
	int i;
	for (i = 0; i < hashlen; i++)
		if (hash1[i] != hash2[i])
			return false;
	
	return true;
}
 
char *** groupAnagrams(char strs[][4], int strsSize, int* returnSize, int** returnColumnSizes)
{
	int *collection, **hash, *colElem;
	int strslen, retSize = 0, *ColumnSizes;
	int i, j, m, elemNums, colNums;
	char ***ret;
	
	hash = (int**)malloc(sizeof(int*)*strsSize);
	collection = (int*)malloc(sizeof(int)*strsSize);
	for (i = 0; i < strsSize; i++)
	{
		hash[i] = (int*)malloc(sizeof(int)*HASHLEN);
		memset (hash[i], 0, HASHLEN*sizeof(int));
		collection[i] = -1;
		
		strslen = strlen (strs[i]);
		for (j = 0; j < strslen; j++) //统计哈希表
			hash[i][strs[i][j]-'a']++;
		
		for (m = 0; m < i; m++) //合并集合
		{
			if (isEqual(hash[i], hash[m], HASHLEN))
			{
				collection[m]--;
				collection[i] = m;
				break;
			}
		}
		
		if (collection[i] < 0) //统计集合个数
			retSize++;
	}
	
	ColumnSizes = (int*)malloc(sizeof(int)*retSize);
	ret = (char***)malloc(sizeof(char**)*retSize);
	colElem = (int*)malloc(sizeof(int)*strsSize); //集合元素中转站
	colNums = 0;
	
	for (i = 0; i < strsSize; i++)
	{
		if (collection[i] < 0)
		{
			elemNums = 0;
			colElem[elemNums++] = i;
			for (j = i+1; j < strsSize; j++) //收集集合元素
				if (collection[j] == i)
					colElem[elemNums++] = j;
			
			ColumnSizes[colNums] = elemNums;
			ret[colNums] = (char**)malloc(sizeof(char*)*elemNums);
			
			for (j = 0; j < elemNums; j++) //这里不是复制，只是借用了地址
				ret[colNums][j] = strs[colElem[j]];
			
			colNums++;
		}
	}
	
	*returnColumnSizes = ColumnSizes;
	*returnSize = retSize;
	return ret;
}

int main (void)
{
	char strs[][4] = {"eat", "tea", "tan", "ate", "nat", "bat"};
	int strsSize = 6, returnSize, *columnsize;
	int i, j;
	
	char ***result = groupAnagrams(strs, strsSize, &returnSize, &columnsize);
	
	for (i = 0; i < returnSize; i++)
	{
		for (j = 0; j < columnsize[i]; j++)
			printf ("%s ", result[i][j]);
		
		putchar ('\n');
	}
	
	return 0;
}
