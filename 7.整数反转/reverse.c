/*
����һ�� 32 λ���з�������������Ҫ�����������ÿλ�ϵ����ֽ��з�ת��

ʾ��1:
����: 123
���: 321

ʾ�� 2:
����: -123
���: -321

ע��:

�������ǵĻ���ֻ�ܴ洢���� 32 λ���з���������������ֵ��ΧΪ[-2147483648,2147483647]��
�����������裬�����ת�����������ô�ͷ��� 0��
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DATA -2147483641

int reverse(int x)
{
	int result = 0;
	int MAX = 2147483647;
	int MIN = -2147483648;
	
	while (x != 0)
	{
		//���һλ�Ĵ�Сһ����С��3�ģ����Բ���Ҫ�ж�
		//ͬʱ���Է�ֹresult���
		if (result < MIN / 10 || result > MAX / 10)
			return 0;
		
		result *= 10; //ÿ�γ�10
		result += x % 10; //�Ӹ�λ����
		x = x / 10; //ȥ����λ
	}
	
	return result;
}

int main(void)
{
	printf ("%d", reverse(DATA));
	
	return 0;
}
