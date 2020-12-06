/*
148. 排序链表

给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

进阶：
你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
 
示例 1：
输入：head = [4,2,1,3]
输出：[1,2,3,4]

示例 2：
输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]

示例 3：
输入：head = []
输出：[]
 
提示：
链表中节点的数目在范围 [0, 5 * 104] 内
-105 <= Node.val <= 105

解题思路：
1. 排序+O(n log n)，我看了看，最符合条件的就是归并排序了
2. 归并排序有两种方式，递归和非递归
3. 我先尝试递归吧！
4. 其实这题超简单的，就是归并排序，只要在拆分时，将列表拆断即可（左边数据最后改为NULL）
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

//LBegin：左起始、LEnd：左结束(应该可以不要这个形参)、RBegin；右起始、REnd；右结束
struct ListNode* Msort (struct ListNode* LBegin, struct ListNode* RBegin)
{
	struct ListNode *result, *tail, *temp1, *temp2;
	
	result = (struct ListNode*)malloc(sizeof(struct ListNode));
	result->next = NULL;
	tail = result;
	
	//开始归并(尾插法)
	temp1 = LBegin;
	temp2 = RBegin;
	while (temp1 != NULL && temp2 != NULL)
	{
		if (temp1->val >= temp2->val)
		{
			tail->next = temp2;
			temp2 = temp2->next;
		}
		else
		{
			tail->next = temp1;
			temp1 = temp1->next;
		}
		tail = tail->next;
	}
	
	//接上剩余结点
	if (temp1 != NULL)
		tail->next = temp1;
	if (temp2 != NULL)
		tail->next = temp2;
	
	return result->next;
}

struct ListNode* Merging_sort(struct ListNode* head, struct ListNode* tail)
{
	struct ListNode *temp1, *temp2; //快慢指针
	
	if (head == NULL || head->next == NULL)
		return head;
	
	temp1 = head;
	temp2 = head->next;
	
	while (temp2 != tail) //一定要避免访问野指针
	{
		temp1 = temp1->next;
		temp2 = temp2->next;
		if (temp2 != tail)
			temp2 = temp2->next;
	}
	temp2 = temp1->next; //后段数据的首结点
	temp1->next = NULL; //相当于切断这组数据，切割成左右两组数据
	
	return Msort (Merging_sort (head, temp1), Merging_sort (temp2, tail));
}

struct ListNode* sortList(struct ListNode* head)
{
	return Merging_sort (head, NULL);
}

//leetcode答案
struct ListNode* merge(struct ListNode* head1, struct ListNode* head2) {
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->val = 0;
    struct ListNode *temp = dummyHead, *temp1 = head1, *temp2 = head2;
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->val <= temp2->val) {
            temp->next = temp1;
            temp1 = temp1->next;
        } else {
            temp->next = temp2;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    if (temp1 != NULL) {
        temp->next = temp1;
    } else if (temp2 != NULL) {
        temp->next = temp2;
    }
    return dummyHead->next;
}

struct ListNode* toSortList(struct ListNode* head, struct ListNode* tail) {
    if (head == NULL) {
        return head;
    }
    if (head->next == tail) {
        head->next = NULL;
        return head;
    }
    struct ListNode *slow = head, *fast = head;
    while (fast != tail) {
        slow = slow->next;
        fast = fast->next;
        if (fast != tail) {
            fast = fast->next;
        }
    }
    struct ListNode* mid = slow;
    return merge(toSortList(head, mid), toSortList(mid, tail));
}

struct ListNode* sortList(struct ListNode* head) {
    return toSortList(head, NULL);
}
