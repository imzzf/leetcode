package offer;

/**
 * @author zzf
 * @date 2020/09/09
 */
public class of42 {

    /**
     * 动态规划
     * dp[i]为以nums[i]结尾的连续子数组的最大值
     * 最后再求出所有dp[0..n-1]中的最大值
     *
     * @param nums
     * @return
     */
    public int maxSubArray(int[] nums) {
        int ans = nums[0];
        int pre = nums[0];
        int cur;
        for (int i = 1; i < nums.length; ++i) {
            if (pre >= 0) {
                cur = pre + nums[i];
            } else {
                cur = nums[i];
            }
            ans = Math.max(ans, cur);
            pre = cur;
        }
        return ans;
    }
}
