/*
222. ��ȫ�������Ľڵ����
����һ����ȫ����������������Ľڵ������

˵����
��ȫ�������Ķ������£�����ȫ�������У�������ײ�ڵ����û�����⣬
����ÿ��ڵ������ﵽ���ֵ������������һ��Ľڵ㶼�����ڸò�����ߵ�����λ�á�
����ײ�Ϊ�� h �㣬��ò���� 1~ 2h ���ڵ㡣

ʾ��:
����: 
    1
   / \
  2   3
 / \  /
4  5 6
���: 6

����˼·��
1. ˵���˾��Ǳ������������ܼ򵥵�
*/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void PreorderTraversal (struct TreeNode *root, int *TreeNodeNum)
{
	if (root == NULL)
		return;
		
	(*TreeNodeNum)++; //��Ϊ�յĻ�����������1  
	PreorderTraversal (root->left, TreeNodeNum);
	PreorderTraversal (root->right, TreeNodeNum);
}

int countNodes(struct TreeNode *root){
	int TreeNodeNum = 0;
	
	PreorderTraversal (root, &TreeNodeNum);
	
	return TreeNodeNum;
}

//���򵥱����ķ�ʽ��
int countNodes(struct TreeNode* root){
	if(root==NULL)
		return 0;
	return countNodes(root->left) + countNodes(root->right) + 1;
}
