/*
861. ��ת�����ĵ÷�
��һ����ά���� A ����ÿ��Ԫ�ص�ֵΪ 0 �� 1 ��

�ƶ���ָѡ����һ�л��У���ת�����л����е�ÿһ��ֵ�������� 0 ������Ϊ 1�������� 1 ������Ϊ 0��

����������������ƶ��󣬽��þ����ÿһ�ж����ն������������ͣ�����ĵ÷־�����Щ���ֵ��ܺ͡�

���ؾ����ܸߵķ�����

 

ʾ����

���룺[[0,0,1,1],[1,0,1,0],[1,1,0,0]]
�����39
���ͣ�
ת��Ϊ [[1,1,1,1],[1,0,0,1],[1,1,1,1]]
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
*/ 

//�еߵ�
void RowInvert (int **A, int n, int size)
{
	int i;
	for (i = 0; i < size; i++)
		A[n][i] = 1-A[n][i];
}

int matrixScore(int** A, int ASize, int* AColSize)
{
	int i, j, zero_num, zeroMAX, ret;
	
	zeroMAX = ASize/2; //��������Ϊ������A��������һ��Ԫ�أ�����һ��ҪС��Խ��
	
	//��ÿһ�еĵ�һ��Ԫ�ؽ��еߵ�
	for (i = 0; i < ASize; i++)
		if (A[i][0] == 0)
			RowInvert (A, i, AColSize[i]);
	
	ret = (int)(ASize * pow(2, AColSize[0]-1)); //ֱ�Ӽ����ÿ�е�һ�еĽ��
	
	//��ÿһ�н���ͳ�ƣ����Բ�����Ҫ����н��еߵ�
	for (i = 1; i < AColSize[0]; i++)
	{
		zero_num = 0; //0�ĸ���
		for (j = 0; j < ASize; j++)
			if (A[j][i] == 0)
				zero_num++;
		
		if (zero_num > zeroMAX)
			ret += (zero_num)*(1 << (AColSize[0]-1-i));
		else
			ret += (ASize-zero_num)*(1 << (AColSize[0]-1-i));
	}
	
	return ret;
}
