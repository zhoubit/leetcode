/*
406. ��������ؽ�����
�����д���˳���һȺ��վ��һ�����С� ÿ������һ��������(h, k)��ʾ������h������˵���ߣ�k�����������ǰ������ߴ��ڻ����h�������� ��дһ���㷨���ؽ�������С�

ע�⣺
����������1100�ˡ�

ʾ��
����:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

���:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 
 ˼·��
 1. �ȶ��������н�����������ɸߵ��ͣ������ȵ�ǰ���µڶ��������ɸߵ�������
 2. ��[hmax,kmin](�������ߵ�������ѡk��С��Ԫ��)��λ�ý��б�ǣ�����λ��Ϊ[i]
 3. ����Ҫע�⣬һ���ź����hmax��Ԫ�ص����λ�ò��䣬���Դ�[i-1]��ʼ�����ƶ�
 4. �ƶ����� d = k-ǰ�����people[i-1][0]�Ĵ���;
 4. ���β��룬ֱ��people[0]Ҳ�������
*/

#include <stdio.h>
#include <stdlib.h>

void print (int **a, int len);

int array_cmp (const void *a, const void *b)
{
	int *a_ptr = *(int**)a;
	int *b_ptr = *(int**)b;
	
	if (a_ptr[0] == b_ptr[0])
		return a_ptr[1] - b_ptr[1];
	else
		return a_ptr[0] - b_ptr[0];
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes)
{
	int current = peopleSize-1; //��ǰ���˼·����ʼ��Ϊ���һ��Ԫ��
	int temp, temp_h, temp_k1, temp_k2; //�滻λ��ʱ����ת
	int same_num; //ǰ����ͬ�߶�h��Ԫ�ظ���
	
//	*returnColumnSizes = peopleColSize;//��Ҳ��֪�������ʲô�ã���Ŀû˵�������һ��Ҫд
	*returnSize = peopleSize;
	
	if (peopleSize == 0 || peopleSize == 1) //û�˻�ֻ��һ����(�������)
		return people;
	
	//��ԭ��������
	qsort(people, peopleSize, sizeof(people[0]), array_cmp);
	
	//���ҵ�h���ֵ���׸���
	while (people[current][1] != 0)
		current--;
	current--; //Ȼ���ҵ����ֵ��Ҫ��1
	
	while (current >= 0)
	{
		temp_k1 = people[current][1]; //���Ƶ�λ����
		
		if (temp_k1 > 0)
		{
			//�鿴ǰ���м�����ͬ�߶ȵ���
			same_num = 0; //��ʼ��
			while (current-1-same_num >= 0 && people[current][0] == people[current-1-same_num][0])
				same_num++; //�����ı�
			
			temp_k2 = temp_k1 - same_num;
			temp_h = people[current][0];
			temp = current;
			
			while (temp_k2 > 0)
			{
				people[temp][0] = people[temp+1][0];
				people[temp][1] = people[temp+1][1];
				temp_k2--;
				temp++;
			}
			
			people[temp][0] = temp_h;
			people[temp][1] = temp_k1;
		}
		current--;
	}
	
	return people;
}

void print (int **a, int len)
{
	int i;
	for (i = 0; i < len; i++)
		printf ("[%d,%d] ", a[i][0], a[i][1]);
	putchar('\n');
}

int main (void)
{
	int i;
	
//	int len = 7;
//	int a[7][2] = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}, {0,3}};
	int len = 1;
	int a[1][2] = {{0,0}};
	
	int **b;
	int returnlen;
	int **c;
	
	b = (int**)malloc(sizeof(int*)*len);
	for (i = 0; i < len; i++)
	{
		b[i] = (int*)malloc(sizeof(int)*2);
		b[i][0] = a[i][0];
		b[i][1] = a[i][1];
	}
	
	printf("����ǰ��");
	print(b, len);
	b = reconstructQueue(b, len, *c, &returnlen, c);
	printf("�����");
	print(b, len);
	
	return 0;
}
