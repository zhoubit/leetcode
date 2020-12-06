/*
222. 完全二叉树的节点个数
给出一个完全二叉树，求出该树的节点个数。

说明：
完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，
其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。
若最底层为第 h 层，则该层包含 1~ 2h 个节点。

示例:
输入: 
    1
   / \
  2   3
 / \  /
4  5 6
输出: 6

答题思路：
1. 说白了就是遍历二叉树，很简单的
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
		
	(*TreeNodeNum)++; //不为空的话，结点个数加1  
	PreorderTraversal (root->left, TreeNodeNum);
	PreorderTraversal (root->right, TreeNodeNum);
}

int countNodes(struct TreeNode *root){
	int TreeNodeNum = 0;
	
	PreorderTraversal (root, &TreeNodeNum);
	
	return TreeNodeNum;
}

//更简单暴力的方式：
int countNodes(struct TreeNode* root){
	if(root==NULL)
		return 0;
	return countNodes(root->left) + countNodes(root->right) + 1;
}
