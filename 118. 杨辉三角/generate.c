/*
118. �������
����һ���Ǹ����� numRows������������ǵ�ǰ numRows �С�
����������У�ÿ�����������Ϸ������Ϸ������ĺ͡�

ʾ��:
����: 5
���:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

����˼·��
1. ���Ǻܳ����ѭ�����о�û�п�ʲô֪ʶ��
2. �����ڴ�ռ��ͬʱ���Խ�ÿ�еĵ�0λ�����һλ��ʼ��Ϊ1
3. Ȼ�����Ĳ�������ֱ��ѭ��������һ�е�����Ԫ�غϲ���������Ȼ������Ҫһ���߼�֪ʶ
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
