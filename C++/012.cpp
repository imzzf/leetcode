#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string intToRoman(int num) {
        // 枚举所有可能出现的罗马数字组合
        vector<int> values  = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> strs = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string res;
        for (int i = 0; i < values.size(); i++) {
            while (num >= values[i]) {
                res.append(strs[i]);  //依次连接最大的小于该数的组合
                num -= values[i];
            }
        }
        return res;
    }
};