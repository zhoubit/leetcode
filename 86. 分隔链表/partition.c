/*
86. �ָ�����

����һ�������һ���ض�ֵ x �������������зָ���ʹ������С�� x �Ľڵ㶼�����ڴ��ڻ���� x �Ľڵ�֮ǰ��
��Ӧ����������������ÿ���ڵ�ĳ�ʼ���λ�á�

ʾ����
���룺head = 1->4->3->2->5->2, x = 3
�����1->2->2->4->3->5

�������̣�
1. �����Ҿ��û��Ǻܼ򵥵ģ�ֱ�Ӳ�ֳ����ͺ��ˣ�Ȼ������������
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
				pre = head; //һ��ϸ�ھ���Ҫ�޸�pre��λ�ã���Ȼ�����
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
