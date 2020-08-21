package leetcode;

/**
 * @author zzf
 * @date 2020/08/21
 */
public class lc125 {

    public static boolean isPalindrome(String s) {
        if ("".equals(s)) {
            return true;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); ++i) {
            char ch = s.charAt(i);
            if (ch >= 'A' && ch <= 'Z') {
                ch -= 'A' - 'a';
                sb.append(ch);
            } else if ((ch >= '0' && ch <= '9') || (ch >= 'a' & ch <= 'z')) {
                sb.append(ch);
            }
        }
        int i = 0;
        int j = sb.length() - 1;
        while (i <= j) {
            if (sb.charAt(i) == sb.charAt(j)) {
                ++i;
                --j;
            } else {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        String str = "A man, a plan, a canal: Panama";
        System.out.println(isPalindrome(str));
    }
}
