package leetcode;

/**
 * @author zzf
 * @date 2020/09/19
 */
public class lc404 {

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    public int sumOfLeftLeaves(TreeNode root) {
        if (root == null) {
            return 0;
        }
        //是否左叶子
        int ans = (root.left != null && root.left.left == null && root.left.right == null) ? root.left.val : 0;
        return ans + sumOfLeftLeaves(root.left) + sumOfLeftLeaves(root.right);
    }
}
