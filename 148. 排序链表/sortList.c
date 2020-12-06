/*
148. ��������

���������ͷ��� head ���뽫�䰴 ���� ���в����� ���������� ��

���ף�
������� O(n log n) ʱ�临�ӶȺͳ������ռ临�Ӷ��£����������������
 
ʾ�� 1��
���룺head = [4,2,1,3]
�����[1,2,3,4]

ʾ�� 2��
���룺head = [-1,5,3,4,0]
�����[-1,0,3,4,5]

ʾ�� 3��
���룺head = []
�����[]
 
��ʾ��
�����нڵ����Ŀ�ڷ�Χ [0, 5 * 104] ��
-105 <= Node.val <= 105

����˼·��
1. ����+O(n log n)���ҿ��˿�������������ľ��ǹ鲢������
2. �鲢���������ַ�ʽ���ݹ�ͷǵݹ�
3. ���ȳ��Եݹ�ɣ�
4. ��ʵ���ⳬ�򵥵ģ����ǹ鲢����ֻҪ�ڲ��ʱ�����б��ϼ��ɣ������������ΪNULL��
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

//LBegin������ʼ��LEnd�������(Ӧ�ÿ��Բ�Ҫ����β�)��RBegin������ʼ��REnd���ҽ���
struct ListNode* Msort (struct ListNode* LBegin, struct ListNode* RBegin)
{
	struct ListNode *result, *tail, *temp1, *temp2;
	
	result = (struct ListNode*)malloc(sizeof(struct ListNode));
	result->next = NULL;
	tail = result;
	
	//��ʼ�鲢(β�巨)
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
	
	//����ʣ����
	if (temp1 != NULL)
		tail->next = temp1;
	if (temp2 != NULL)
		tail->next = temp2;
	
	return result->next;
}

struct ListNode* Merging_sort(struct ListNode* head, struct ListNode* tail)
{
	struct ListNode *temp1, *temp2; //����ָ��
	
	if (head == NULL || head->next == NULL)
		return head;
	
	temp1 = head;
	temp2 = head->next;
	
	while (temp2 != tail) //һ��Ҫ�������Ұָ��
	{
		temp1 = temp1->next;
		temp2 = temp2->next;
		if (temp2 != tail)
			temp2 = temp2->next;
	}
	temp2 = temp1->next; //������ݵ��׽��
	temp1->next = NULL; //�൱���ж��������ݣ��и��������������
	
	return Msort (Merging_sort (head, temp1), Merging_sort (temp2, tail));
}

struct ListNode* sortList(struct ListNode* head)
{
	return Merging_sort (head, NULL);
}

//leetcode��
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
