#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    bool same(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) return true;
        if ((p != NULL && q == NULL) || (p == NULL && q != NULL) || (p->val != q->val)) return false;
        return same(p->left, q->left) && same(p->right, q->right);
    }

    bool dfs(TreeNode *p, TreeNode *q) {
        if (p == NULL) return false;
        return same(p, q) || dfs(p->left, q) || dfs(p->right, q);
    }

    bool isSubtree(TreeNode *s, TreeNode *t) {
        return dfs(s, t);
    }
};

int main() {
    return 0;
}