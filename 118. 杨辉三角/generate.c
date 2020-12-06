/*
118. 杨辉三角
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:
输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

解题思路：
1. 就是很常规的循环，感觉没有考什么知识点
2. 申请内存空间的同时可以将每行的第0位和最后一位初始化为1
3. 然后后面的操作就是直接循环，将上一行的两个元素合并起来，当然这里需要一点逻辑知识
*/

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
	int i, j;
	int **result, *ColumnSizes;
	
	*returnSize = numRows;
	result = (int**)malloc(sizeof(int*)*numRows);
	ColumnSizes = (int*)malloc(sizeof(int)*numRows);
	for (i = 0; i < numRows; i++)
	{
		result[i] = (int*)malloc(sizeof(int)*(i+1));
		result[i][0] = 1;
		result[i][i] = 1;
		ColumnSizes[i] = i+1;
	}
	*returnColumnSizes = ColumnSizes;
	
	for (i = 2; i < numRows; i++)
		for (j = 1; j < i; j++)
			result[i][j] = result[i-1][j-1]+result[i-1][j];
	
	return result;
}
