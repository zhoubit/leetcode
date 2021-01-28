/*
1128. 等价多米诺骨牌对的数量

给你一个由一些多米诺骨牌组成的列表 dominoes。
如果其中某一张多米诺骨牌可以通过旋转 0 度或 180 度得到另一张多米诺骨牌，我们就认为这两张牌是等价的。
形式上，dominoes[i] = [a, b] 和 dominoes[j] = [c, d] 等价的前提是 a==c 且 b==d，或是 a==d 且 b==c。
在 0 <= i < j < dominoes.length 的前提下，找出满足 dominoes[i] 和 dominoes[j] 等价的骨牌对 (i, j) 的数量。

示例：
输入：dominoes = [[1,2],[2,1],[3,4],[5,6]]
输出：1

提示：
1. 1 <= dominoes.length <= 40000
2. 1 <= dominoes[i][j] <= 9

解题思路：
1. 这里面有点数学公式，就是同一组有N个的话，那么就有 N*(N-1)/2 组等价骨牌
2. 由1可得，我们只需要将所有组的结果计算出来后再加起来返回就行了
3. 这里我们又要注意一个溢出的问题，所以我们计算时要使用double类型
*/

int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize)
{
	if (dominoesSize < 2)
		return 0;
	
	int hash[dominoesSize][3]; //0位存放数量 12位存放种类
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
		
		if (j >= hash_i) //没找到
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
