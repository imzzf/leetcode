package leetcode;

/**
 * @author zzf
 * @date 2020/08/29
 */
public class lc070 {

    public int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        int a = 1, b = 2, c;
        for (int i = 2; i < n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
}
