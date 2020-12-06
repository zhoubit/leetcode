/*
1030. 距离顺序排列矩阵单元格
给出 R 行 C 列的矩阵，其中的单元格的整数坐标为 (r, c)，满足 0 <= r < R 且 0 <= c < C。
另外，我们在该矩阵中给出了一个坐标为 (r0, c0) 的单元格。
返回矩阵中的所有单元格的坐标，并按到 (r0, c0) 的距离从最小到最大的顺序排，
其中，两单元格(r1, c1) 和 (r2, c2) 之间的距离是曼哈顿距离，|r1 - r2| + |c1 - c2|。
（你可以按任何满足此条件的顺序返回答案。）

示例 1：
输入：R = 1, C = 2, r0 = 0, c0 = 0
输出：[[0,0],[0,1]]
解释：从 (r0, c0) 到其他单元格的距离为：[0,1]

示例 2：
输入：R = 2, C = 2, r0 = 0, c0 = 1
输出：[[0,1],[0,0],[1,1],[1,0]]
解释：从 (r0, c0) 到其他单元格的距离为：[0,1,1,2]
[[0,1],[1,1],[0,0],[1,0]] 也会被视作正确答案。

示例 3：
输入：R = 2, C = 3, r0 = 1, c0 = 2
输出：[[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
解释：从 (r0, c0) 到其他单元格的距离为：[0,1,1,2,2,3]
其他满足题目要求的答案也会被视为正确，例如 [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]]。

提示：
1 <= R <= 100
1 <= C <= 100
0 <= r0 < R
0 <= c0 < C

思路：
1. 题意是返回result[R*C][2]大小的数组，其中存放的是坐标，坐标顺序按到（r0,c0）的近远依次排序
2. 很简单，借助栈，就像之前数据结构的图的广度优先遍历一样
3. 但是我们可以不用新开栈结构，直接放在result数组里面，该数组是一定够大的，但是要定好位
4. 定位做好后，还要注意标记是否访问过
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** allCellsDistOrder(int R, int C, int r0, int c0, int* returnSize, int** returnColumnSizes)
{
	int i, j; //循环
	int sum = R*C; //坐标总数
	int top, front; //栈的顶部和底部
	int **result; //既是结果数组，又是栈的数组结构
	int **visited; //用来查看是否访问；1访问、0未访问
	int r, c; //当前坐标
	
	*returnSize = sum; //坐标数
	result = (int**)malloc(sizeof(int*)*sum);
	*returnColumnSizes = (int*)malloc(sizeof(int)*sum); //存放的是返回数组每行有多少个元素，即列数
	for (i = 0; i < sum; i++)
	{
		result[i] = (int*)malloc(sizeof(int)*2);
		(*returnColumnSizes)[i] = 2; //表示每行两个元素
	}
	
	visited = (int**)malloc(sizeof(int*)*R);
	for (i = 0; i < R; i++)
	{
		visited[i] = (int*)malloc(sizeof(int)*C);
		for (j = 0; j < C; j++)
			visited[i][j] = 0; //初始化为未访问
	}
	
	result[0][0] = r0;
	result[0][1] = c0;
	visited[r0][c0] = 1; //标记已访问
	for (top = 1, front = 0; front < sum && top < sum; front++)
	{
		//出栈
		r = result[front][0]; //行 
		c = result[front][1]; //列
		
		//将出栈坐标上下左右的坐标入栈
		if (r-1 >= 0 && visited[r-1][c] == 0) //上
		{
			result[top][0] = r-1;
			result[top][1] = c;
			visited[r-1][c] = 1;
			top++;
		}
		if (r+1 < R && visited[r+1][c] == 0) //下
		{
			result[top][0] = r+1;
			result[top][1] = c;
			visited[r+1][c] = 1;
			top++;
		}
		if (c-1 >= 0 && visited[r][c-1] == 0) //左 
		{
			result[top][0] = r;
			result[top][1] = c-1;
			visited[r][c-1] = 1;
			top++;
		}
		if (c+1 < C && visited[r][c+1] == 0) //右 
		{
			result[top][0] = r;
			result[top][1] = c+1;
			visited[r][c+1] = 1;
			top++;
		}
	}
	
	return result;
}

int main (void)
{
	int i, j;
	int R, C, r0, c0, returnSize;
	int *returnColunmSizes = NULL;
	int **result;
	
	R = 2;
	C = 3;
	r0 = 1;
	c0 = 2;
	
//	R = 2;
//	C = 2;
//	r0 = 0;
//	c0 = 1;
	
//	R = 1;
//	C = 2;
//	r0 = 0;
//	c0 = 0;
	
	result = allCellsDistOrder(R, C, r0, c0, &returnSize, &returnColunmSizes);
	
	for (i = 0; i < returnSize; i++)
	{
		for (j = 0; j < returnColunmSizes[i]; j++)
			printf ("[%d,%d] ", result[i][0], result[i][1]);
		putchar('\n');
	}
	
	return 0;
}
