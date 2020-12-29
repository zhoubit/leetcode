/*
64. ��С·����

����һ�������Ǹ������� m x n ���� grid �����ҳ�һ�������Ͻǵ����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С��
˵����ÿ��ֻ�����»��������ƶ�һ����

ʾ�� 1��
���룺grid = [[1,3,1],[1,5,1],[4,2,1]]
�����7
���ͣ���Ϊ·�� 1��3��1��1��1 ���ܺ���С��

ʾ�� 2��
���룺grid = [[1,2,3],[4,5,6]]
�����12
 
��ʾ��
m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100

�������̣�
1. ��̬�滮��ֱ�ӱ���һ��Ϳ�����
2. ��ԭλ���ϴ�����·������ 
*/

int minPathSum(int** grid, int gridSize, int* gridColSize)
{
	int i, j, m = gridSize-1, n = gridColSize[gridSize]-1;
	
	for (i = 1; i <= n; i++) //��һ���� 
		grid[0][i] += grid[0][i-1];
	
	for (i = 1; i <= m; i++) //��һ���� 
		grid[i][0] += grid[i-1][0];
		
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
			grid[i][j] += fmin (grid[i-1][j], grid[i][j-1]);
	
	return grid[m][n];
}
