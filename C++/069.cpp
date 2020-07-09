#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
   public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int l = 0, r = x / 2 + 1;
        ll mid;
        while (l <= r) {
            mid  = l + ((r - l) >> 1);
            ll t = mid * mid;
            if (x > t) {
                l = mid + 1;
            } else if (x < t) {
                r = mid - 1;
            } else {
                return mid;
            }
        }
        return r;
    }
};

int main() {
    Solution s;
    int x = 99;
    cout << s.mySqrt(x);
    return 0;
}