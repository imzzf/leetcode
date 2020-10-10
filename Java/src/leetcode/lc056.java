package leetcode;

import java.util.Arrays;

/**
 * @author zzf
 * @date 2020/10/09
 */
public class lc056 {
    public int[][] merge(int[][] intervals) {
        if (intervals.length == 0) {
            return new int[0][];
        }
        Arrays.sort(intervals, (a, b) -> {
            return a[0] - b[0];
        });
        int[][] q = new int[intervals.length][];
        q[0] = intervals[0];
        int p = 0;
        for (int i = 1; i < intervals.length; ++i) {
            int r = q[p][1];
            if (r >= intervals[i][0]) {
                int t = intervals[i][1];
                if (t > r) {
                    q[p][1] = t;
                }
            } else {
                q[++p] = intervals[i];
            }
        }
        int[][] ans = new int[p + 1][];
        for (int i = 0; i <= p; ++i) {
            ans[i] = q[i];
        }
        return ans;
    }
}
