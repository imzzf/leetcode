#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        //滑动窗口
        int res = 0;
        int len = s.length();
        map<char, int> map;
        for (int i = 0, j = 0; j < len; j++) {
            if (map.count(s[j])) {
                i = i > map[s[j]] ? i : map[s[j]];
            }
            map[s[j]] = j + 1;
            res       = j - i + 1 > res ? j - i + 1 : res;
        }
        return res;
    }
};