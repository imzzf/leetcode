#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int ans  = 0;
        int _min = prices[0];
        for (int price : prices) {
            if (price > _min) {
                ans += price - _min;
            }
            _min = price;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> prices  = {7, 1, 5, 3, 6, 4};
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << s.maxProfit(prices2);
    return 0;
}