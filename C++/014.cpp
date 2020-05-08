#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return {};
        }
        if (strs.size() == 1) {
            return strs[0];
        }
        string prefix = strs[0];
        for (int i = 0; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.size() == 0) {
                    return {};
                }
            }
        }
        return prefix;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"flower", "flow", "flight"};
    //vector<string> strs = {};
    cout << s.longestCommonPrefix(strs);
    return 0;
}