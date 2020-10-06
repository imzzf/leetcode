package leetcode;

/**
 * @author zzf
 * @date 2020/10/03
 */
public class lc495 {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        if (timeSeries.length == 0) {
            return 0;
        }
        if (timeSeries.length == 1) {
            return duration;
        }
        int ans = duration;
        for (int i = 1; i < timeSeries.length; ++i) {
            if (timeSeries[i] >= duration + timeSeries[i - 1]) {
                ans += duration;
            } else {
                ans += timeSeries[i] - timeSeries[i - 1];
            }
        }
        return ans;
    }
}
