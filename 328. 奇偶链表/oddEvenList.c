/*
����һ�������������е������ڵ��ż���ڵ�ֱ�����һ��
��ע�⣬����������ڵ��ż���ڵ�ָ���ǽڵ��ŵ���ż�ԣ�
�����ǽڵ��ֵ����ż�ԡ�

�볢��ʹ��ԭ���㷨��ɡ�����㷨�Ŀռ临�Ӷ�ӦΪ O(1)��ʱ�临�Ӷ�ӦΪ O(nodes)��nodes Ϊ�ڵ�������

ʾ�� 1:
����: 1->2->3->4->5->NULL
���: 1->3->5->2->4->NULL

ʾ�� 2:
����: 2->1->3->5->6->4->7->NULL 
���: 2->3->6->7->1->5->4->NULL

˵��:
Ӧ�����������ڵ��ż���ڵ�����˳��
����ĵ�һ���ڵ���Ϊ�����ڵ㣬�ڶ����ڵ���Ϊż���ڵ㣬�Դ����ơ�

������
1.��ǵ�˫����β��
2.Ҫץס��ǰ������˫��β�͵ĺ�̽����ص�
3.��һ�����������㵥˫��
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

void print (struct ListNode *A)
{
	struct ListNode *current;
	
	for (current = A; current != NULL; current = current->next)
		printf ("%d ", current->val);
}

struct ListNode* oddEvenList(struct ListNode* head)
{
	int i = 3; //���������鵥˫�����ӵ���λ��ʼ��
	struct ListNode *oddTail, *evenTail, *current, *temp;
			//����β�͡�˫��β�͡���ǰ��ȡ��㡢��ǰ������
	
	oddTail = head;
	if (oddTail == NULL) //һ��Ҫ��ǰ�жϣ�����������ÿ�ָ��
		return head;
	evenTail = oddTail->next;
	if (evenTail == NULL)
		return head;
	
	current = evenTail->next; //��ǵ�ǰ���
	while (current != NULL)
	{
		//�����������
		if (i % 2 == 1) //����
		{
			evenTail->next = current->next; //ȡ���ɹ�
			current->next = oddTail->next;
			oddTail->next = current;
			oddTail = current;
		}
		else //˫��
			evenTail = current;
		
		i++;
		current = evenTail->next; //���µ�ǰ���
	}
	
	return head;
}

void getinput(struct ListNode *book)
{
	printf ("���������֣�");
	scanf ("%d", &book->val);
}

void addBook(struct ListNode **library) //������Ϊʲô����*����ָ��ָ���ָ�롣��Ϊ��Ҫ�޸ĵ���ָ���ֵ��������Ҫ�ҵ����ĵ�ַ�� 
{
	struct ListNode *book;
	
	book = (struct ListNode *)malloc(sizeof(struct ListNode));  //��������� 
	if (book == NULL)
	{
		printf ("���ź����ڴ�ʧ���ˣ�\n");
		exit(1);
	}
	
	getinput(book);
	
	if (*library != NULL) //���ԭ����ͷ�������� 
	{
		book->next = *library;
		*library = book;
	}
	else
	{
		*library = book;
		book->next = NULL;
	}
}

int main (void)
{
	int i;
	struct ListNode *A;
	A = NULL;
	
	for (i = 0; i < 5; i++)
		addBook (&A);
	printf ("��תǰ��");
	print (A);
	A = oddEvenList (A);
	printf ("��ת��");
	print (A);
	return 0;
}
