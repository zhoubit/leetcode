/*
给定一个非负整数数组A， A 中一半整数是奇数，一半整数是偶数。
对数组进行排序，以便当A[i] 为奇数时，i也是奇数；当A[i]为偶数时，i也是偶数。
你可以返回任何满足上述条件的数组作为答案。

示例：
输入：[4,2,5,7]
输出：[4,5,2,7]
解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。

提示：
2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000

解题思路：
1.哈希表
2.下标 = A[i] % 2 + A[i]对应单双数的数量 * 2
3.单双数的数量可用计数器实现
*/

#include <stdio.h>
#include <stdlib.h>

/*
Note: The returned array must be malloced, assume caller calls free().
*/
int* sortArrayByParityII(int* A, int ASize, int* returnSize){
	int i, j; //定位用
	int oddnum, evennum; //单双数计数器
	int remainder; //余数
	int *result; //结果数组
	
	result = (int*)malloc(sizeof(int)*ASize);
	oddnum = 0;
	evennum = 0;
	
	for (i = 0; i < ASize; i++)
	{
		remainder = A[i]%2; //求余
		if (remainder == 0) //偶数
		{
			j = remainder + evennum*2;
			result[j] = A[i];
			evennum++; //偶数加一
		}
		else
		{
			j = remainder + oddnum*2;
			result[j] = A[i];
			oddnum++; //奇数加一
		}
	}
	
	*returnSize = ASize;
	return result;
}

int main (void)
{
	int A[4] = {4, 2, 5, 7};
	int ASize=4, returnSize, i;
	int *result;
	
	result = sortArrayByParityII(A, ASize, &returnSize);
	
	for (i = 0; i < returnSize; i++)
		printf ("%d ", result[i]);
}
