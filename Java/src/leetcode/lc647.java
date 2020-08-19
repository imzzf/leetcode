package leetcode;

/**
 * @author zzf
 * @date 2020/08/19
 */
public class lc647 {

    public int countSubstrings(String s) {
        if (s.length() == 0) {
            return 0;
        }
        int len = s.length();
        int ans = 0;
//        //奇数长度
//        for (int i = 0; i < len; ++i) {
//            int a = i, b = i;
//            while (a >= 0 && b < len && s.charAt(a) == s.charAt(b)) {
//                ++ans;
//                --a;
//                ++b;
//            }
//        }
//        //偶数长度
//        for (int i = 0; i < len - 1; ++i) {
//            int a = i, b = i + 1;
//            while (a >= 0 && b < len && s.charAt(a) == s.charAt(b)) {
//                ++ans;
//                --a;
//                ++b;
//            }
//        }

        //将两种情况合并
        //总共有2n-1个回文中心
        for (int i = 0; i < 2 * len - 1; ++i) {
            int a = i / 2, b = i / 2 + i % 2;
            while (a >= 0 && b < len && s.charAt(a) == s.charAt(b)) {
                ++ans;
                --a;
                ++b;
            }
        }
        return ans;
    }
}
