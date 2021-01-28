/*
435. ���ص�����
����һ������ļ��ϣ��ҵ���Ҫ�Ƴ��������С������ʹʣ�����以���ص���

ע��:
������Ϊ������յ����Ǵ���������㡣
���� [1,2] �� [2,3] �ı߽��໥���Ӵ�������û���໥�ص���

ʾ�� 1:
����: [ [1,2], [2,3], [3,4], [1,3] ]
���: 1
����: �Ƴ� [1,3] ��ʣ�µ�����û���ص���

ʾ�� 2:
����: [ [1,2], [1,2], [1,2] ]
���: 2
����: ����Ҫ�Ƴ����� [1,2] ��ʹʣ�µ�����û���ص���

ʾ�� 3:
����: [ [1,2], [2,3] ]
���: 0
����: �㲻��Ҫ�Ƴ��κ����䣬��Ϊ�����Ѿ������ص����ˡ�

�������̣�
1. һ��ʼ��������⣬�����±Ƶģ������������͵���Ŀ��������̫���� 
2. ���������֪����ֱ��һ�����ţ�Ȼ��̬�滮������һ�μ���
*/

int cmp (const void *_a, const void *_b)
{
	int *a = *(int**)_a, *b = *(int**)_b;
	
	if (a[0] == b[0])
		return a[1]-b[1];
	else
		return a[0]-b[0];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize)
{
	if (intervalsSize < 2)
		return 0;
	
	int cur, ret = 0, pre = 0;
	
	qsort (intervals, intervalsSize, sizeof(int)*2, cmp);
	
	for (cur = 1; cur < intervalsSize; cur++)
	{
		if (intervals[cur][0] < intervals[pre][1])
		{
			if (intervals[cur][1] < intervals[pre][1])
				pre = cur;
			ret++;
		}
		else
			pre = cur;
	}
	
	return ret;
}
