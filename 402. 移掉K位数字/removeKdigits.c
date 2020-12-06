/*
402. �Ƶ�Kλ����
����һ�����ַ�����ʾ�ķǸ����� num���Ƴ�������е� k λ���֣�ʹ��ʣ�µ�������С��

ע��:
num �ĳ���С�� 10002 �� �� k��
num ��������κ�ǰ���㡣

ʾ�� 1 :
����: num = "1432219", k = 3
���: "1219"
����: �Ƴ����������� 4, 3, �� 2 �γ�һ���µ���С������ 1219��

ʾ�� 2 :
����: num = "10200", k = 1
���: "200"
����: �Ƶ���λ�� 1 ʣ�µ�����Ϊ 200. ע������������κ�ǰ���㡣

ʾ�� 3 :
����: num = "10", k = 2
���: "0"
����: ��ԭ�����Ƴ����е����֣�ʣ��Ϊ�վ���0��

˼·��
1.�ȿ����ɣ��Ƴ����ֺ�ʣ�µ����ְ�ԭ����˳���ź�
2.����ÿ�ζ�Ĭ�����λ��Ϊ��Сֵ�����ϲ�����û�б�����С������
	���磺	ʾ��һ:num = "1432219", k = 3
	2.1 �ܹ�7λ�����Ƴ�3λ����4λ��������mallocһ��4��С��char���飬������СֵΪĩβ��2219
	2.2 ��ȡ��2219�еĵ�һ��2���Ա�2֮ǰ�Ƿ���ڱ�2С������ѡ����С����λ��Ŀ������1(�����������)
	2.3 ��Ŀ��������malloc�������ͬʱ���1��λ�ã��´�ֻ����1�Ժ������Сֵ���Ͼ�˳�����Ҫ
	2.4 ͬ���õ�num�еĵ�һλ2����ס�������������ȵģ�ҲҪ��������ֵ���ȵ���
	2.5 ��1ʱ��ֻ�д���1�������ڣ�����ֱ�ӽ�1��9���Ƶ��µ������Ｔ�ɣ�������������
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* removeKdigits(char *num, int k)
{
	int len = strlen(num); //Ŀ���ַ����ĳ���
	int num_begin = 0; //num����ʼ��
	int num_i; //��ǰnum��λ��
	int result_i; //��ǰresult��λ��
	int result_num; //�����λ��
	int min_i; //��¼��Сֵ��λ��
	char *result;
	
	if (len == k)
		return "0";
	
	result = (char*)malloc(sizeof(char)*(len-k+1));
	
	result_num = len-k; //���ǽ����λ��
	for (result_i = 0; result_i < result_num; result_i++) //��ѭ���ǽ����λ��
	{
		min_i = len-result_num+result_i; //��ʼλ��
		for (num_i = (min_i-1); num_i >= num_begin; num_i--) //��ѭ���ǲ��Һ��ʵ�Ԫ��
		{
			if (num[num_i] <= num[min_i]) //Ѱ����С��λ��
				min_i = num_i;
		}
		
		//result_num != 1 ���ֻ��һλ������ô����0��ȥ
		if (result_i == 0 && num[min_i] == '0' && result_num != 1)
		{
			result_i--;
			result_num--;
			num_begin = min_i+1;
		}
		else if (min_i == len-k+result_i) //���������Сֵ��λ��
		{
			while (result_i < len-k)
				result[result_i++] = num[min_i++];
		}
		else
		{
			result[result_i] = num[min_i];
			num_begin = min_i+1;
		}
	}
	result[result_num] = '\0';
	
	return result;
}

int main (void)
{
//	char *num = "1432219";
//	int k = 3;
//	char *num = "10";
//	int k = 2;
	char *num = "100001";
	int k = 1;
	
	printf ("ת��ǰ��%s\n", num);
	num = removeKdigits(num, k);
	printf ("ת����%s\n", num);
	
	return 0;
}
