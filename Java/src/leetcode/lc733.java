package leetcode;

import java.util.LinkedList;
import java.util.Queue;

/**
 * @author zzf
 * @date 2020/08/16
 */
public class lc733 {
    //dfs
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor) {
            dfs(image, sr, sc, image[sr][sc], newColor);
        }
        return image;
    }

    public void dfs(int[][] image, int x, int y, int color, int newColor) {
        if (x < 0 || y < 0 || x == image.length || y == image[0].length || image[x][y] != color || image[x][y] == newColor) {
            return;
        }
        image[x][y] = newColor;
        dfs(image, x + 1, y, color, newColor);
        dfs(image, x, y + 1, color, newColor);
        dfs(image, x - 1, y, color, newColor);
        dfs(image, x, y - 1, color, newColor);
    }

    //bfs
    public int[][] floodFill2(int[][] image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color == newColor) {
            return image;
        }
        image[sr][sc] = newColor;
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{sr, sc});
        while (!queue.isEmpty()) {
            int[] p = queue.poll();
            int x = p[0];
            int y = p[1];
            image[x][y] = newColor;
            if (x + 1 < image.length && image[x + 1][y] == color) {
                queue.offer(new int[]{x + 1, y});
            }
            if (y + 1 < image[0].length && image[x][y + 1] == color) {
                queue.offer(new int[]{x, y + 1});
            }
            if (x - 1 >= 0 && image[x - 1][y] == color) {
                queue.offer(new int[]{x - 1, y});
            }
            if (y - 1 >= 0 && image[x][y - 1] == color) {
                queue.offer(new int[]{x, y - 1});
            }
        }
        return image;
    }
}
