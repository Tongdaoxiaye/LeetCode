//102. �������Ĳ������
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> que;//�½�һ������
    vector<vector<int>> res;//����һ���������ڴ��ÿһ��ε�Ԫ��
    if (root != nullptr) que.push(root);
    while (!que.empty()) {
        vector<int> temp;
        for (int i = que.size();i > 0;--i) {
            root = que.front();
            que.pop();
            temp.push_back(root->val);
            if (root->left) que.push(root->left);
            if (root->right) que.push(root->right);
        }
        res.push_back(temp);
    }
    return res;
}

//int main() {
//    // ����ʾ�����빹�������� [3,9,20,null,null,15,7]
//    TreeNode* root = new TreeNode(3);
//    root->left = new TreeNode(9);
//    root->right = new TreeNode(20);
//    root->right->left = new TreeNode(15);
//    root->right->right = new TreeNode(7);
//
//    // ���ò����������
//    vector<vector<int>> result = levelOrder(root);
//
//    // ������
//    cout << "[";
//    for (int i = 0; i < result.size(); ++i) {
//        cout << "[";
//        for (int j = 0; j < result[i].size(); ++j) {
//            cout << result[i][j];
//            if (j != result[i].size() - 1) {
//                cout << ",";
//            }
//        }
//        cout << "]";
//        if (i != result.size() - 1) {
//            cout << ",";
//        }
//    }
//    cout << "]" << endl;
//
//    return 0;
//}

