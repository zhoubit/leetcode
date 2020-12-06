/*
1030. ����˳�����о���Ԫ��
���� R �� C �еľ������еĵ�Ԫ�����������Ϊ (r, c)������ 0 <= r < R �� 0 <= c < C��
���⣬�����ڸþ����и�����һ������Ϊ (r0, c0) �ĵ�Ԫ��
���ؾ����е����е�Ԫ������꣬������ (r0, c0) �ľ������С������˳���ţ�
���У�����Ԫ��(r1, c1) �� (r2, c2) ֮��ľ����������پ��룬|r1 - r2| + |c1 - c2|��
������԰��κ������������˳�򷵻ش𰸡���

ʾ�� 1��
���룺R = 1, C = 2, r0 = 0, c0 = 0
�����[[0,0],[0,1]]
���ͣ��� (r0, c0) ��������Ԫ��ľ���Ϊ��[0,1]

ʾ�� 2��
���룺R = 2, C = 2, r0 = 0, c0 = 1
�����[[0,1],[0,0],[1,1],[1,0]]
���ͣ��� (r0, c0) ��������Ԫ��ľ���Ϊ��[0,1,1,2]
[[0,1],[1,1],[0,0],[1,0]] Ҳ�ᱻ������ȷ�𰸡�

ʾ�� 3��
���룺R = 2, C = 3, r0 = 1, c0 = 2
�����[[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
���ͣ��� (r0, c0) ��������Ԫ��ľ���Ϊ��[0,1,1,2,2,3]
����������ĿҪ��Ĵ�Ҳ�ᱻ��Ϊ��ȷ������ [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]]��

��ʾ��
1 <= R <= 100
1 <= C <= 100
0 <= r0 < R
0 <= c0 < C

˼·��
1. �����Ƿ���result[R*C][2]��С�����飬���д�ŵ������꣬����˳�򰴵���r0,c0���Ľ�Զ��������
2. �ܼ򵥣�����ջ������֮ǰ���ݽṹ��ͼ�Ĺ�����ȱ���һ��
3. �������ǿ��Բ����¿�ջ�ṹ��ֱ�ӷ���result�������棬��������һ������ģ�����Ҫ����λ
4. ��λ���ú󣬻�Ҫע�����Ƿ���ʹ�
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
	int i, j; //ѭ��
	int sum = R*C; //��������
	int top, front; //ջ�Ķ����͵ײ�
	int **result; //���ǽ�����飬����ջ������ṹ
	int **visited; //�����鿴�Ƿ���ʣ�1���ʡ�0δ����
	int r, c; //��ǰ����
	
	*returnSize = sum; //������
	result = (int**)malloc(sizeof(int*)*sum);
	*returnColumnSizes = (int*)malloc(sizeof(int)*sum); //��ŵ��Ƿ�������ÿ���ж��ٸ�Ԫ�أ�������
	for (i = 0; i < sum; i++)
	{
		result[i] = (int*)malloc(sizeof(int)*2);
		(*returnColumnSizes)[i] = 2; //��ʾÿ������Ԫ��
	}
	
	visited = (int**)malloc(sizeof(int*)*R);
	for (i = 0; i < R; i++)
	{
		visited[i] = (int*)malloc(sizeof(int)*C);
		for (j = 0; j < C; j++)
			visited[i][j] = 0; //��ʼ��Ϊδ����
	}
	
	result[0][0] = r0;
	result[0][1] = c0;
	visited[r0][c0] = 1; //����ѷ���
	for (top = 1, front = 0; front < sum && top < sum; front++)
	{
		//��ջ
		r = result[front][0]; //�� 
		c = result[front][1]; //��
		
		//����ջ�����������ҵ�������ջ
		if (r-1 >= 0 && visited[r-1][c] == 0) //��
		{
			result[top][0] = r-1;
			result[top][1] = c;
			visited[r-1][c] = 1;
			top++;
		}
		if (r+1 < R && visited[r+1][c] == 0) //��
		{
			result[top][0] = r+1;
			result[top][1] = c;
			visited[r+1][c] = 1;
			top++;
		}
		if (c-1 >= 0 && visited[r][c-1] == 0) //�� 
		{
			result[top][0] = r;
			result[top][1] = c-1;
			visited[r][c-1] = 1;
			top++;
		}
		if (c+1 < C && visited[r][c+1] == 0) //�� 
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
