#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
   public:
    int numDecodings(string s) {
        int len = s.length();
        if (len == 0) return 0;
        if (len == 1) {
            if (s[0] == '0')
                return 0;
            else
                return 1;
        }
        vector<int> dp(len + 1);
        // dp[i+1]表示s[0..i]的解码方案数
        if (s[0] == '0') return 0;
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') {//出现0时，只有10和20是可解码的
                    dp[i + 1] = dp[i - 1];
                } else {
                    return 0;
                }
            } else {
                //只有11-19、21-26可以通过合并或拆分来解码
                if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6' && s[i] >= '0')) {
                    dp[i + 1] = dp[i - 1] + dp[i];
                } else {
                    dp[i + 1] = dp[i];
                }
            }
        }
        return dp[len];
    }
};

int main() {
    return 0;
}