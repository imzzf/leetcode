#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        //滑动窗口
        int ans = 0;
        int len = s.length();
        map<char, int> map;
        int i = 0;
        for (int j = 0; j < len; j++) {
            if (map.count(s[j])) {
                i = max(i, map[s[j]]);
            }
            ans       = max(j - i + 1, ans);
            map[s[j]] = j + 1;
        }
        return ans;
    }
};