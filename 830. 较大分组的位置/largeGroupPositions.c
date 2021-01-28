/*
830. �ϴ�����λ��

��һ����Сд��ĸ���ɵ��ַ��� s �У�������һЩ��������ͬ�ַ������ɵķ��顣
���磬���ַ��� s = "abbxxxxzyy" �У��ͺ��� "a", "bb", "xxxx", "z" �� "yy" ������һЩ���顣
������������� [start, end] ��ʾ������ start �� end �ֱ��ʾ�÷������ʼ����ֹλ�õ��±ꡣ�����е� "xxxx" �����������ʾΪ [3,6] ��
���ǳ����а������ڻ�������������ַ��ķ���Ϊ �ϴ���� ��
�ҵ�ÿһ�� �ϴ���� �����䣬����ʼλ���±����˳������󣬷��ؽ����
 
ʾ�� 1��
���룺s = "abbxxxxzzy"
�����[[3,6]]
���ͣ�"xxxx" ��һ����ʼ�� 3 ����ֹ�� 6 �Ľϴ���顣

ʾ�� 2��
���룺s = "abc"
�����[]
���ͣ�"a","b" �� "c" �����Ƿ���Ҫ��Ľϴ���顣

ʾ�� 3��
���룺s = "abcdddeeeeaabbbcd"
�����[[3,5],[6,9],[12,14]]
���ͣ��ϴ����Ϊ "ddd", "eeee" �� "bbb"

ʾ�� 4��
���룺s = "aba"
�����[]
 
��ʾ��
1 <= s.length <= 1000
s ����СдӢ����ĸ
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largeGroupPositions(char * s, int* returnSize, int** returnColumnSizes)
{
	int **ret, *ColumnSizes;
	int len = strlen(s), i, end, len_3 = len/3;
	
	ret = (int**)malloc(sizeof(int*)*len_3);
 	ColumnSizes = (int*)malloc(sizeof(int)*len_3);
	for (i = 0; i < len_3; i++)
	{
		ret[i] = (int*)malloc(sizeof(int)*2);
		ColumnSizes[i] = 2;
	}
	*returnSize = 0;
	*returnColumnSizes = ColumnSizes;
	
	for (i = 0; i < len; )
	{
		end = i+1;
		while (s[end] == s[i] && end < len)
			end++;
		
		if (end > i+1)
		{
			if (end - i >= 3)
			{
				ret[*returnSize][0] = i;
				ret[(*returnSize)++][1] = end-1;
			}
			i = end;
		}
        else
            i++;
	}
	
	return ret;
}
