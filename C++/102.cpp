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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        queue<TreeNode *> q;
        q.push(root);
        //bfs遍历，使用queue每次取出一层，再放入每个node的left与right结点
        while (!q.empty()) {
            int curr = q.size();
            ans.push_back(vector<int>());
            for (int i = 0; i < curr; ++i) {
                TreeNode *node = q.front();
                q.pop();
                ans.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}