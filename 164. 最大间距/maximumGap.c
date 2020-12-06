/*
164. �����

����һ����������飬�ҳ�����������֮������Ԫ��֮�����Ĳ�ֵ��
�������Ԫ�ظ���С�� 2���򷵻� 0��

ʾ�� 1:
����: [3,6,9,1]
���: 3
����: ������������ [1,3,6,9], ��������Ԫ�� (3,6) �� (6,9) ֮�䶼��������ֵ 3��

ʾ�� 2:
����: [10]
���: 0
����: ����Ԫ�ظ���С�� 2����˷��� 0��

˵��:
1. ����Լ�������������Ԫ�ض��ǷǸ�����������ֵ�� 32 λ�з���������Χ�ڡ�
2. �볢��������ʱ�临�ӶȺͿռ临�Ӷȵ������½�������⡣

˼·������
1. ���ڹ涨������ʱ�临�ӶȺͿռ临�Ӷȣ����Լ򵥵�����Ͳ��������ó���
2. �����ֻ��ʹ�û��������Ͱ������Ҳ��������ѧ�ģ������һὫ���ַ����������ó���
3. ����Ͱ�����ǻ�������Ļ�������������Ͱ�����ٻ�������
*/

/*
Ͱ����:
1. �ҳ�imax��imin����maximumGap > (imax-imin)/(n-1)
2. ��������Ͱ�ļ���Ϳ������ó� gap = (imax-imin)/(n-1)+1 (+1�Ǳ���gap == 0)
3. Ȼ�󰴼����С�������е����ݷ���Ͱ��
4. ������������ֻ��Ҫ�������������������ֻ��Ҫ��¼ÿһ��Ͱ�����ݵ����ֵ����Сֵ����,���ö�ά������
5. ������������ڵ�����Ͱ�У�����������ֵ = ǰͰ����Сֵ-��Ͱ�����ֵ
*/
#include <stdio.h>
#include <stdlib.h>

int MinForArr (int *nums, int len) //�������е���Сֵ
{
	if (nums == NULL)
	{
		printf ("Error��MinForArr�����в����˿յ����飡\n");
		exit(-1); 
	}
	
	int i;
	int result = nums[0];
	
	for (i = 1; i < len; i++)
		if (result > nums[i])
			result = nums[i];
	
	return result;
}
int MaxForArr (int *nums, int len) //�������е����ֵ
{
	if (nums == NULL)
	{
		printf ("Error��MaxForArr�����в����˿յ����飡\n");
		exit(-1); 
	}
	
	int i;
	int result = nums[0];
	
	for (i = 1; i < len; i++)
		if (result < nums[i])
			result = nums[i];
	
	return result;
}

int maximumGap(int *nums, int numsSize)
{
	if (numsSize < 2)
		return 0;
	
	int imin, imax, d; //��С���ֵ�����d
	int bucket_num, **bucket; //Ͱ�Ĵ�С��Ͱ�ṹ��0λ��¼��Сֵ��1λ��¼���ֵ��
	int i; //ѭ����
	int current, result = 0; //result��ʼ��Ϊ0������ȫ��ͬһ����ֵ�����飩
	int next; //��һ��Ͱ����Ϊ��ЩͰ�������ݣ�����һ��Ҫ��Ǻ���һ��Ͱ��
	
	imax = MaxForArr(nums, numsSize);
	imin = MinForArr(nums, numsSize);
	d = (imax-imin)/(numsSize-1);
	if (d == 0)
		d = 1; //��ֹ�����ڳ��ִ����ظ�Ԫ��
	
	//����Ͱ�ڴ沢��ʼ�����ֵ����Сֵ
	bucket_num = (imax-imin)/d + 1;
	bucket = (int**)malloc(sizeof(int*) * bucket_num);
	if (bucket == NULL)
	{
		printf ("Error��maximumGap������bucket�����ڴ�ʧ�ܣ�\n");
		exit (-1);
	}
	for (i = 0; i < bucket_num; i++)
	{
		bucket[i] = (int*)malloc(sizeof(int) * 2);
		if (bucket[i] == NULL)
		{
			printf ("Error��maximumGap������bucket[i]�����ڴ�ʧ�ܣ�\n");
			exit (-1);
		}
		bucket[i][0] = INT_MAX; //0�����Сֵ����ʼ��λ���ֵ
		bucket[i][1] = INT_MIN; //1������ֵ����ʼ��Ϊ��Сֵ
	}
	
	//ͳ��ÿ��Ͱ�ڵ����ֵ����Сֵ
	for (i = 0; i < numsSize; i++)
	{
		current = (nums[i]-imin)/d; //�������
		
		if (nums[i] < bucket[current][0])
			bucket[current][0] = nums[i];
		if (nums[i] > bucket[current][1])
			bucket[current][1] = nums[i];
	}
	
	//���������
	i = 0;
	next = 1; //��һ��Ͱ��λ������
	while (i < bucket_num-1) //-1��ԭ�������һ�������� bucket_num-1, ����iΪǰһ��Ͱ��ֻ��Ҫ�������ڶ���������
	{
		//һ��Ҫ���������ݵ�Ͱ
		while (i < bucket_num-1 && bucket[i][1] == INT_MIN)
			i++;
		while (i+next < bucket_num && bucket[i+next][0] == INT_MAX)
			next++;
		
		if (i+next < bucket_num && bucket[i+next][0]-bucket[i][1] > result) //Ҫȷ����ȡ���鲻Խ��
			result = bucket[i+next][0]-bucket[i][1];
		
		next = 1; //��ʼ����һ��Ͱ��next��ֵ
		i++;
	}
	
	return result;
}

/*
�������򣺴���
*/

int main (void)
{
	int nums[] = {3,6,9,1};
	int len = 4;
//	
//	int nums[] = {10};
//	int len = 1;
//	
//	int nums[] = {1, 3, 100};
//	int len = 3;
	
	printf ("max = %d, min = %d\n", MaxForArr(nums, len), MinForArr(nums, len));
	printf ("����ࣺ%d\n", maximumGap (nums, len));
	
	return 0;
}
