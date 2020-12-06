/*
204. ��������
ͳ������С�ڷǸ����� n ��������������

ʾ�� 1��
���룺n = 10
�����4
���ͣ�С�� 10 ������һ���� 4 ��, ������ 2, 3, 5, 7 ��

ʾ�� 2��
���룺n = 0
�����0

ʾ�� 3��
���룺n = 1
�����0

��ʾ��0 <= n <= 5 * 10^6

����˼·��
1. ̫���ˣ�����˫��ѭ�����ܸ㶨����
*/
#include <stdio.h>

int isPrimeNum (int num)
{
	int i;
	for (i = 2; i*i <= num; i++) //num
		if (num % i == 0)
			return 0; //�������� 
	
	return 1; //������
}

int countPrimes(int n)
{
	if (n < 3)
		return 0;
	
	int i, PrimeNums = 1; //����2�Ѿ�������
	for (i = 3; i < n; i++)
		PrimeNums += isPrimeNum(i);
	
	return PrimeNums;
}

int main (void)
{
	printf ("%d\n", countPrimes(10));
	
	return 0;
}
