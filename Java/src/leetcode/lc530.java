package leetcode;

/**
 * @author zzf
 * @date 2020/10/12
 */
public class lc530 {

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    TreeNode pre;
    int ans = Integer.MAX_VALUE;

    public int getMinimumDifference(TreeNode root) {
        dfs(root);
        return ans;
    }

    public void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root.left);
        if (pre != null) {
            ans = Math.min(ans, root.val - pre.val);
        }
        pre = root;
        dfs(root.right);
    }

}
