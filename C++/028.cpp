#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int strStr(string haystack, string needle) {
        //Boyer-Moore算法
        //https://www.cnblogs.com/lanxuezaipiao/p/3452579.html

        if (needle == "") {
            return 0;
        } else {
            return bm(needle, haystack);
        }
    }

    void getBadChar(string& pattern, vector<int>& bmBadChar) {  //坏字符数组
        int m = pattern.size();
        for (int i = 0; i < 256; ++i) {
            bmBadChar.push_back(m);
        }
        for (int i = 0; i < m - 1; ++i) {
            bmBadChar[pattern[i]] = m - 1 - i;
        }
    }

    void getGoodSuff(string& pattern, vector<int>& bmGoodSuff) {  //好后缀数组
        int i, j;
        int m = pattern.size();
        vector<int> suff(m + 1, 0);

        suffix(pattern, suff);

        for (i = 0; i < m; i++) {
            bmGoodSuff[i] = m;
        }

        for (i = m - 1; i >= 0; i--) {
            if (suff[i] == i + 1) {
                for (j = 0; j < m - 1 - i; j++) {
                    if (bmGoodSuff[j] == m)
                        bmGoodSuff[j] = m - 1 - i;
                }
            }
        }

        for (i = 0; i <= m - 2; i++) {
            bmGoodSuff[m - 1 - suff[i]] = m - 1 - i;
        }
    }

    void suffix(string& pattern, vector<int>& suff) {
        int j;
        int m = pattern.size();

        suff[m - 1] = m;

        for (int i = m - 2; i >= 0; i--) {
            j = i;
            while (j >= 0 && pattern[j] == pattern[m - 1 - i + j]) j--;

            suff[i] = i - j;
        }
    }

    int bm(string& pattern, string& text) {
        int m = pattern.size();
        int n = text.size();
        int i;
        int j = 0;
        vector<int> bmBadChar;
        vector<int> bmGoodSuff(m, 0);
        getBadChar(pattern, bmBadChar);
        getGoodSuff(pattern, bmGoodSuff);

        while (j <= n - m) {
            for (i = m - 1; i >= 0 && pattern[i] == text[i + j]; i--)
                ;
            if (i < 0) {
                return j;
            }
            int a = bmBadChar[text[i + j]] - m + 1 + i;
            int b = bmGoodSuff[i];
            j += a > b ? a : b;
        }
        return -1;
    }
};

int main() {
    Solution s;
    string haystack = "saflasjlfk";
    string needle   = "afjl";
    cout << s.strStr(haystack, needle);

    return 0;
}