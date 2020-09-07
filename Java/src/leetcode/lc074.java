package leetcode;

/**
 * @author zzf
 * @date 2020/09/07
 */
public class lc074 {

    /**
     * 从右上角按行和列缩小查找范围
     * O(m+n)
     *
     * @param matrix
     * @param target
     * @return
     */
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }
        int i = 0;
        int j = matrix[0].length - 1;
        while (i <= matrix.length - 1 && j >= 0) {
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

    /**
     * 二分查找
     * O(log(mn))
     *
     * @param matrix
     * @param target
     * @return
     */
    public boolean searchMatrix2(int[][] matrix, int target) {
        if (matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }
        int m = matrix.length;
        int n = matrix[0].length;
        int l = 0;
        int r = m * n - 1;
        while (l <= r) {
            //记得移位加括号，+ -优先级比>> <<高
            int mid = l + ((r - l) >> 1);
//            int mid = (l + r) >> 1;
            int cur = matrix[mid / n][mid % n];
            if (target > cur) {
                l = mid + 1;
            } else if (target < cur) {
                r = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }

}
