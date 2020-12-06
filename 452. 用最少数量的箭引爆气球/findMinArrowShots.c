/*
452. 用最少数量的箭引爆气球
在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。
由于它是水平的，所以纵坐标并不重要，因此只要知道开始和结束的横坐标就足够了。开始坐标总是小于结束坐标。
一支弓箭可以沿着 x 轴从不同点完全垂直地射出。
在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend，且满足  xstart ≤ x ≤ xend，
则该气球会被引爆。可以射出的弓箭的数量没有限制。 
弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。

给你一个数组 points ，其中 points [i] = [xstart,xend] ，返回引爆所有气球所必须射出的最小弓箭数。
示例 1：
输入：points = [[10,16],[2,8],[1,6],[7,12]]
输出：2
解释：对于该样例，x = 6 可以射爆 [2,8],[1,6] 两个气球，以及 x = 11 射爆另外两个气球

示例 2：
输入：points = [[1,2],[3,4],[5,6],[7,8]]
输出：4

示例 3：
输入：points = [[1,2],[2,3],[3,4],[4,5]]
输出：2

示例 4：
输入：points = [[1,2]]
输出：1

示例 5：
输入：points = [[2,3],[2,3]]
输出：1
 
提示：
0 <= points.length <= 104
points[i].length == 2
-231 <= xstart < xend <= 231 - 1

解题思路：
说白了就是脑筋急转弯，先排序
1. 按左边界从大到小排序，每次从左边界中最右边的气球开始进行射击
2. 可推出：如果发生重叠，那么重叠部分的左边界一定与重叠气球中最右边的左边界重叠
3. 搞明白上一个推论后，就可以进行排序了
4. 然后每次从最右边的左边界开始射击，依次射击完后得到的次数就是最少的射击次数了
5. 要小心边界的范围，容易溢出
*/
#include <stdio.h>
#include <stdlib.h>

int cmp (const void *a, const void *b)
{
	int *_a = *(int**)a, *_b = *(int**)b;
	
	return _b[0] < _a[0] ? -1 : 1; //从大到小排序
}

int findMinArrowShots(int** points, int pointsSize)//, int* pointsColSize)
{
	if (pointsSize == 0)
		return 0;
		
	int arrowNums = 1; //统计次数
	int i; //循环遍历用
	int hit; //当前射击位置
	
	qsort (points, pointsSize, sizeof(int)*2, cmp);
	
	hit = points[0][0];
	for (i = 1; i < pointsSize; i++)
	{
		if (points[i][1] < hit)
		{
			arrowNums++; 
			hit = points[i][0];
		}
	}
	
	return arrowNums;
}

int main (void)
{
	int **a;
	int i;
	
	a = (int**)malloc(sizeof(int*)*4);
	for (i = 0; i < 4; i++)
	{
		a[i] = (int*)malloc(sizeof(int)*2);
		scanf ("%d %d", &a[i][0], &a[i][1]);
	}
	
	printf ("次数：%d\n", findMinArrowShots(a, 4));
	
	return 0;
}
