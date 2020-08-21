package leetcode;

import java.util.LinkedList;
import java.util.Queue;

/**
 * @author zzf
 * @date 2020/08/21
 */
public class lc111 {

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    //dfs
    public int minDepth(TreeNode root) {
        // 用例[1,2]，此时返回的结果应该是2而不是1，因为节点1是根节点，题目要求的是从叶子节点到根节点的最短距离
        // 这里容易考虑不清
        if (root == null) {
            return 0;
        }
        // 左为空，不能直接返回1，需要根据右节点来判断
        if (root.left == null) {
            return minDepth(root.right) + 1;
        }
        // 同理
        if (root.right == null) {
            return minDepth(root.left) + 1;
        }
        //左右都不空，递归到左右节点
        int ans = Math.min(minDepth(root.left), minDepth(root.right));
        return ans + 1;
    }

    //bfs
    public int minDepth2(TreeNode root) {
        if (root == null) {
            return 0;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int ans = 0;
        while (!queue.isEmpty()) {
            //该层的节点数
            int p = queue.size();
            ++ans;
            //遍历这一层
            for (int i = 0; i < p; ++i) {
                TreeNode node = queue.poll();
                //找到叶子节点，答案即该层高度
                if (node.left == null && node.right == null) {
                    return ans;
                }
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
        }
        return -1;
    }
}
