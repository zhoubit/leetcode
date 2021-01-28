/*
 605. �ֻ�����
��������һ���ܳ��Ļ�̳��һ���ֵؿ���ֲ�˻�����һ����ȴû�С����ǣ����ܲ�����ֲ�����ڵĵؿ��ϣ����ǻ�����ˮԴ�����߶�����ȥ��
����һ����̳����ʾΪһ���������0��1������0��ʾû��ֲ����1��ʾ��ֲ�˻�������һ���� n ��
�ܷ��ڲ�������ֲ�������������� n �仨�����򷵻�True�������򷵻�False��

ʾ�� 1:
����: flowerbed = [1,0,0,0,1], n = 1
���: True

ʾ�� 2:
����: flowerbed = [1,0,0,0,1], n = 2
���: False

ע��:
���������ֺõĻ�����Υ����ֲ����
��������鳤�ȷ�ΧΪ [1, 20000]��
n �ǷǸ��������Ҳ��ᳬ����������Ĵ�С��
*/

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n)
{
	int i;
	
	if (flowerbed[0] == 0)
	{
		if (flowerbedSize > 1 && flowerbed[1] == 0)
		{
			flowerbed[0] = 1;
			n--;
		}
		else if (flowerbedSize == 1)
			return true;
	}
	
	for (i = 1; i < flowerbedSize-1; i++)
	{
		if (flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0)
		{
			flowerbed[i] = 1;
			n--;
		}
	}
	
	if (flowerbed[flowerbedSize-1] == 0)
	{
		if (flowerbedSize > 1 && flowerbed[flowerbedSize-2] == 0)
		{
			flowerbed[flowerbedSize-1] = 1;
			n--;
		}
	}
	
	if (n < 1)
		return true; 
	
	return false;
}
