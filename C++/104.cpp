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
    // int ans = 0;
    // void dfs(TreeNode* root, int depth) {
    //     if (root == NULL) return;
    //     ans = max(ans, depth);
    //     dfs(root->left, depth + 1);
    //     dfs(root->right, depth + 1);
    // }

    // int maxDepth(TreeNode* root) {
    //     if (root == NULL) return 0;
    //     dfs(root, 1);
    //     return ans;
    // }

    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            int cursize = q.size();

            for (int i = 0; i < cursize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ++ans;
        }
        return ans;
    }
};

int main() {
    return 0;
}