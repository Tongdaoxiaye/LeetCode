#include <iostream>
#include <queue>
using namespace std;


struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//先序遍历二叉树
void firstOut(TreeNode* n) {
	if (n) {
		firstOut(n->left);
		cout << n->val << " ";
		firstOut(n->right);
	}
}
//中序遍历二叉树
void midOut(TreeNode* n) {
	if (n) {
		cout << n->val << " ";
		midOut(n->left);
		midOut(n->right);
	}
}
//后序遍历二叉树
void lastOut(TreeNode* n) {
	if (n) {
		lastOut(n->left);
		lastOut(n->right);
		cout << n->val << " ";
	}
}

//层序遍历二叉树
void levelOut(TreeNode * root) {
	if (!root) return;
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		TreeNode* node = q.front();//获取队首元素
		q.pop();
		cout << node->val << " ";
		if (node->left) q.push(node->left);
		if (node->right) q.push(node->right);
	}
}

int main02() {
	//初始化节点
	TreeNode *n1 = new TreeNode(1);
	TreeNode *n2 = new TreeNode(2);
	TreeNode *n3 = new TreeNode(3);
	TreeNode *n4 = new TreeNode(4);
	TreeNode *n5 = new TreeNode(5);

	//建立节点关系
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;

	//遍历二叉树
	firstOut(n1);
	cout << endl;
	midOut(n1);
	cout << endl;
	lastOut(n1);
	cout << endl;
	levelOut(n1);
	return 0;
}