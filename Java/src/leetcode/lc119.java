package leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * @author zzf
 * @date 2020/10/08
 */
public class lc119 {

    //参考 https://leetcode.com/problems/pascals-triangle-ii/discuss/38420/Here-is-my-brief-O(k)-solution/36288
    public List<Integer> getRow(int rowIndex) {
        List<Integer> ans = new ArrayList<>();
        ans.add(1);
        for (int i = 1; i <= rowIndex; ++i) {
            //只使用一维数组，可以从后往前遍历，就不会覆盖掉下次求和所需的数了
            for (int j = i - 1; j >= 1; --j) {
                ans.set(j, ans.get(j) + ans.get(j - 1));
            }
            ans.add(1);
        }
        return ans;
    }
}
