/*
454. 四数相加 II

给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。

为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。
所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。

例如:
输入:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

输出:
2

解释:
两个元组如下:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

解题思路：
1. 像这种题肯定不是简单的四重循环暴力解决的，这样就显得很没有出题水平
2. 由于我们是多个的不同数组的数据相加，所以为了减小时间复杂度，我们可以将多个数组拆分成一半（分而治之）
3. 这题提供了四个数组，我们就拆分成A+B & C+D，这样就达到了我们要的分而治之效果了
4. 了解完思路后，我们还要考虑拆分后计算出来的数据存放在哪里
5. 这里可以采取哈希表（单链表结构）存放结果，查找速度是最快的
6. 我们不需要将C+D也设计一个哈希表，而是直接计算C+D+哈希表数据是否为0，是的话就result += hash->num 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct HashNode{
	int data; //存放结果
	int num; //存放该结果的数量
	struct HashNode *next;
}HashNode, *HashTable;

void AddHash (HashTable*, int);
int FindHash (HashTable*, int, HashTable*);
int fourSumCount(int*, int, int*, int, int*, int, int*, int);
void printHash (HashTable);

//添加哈希表元素
void AddHash (HashTable *head, int test)
{
	HashTable temp = (HashTable)malloc(sizeof(HashNode));
	temp->data = test;
	temp->num = 1;
	temp->next = *head; //头插法
	*head = temp;
}

//查找哈希表元素
int FindHash (HashTable *head, int test, HashTable *temp)
{
	HashTable current = *head;
	
	while (current != NULL)
	{
		if (current->data == test)
		{
			*temp = current;
			return 1; //1:哈希表内存在该元素
		}
		current = current->next;
	}
	return 0; //0:哈希表内不存在该元素
}

//主算法
int fourSumCount(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize)
{
	int result = 0, test; //test:存放每次求和的值
	int i, j; //循环专用
	HashTable temp = NULL, head = NULL; 
	
	//统计A+B的哈希表
	for (i = 0; i < ASize; i++)
	{
		for (j = 0; j < BSize; j++)
		{
			test = A[i]+B[j];
			if (FindHash (&head, test, &temp))
				temp->num++;
			else
				AddHash (&head, test);
		}
	}
	
	printHash (head);
	
	//检测是否C+D+head->data == 0
	for (i = 0; i < CSize; i++)
	{
		for (j = 0; j < DSize; j++)
		{
			test = C[i]+D[j];
			if (FindHash (&head, -test, &temp))
				result += temp->num;
		}
	}
	
	return result;
}

//打印哈希表内的元素（检测调试用）
void printHash (HashTable head)
{
	HashTable current;
	
	printf ("哈希表：\n");
	for (current = head; current != NULL; current = current->next)
		printf ("data: %d, frequency: %d\n", current->data, current->num);
}

int main(void)
{
	int A[] = {-16,-30,-6,8,-26,-23,-14,-29,-23,10,7,9,5,-13,-2,-18,5,5,-31,-26,7,-32,-18,-30,-23,-30,9,-1,-13,-27,-9,-14,1,-18,-6,5,2,-15,-19,5,-17,6,-26,-11,-29,-15,-9,-12,-11,-18,-17,1,1,-1,-10,9,-3,7,0,-1,-10,10,-3,-26,-11,-27,-2,-26,-27,-8,-26,-23,-10,3,0,-11,-5,-4,-10,-31,8,-11,-22,-14,-9,-22,-20,-20,-5,-1,10,-29,-32,7,-26,-2,8,4,-15,-24};
	int B[] = {8,-15,-26,10,-21,-20,6,-20,-22,-6,8,-8,-27,-9,-1,-27,-2,-24,1,9,-1,-4,9,7,-21,-11,0,-7,3,4,-13,-19,-13,-32,-12,-30,-17,-5,-31,-21,-14,-23,-31,-6,-26,-4,-21,-12,1,-3,-3,5,4,-13,-2,-20,-16,-6,3,-16,-1,-18,-31,-2,4,-2,-32,-5,-7,5,-5,-22,-20,-26,8,-24,-8,-23,4,7,-10,-31,-22,-7,-26,6,-17,5,-28,5,6,-11,-29,-1,-1,-12,-32,-16,-8,-10};
	int C[] = {10,-25,-2,-1,-10,-18,-20,-17,10,-31,6,-12,5,-2,-19,-2,-25,-26,-21,-29,8,-28,-8,-18,-32,-24,-17,2,-25,-32,-7,3,-28,-31,-21,-9,2,-2,-18,-25,-14,-15,-11,5,-29,-23,-4,-4,10,0,-9,-24,6,-23,5,-7,-16,5,-17,6,-18,-8,5,-6,-29,-15,9,10,-12,8,5,3,5,9,-6,-25,-28,-21,8,-17,-31,-12,-2,2,-12,2,-28,9,-28,-13,-17,-27,10,-26,6,-25,-25,-19,10,-8};
	int D[] = {-6,-29,-15,-6,-16,-18,1,-27,-15,-8,4,-14,-11,-28,5,-13,-18,-30,-19,-17,-17,3,6,-7,-5,-23,-20,-32,0,-17,-24,-10,-11,-23,-12,-31,-29,-31,3,-18,-16,-13,10,-18,-28,-27,-1,-23,2,10,0,-5,-8,4,-18,-16,-3,-4,-22,-15,2,0,-30,1,-1,-14,-9,-24,-24,-17,10,0,-29,-9,-19,-12,-22,1,-14,-22,2,-31,-22,-30,-29,-16,-15,-15,-14,-25,-28,7,-29,-5,-30,7,9,5,0,-6};
	
//	int A[] = { 1, 2};
//	int B[] = {-2,-1};
//	int C[] = {-1, 2};
//	int D[] = { 0, 2};
	
	int len = sizeof(A)/sizeof(int);
	
	printf("%d\n", fourSumCount(A, len, B, len, C, len, D,len));
	
	return 0;
}
