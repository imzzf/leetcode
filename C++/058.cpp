#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
   public:
    int lengthOfLastWord(string s) {
        if (s.length() == 0) return 0;
        int count = 0;
        int p     = s.length() - 1;
        while (s[p] == ' ' && p > 0) --p;  //去除末尾空格
        //if (p == 0) return 0;

        for (int i = p; i >= 0; --i) {
            if (s[i] != ' ') {
                ++count;
            } else {
                break;
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    string str = " ";
    cout << s.lengthOfLastWord(str);
    return 0;
}