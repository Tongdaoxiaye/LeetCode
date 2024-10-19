#include <iostream>
using namespace std;


struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//�������������
void firstOut(TreeNode* n) {
	if (n) {
		firstOut(n->left);
		cout << n->val << " ";
		firstOut(n->right);
	}
}
//�������������
void midOut(TreeNode* n) {
	if (n) {
		cout << n->val << " ";
		midOut(n->left);
		midOut(n->right);
	}
}
//�������������
void lastOut(TreeNode* n) {
	if (n) {
		lastOut(n->left);
		lastOut(n->right);
		cout << n->val << " ";
	}
}

int main() {
	//��ʼ���ڵ�
	TreeNode *n1 = new TreeNode(1);
	TreeNode *n2 = new TreeNode(2);
	TreeNode *n3 = new TreeNode(3);
	TreeNode *n4 = new TreeNode(4);
	TreeNode *n5 = new TreeNode(5);

	//�����ڵ��ϵ
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;

	firstOut(n1);
	cout << endl;
	midOut(n1);
	cout << endl;
	lastOut(n1);
}