package leetcode;

import java.util.LinkedList;
import java.util.List;

/**
 * @author zzf
 * @date 2020/08/19
 */
public class lc077 {

    List<List<Integer>> ans = new LinkedList<>();

    public void backtrack(int begin, List<Integer> cur, int n, int k) {
        if (cur.size() == k) {
            ans.add(new LinkedList<>(cur));
            return;
        }
        //这里进行剪枝
//        for (int i = begin; i <= n; ++i) {
        //1 2 3 4 5中取3个数，此时取第一个数，但是无需遍历到5
        //因为第一个数到了5，那么后面的数就无法取值，进行了不必要的操作，因此只需要遍历到3
        //maxi=5-3+1
        for (int i = begin; i <= n - (k - cur.size()) + 1; ++i) {
            cur.add(i);
            backtrack(i + 1, cur, n, k);
            cur.remove(cur.size() - 1);
        }
    }

    public List<List<Integer>> combine(int n, int k) {
        backtrack(1, new LinkedList<>(), n, k);
        return ans;
    }
}
