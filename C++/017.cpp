#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<string> res;
    map<string, string> number_letter = {
        {"2", "abc"},
        {"3", "def"},
        {"4", "ghi"},
        {"5", "jkl"},
        {"6", "mno"},
        {"7", "pqrs"},
        {"8", "tuv"},
        {"9", "wxyz"}};
    vector<string> letterCombinations(string digits) {
        if (digits.length() != 0) {
            backtrack("", digits);
        }
        return res;
    }
    //回溯法
    void backtrack(string combination, string next_digits) {
        if (next_digits.length() == 0) {
            res.push_back(combination);
        } else {
            string digit   = next_digits.substr(0, 1);  //先取数字串的第一位
            string letters = number_letter[digit];
            for (int i = 0; i < letters.length(); i++) {
                string letter = letters.substr(i, 1);  //取出待添加到字符串最后的字母
                backtrack(combination + letter, next_digits.substr(1));
            }
        }
    }
};

int main() {
    Solution s;
    string digits      = "234";
    vector<string> res = s.letterCombinations(digits);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}