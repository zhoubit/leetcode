/*
767. 重构字符串

给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。
若可行，输出任意可行的结果。若不可行，返回空字符串。

示例 1:
输入: S = "aab"
输出: "aba"

示例 2:
输入: S = "aaab"
输出: ""

注意:
S 只包含小写字母并且长度在[1, 500]区间内。

解题思路：
1. 首先这题就是带有一定的巧妙性，即只要同一个字母不大于一定的次数即可
2. nMax = SLen/2 (SLen%2 == 0), nMax = SLen/2+1 (SLen%2 == 1)
3. 很明显，用哈希表数组结构是最简单的方式
4. 判断完后，我们还要将可以重构的字符串输出为相邻字符不相等的特征
5. 很明显，我们只需要将哈希表内的字符依次间隔一位(1,3,…,2n-1)和(2,4,…,2n)放入原字符数组即可 
6. 但是，有一种特殊情况是最大频次字符刚好有nMax = SLen/2+1 (SLen%2 == 1)个，此时最大频次字符必须从第0位开始存放 
7. 所以我们必须在单数且nMax的情况下标记nMax位置，标记可以在查找nMax时标记
*/
#include <stdio.h>
#include <string.h>

char* reorganizeString(char *S)
{
	int Hash[26] = {0};
	int ii, jj = 0, slen = strlen(S);
	int nMax = slen/2; //可以出现频次的最大值
	int Max_i = -1; //位置，初始化为不存在
	
	if (slen % 2 == 1) //单数情况
		nMax++;
	
	for (ii = 0; ii < slen; ii++)
		Hash[S[ii]-'a']++; //统计个数
	
	//检测是否符合要求，并找到可能出现的最大位置
	for (ii = 0; ii < 26; ii++)
	{
		if (Hash[ii] > nMax) //不符合标准
			return "";
		
		if (Hash[ii] == nMax)
		{
			Max_i = ii;
			break;
		}
	}
	
	if (Max_i > 0) //
	{
		for (ii = 0; ii < slen; ii += 2)
			S[ii] = Max_i + 'a';
		
		jj = 1; //下一个存入的起始位置
		Hash[Max_i] = 0; //哈希表内的最大频率归零
	}
	
	//遍历哈希表
	for (ii = 0; ii < 26; ii++)
	{
		while (Hash[ii] > 0)
		{
			S[jj] = ii + 'a';
			jj += 2;
			
			if (jj >= slen) //换初始位置
				jj = 1; 
			
			Hash[ii]--;
		}
	}
	
	return S;
}

int main (void)
{
	char s[] = "aaab";
	
	printf ("重构前：%s\n", s);
	printf ("重构后：%s\n", reorganizeString(s));
	
	return 0;
}
