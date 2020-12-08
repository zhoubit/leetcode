/*
861. 翻转矩阵后的得分
有一个二维矩阵 A 其中每个元素的值为 0 或 1 。

移动是指选择任一行或列，并转换该行或列中的每一个值：将所有 0 都更改为 1，将所有 1 都更改为 0。

在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的得分就是这些数字的总和。

返回尽可能高的分数。

 

示例：

输入：[[0,0,1,1],[1,0,1,0],[1,1,0,0]]
输出：39
解释：
转换为 [[1,1,1,1],[1,0,0,1],[1,1,1,1]]
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
*/ 

//行颠倒
void RowInvert (int **A, int n, int size)
{
	int i;
	for (i = 0; i < size; i++)
		A[n][i] = 1-A[n][i];
}

int matrixScore(int** A, int ASize, int* AColSize)
{
	int i, j, zero_num, zeroMAX, ret;
	
	zeroMAX = ASize/2; //这里是因为限制了A中至少有一个元素，否则一定要小心越界
	
	//对每一行的第一个元素进行颠倒
	for (i = 0; i < ASize; i++)
		if (A[i][0] == 0)
			RowInvert (A, i, AColSize[i]);
	
	ret = (int)(ASize * pow(2, AColSize[0]-1)); //直接计算出每行第一列的结果
	
	//对每一列进行统计，并对不符合要求的列进行颠倒
	for (i = 1; i < AColSize[0]; i++)
	{
		zero_num = 0; //0的个数
		for (j = 0; j < ASize; j++)
			if (A[j][i] == 0)
				zero_num++;
		
		if (zero_num > zeroMAX)
			ret += (zero_num)*(1 << (AColSize[0]-1-i));
		else
			ret += (ASize-zero_num)*(1 << (AColSize[0]-1-i));
	}
	
	return ret;
}
