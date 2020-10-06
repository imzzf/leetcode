package leetcode;

/**
 * @author zzf
 * @date 2020/10/05
 */
public class lc283 {
    public void moveZeroes(int[] nums) {
        int a = 0;
        int n = nums.length;
        for (int b = 0; b < n; ++b) {
            if (nums[b] != 0) {
                if (a != b) {
                    nums[a] = nums[b];
                    nums[b] = 0;
                }
                ++a;
            }
        }
    }
}
