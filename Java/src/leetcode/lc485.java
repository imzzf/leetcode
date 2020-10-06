package leetcode;

/**
 * @author zzf
 * @date 2020/10/03
 */
public class lc485 {
    public int findMaxConsecutiveOnes(int[] nums) {
        int count = 0, maxcount = 0;
        for (int num : nums) {
            if (num == 1) {
                ++count;
            } else if (num == 0) {
                maxcount = Math.max(count, maxcount);
                count = 0;
            }
        }
        return Math.max(count, maxcount);
    }
}
