#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int change(int n) {
        int res = 0;
        while (n != 0) {
            int t = n % 10;
            res += t * t;
            n /= 10;
        }
        return res;
    }

    // bool isHappy(int n) {
    //     set<int> p;
    //     p.insert(n);
    //     while (n != 1) {
    //         n = change(n);
    //         if (p.find(n) != p.end()) {
    //             return false;
    //         }
    //         p.insert(n);
    //     }
    //     return true;
    // }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = change(slow);
            fast = change(fast);
            fast = change(fast);
        } while (fast != slow);
        return fast == 1;
    }
};

int main() {
    return 0;
}