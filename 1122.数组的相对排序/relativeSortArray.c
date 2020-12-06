/*
1122. 数组的相对排序
给你两个数组，arr1 和 arr2，

arr2 中的元素各不相同
arr2 中的每个元素都出现在 arr1 中
对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。

示例：
输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
输出：[2,2,2,1,4,3,3,9,6,7,19]
 

提示：
arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
arr2 中的元素 arr2[i] 各不相同
arr2 中的每个元素 arr2[i] 都出现在 arr1 中

思路：
1.我们采取在原数组的基础上进行移位操作
2.采取双重循环，外循环是关于数组2的下标，内循环是关于数组1的下标
3.每次一找到相同的元素就对数组1的元素进行交换
4.一定要有一个定位器，定位到目前数组1更新的位置
5.调整好相同的元素后，不相同的元素一定是放在最后面，可以采取冒泡排序
6.最终返回数组1 
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize)
{
	int address = 0; //记录目前已经更新好的数组1位置,初始化为0 
	int i1, i2; //数组1和数组2的元素地址
	int temp; //交换元的位置时的中间元素
	
	for (i2 = 0; i2 < arr2Size; i2++) //数组2的下标
	{
		for (i1 = address; i1 < arr1Size; i1++)
		{
			if (arr1[i1] == arr2[i2]) //找到相等的元素，则交换元素位置
			{
				temp = arr1[i1];
				arr1[i1] = arr1[address];
				arr1[address] = temp;
				address++; //更新位置,后面就可以跳过这个元素了
			}
		}
	}
	
	//冒泡排序
	for (i2 = arr1Size-1; i2 >= address; i2--) //下界
	{
		for (i1 = address; i1 < i2; i1++) //当前位置
		{
			if (arr1[i1] > arr1[i1+1]) //大的往后放
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
