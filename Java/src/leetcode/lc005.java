package leetcode;

/**
 * @author zzf
 * @date 2020/08/19
 */
public class lc005 {

    public static String longestPalindrome(String s) {
        if (s == null || s.length() == 0) {
            return "";
        }
        int len = s.length();
        int maxlen = 0;
        int aa = 0, bb = 0;
        for (int i = 0; i < 2 * len - 1; ++i) {
            int a = i / 2;
            int b = i / 2 + i % 2;

            while (a >= 0 && b < len && s.charAt(a) == s.charAt(b)) {
                --a;
                ++b;
            }
            int curlen = b - a - 1;
            if (curlen > maxlen) {
                maxlen = curlen;
                aa = a + 1;
                bb = b - 1;
            }
        }

        return s.substring(aa, bb + 1);
    }

    public static void main(String[] args) {
        System.out.println(longestPalindrome("bababbb"));
    }
}
