#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    // vector<int> ans;
    // vector<int> preorderTraversal(TreeNode *root) {
    //     helper(root);
    //     return ans;
    // }

    // void helper(TreeNode *root) {
    //     if (!root) return;
    //     ans.push_back(root->val);
    //     helper(root->left);
    //     helper(root->right);
    // }

    //非递归方法需要使用stack，由于栈的特性必须先入右结点，再入左结点，出栈时才能先左后右
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (!root) return ans;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            ans.push_back(node->val);
            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
        }
        return ans;
    }

    vector<int> preorderTraversal_2(TreeNode *root) {
        vector<int> ans;
        if (!root) return ans;
        stack<TreeNode *> s;
        TreeNode *node = root;
        while (node || !s.empty()) {
            while (node) {
                ans.push_back(node->val);
                s.push(node->right);
                node = node->left;
            }
            node = s.top();
            s.pop();
        }
        return ans;
    }
};

int main() {
    return 0;
}