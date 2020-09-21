package leetcode;

/**
 * @author zzf
 * @date 2020/09/21
 */
public class lc538 {

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }


    int sum = 0;

    public TreeNode convertBST(TreeNode root) {
        // 由于给定的二叉搜索树，中序遍历得到的结果是一个升序序列
        // 需要将比该节点大的值都加上，我们可以反向进行中序遍历就可以得到降序排列
        // 依次进行累加，直到遍历到的节点，就可以得到所有比它大的数的和
        if (root != null) {
            convertBST(root.right);
            sum += root.val;
            root.val = sum;
            convertBST(root.left);
        }
        return root;
    }

}
