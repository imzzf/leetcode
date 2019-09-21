#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isMatch(string s, string p) {
        //动态规划

        int m = s.length();
        int n = p.length();

        //dp[i][j]表示 s的前i个字符 与 p的前j个字符是否匹配
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;

        //匹配p开头连续的'*'
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = true;
            } else {
                break;
            }
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    //p的第j位为*
                    //例如   s=abc  p=ab*  dp[3][3]=dp[2][3]
                    //      s=ab  p=ab*  dp[2][3]=dp[2][2]
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    //p的第j位为?  或  字符匹配上
                    //例如   s=abcd  p=defd  dp[4][4]=dp[3][3]
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    //其他情况
                    dp[i][j] = false;
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution solution;
    string s = "pgsdpsj";
    string p = "*sd*";
    cout << (solution.isMatch(s, p) ? "true" : "false");
    return 0;
}