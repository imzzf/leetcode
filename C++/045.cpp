#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
   public:
    int jump(vector<int>& nums) {
        int max_pos = 0;
        int end     = 0;
        int ans     = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            max_pos = max(max_pos, i + nums[i]);
            if (i == end) {
                end = max_pos;
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << s.jump(nums);
    return 0;
}