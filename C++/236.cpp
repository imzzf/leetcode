#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    unordered_map<int, TreeNode*> m;
    unordered_map<int, bool> vis;

    void dfs(TreeNode* root) {
        if (root->left != NULL) {
            m[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right != NULL) {
            m[root->right->val] = root;
            dfs(root->right);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        m[root->val] = NULL;
        dfs(root);
        while (p != NULL) {
            vis[p->val] = true;
            p           = m[p->val];
        }
        while (q != NULL) {
            if (vis[q->val]) return q;
            q = m[q->val];
        }
        return NULL;
    }
};

int main() {
    Solution s;
    return 0;
}