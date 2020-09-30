package leetcode;

/**
 * @author zzf
 * @date 2020/09/23
 */
public class lc617 {

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if (t1 == null) {
            return t2;
        }
        if (t2 == null) {
            return t1;
        }
        TreeNode curr = new TreeNode(t1.val + t2.val);
        curr.left = mergeTrees(t1.left, t2.left);
        curr.right = mergeTrees(t1.right, t2.right);
        return curr;
    }
}
