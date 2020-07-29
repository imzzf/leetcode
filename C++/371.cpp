#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
   public:
    int getSum(int a, int b) {
        int sum, carry;
        while (b != 0) {
            // 两数相异或，可以得到不含进位的和
            sum = a ^ b;
            // 使用G++没有问题，但在leetcode的编译器下负数左移会出问题，需要转为无符号整数
            // 两数相与，可以得到进位，需左移到正确位置
            carry = (unsigned)(a & b) << 1;
            a     = sum;
            b     = carry;
        }
        return a;
    }
};

int main() {
    Solution s;
    cout << s.getSum(-1, 1);
    return 0;
}