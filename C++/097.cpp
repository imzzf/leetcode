#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
   public:
    bool isInterleave(string s1, string s2, string s3) {
        int a = s1.size(), b = s2.size(), c = s3.size();
        // dp[i][j]表示s1的前i个字符与s2的前j个字符能否组成s3的前i+j个字符
        // dp[a][b]需要(a+1)*(b+1)大小
        vector<vector<bool>> dp(a + 1, vector<bool>(b + 1, false));

        // 首先保证长度是符合的
        if (a + b != c) {
            return false;
        }

        /**
         * dp[i][j]成立的条件是 dp[i-1][j]成立且s1的第i个字符与s3的第i+j个字符一致
         * 或者是 dp[i][j-1]成立且s2的第j个字符与s3的第i+j个字符一致
         */
        for (int i = 0; i <= a; ++i) {
            for (int j = 0; j <= b; ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
                } else {
                    dp[i][j] = (dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) || (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));
                }
            }
        }
        return dp[a][b];
    }
};

int main() {
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    Solution s;
    cout << s.isInterleave(s1, s2, s3);
    return 0;
}