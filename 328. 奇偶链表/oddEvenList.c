/*
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。
请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，
而不是节点的值的奇偶性。

请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

示例 1:
输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL

示例 2:
输入: 2->1->3->5->6->4->7->NULL 
输出: 2->3->6->7->1->5->4->NULL

说明:
应当保持奇数节点和偶数节点的相对顺序。
链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。

方法：
1.标记单双数的尾巴
2.要抓住当前结点就是双数尾巴的后继结点的特点
3.找一个计数器计算单双数
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
	int i = 3; //计数（检验单双数，从第三位开始）
	struct ListNode *oddTail, *evenTail, *current, *temp;
			//单数尾巴、双数尾巴、当前读取结点、当前插入结点
	
	oddTail = head;
	if (oddTail == NULL) //一定要提前判断，避免后面引用空指针
		return head;
	evenTail = oddTail->next;
	if (evenTail == NULL)
		return head;
	
	current = evenTail->next; //标记当前结点
	while (current != NULL)
	{
		//插入待插入结点
		if (i % 2 == 1) //单数
		{
			evenTail->next = current->next; //取出成功
			current->next = oddTail->next;
			oddTail->next = current;
			oddTail = current;
		}
		else //双数
			evenTail = current;
		
		i++;
		current = evenTail->next; //更新当前结点
	}
	
	return head;
}

void getinput(struct ListNode *book)
{
	printf ("请输入数字：");
	scanf ("%d", &book->val);
}

void addBook(struct ListNode **library) //在这里为什么两个*，即指向指针的指针。因为你要修改的是指针的值，所以你要找到它的地址。 
{
	struct ListNode *book;
	
	book = (struct ListNode *)malloc(sizeof(struct ListNode));  //待插入的项 
	if (book == NULL)
	{
		printf ("很遗憾，内存失败了！\n");
		exit(1);
	}
	
	getinput(book);
	
	if (*library != NULL) //如果原来的头有数据了 
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
	printf ("反转前：");
	print (A);
	A = oddEvenList (A);
	printf ("反转后：");
	print (A);
	return 0;
}
