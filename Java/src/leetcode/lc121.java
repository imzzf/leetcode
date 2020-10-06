package leetcode;

/**
 * @author zzf
 * @date 2020/10/05
 */
public class lc121 {
    public int maxProfit(int[] prices) {
        if (prices.length == 0) {
            return 0;
        }
        //记录截止当日的最大收益，第一天收益为0
        int ans = 0;
        //记录截止当日的股价最低值
        int min = prices[0];
        for (int price : prices) {
            min = Math.min(min, price);
            //每一天的最大收益 = max(前一天的最大收益, 当日价格 - 历史低值)
            ans = Math.max(ans, price - min);
        }
        return ans;
    }
}
