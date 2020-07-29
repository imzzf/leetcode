#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int p : nums) {
            m[p]++;
        }
        // set内部使用红黑树实现，是有序排列的
        // multiset不同于set，其允许相同的键值
        // 利用set模拟最小堆，每次只需要与根节点比较
        // multiset<pair<int, int>> s;
        // for (auto p : m) {
        //     if (s.size() < k) {
        //         s.insert(pair<int, int>(p.second, p.first));
        //     } else {
        //         if (p.second > (*s.begin()).first) {
        //             s.erase(s.begin());
        //             s.insert(pair<int, int>(p.second, p.first));
        //         }
        //     }
        // }
        // vector<int> ans;
        // for (pair<int, int> p : s) {
        //     ans.push_back(p.second);
        // }
        // return ans;

        //优先队列  小根堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto p : m) {
            if (pq.size() < k) {
                pq.push(make_pair(p.second, p.first));
            } else {
                if (p.second > pq.top().first) {
                    pq.pop();
                    pq.push(make_pair(p.second, p.first));
                }
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1, 1, 2, 2, 2, 3};
    int k            = 2;
    vector<int> ans  = s.topKFrequent(nums, k);
    for (int i : ans) cout << i << " ";
    return 0;
}