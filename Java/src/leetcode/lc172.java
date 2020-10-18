package leetcode;

/**
 * @author zzf
 * @date 2020/10/16
 */
public class lc172 {
    public int trailingZeroes(int n) {
        int ans = 0;
        while (n != 0) {
            ans += n / 5;
            n /= 5;
        }
        return ans;
    }
}
