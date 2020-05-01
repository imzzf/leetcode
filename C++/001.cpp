#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> p;
        for (int i = 0; i < nums.size(); ++i) {
            int t = target - nums[i];
            if (p.find(t) != p.end()) {
                ans = {i, p[t]};
                break;
            }
            p[nums[i]] = i;
        }
        return ans;
    }
};