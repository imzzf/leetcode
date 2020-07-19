#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                //不是9就不会产生进位，直接返回
                digits[i]++;
                return digits;
            }
        }
        //每一位都是9，经过遍历后每一位都置为0，进位的1需要在首位插入
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    Solution s;
    vector<int> digits = {9, 9, 9};
    vector<int> ans    = s.plusOne(digits);
    for (int p : ans) cout << p << " ";
    return 0;
}