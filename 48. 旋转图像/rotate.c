/*
48. 旋转图像
给定一个 n × n 的二维矩阵表示一个图像。
将图像顺时针旋转 90 度。

说明：
你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:
给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

示例 2:
给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

解题历程：
1. 说实话，看到这题，第一感觉就是简单，因为毫无算法可言，只需要找到一定的规律，然后进行旋转即可
2. 其实就可以想象是一个陀螺，从外到内或从内到外，一圈一圈地旋转 n/2 圈，用一个数组存放一圈即可
3. 敲到一半，突然发现有更好的规律，不需要死板地解题了,可以先左右对称交换元素，然后再斜线对称交换元素（画图就可以理解了）
4. 那我就把两种方法都敲出来吧！ 
*/

void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
	int *side, ring, point_x, point_y, ring_max, point_max;
	
	side = (int*)malloc(sizeof(int)*(matrixSize-1));
	ring_max = matrixSize/2; //圈数
	
	for (ring = 0; ring < ring_max; ring++)
	{
		point_max = matrixSize-2*ring-1;
		for (point_x = ring, point_y = 0; point_y < point_max; point_y++) //记录上边
			side[point_y] = matrix[point_x][point_y+ring];
		
		for (point_x = 0, point_y = ring; point_x < point_max; point_x++) //转移左边
			matrix[point_y][matrixSize-1-ring-point_x-1] = matrix[point_x+ring+1][point_y];
		
		for (point_x = matrixSize-ring-1, point_y = 0; point_y < point_max; point_y++) //转移下边
			matrix[point_y+ring+1][ring] = matrix[point_x][point_y+ring+1];
		
		for (point_x = 0, point_y = matrixSize-ring-1; point_x < point_max; point_x++) //转移右边
			matrix[point_y][matrixSize-ring-point_x-1] = matrix[point_x+ring][point_y];
		
		for (point_x = ring, point_y = 0; point_y < point_max; point_y++) //转移上边
			matrix[point_y+ring][matrixSize-ring-1] = side[point_y];
	}
}

void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
	int i, j, tmp, point_max = matrixSize/2;
	
	for (i = 0; i < matrixSize; i++) //左右对称交换
	{
		for (j = 0; j < point_max; j++)
		{
			tmp = matrix[i][j];
			matrix[i][j] = matrix[i][matrixSize-j-1];
			matrix[i][matrixSize-j-1] = tmp;
		}
	}
	
	for (i = 0; i < matrixSize-1; i++)
	{
		point_max = matrixSize-i;
		for (j = 0; j < point_max; j++)
		{
			tmp = matrix[i][j];
			matrix[i][j] = matrix[matrixSize-1-j][matrixSize-1-i];
			matrix[matrixSize-1-j][matrixSize-1-i] = tmp;
		}
	}
}
