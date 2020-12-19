/*
48. ��תͼ��
����һ�� n �� n �Ķ�ά�����ʾһ��ͼ��
��ͼ��˳ʱ����ת 90 �ȡ�

˵����
�������ԭ����תͼ������ζ������Ҫֱ���޸�����Ķ�ά�����벻Ҫʹ����һ����������תͼ��

ʾ�� 1:
���� matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],ԭ����ת�������ʹ���Ϊ:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

ʾ�� 2:
���� matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], ԭ����ת�������ʹ���Ϊ:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

�������̣�
1. ˵ʵ�����������⣬��һ�о����Ǽ򵥣���Ϊ�����㷨���ԣ�ֻ��Ҫ�ҵ�һ���Ĺ��ɣ�Ȼ�������ת����
2. ��ʵ�Ϳ���������һ�����ݣ����⵽�ڻ���ڵ��⣬һȦһȦ����ת n/2 Ȧ����һ��������һȦ����
3. �õ�һ�룬ͻȻ�����и��õĹ��ɣ�����Ҫ����ؽ�����,���������ҶԳƽ���Ԫ�أ�Ȼ����б�߶Գƽ���Ԫ�أ���ͼ�Ϳ�������ˣ�
4. ���ҾͰ����ַ������ó����ɣ� 
*/

void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
	int *side, ring, point_x, point_y, ring_max, point_max;
	
	side = (int*)malloc(sizeof(int)*(matrixSize-1));
	ring_max = matrixSize/2; //Ȧ��
	
	for (ring = 0; ring < ring_max; ring++)
	{
		point_max = matrixSize-2*ring-1;
		for (point_x = ring, point_y = 0; point_y < point_max; point_y++) //��¼�ϱ�
			side[point_y] = matrix[point_x][point_y+ring];
		
		for (point_x = 0, point_y = ring; point_x < point_max; point_x++) //ת�����
			matrix[point_y][matrixSize-1-ring-point_x-1] = matrix[point_x+ring+1][point_y];
		
		for (point_x = matrixSize-ring-1, point_y = 0; point_y < point_max; point_y++) //ת���±�
			matrix[point_y+ring+1][ring] = matrix[point_x][point_y+ring+1];
		
		for (point_x = 0, point_y = matrixSize-ring-1; point_x < point_max; point_x++) //ת���ұ�
			matrix[point_y][matrixSize-ring-point_x-1] = matrix[point_x+ring][point_y];
		
		for (point_x = ring, point_y = 0; point_y < point_max; point_y++) //ת���ϱ�
			matrix[point_y+ring][matrixSize-ring-1] = side[point_y];
	}
}

void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
	int i, j, tmp, point_max = matrixSize/2;
	
	for (i = 0; i < matrixSize; i++) //���ҶԳƽ���
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
