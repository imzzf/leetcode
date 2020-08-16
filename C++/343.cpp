#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
   public:
    int integerBreak(int n) {
        //其实就是剑指里的剪绳子

        // vector<int> dp(n + 1);
        // for (int i = 2; i <= n; ++i) {
        //     int curmax = 0;
        //     for (int j = 1; j < i; ++j) {
        //         curmax = max(curmax, max(j * (i - j), j * dp[i - j]));
        //     }
        //     dp[i] = curmax;
        // }
        // return dp[n];

        if (n == 2) return 1;
        if (n == 3) return 2;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        int m;
        for (int i = 4; i <= n; ++i) {
            m = 0;
            for (int j = 1; j <= i / 2; ++j) {
                m = max(dp[j] * dp[i - j], m);
            }
            dp[i] = m;
        }
        return dp[n];
    }
};

int main() {
    return 0;
}