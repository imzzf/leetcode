#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return res;
    }
    //回溯法
    void backtrack(string cur, int l, int r, int n) {
        if (cur.length() == 2 * n) {
            res.push_back(cur);
        }
        if (l < n) {  //如果左括号还剩余则能放一个左括号
            backtrack(cur + "(", l + 1, r, n);
        }
        if (r < l) {  //如果右括号少于左括号则能放一个右括号
            backtrack(cur + ")", l, r + 1, n);
        }
    }
};