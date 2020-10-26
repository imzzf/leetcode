package leetcode;

/**
 * @author zzf
 * @date 2020/10/25
 */
public class lc136 {
    public int singleNumber(int[] nums) {
        // 题目要求不使用额外空间
        // 通过位运算异或的性质，a^a=0
        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }
        return ans;
    }
}
