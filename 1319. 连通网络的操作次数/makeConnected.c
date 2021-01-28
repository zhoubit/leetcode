/*
1319. ��ͨ����Ĳ�������
����̫�����½� n ̨��������ӳ�һ�����磬������ı�Ŵ� 0 �� n-1�������� connections ��ʾ��
���� connections[i] = [a, b] �����˼���� a �� b��
�����е��κ�һ̨�����������ͨ������ֱ�ӻ��߼�ӷ���ͬһ����������������һ̨�������
����������������ĳ�ʼ���� connections������԰ο�������ֱ̨�������֮������£�����������һ��δֱ���ļ������
������㲢����ʹ���м��������ͨ��������ٲ�����������������ܣ��򷵻� -1 �� 

ʾ�� 1��
���룺n = 4, connections = [[0,1],[0,2],[1,2]]
�����1
���ͣ����¼���� 1 �� 2 ֮������£��������嵽����� 1 �� 3 �ϡ�

ʾ�� 2��
���룺n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
�����2

ʾ�� 3��
���룺n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
�����-1
���ͣ������������㡣

ʾ�� 4��
���룺n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
�����0

��ʾ��
1 <= n <= 10^5
1 <= connections.length <= min(n*(n-1)/2, 10^5)
connections[i].length == 2
0 <= connections[i][0], connections[i][1] < n
connections[i][0] != connections[i][1]
û���ظ������ӡ�
��̨���������ͨ�������������ӡ�

�������̣�
1. Ӧ���Ǹ�������صĽⷨ
2. �����̨���Զ�û��ĳ��������Ļ�����ô�ͽ�1���ӵ�0
3. �������һ̨û��ĳ��������Ļ�����ô�Ͱ�������������
4. �����̨���Զ��м��ϣ���ô�ͽ���������ͳ�Ƶ�lines��
5. ���ͳ�Ƽ��ϵ����� internet���Ա�Internet��lines�Ĵ�С�����ؽ��
*/

int makeConnected(int n, int** connections, int connectionsSize, int* connectionsColSize)
{
	int lines = 0, internet = 0, c1, c2;
	int i;
	int group[n], current; 
	
	memset (group, -1, sizeof(int)*n);
	
	for (i = 0; i < connectionsSize; i++)
	{
		c1 = connections[i][0];
		c2 = connections[i][1]; 
		
		if (group[c1] != -1)
		{
			if (group[c2] != -1) //��̨���Զ�����·��ʱ����Ҫ�������ǲ�����ͬiһ��������
			{
				while (group[c1] >= 0)
					c1 = group[c1];
				while (group[c2] >= 0)
					c2 = group[c2];
				if (c1 != c2)
					group[c2] = c1;
				else
					lines++;
			}
			else 	//group[c2] == -1
			{
				while (group[c1] >= 0)
					c1 = group[c1];
				if (c1 != c2)
					group[c2] = c1;
				else
					lines++;
			}
		}
		else	//group[c1] == -1
		{
			if (group[c2] == -1)
				group[c2] = c1;
			else	//group[c2] != -1
			{
				while (group[c2] >= 0)
					c2 = group[c2];
				if (c1 != c2)
					group[c1] = c2;
				else
					lines++;
			}
		}
	}
	
	for (i = 0; i < n; i++)
		if (group[i] < 0)
			internet++;
	internet--;
	
	if (internet > lines)
		return -1;
	else
		return internet;
}
