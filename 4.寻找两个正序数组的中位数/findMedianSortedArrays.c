/*
4. Ѱ�����������������λ��
����������СΪ m �� n �����򣨴�С�������� nums1 �� nums2�������ҳ������������������������λ����

���ף��������һ��ʱ�临�Ӷ�Ϊ O(log (m+n)) ���㷨�����������

ʾ�� 1��
���룺nums1 = [1,3], nums2 = [2]
�����2.00000
���ͣ��ϲ����� = [1,2,3] ����λ�� 2

ʾ�� 2��
���룺nums1 = [1,2], nums2 = [3,4]
�����2.50000
���ͣ��ϲ����� = [1,2,3,4] ����λ�� (2 + 3) / 2 = 2.5

ʾ�� 3��
���룺nums1 = [0,0], nums2 = [0,0]
�����0.00000

ʾ�� 4��
���룺nums1 = [], nums2 = [1]
�����1.00000

ʾ�� 5��
���룺nums1 = [2], nums2 = []
�����2.00000
 

��ʾ��
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

����˼·��
1. ֮ǰ��������������ѣ���������һ����û��ô����
2. ������ĿҪ������ֻ��ʹ�ö��ַ�
3. ÿ�ηֱ�Ա�����������м�ֵ��Ȼ���Ϊ����������δ���
*/
#include <stdio.h>
#include <math.h>

double OneAndArrayOfMedian (int one, int *nums, int a, int b)
{
	int m = (a+b)/2;
	int mid;
	
	if (nums[m] == one)
		return one;
	else if (nums[m] < one)
	{
		mid = nums[m+1];
		if (one <= mid)
			mid = one;	
		if ((b-a)%2 == 0)
			return 1.0*(nums[m]+mid)/2;
		else
			return 1.0*mid;
	}
	else
	{
		mid = nums[m-1];
		if (one >= mid)
			mid = one;
		if ((b-a)%2 == 0)
			return 1.0*(nums[m]+mid)/2;
		else
			return 1.0*nums[m];
	}
	
}

double findMedianSortedArrays (int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int a1, b1, m1, a2, b2, m2;
	int len1, len2, len;
	
	a1 = 0;
	a2 = 0;
	b1 = nums1Size-1;
	b2 = nums2Size-1;
	
	if (nums1Size == 0)
	{
		if (nums2Size == 0)
			return 0;
		
		m2 = b2/2;
		if ((b2-a2)%2 == 1)
			return 1.0*(nums2[m2]+nums2[m2+1])/2;
		else
			return 1.0*nums2[m2];
	}
	else if (nums2Size == 0)
	{
		m1 = b1/2;
		if ((b1-a1)%2 == 1)
			return 1.0*(nums1[m1]+nums1[m1+1])/2;
		else
			return 1.0*nums1[m1];
	}
	
	while (a1 < b1 && a2 < b2)
	{
		m1 = (b1-a1+1)/2;
		m2 = (b2-a2)/2;
		printf ("%d %d %d %d %d %d\n", a1, b1, m1, a2, b2, m2);
		if (nums1[m1] > nums2[m2])
		{
			len1 = b1-m1;
			len2 = m2-a2;
		
			len = fmax(fmin(len1,len2),1);
			if (m1 == b1)
			b1 -= len;
			a2 += len;
		}
		else if (nums1[m1] < nums2[m2])
		{
			len1 = m1-a1;
			len2 = b2-m2;
			
			len = fmax(fmin(len1,len2),1);
			a1 += len;
			b2 -= len;
		}
		else
			return 1.0*nums1[m1];
	}
	
	if (a1 == b1)
	{
		if (a2 == b2)
			return 1.0*(nums1[a1]+nums2[a2])/2;
		else //a1 == b1 && a2 != b2
			return OneAndArrayOfMedian (nums1[a1], nums2, a2, b2);
	}
	else //a1 != b1 && a2 == b2
		return OneAndArrayOfMedian (nums2[a2], nums1, a1, b1);
}

int main (void)
{
	int nums1[] = {2,3}, nums2[] = {0,4};
	
	printf ("\nresult = %lf\n", findMedianSortedArrays(nums1, sizeof(nums1)/sizeof(int), nums2, sizeof(nums2)/sizeof(int)));
	
	return 0;
}
