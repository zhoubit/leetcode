/*
738. ��������������
����һ���Ǹ����� N���ҳ�С�ڻ���� N ������������ͬʱ���������Ҫ���������λ���ϵ������ǵ���������

�����ҽ���ÿ������λ���ϵ����� x �� y ���� x <= y ʱ�����ǳ���������ǵ��������ġ���

ʾ�� 1:
����: N = 10
���: 9

ʾ�� 2:
����: N = 1234
���: 1234

ʾ�� 3:
����: N = 332
���: 299

˵��: N ���� [0, 10^9] ��Χ�ڵ�һ��������

����˼·��
1. ��������򵥣�ֱ��һ������nums���ÿλ���־����ˣ�Ȼ�󲻶ϵ�����ret 
2. �����Ļ�ֻ�����������
	2.1 nums�ǵ��������飬��ô����N
	2.2 nums�Ƿǵ��������飬��ôret[0] = nums[0]-1,����Ķ�Ϊ9
*/
#include <math.h>
#include <stdio.h>

int monotoneIncreasingDigits(int N)
{
	int nums[10];
	int numslen, tmp, ret, i;
	
	for (numslen = -1, tmp = N; tmp > 0; tmp /= 10)
		nums[++numslen] = tmp%10; //�����
	
	if (numslen > 0 && nums[numslen-1] < nums[numslen])
		return nums[numslen]*pow(10, numslen)-1;
	else if (numslen > 0)
		ret = nums[numslen]*pow(10, numslen);
	
	for (i = numslen; i > 0; i--)
	{
		if (nums[i-1] < nums[i]) //�ǵ���
		{
			while (i < numslen && nums[i] == nums[i+1]) //�ǵ�������ǰ������������ȵ���� 
				ret -= nums[i]*pow(10, i++);
			
			return ret-1;
		}
		
		ret += nums[i-1]*pow(10, i-1); //����
	}
	
	return N;
}


int main (void)
{
	printf ("\n%d\n", monotoneIncreasingDigits(10));
	
	return 0;
}
