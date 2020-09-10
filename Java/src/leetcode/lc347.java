package leetcode;

import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

/**
 * @author zzf
 * @date 2020/08/20
 */
public class lc347 {

    public int[] topKFrequent(int[] nums, int k) {

        //先用hashmap记录各数出现的频率
        Map<Integer, Integer> map = new HashMap<>();
        for (int p : nums) {
            if (map.containsKey(p)) {
                map.put(p, map.get(p) + 1);
            } else {
                map.put(p, 1);
            }
        }

        //用小根堆找出最多的k个数，存的是key，插入堆时比较的是value即出现的频率
        //堆的大小保证在k以内，于是各种操作的时间复杂度是O(nlogk)
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> map.get(a) - map.get(b));
        for (Integer p : map.keySet()) {
            pq.add(p);
            if (pq.size() > k) {
                pq.remove();
                pq.poll();
            }
        }
        int[] ans = new int[k];
        for (int i = 0; i < k; ++i) {
            ans[i] = pq.remove();
        }
        return ans;
    }
}
