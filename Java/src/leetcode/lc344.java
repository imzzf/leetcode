package leetcode;

/**
 * @author zzf
 * @date 2020/10/08
 */
public class lc344 {
    public void reverseString(char[] s) {
        int i = 0;
        int j = s.length - 1;
        while (i < j) {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
            ++i;
            --j;
        }
    }
}
