package leetcode;

/**
 * @author zzf
 * @date 2020/09/30
 */
public class lc701 {

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }


    public TreeNode insertIntoBST(TreeNode root, int val) {
        if (root == null) {
            return new TreeNode(val);
        }
        TreeNode curr = root;
        //将需要插入的值插入到二叉搜索树的叶子节点是最简单的方案
        while (curr != null) {
            if (curr.val > val) {
                //小于根节点，就在左子树
                if (curr.left != null) {
                    curr = curr.left;
                } else {
                    curr.left = new TreeNode(val);
                    break;
                }
            } else if (curr.val < val) {
                //大于根节点，就在右子树
                if (curr.right != null) {
                    curr = curr.right;
                } else {
                    curr.right = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
}
