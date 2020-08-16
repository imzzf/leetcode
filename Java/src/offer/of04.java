package offer;

/**
 * @author zzf
 * @date 2020/08/08
 */
public class of04 {
    public static class Solution {
        public boolean findNumberIn2DArray(int[][] matrix, int target) {
            if (matrix.length == 0 || matrix[0].length == 0) {
                return false;
            }
            int n = matrix.length;
            int m = matrix[0].length;
            int i = 0;
            int j = m - 1;
            while (i < n && j >= 0) {
                if (target > matrix[i][j]) {
                    ++i;
                } else if (target < matrix[i][j]) {
                    --j;
                } else {
                    return true;
                }
            }
            return false;
        }
    }
}
