package leetcode;

/**
 * @author zzf
 * @date 2020/09/23
 */
public class lc169 {

    /**
     * Boyer-Moore 投票算法
     * 只需遍历一次就可得到众数
     * 由于众数在数组中多于一半，将众数看作+1，将其他数看作-1，最终总和必大于0
     * 思路是当计数器为0时，换新的候选人
     * 计数器非0时，且与候选人一致时，计数器+1，与候选人不一致时，计数器-1
     * 最终留下来的必然是众数
     *
     * 投票算法证明，来自评论区
     * 如果候选人不是maj，则maj会和其他非候选人一起反对候选人，所以候选人一定会下台(maj==0时发生换届选举)
     * 如果候选人是maj，则maj会支持自己，其他候选人会反对，同样因为maj票数超过一半，所以maj一定会成功当选
     */
    public int majorityElement(int[] nums) {
        int candidate = nums[0];
        int count = 1;
        for (int i = 1; i < nums.length; ++i) {
            if (count == 0) {
                candidate = nums[i];
            }
            if (nums[i] == candidate) {
                ++count;
            } else {
                --count;
            }
        }
        return candidate;
    }
}
