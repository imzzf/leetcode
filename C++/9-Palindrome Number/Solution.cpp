#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long long reverse = 0;  //防止溢出
        int _x            = x;
        while (_x != 0) {
            reverse = reverse * 10 + _x % 10;
            _x /= 10;
        }
        return x == reverse;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome(2147483647);

    return 0;
}