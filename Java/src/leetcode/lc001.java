package leetcode;

import java.util.HashMap;
import java.util.Map;

/**
 * @author zzf
 * @date 2020/08/06
 */
public class lc001 {
    public int[] twoSum(int[] nums, int target) {
        int[] ans = new int[2];
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            int t = target - nums[i];
            if (map.containsKey(t)) {
                ans[0] = i;
                ans[1] = map.get(t);
            }
            map.put(nums[i], i);
        }
        return ans;
    }

    public static void main(String[] args) {
        lc001 s = new lc001();
        int[] nums = {2, 7, 11, 15};
        int target = 9;
        int[] ans = s.twoSum(nums, target);
        System.out.println(ans[0] + " " + ans[1]);
    }
}
