/*
��������һλ�ܰ��ļҳ�����Ҫ����ĺ�����һЩС���ɡ����ǣ�ÿ���������ֻ�ܸ�һ����ɡ�

��ÿ������ i������һ��θ��ֵ g[i]���������ú���������θ�ڵı��ɵ���С�ߴ磻
����ÿ����� j������һ���ߴ� s[j]��
��� s[j] >= g[i]�����ǿ��Խ�������� j ��������� i ��������ӻ�õ����㡣
���Ŀ���Ǿ���������Խ�������ĺ��ӣ��������������ֵ��
 
ʾ��1:
����: g = [1,2,3], s = [1,1]
���: 1
����: 
�����������Ӻ�����С���ɣ�3�����ӵ�θ��ֵ�ֱ��ǣ�1,2,3��
��Ȼ��������С���ɣ��������ǵĳߴ綼��1����ֻ����θ��ֵ��1�ĺ������㡣
������Ӧ�����1��

ʾ��2:
����: g = [1,2], s = [1,2,3]
���: 2
����: 
�����������Ӻ�����С���ɣ�2�����ӵ�θ��ֵ�ֱ���1,2��
��ӵ�еı��������ͳߴ綼���������к������㡣
����Ӧ�����2.

��ʾ��
1 <= g.length <= 3 * 104
0 <= s.length <= 3 * 104
1 <= g[i], s[j] <= 231 - 1
*/
#include <stdio.h> 
#include <stdlib.h>

int cmp (const void *_a, const void *_b)
{
	int *a = (int*)_a;
	int *b = (int*)_b;
	
	return *a - *b; //��С��������
}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
	int i, j; //ѭ����
	int temp; //����ʱ������λ�õ���תվ
	int result = 0; //ͳ�ƵĽ��
	
	//�Ժ���θ������
	qsort (g, gSize, sizeof(int), cmp);
	
	//�Ա��ɴ�С����
	qsort (s, sSize, sizeof(int), cmp);
	
	//��ʼ�ַ�����
	for (i = 0, j = 0; i < gSize && j < sSize ; j++)
	{
		if (g[i] <= s[j])
		{
			result++; //���ʵĻ�������� 1 
			i++;
		}
	}
	
	return result;
}

int main (void)
{
	int g[] = {4,5,8,9,5,6,4,1,23,1};
	int gSize = sizeof(g)/sizeof(int);
	int s[] = {};
	int sSize = sizeof(s)/sizeof(int);
	
	printf ("%d", findContentChildren(g, gSize, s, sSize));
	
	return 0;
}
