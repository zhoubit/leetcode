/*
1122. ������������
�����������飬arr1 �� arr2��

arr2 �е�Ԫ�ظ�����ͬ
arr2 �е�ÿ��Ԫ�ض������� arr1 ��
�� arr1 �е�Ԫ�ؽ�������ʹ arr1 ��������˳��� arr2 �е����˳����ͬ��δ�� arr2 �г��ֹ���Ԫ����Ҫ����������� arr1 ��ĩβ��

ʾ����
���룺arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
�����[2,2,2,1,4,3,3,9,6,7,19]
 

��ʾ��
arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
arr2 �е�Ԫ�� arr2[i] ������ͬ
arr2 �е�ÿ��Ԫ�� arr2[i] �������� arr1 ��

˼·��
1.���ǲ�ȡ��ԭ����Ļ����Ͻ�����λ����
2.��ȡ˫��ѭ������ѭ���ǹ�������2���±꣬��ѭ���ǹ�������1���±�
3.ÿ��һ�ҵ���ͬ��Ԫ�ؾͶ�����1��Ԫ�ؽ��н���
4.һ��Ҫ��һ����λ������λ��Ŀǰ����1���µ�λ��
5.��������ͬ��Ԫ�غ󣬲���ͬ��Ԫ��һ���Ƿ�������棬���Բ�ȡð������
6.���շ�������1 
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize)
{
	int address = 0; //��¼Ŀǰ�Ѿ����ºõ�����1λ��,��ʼ��Ϊ0 
	int i1, i2; //����1������2��Ԫ�ص�ַ
	int temp; //����Ԫ��λ��ʱ���м�Ԫ��
	
	for (i2 = 0; i2 < arr2Size; i2++) //����2���±�
	{
		for (i1 = address; i1 < arr1Size; i1++)
		{
			if (arr1[i1] == arr2[i2]) //�ҵ���ȵ�Ԫ�أ��򽻻�Ԫ��λ��
			{
				temp = arr1[i1];
				arr1[i1] = arr1[address];
				arr1[address] = temp;
				address++; //����λ��,����Ϳ����������Ԫ����
			}
		}
	}
	
	//ð������
	for (i2 = arr1Size-1; i2 >= address; i2--) //�½�
	{
		for (i1 = address; i1 < i2; i1++) //��ǰλ��
		{
			if (arr1[i1] > arr1[i1+1]) //��������
			{
				temp = arr1[i1];
				arr1[i1] = arr1[i1+1];
				arr1[i1+1] = temp;
			}
		}
	}
	
	*returnSize = arr1Size;
	return arr1;
}
