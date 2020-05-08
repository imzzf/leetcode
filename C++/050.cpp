#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    double myPow(double x, int n) {
        //暴力法
        //在 0.00001  2147483647 超时了
        // double ans = 1;
        // if (n < 0) {
        //     x = 1 / x;
        //     n = -n;
        // }
        // for (int i = 0; i < n; ++i) {
        //     ans *= x;
        // }
        // return ans;

        //快速幂
        double ans  = 1;
        long long i = n;
        //当 n = -2147483648 时取负会溢出，用长整型来记录绝对值
        i = i < 0 ? -i : i;
        //将指数n用2的幂之和表示
        for (i; i != 0; i /= 2) {
            if (i & 1) {
                ans *= x;
            }
            x *= x;
        }
        return n > 0 ? ans : (1 / ans);
    }
};

int main() {
    Solution s;

    double x = 1.00000;
    int n    = -2147483648;
    cout << s.myPow(x, n);
    return 0;
}
