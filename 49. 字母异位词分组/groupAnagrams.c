/* 
49. ��ĸ��λ�ʷ���
����һ���ַ������飬����ĸ��λ�������һ����ĸ��λ��ָ��ĸ��ͬ�������в�ͬ���ַ�����

ʾ��:
����: ["eat", "tea", "tan", "ate", "nat", "bat"]
���:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

˵����
���������ΪСд��ĸ��
�����Ǵ������˳��

�������̣�
1. һ�������������ΪСд��ĸ���Ҿ������뵽�˹�ϣ�� 
2. �ܼ򵥣�ֱ�ӽ������ַ�������һ����С�Ĺ�ϣ������ˣ�Ȼ����ͳ���Ƿ���ͬ
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
		for (j = 0; j < strslen; j++) //ͳ�ƹ�ϣ��
			hash[i][strs[i][j]-'a']++;
		
		for (m = 0; m < i; m++) //�ϲ�����
		{
			if (isEqual(hash[i], hash[m], HASHLEN))
			{
				collection[m]--;
				collection[i] = m;
				break;
			}
		}
		
		if (collection[i] < 0) //ͳ�Ƽ��ϸ���
			retSize++;
	}
	
	ColumnSizes = (int*)malloc(sizeof(int)*retSize);
	ret = (char***)malloc(sizeof(char**)*retSize);
	colElem = (int*)malloc(sizeof(int)*strsSize); //����Ԫ����תվ
	colNums = 0;
	
	for (i = 0; i < strsSize; i++)
	{
		if (collection[i] < 0)
		{
			elemNums = 0;
			colElem[elemNums++] = i;
			for (j = i+1; j < strsSize; j++) //�ռ�����Ԫ��
				if (collection[j] == i)
					colElem[elemNums++] = j;
			
			ColumnSizes[colNums] = elemNums;
			ret[colNums] = (char**)malloc(sizeof(char*)*elemNums);
			
			for (j = 0; j < elemNums; j++) //���ﲻ�Ǹ��ƣ�ֻ�ǽ����˵�ַ
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
