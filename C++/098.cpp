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
    bool helper(TreeNode *root, ll lower, ll upper) {
        if (root == NULL) return true;
        if (root->val <= lower || root->val >= upper) return false;
        return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
    }

    bool isValidBST(TreeNode *root) {
        return helper(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};

int main() {
    return 0;
}