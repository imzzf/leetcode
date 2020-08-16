#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;

        int ans  = 0;          //记录截止当日的最大收益，第一天收益为0
        int _min = prices[0];  //记录截止当日的股价最低值

        for (int price : prices) {
            //每一天的最大收益 = max(前一天的最大收益, 当日价格 - 历史低值)
            ans  = max(ans, price - _min);
            _min = min(_min, price);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(prices);
    return 0;
}