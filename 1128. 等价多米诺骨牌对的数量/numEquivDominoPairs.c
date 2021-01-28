/*
1128. �ȼ۶���ŵ���ƶԵ�����

����һ����һЩ����ŵ������ɵ��б� dominoes��
�������ĳһ�Ŷ���ŵ���ƿ���ͨ����ת 0 �Ȼ� 180 �ȵõ���һ�Ŷ���ŵ���ƣ����Ǿ���Ϊ���������ǵȼ۵ġ�
��ʽ�ϣ�dominoes[i] = [a, b] �� dominoes[j] = [c, d] �ȼ۵�ǰ���� a==c �� b==d������ a==d �� b==c��
�� 0 <= i < j < dominoes.length ��ǰ���£��ҳ����� dominoes[i] �� dominoes[j] �ȼ۵Ĺ��ƶ� (i, j) ��������

ʾ����
���룺dominoes = [[1,2],[2,1],[3,4],[5,6]]
�����1

��ʾ��
1. 1 <= dominoes.length <= 40000
2. 1 <= dominoes[i][j] <= 9

����˼·��
1. �������е���ѧ��ʽ������ͬһ����N���Ļ�����ô���� N*(N-1)/2 ��ȼ۹���
2. ��1�ɵã�����ֻ��Ҫ��������Ľ������������ټ��������ؾ�����
3. ����������Ҫע��һ����������⣬�������Ǽ���ʱҪʹ��double����
*/

int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize)
{
	if (dominoesSize < 2)
		return 0;
	
	int hash[dominoesSize][3]; //0λ������� 12λ�������
	double ret = 0;
	int i, j, hash_i = 0;
	
	memset (hash, 0, sizeof(int)*dominoesSize*3);
	
	for (i = 0; i < dominoesSize; i++)
	{
		for (j = 0; j < hash_i; j++)
		{
			if (dominoes[i][0] == hash[j][1])
			{
				if (dominoes[i][1] == hash[j][2])
				{
					hash[j][0]++;
					break;
				}
			}
			else if (dominoes[i][1] == hash[j][1])
			{
				if (dominoes[i][0] == hash[j][2])
				{
					hash[j][0]++;
					break;
				}
			}
		}
		
		if (j >= hash_i) //û�ҵ�
		{
			hash[hash_i][0] = 1;
			hash[hash_i][1] = dominoes[i][0];
			hash[hash_i++][2] = dominoes[i][1];
		}
	}
	
	for (i = 0; i < hash_i; i++)
	{
		j = hash[i][0];
		if (j > 1)
			ret += j*(j-1)/2;
	}
	
	return ret;
}
