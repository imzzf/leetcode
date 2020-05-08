#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isValid(string s) {
        map<string, string> map = {{")", "("}, {"]", "["}, {"}", "{"}};
        stack<string> stack;
        for (int i = 0; i < s.length(); i++) {
            string current = s.substr(i, 1);
            if (map.count(current)) {//如果是右括号
                if (stack.size() == 0 || map[current] != stack.top()) {
                    //如果栈中无括号或者栈顶非对应的左括号
                    return false;
                } else {
                    stack.pop();
                }
            } else {
                stack.push(current);//将左括号入栈
            }
        }
        return stack.empty();//栈空则有效，栈有余留则无效
    }
};
int main() {
    Solution solution;
    string s = "()[]{[]}";
    cout << solution.isValid(s);
    return 0;
}