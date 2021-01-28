/*
86. 分隔链表

给你一个链表和一个特定值 x ，请你对链表进行分隔，使得所有小于 x 的节点都出现在大于或等于 x 的节点之前。
你应当保留两个分区中每个节点的初始相对位置。

示例：
输入：head = 1->4->3->2->5->2, x = 3
输出：1->2->2->4->3->5

解题历程：
1. 这题我觉得还是很简单的，直接拆分出来就好了，然后再连接起来
*/


struct ListNode {
	int val;
	struct ListNode *next;
}ListNode;



struct ListNode* partition(struct ListNode* head, int x)
{
	if (head == NULL || head->next == NULL)
		return head;
	
	struct ListNode *ret_head, *ret_tail, *cur, *pre;
	
	cur = head;
	pre = cur;
	ret_head = (struct ListNode*)malloc(sizeof(struct ListNode));
	ret_head->next = NULL;
	ret_tail = ret_head;
	
	while (cur != NULL)
	{
		if (cur->val < x)
		{
			ret_tail->next = cur;
			ret_tail = cur;
			pre->next = cur->next;
			
			if (cur == head)
			{
				head = cur->next;
				pre = head; //一个细节就是要修改pre的位置，不然会出错
			}
		}
		else
			pre = cur;
		
		cur = cur->next;
		ret_tail->next = NULL;
	}
	ret_tail->next = head;
	
	return ret_head->next; 
}
