#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
   public:
    bool isSubsequence(string s, string t) {
        int a = s.length();
        int b = t.length();
        int i = 0, j = 0;
        while (i < a && j < b) {
            if (s[i] == t[j]) {
                ++i;
            }
            ++j;
        }
        return i == a;
    }
};

int main() {
    return 0;
}