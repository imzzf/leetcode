package leetcode;

/**
 * @author zzf
 * @date 2020/10/16
 */
public class lc977 {
    public int[] sortedSquares(int[] A) {
        int n = A.length;
        int i = 0;
        int j = n - 1;
        int p = n - 1;
        int[] ans = new int[n];
        while (i <= j) {
            if (A[i] * A[i] > A[j] * A[j]) {
                ans[p--] = A[i] * A[i];
                ++i;
            } else {
                ans[p--] = A[j] * A[j];
                --j;
            }
        }
        return ans;
    }
}
