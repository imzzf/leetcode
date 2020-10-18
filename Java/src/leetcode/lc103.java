package leetcode;

import java.util.*;

/**
 * @author zzf
 * @date 2020/10/13
 */
public class lc103 {

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if (root == null) {
            return new LinkedList<>();
        }
        List<List<Integer>> ans = new LinkedList<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        boolean flag = true;
        while (!q.isEmpty()) {
            List<Integer> t = new LinkedList<>();
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode node = q.poll();
                if (flag) {
                    t.add(node.val);
                } else {
                    t.add(0, node.val);
                }
                if (node.left != null) {
                    q.offer(node.left);
                }
                if (node.right != null) {
                    q.offer(node.right);
                }

            }
            ans.add(t);
            flag = !flag;
        }
        return ans;
    }
}
