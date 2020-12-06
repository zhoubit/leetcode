/*
406. 根据身高重建队列
假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

注意：
总人数少于1100人。

示例
输入:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

输出:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 
 思路：
 1. 先对整个队列进行排序，身高由高到低，身高相等的前提下第二个参数由高到低排序
 2. 对[hmax,kmin](在身高最高的人里面选k最小的元素)的位置进行标记，假设位置为[i]
 3. 这里要注意，一旦排好序后，hmax的元素的相对位置不变，所以从[i-1]开始向右移动
 4. 移动距离 d = k-前面出现people[i-1][0]的次数;
 4. 依次插入，直至people[0]也插入完毕
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
	int current = peopleSize-1; //按前面的思路，初始化为最后一个元素
	int temp, temp_h, temp_k1, temp_k2; //替换位置时的中转
	int same_num; //前面相同高度h的元素个数
	
//	*returnColumnSizes = peopleColSize;//我也不知道这个有什么用，题目没说清楚，但一定要写
	*returnSize = peopleSize;
	
	if (peopleSize == 0 || peopleSize == 1) //没人或只有一个人(特殊情况)
		return people;
	
	//对原数据排序
	qsort(people, peopleSize, sizeof(people[0]), array_cmp);
	
	//先找到h最大值的首个人
	while (people[current][1] != 0)
		current--;
	current--; //然后找到最大值后还要减1
	
	while (current >= 0)
	{
		temp_k1 = people[current][1]; //后移的位移量
		
		if (temp_k1 > 0)
		{
			//查看前面有几个相同高度的人
			same_num = 0; //初始化
			while (current-1-same_num >= 0 && people[current][0] == people[current-1-same_num][0])
				same_num++; //数量改变
			
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
	
	printf("排序前：");
	print(b, len);
	b = reconstructQueue(b, len, *c, &returnlen, c);
	printf("排序后：");
	print(b, len);
	
	return 0;
}
