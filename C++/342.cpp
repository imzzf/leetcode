#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
   public:
    bool isPowerOfFour(int num) {
        /**
         * (num & (num - 1)) == 0 的作用是消去num最右侧的1，若结果为0，则num是2的幂
         * 观察4的幂，1只出现在奇数位，使用偶数位都是1的1010...1010相与，即0xaaaaaaaa，结果为0就是4的幂
         */
        return num > 0 && (num & (num - 1)) == 0 && (num & 0xaaaaaaaa) == 0;
    }
};

int main() {
    Solution s;
    cout << s.isPowerOfFour(16);
    return 0;
}