package leetcode;

/**
 * @author zzf
 * @date 2020/10/11
 */
public class lc014 {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) {
            return "";
        }
        if (strs.length == 1) {
            return strs[0];
        }
        for (int i = 0; i < strs[0].length(); ++i) {
            char ch = strs[0].charAt(i);
            for (String str : strs) {
                if (i == str.length() || ch != str.charAt(i)) {
                    return strs[0].substring(0, i);
                }
            }
        }
        return strs[0];
    }
}