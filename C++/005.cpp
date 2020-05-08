#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // 中心扩展算法
    // 求出以此为中心的最长回文串的长度
    // 从每次寻找的中心向左右两侧扩展直到出现不一致
    int expandAroundCenter(string s, int l, int r) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;
    }

    string longestPalindrome(string s) {
        if (s.length() == 0) return "";
        int len   = s.length();
        int begin = 0, end = 0;
        int m = 0;
        for (int i = 0; i < len; ++i) {
            // 奇数长度的回文串
            int a = expandAroundCenter(s, i, i);
            // 偶数长度的回文串
            int b = expandAroundCenter(s, i, i + 1);
            m     = max(a, b);
            if (m > end - begin + 1) {
                begin = i - (m - 1) / 2;
                end   = i + m / 2;
            }
        }
        return s.substr(begin, end - begin + 1);
    }
};

int main() {
    Solution s;
    string str = "babad";
    cout << s.longestPalindrome(str);

    return 0;
}